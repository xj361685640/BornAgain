// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/RealSpaceWidgets/RealSpace2DParacrystalUtils.h
//! @brief     Defines RealSpaceBuilderUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef REALSPACE2DPARACRYSTALUTILS_H
#define REALSPACE2DPARACRYSTALUTILS_H

#include "WinDllMacros.h"
#include <vector>

class InterferenceFunction2DParaCrystal;

namespace RealSpace2DParacrystalUtils
{
std::vector<std::vector<double>>
Compute2DParacrystalLatticePositions(const InterferenceFunction2DParaCrystal*, double layer_size);
};

#endif // REALSPACE2DPARACRYSTALUTILS_H