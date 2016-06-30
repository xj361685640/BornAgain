"""
Two parameter fit of cylinders.
In this example we are trying to find cylinder's height and radius
using chain of minimizers.

During the first fit round Genetic minimizer will be used.
It will roughly look for possible local minimas.
After it is done, the second Minuit2 minimizer will continue
to find the precise location of best minima found on previous step.
"""

from __future__ import print_function
from matplotlib import pyplot as plt
import math
import random
import bornagain as ba
from bornagain import deg, angstrom, nm


def get_sample(radius=5*nm, height=5*nm):
    """
    Returns a sample with uncorrelated cylinders and pyramids on a substrate.
    """
    m_air = ba.HomogeneousMaterial("Air", 0.0, 0.0)
    m_substrate = ba.HomogeneousMaterial("Substrate", 6e-6, 2e-8)
    m_particle = ba.HomogeneousMaterial("Particle", 6e-4, 2e-8)

    cylinder_ff = ba.FormFactorCylinder(radius, height)
    cylinder = ba.Particle(m_particle, cylinder_ff)

    particle_layout = ba.ParticleLayout()
    particle_layout.addParticle(cylinder)

    air_layer = ba.Layer(m_air)
    air_layer.addLayout(particle_layout)

    substrate_layer = ba.Layer(m_substrate, 0)
    multi_layer = ba.MultiLayer()
    multi_layer.addLayer(air_layer)
    multi_layer.addLayer(substrate_layer)
    return multi_layer


def get_simulation():
    """
    Returns a GISAXS simulation with beam and detector defined.
    """
    simulation = ba.GISASSimulation()
    simulation.setDetectorParameters(100, 0.0*deg, 2.0*deg,
                                     100, 0.0*deg, 2.0*deg)
    simulation.setBeamParameters(1.0*angstrom, 0.2*deg, 0.0*deg)
    return simulation


def create_real_data():
    """
    Generating "real" data by adding noise to the simulated data.
    """
    sample = get_sample(5.0*nm, 5.0*nm)

    simulation = get_simulation()
    simulation.setSample(sample)

    simulation.runSimulation()
    real_data = simulation.getIntensityData()

    # spoiling simulated data with the noise to produce "real" data
    noise_factor = 0.1
    for i in range(0, real_data.getTotalNumberOfBins()):
        amplitude = real_data.getBinContent(i)
        sigma = noise_factor*math.sqrt(amplitude)
        noisy_amplitude = random.gauss(amplitude, sigma)
        if noisy_amplitude < 0.1:
            noisy_amplitude = 0.1
        real_data.setBinContent(i, noisy_amplitude)
    return real_data


def run_fitting():
    """
    main function to run fitting
    """
    simulation = get_simulation()
    sample = get_sample()
    simulation.setSample(sample)

    real_data = create_real_data()

    fit_suite = ba.FitSuite()
    fit_suite.addSimulationAndRealData(simulation, real_data)
    fit_suite.initPrint(10)

    draw_observer = ba.DefaultFitObserver(draw_every_nth=10)
    fit_suite.attachObserver(draw_observer)

    # setting fitting parameters with starting values
    # Here we select starting values being quite far from true values
    # to puzzle our minimizer's as much as possible
    fit_suite.addFitParameter(
        "*Height", 1.*nm, ba.AttLimits.limited(0.01, 30.), 0.04*nm)
    fit_suite.addFitParameter(
        "*Radius", 20.*nm, ba.AttLimits.limited(0.01, 30.), 0.06*nm)

    # Now we create first fig strategy which will run first minimization round
    # using the Genetic minimizer.
    # The Genetic minimizer is able to explore large parameter space
    # without being trapped by some local minima.
    strategy1 = ba.FitStrategyAdjustMinimizer("Genetic")
    strategy1.getMinimizerOptions().setMaxIterations(3)
    fit_suite.addFitStrategy(strategy1)

    # Second fit strategy will use another minimizer.
    # It starts from best parameters found in previous minimization
    # and then continues until fit converges.
    strategy2 = ba.FitStrategyAdjustMinimizer("Minuit2", "Migrad")
    fit_suite.addFitStrategy(strategy2)

    # running fit
    fit_suite.runFit()

    print("Fitting completed.")
    print("chi2:", fit_suite.getChi2())
    fitpars = fit_suite.getFitParameters()
    for i in range(0, fitpars.size()):
        print(fitpars[i].getName(), fitpars[i].getValue(), fitpars[i].getError())


if __name__ == '__main__':
    run_fitting()
    plt.show()
