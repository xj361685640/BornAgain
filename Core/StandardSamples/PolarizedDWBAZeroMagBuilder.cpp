// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/PolarizedDWBAZeroMagBuilder.cpp
//! @brief     Implements class PolarizedDWBAZeroMagBuilder
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "PolarizedDWBAZeroMagBuilder.h"
#include "MultiLayer.h"
#include "ParticleDecoration.h"
#include "MaterialManager.h"
#include "FormFactorCylinder.h"
#include "Units.h"
#include "InterferenceFunctionNone.h"

PolarizedDWBAZeroMagBuilder::PolarizedDWBAZeroMagBuilder()
    : m_cylinder_height(5*Units::nanometer)
    , m_cylinder_radius(5*Units::nanometer)
{
    init_parameters();
}


void PolarizedDWBAZeroMagBuilder::init_parameters()
{
    clearParameterPool();
    registerParameter("cylinder_height", &m_cylinder_height);
    registerParameter("cylinder_raduis", &m_cylinder_radius);
}


ISample *PolarizedDWBAZeroMagBuilder::buildSample() const
{
	MultiLayer *multi_layer = new MultiLayer();

    kvector_t magnetic_field(0.0, 0.0, 0.0);
    const IMaterial *p_air_material =
            MaterialManager::getHomogeneousMaterial("Air", 0.0, 0.0);
    const IMaterial *p_substrate_material =
            MaterialManager::getHomogeneousMaterial("Substrate", 6e-6, 2e-8);
    Layer air_layer;
    air_layer.setMaterial(p_air_material);
    Layer substrate_layer;
    substrate_layer.setMaterial(p_substrate_material);
    const IMaterial *particle_material =
            MaterialManager::getHomogeneousMagneticMaterial(
                    "MagParticle", 6e-4, 2e-8, magnetic_field);

    ParticleDecoration particle_decoration(
            new Particle(particle_material,
                    new FormFactorCylinder(m_cylinder_height,
                                           m_cylinder_radius)));

    particle_decoration.addInterferenceFunction(new InterferenceFunctionNone());

    air_layer.setDecoration(particle_decoration);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);
    return multi_layer;
}

