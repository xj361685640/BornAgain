#include "NormalizingSpecularComputationTerm.h"
#include "SimulationElement.h"
#include "IFresnelMap.h"
#include "ILayerRTCoefficients.h"

NormalizingSpecularComputationTerm::NormalizingSpecularComputationTerm(const MultiLayer* p_multi_layer,
                                         const IFresnelMap* p_fresnel_map)
    : SpecularComputationTerm(p_multi_layer, p_fresnel_map)
{}

void NormalizingSpecularComputationTerm::evalSingle(const std::vector<SimulationElement>::iterator& iter) const
{
    complex_t R = mp_fresnel_map->getInCoefficients(*iter, 0)->getScalarR();
    double sin_alpha_i = std::abs(std::sin(iter->getAlphaI()));
    if (sin_alpha_i == 0.0)
        sin_alpha_i = 1.0;
    const double solid_angle = iter->getSolidAngle();
    if (solid_angle <= 0.0)
        return;
    const double intensity = std::norm(R) * sin_alpha_i / solid_angle;
    iter->setIntensity(intensity);
}
