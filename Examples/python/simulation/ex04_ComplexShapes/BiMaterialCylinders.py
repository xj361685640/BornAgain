"""
Cylindrical particle made from two materials.
Particle crosses air/substrate interface.
"""
import bornagain as ba
from bornagain import deg, angstrom, nm

phi_min, phi_max = -1.0, 1.0
alpha_min, alpha_max = 0.0, 2.0


def get_composition(top_material, bottom_material, top_height=4.0, bottom_height=10.0):
    """
    Returns cylindrical particle made of two different materials.
    """

    cylinder_radius = 10*nm

    topPart = ba.Particle(top_material, ba.FormFactorCylinder(cylinder_radius, top_height))
    bottomPart = ba.Particle(bottom_material, ba.FormFactorCylinder(cylinder_radius, bottom_height))

    result = ba.ParticleComposition()
    result.addParticle(topPart, ba.kvector_t(0.0, 0.0, bottom_height))
    result.addParticle(bottomPart)

    return result


def get_sample():
    """
    Returns a multi layer with substrate/air layers. Air layer contains cylindrical particle
    made of two materials. Particle shifted down to cross interface.
    """

    # defining materials
    m_air = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 3.212e-6, 3.244e-8)
    m_top_part = ba.HomogeneousMaterial("Ag", 1.245e-5, 5.419e-7)
    m_bottom_part = ba.HomogeneousMaterial("Teflon", 2.900e-6, 6.019e-9)

    # collection of particles
    composition = get_composition(m_top_part, m_bottom_part)
    shift = 10.0*nm
    composition.setPosition(0, 0, -shift)  # will be shifted below interface

    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(composition)
    particle_layout.setTotalParticleSurfaceDensity(1)

    # air layer with particles and substrate form multi layer
    air_layer = ba.Layer(m_air)
    air_layer.addLayout(particle_layout)
    substrate_layer = ba.Layer(m_substrate)
    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    print(multi_layer.treeToString())
    return multi_layer


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined.
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(100, phi_min*deg, phi_max*deg,
                                     100, alpha_min*deg, alpha_max*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    simulation.setBeamIntensity(1.0e+08)
    return simulation


def run_simulation():
    """
    Runs simulation and returns resulting intensity map.
    """
    sample = get_sample()
    simulation = get_simulation()
    simulation.setSample(sample)
    simulation.runSimulation()
    return simulation.getIntensityData()


if __name__ == '__main__':
    result = run_simulation()
    ba.plot_intensity_data(result)
