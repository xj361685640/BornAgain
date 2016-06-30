// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/MaskWidgets/MaskEditorPropertyPanel.cpp
//! @brief     Implements class MaskEditorPropertyPanel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "MaskEditorPropertyPanel.h"
#include "SessionModel.h"
#include "MaskEditorFlags.h"
#include "IntensityDataItem.h"
#include "AccordionWidget.h"
#include "ComponentEditor.h"
#include "ContentPane.h"

#include <QVBoxLayout>
#include <QListView>
#include <QItemSelection>
#include <QModelIndexList>
#include <QButtonGroup>
#include <QToolButton>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QDebug>

MaskEditorPropertyPanel::MaskEditorPropertyPanel(QWidget *parent)
    : QWidget(parent)
    , m_listView(new QListView)
    , m_maskPropertyEditor(new ComponentEditor)
    , m_plotPropertyEditor(new ComponentEditor)
    , m_maskModel(0)
    , m_intensityDataItem(0)
{
    setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
    setObjectName(QLatin1String("MaskEditorToolPanel"));

    m_listView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(m_listView, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(onCustomContextMenuRequested(const QPoint &)));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setContentsMargins(0,0,0,0);

    AccordionWidget *accordion = new AccordionWidget();
    mainLayout->addWidget(accordion);
    mainLayout->setSpacing(0);

    setup_MaskStack(accordion);
    setup_MaskProperties(accordion);
    setup_PlotProperties(accordion);
//    mainLayout->addWidget(m_plotPropertyEditor);

    setLayout(mainLayout);
}


void MaskEditorPropertyPanel::setMaskContext(SessionModel *model, const QModelIndex &maskContainerIndex,
                    IntensityDataItem *intensityItem)
{
    m_maskModel = model;
    m_rootIndex = maskContainerIndex;
    m_intensityDataItem = intensityItem;

    m_listView->setModel(m_maskModel);
    m_listView->setRootIndex(m_rootIndex);
    m_listView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    connect(m_listView->selectionModel(),
            SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
            this,
            SLOT(onSelectionChanged(QItemSelection, QItemSelection)));

    m_plotPropertyEditor->setItem(m_intensityDataItem);
}

QItemSelectionModel *MaskEditorPropertyPanel::selectionModel()
{
    Q_ASSERT(m_listView);
    return m_listView->selectionModel();
}

//! Show/Hide panel. When panel is hidden, all property editors are disabled.
void MaskEditorPropertyPanel::setPanelHidden(bool value)
{
    this->setHidden(value);

    if(!m_rootIndex.isValid()) return;

    if(value) {
        m_maskPropertyEditor->setItem(0);
        m_plotPropertyEditor->setItem(0);
    } else {
        QModelIndexList indexes = selectionModel()->selectedIndexes();
        if(indexes.size()) {
            m_maskPropertyEditor->setItem(m_maskModel->itemForIndex(indexes.front()));
        }
        m_plotPropertyEditor->setItem(m_intensityDataItem);
    }
}

void MaskEditorPropertyPanel::onSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    Q_UNUSED(deselected);
    if(selected.size()) {
        m_maskPropertyEditor->setItem(m_maskModel->itemForIndex(selected.indexes().front()));
    } else {
        m_maskPropertyEditor->setItem(0);
    }
}

void MaskEditorPropertyPanel::onCustomContextMenuRequested(const QPoint &point)
{
    emit itemContextMenuRequest(m_listView->mapToGlobal(point));
}

void MaskEditorPropertyPanel::setup_MaskStack(AccordionWidget *accordion)
{
    ContentPane *cp = accordion->getContentPane(accordion->addContentPane("Mask stack"));
    cp->setMaximumHeight(400);
    cp->headerClicked();
    cp->setHeaderTooltip("List of created masks representing mask stacking order.");
    cp->setContainerFrameStyle(QFrame::Plain);
    QFrame *contentFrame = cp->getContentFrame();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_listView);
    contentFrame->setLayout(layout);
}

void MaskEditorPropertyPanel::setup_MaskProperties(AccordionWidget *accordion)
{
    ContentPane *cp = accordion->getContentPane(accordion->addContentPane("Mask properties"));
    cp->setMaximumHeight(400);
    cp->setHeaderTooltip("Property editor for currently selected mask.");
    cp->setContainerFrameStyle(QFrame::Plain);
    QFrame *contentFrame = cp->getContentFrame();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_maskPropertyEditor);
    contentFrame->setLayout(layout);
}

void MaskEditorPropertyPanel::setup_PlotProperties(AccordionWidget *accordion)
{
    ContentPane *cp = accordion->getContentPane(accordion->addContentPane("Plot properties"));
    cp->setMaximumHeight(400);
    cp->setHeaderTooltip("Plot properties editor");
    cp->setContainerFrameStyle(QFrame::Plain);
    QFrame *contentFrame = cp->getContentFrame();

    //contentFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);
    m_plotPropertyEditor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(m_plotPropertyEditor);
    contentFrame->setLayout(layout);
}
