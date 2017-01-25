// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/LatticeTypeItems.cpp
//! @brief     Implements classes LatticeTypeItems
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "LatticeTypeItems.h"
#include "BornAgainNamespace.h"

const QString BasicLatticeTypeItem::P_LATTICE_LENGTH1
    = QString::fromStdString(BornAgain::LatticeLength1);
const QString BasicLatticeTypeItem::P_LATTICE_LENGTH2
    = QString::fromStdString(BornAgain::LatticeLength2);
const QString BasicLatticeTypeItem::P_LATTICE_ANGLE
    = QString::fromStdString(BornAgain::LatticeAngle);

BasicLatticeTypeItem::BasicLatticeTypeItem()
    : SessionItem(Constants::BasicLatticeType)
{
    addProperty(P_LATTICE_LENGTH1, 20.0);
    addProperty(P_LATTICE_LENGTH2, 20.0);
    addProperty(P_LATTICE_ANGLE, 90.0);
}

// --------------------------------------------------------------------------------------------- //

const QString SquareLatticeTypeItem::P_LATTICE_LENGTH
    = QString::fromStdString(BornAgain::LatticeLength);

SquareLatticeTypeItem::SquareLatticeTypeItem()
    : SessionItem(Constants::SquareLatticeType)
{
    addProperty(P_LATTICE_LENGTH, 20.0);
}

// --------------------------------------------------------------------------------------------- //

const QString HexagonalLatticeTypeItem::P_LATTICE_LENGTH
    = QString::fromStdString(BornAgain::LatticeLength);

HexagonalLatticeTypeItem::HexagonalLatticeTypeItem()
    : SessionItem(Constants::HexagonalLatticeType)
{
    addProperty(P_LATTICE_LENGTH, 20.0);
}
