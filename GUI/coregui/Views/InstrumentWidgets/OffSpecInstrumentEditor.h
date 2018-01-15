// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/InstrumentWidgets/OffSpecInstrumentEditor.h
//! @brief     Defines class OffSpecInstrumentEditor
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef OFFSPECINSTRUMENTEDITOR_H
#define OFFSPECINSTRUMENTEDITOR_H

#include "SessionItemWidget.h"

class GISASInstrumentItem;
class GISASBeamEditor;
class GISASDetectorEditor;
class EnvironmentEditor;
class PolarizationAnalysisEditor;
class ColumnResizer;
class QVBoxLayout;

class BA_CORE_API_ OffSpecInstrumentEditor : public SessionItemWidget
{
    Q_OBJECT

public:
    OffSpecInstrumentEditor(QWidget* parent = nullptr);

protected:
    void subscribeToItem();

private:
    void addEditor(QVBoxLayout* layout, QWidget* widget, const QString& name, bool expanded=true);

    GISASInstrumentItem* instrumentItem();
    ColumnResizer* m_columnResizer;
    GISASBeamEditor* m_beamEditor;
    GISASDetectorEditor* m_detectorEditor;
    EnvironmentEditor* m_environmentEditor;
    PolarizationAnalysisEditor* m_polarizationAnalysisEditor;
};

#endif  // OFFSPECINSTRUMENTEDITOR_H
