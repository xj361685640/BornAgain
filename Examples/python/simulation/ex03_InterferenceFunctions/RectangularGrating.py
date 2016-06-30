"""
Simulation of grating using very long boxes and 1D lattice.
Monte-carlo integration is used to get rid of
large-particle form factor oscillations.
"""
import numpy
import matplotlib
from matplotlib import pyplot as plt
import bornagain as ba
from bornagain import deg, angstrom, nm

phi_min, phi_max = -1.0, 1.0
alpha_min, alpha_max = 0.0, 2.0


def get_sample(lattice_rotation_angle=45.0*deg):
    """
    Returns a sample with a grating on a substrate,
    modelled by very long boxes forming a 1D lattice with Cauchy correlations.
    """
    # defining materials
    m_ambience = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = ba.HomogeneousMaterial("Particle", 6e-4, 2e-8)

    box_length, box_width, box_height = 10*nm, 10000*nm, 10.0*nm
    lattice_length = 30.0*nm

    # collection of particles
    interference = ba.InterferenceFunction1DLattice(
        lattice_length, lattice_rotation_angle)
    pdf = ba.FTDecayFunction1DCauchy(1000.0)
    interference.setDecayFunction(pdf)

    box_ff = ba.FormFactorBox(box_length, box_width, box_height)
    box = ba.Particle(m_particle, box_ff)

    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(
        box, 1.0, ba.kvector_t(0.0, 0.0, 0.0), ba.RotationZ(lattice_rotation_angle))
    particle_layout.addInterferenceFunction(interference)

    # assembling the sample
    air_layer = ba.Layer(m_ambience)
    air_layer.addLayout(particle_layout)
    substrate_layer = ba.Layer(m_substrate)

    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation(monte_carlo_integration=True):
    """
    Create and return GISAXS simulation with beam and detector defined
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(200, phi_min*deg, phi_max*deg,
                                     200, alpha_min*deg, alpha_max*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    simulation.getOptions().setMonteCarloIntegration(True, 100)

    return simulation


def run_simulation():
    """
    Run simulation and plot results
    """
    sample = get_sample(lattice_rotation_angle=45.0*deg)
    simulation = get_simulation(monte_carlo_integration=True)
    simulation.setSample(sample)
    simulation.runSimulation()
    result = simulation.getIntensityData()

    # showing the result
    im = plt.imshow(
        result.getArray(),
        norm=matplotlib.colors.LogNorm(1.0, result.getMaximum()),
        extent=[result.getXmin()/deg, result.getXmax()/deg,
                result.getYmin()/deg, result.getYmax()/deg],
        aspect='auto')
    cb = plt.colorbar(im)
    cb.set_label(r'Intensity (arb. u.)', size=16)
    plt.xlabel(r'$\phi_f (^{\circ})$', fontsize=16)
    plt.ylabel(r'$\alpha_f (^{\circ})$', fontsize=16)
    plt.show()


if __name__ == '__main__':
    run_simulation()