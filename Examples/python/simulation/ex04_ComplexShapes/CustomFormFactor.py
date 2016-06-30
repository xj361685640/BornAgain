"""
Custom form factor in DWBA.
"""
import numpy
import matplotlib
from matplotlib import pyplot as plt
import bornagain as ba
from bornagain import deg, angstrom, nm
import cmath

phi_min, phi_max = -1.0, 1.0
alpha_min, alpha_max = 0.0, 2.0

def sinc(x):
    if abs(x) == 0.:
        return 1.
    else:
        return cmath.sin(x)/x

class CustomFormFactor(ba.IFormFactorBorn):
    """
    A custom defined form factor
    The particle is a polyhedron, whose planar cross section is a "plus" shape
    with a side length L.
    H is the height of particle
    """
    def __init__(self, L, H):
        ba.IFormFactorBorn.__init__(self)
        # parameters describing the form factor
        self.L = L
        self.H = H


    def clone(self):
        """
        IMPORTANT NOTE:
        The clone method needs to call transferToCPP() on the cloned object
        to transfer the ownership of the clone to the cpp code
        """
        cloned_ff = CustomFormFactor(self.L, self.H)
        cloned_ff.transferToCPP()
        return cloned_ff

    def evaluate_for_q(self, q):
        qzhH = 0.5*q.z()*self.H
        qxhL = 0.5*q.x()*self.L
        qyhL = 0.5*q.y()*self.L
        return 0.5*self.H*self.L**2*cmath.exp(complex(0., 1.)*qzhH)*\
               sinc(qzhH)*(sinc(0.5*qyhL)*(sinc(qxhL)-0.5*sinc(0.5*qxhL))+\
               sinc(0.5*qxhL)*sinc(qyhL))



def get_sample():
    """
    Returns a sample with particles, having a custom form factor, on a substrate.
    """
    # defining materials
    m_ambience = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = ba.HomogeneousMaterial("Particle", 6e-4, 2e-8)

    # collection of particles
    ff = CustomFormFactor(20.0*nm, 15.0*nm)
    particle = ba.Particle(m_particle, ff)
    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(particle, 1.0)
    air_layer = ba.Layer(m_ambience)
    air_layer.addLayout(particle_layout)
    substrate_layer = ba.Layer(m_substrate)

    # assemble multilayer
    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined.
    IMPORTANT NOTE:
    Multithreading should be deactivated by putting ThreadInfo.n_threads to -1
    """
    simulation = ba.GISASSimulation()
    simulation.getOptions().setNumberOfThreads(-1)
    simulation.setDetectorParameters(100, phi_min*deg, phi_max*deg,
                                     100, alpha_min*deg, alpha_max*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    return simulation


def run_simulation():
    """
    Run simulation and plot results
    """
    sample = get_sample()
    simulation = get_simulation()
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
