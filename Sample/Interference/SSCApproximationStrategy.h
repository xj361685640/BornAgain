// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Interference/SSCApproximationStrategy.h
//! @brief     Defines class SSCApproximationStrategy.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_SAMPLE_INTERFERENCE_SSCAPPROXIMATIONSTRATEGY_H
#define BORNAGAIN_SAMPLE_INTERFERENCE_SSCAPPROXIMATIONSTRATEGY_H

#include "Sample/Interference/SSCAHelper.h"

class SimulationElement;

//! Strategy class to compute the total scattering from a particle layout
//! in the size-spacing correlation approximation.
//! @ingroup algorithms_internal

class SSCApproximationStrategy final : public IInterferenceFunctionStrategy
{
public:
    SSCApproximationStrategy(const std::vector<FormFactorCoherentSum>& weighted_formfactors,
                             const IInterferenceFunction* p_iff, SimulationOptions sim_params,
                             bool polarized, double kappa);

private:
    double scalarCalculation(const SimulationElement& sim_element) const override;
    double polarizedCalculation(const SimulationElement& sim_element) const override;
    SSCAHelper m_helper;
};

#endif // BORNAGAIN_SAMPLE_INTERFERENCE_SSCAPPROXIMATIONSTRATEGY_H
