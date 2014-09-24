// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/inc/SimulationParameters.h
//! @brief     Defines class SimulationParameters.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef SIMULATIONPARAMETERS_H_
#define SIMULATIONPARAMETERS_H_

#include "WinDllMacros.h"

#include <cstddef>

//! @class Simulation
//! @ingroup simulation
//! @brief Collect the different options for simulation
//! @ref SimulationParameters

class BA_CORE_API_ SimulationParameters
{
public:
    SimulationParameters();
    enum EFramework { DWBA, BA } me_framework;
    enum EInterferenceApproximation { DA, LMA, SSCA, ISGISAXSMOR } me_if_approx;
    bool m_mc_integration;
    size_t m_mc_points;
};

inline SimulationParameters::SimulationParameters()
: me_framework(DWBA)
, me_if_approx(DA)
, m_mc_integration(false)
, m_mc_points(1)
{
}

#endif /* SIMULATIONPARAMETERS_H_ */


