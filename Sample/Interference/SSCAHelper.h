// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Sample/Interference/SSCAHelper.h
//! @brief     Defines class SSCAHelper.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_SAMPLE_INTERFERENCE_SSCAHELPER_H
#define BORNAGAIN_SAMPLE_INTERFERENCE_SSCAHELPER_H

#include "Sample/Interference/FormFactorPrecompute.h"
#include "Sample/Interference/IInterferenceFunctionStrategy.h"
#include <Eigen/StdVector>

class FormFactorCoherentSum;
class IInterferenceFunction;

//! Helper class for SSCApproximationStrategy, offering some methods, shared between
//! the scalar and polarized scattering calculations
//! @ingroup algorithms_internal

class SSCAHelper
{
public:
    SSCAHelper(double kappa);

    void init(const std::vector<FormFactorCoherentSum>& ff_wrappers);

    complex_t
    getCharacteristicSizeCoupling(double qp,
                                  const std::vector<FormFactorCoherentSum>& ff_wrappers) const;
    complex_t getCharacteristicDistribution(double qp, const IInterferenceFunction* p_iff) const;
    complex_t calculatePositionOffsetPhase(double qp, double radial_extension) const;
    complex_t getMeanFormfactorNorm(double qp, const std::vector<complex_t>& precomputed_ff,
                                    const std::vector<FormFactorCoherentSum>& ff_wrappers) const;
    void getMeanFormfactors(double qp, Eigen::Matrix2cd& ff_orig, Eigen::Matrix2cd& ff_conj,
                            const FormFactorPrecompute::matrixFFVector_t& precomputed_ff,
                            const std::vector<FormFactorCoherentSum>& ff_wrappers) const;

private:
    double m_kappa;
    double m_mean_radius;
};

#endif // BORNAGAIN_SAMPLE_INTERFERENCE_SSCAHELPER_H
