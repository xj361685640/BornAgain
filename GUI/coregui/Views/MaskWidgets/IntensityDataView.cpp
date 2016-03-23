// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/MaskWidgets/IntensityDataView.cpp
//! @brief     Implements IntensityDataView class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "IntensityDataView.h"
#include "ISceneAdaptor.h"
#include <QPainter>
#include <QBrush>
#include <QStyleOptionGraphicsItem>
#include <QDebug>


IntensityDataView::IntensityDataView()
{
    // the key flag to not to draw children going outside ot given shape
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
}

void IntensityDataView::update_view()
{
//    prepareGeometryChange();
    m_bounding_rect = m_adaptor->getViewportRectangle();
    update();
}

void IntensityDataView::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    Q_UNUSED(painter);
}
