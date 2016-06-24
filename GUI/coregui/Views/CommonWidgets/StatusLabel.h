// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/CommonWidgets/StatusLabel.h
//! @brief     Declares class StatusLabel
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef STATUSLABEL_H
#define STATUSLABEL_H

#include "WinDllMacros.h"
#include <QFrame>

class QPaintEvent;

//! The StatusLabel class shows a single line of text on a white background. Opposite to QLabel,
//! it adjusts size of text depending on available space.

class BA_CORE_API_ StatusLabel : public QFrame
{
    Q_OBJECT

public:
    StatusLabel(QWidget *parent = 0);

    void setText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event);

private:
    QString m_text;
};

#endif

