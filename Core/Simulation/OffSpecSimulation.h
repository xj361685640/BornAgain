// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Simulation/OffSpecSimulation.h
//! @brief     Defines class OffSpecSimulation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_SIMULATION_OFFSPECSIMULATION_H
#define BORNAGAIN_CORE_SIMULATION_OFFSPECSIMULATION_H

#include "Base/Pixel/SimulationElement.h"
#include "Core/Simulation/ISimulation2D.h"

class Histogram2D;

//! Main class to run an off-specular simulation.
//! @ingroup simulation

class OffSpecSimulation : public ISimulation2D
{
public:
    OffSpecSimulation();
    ~OffSpecSimulation() final {}

    OffSpecSimulation* clone() const override { return new OffSpecSimulation(*this); }

    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    //! Put into a clean state for running a simulation
    void prepareSimulation() final;

    //! Returns the results of the simulation in a format that supports unit conversion and export
    //! to numpy arrays
    SimulationResult result() const override;

    //! Sets beam parameters from here (forwarded to Instrument)
    void setBeamParameters(double wavelength, const IAxis& alpha_axis, double phi_i);

    //! Returns axis of the beam.
    const IAxis* beamAxis() const;

#ifndef SWIG
    std::unique_ptr<IUnitConverter> createUnitConverter() const;
#endif

    //! Returns the total number of the intensity values in the simulation result
    size_t intensityMapSize() const override;

private:
    OffSpecSimulation(const OffSpecSimulation& other);

    //! Initializes the vector of ISimulation elements
    void initSimulationElementVector() override;

    //! Checks the distribution validity for simulation.
    void validateParametrization(const ParameterDistribution& par_distr) const override;

    //! Creates the appropriate data structure (e.g. 2D intensity map) from the calculated
    //! SimulationElement objects
    void transferResultsToIntensityMap() override;

    //! Default implementation only adds the detector axes
    void updateIntensityMap() override;

    //! Gets the number of elements this simulation needs to calculate
    size_t numberOfSimulationElements() const final;

    //! Normalize, apply detector resolution and transfer detector image corresponding to
    //! alpha_i = m_alpha_i_axis->bin(index)
    void transferDetectorImage(size_t index);

    //! Check correct number of axes
    void checkInitialization() const;

    void initialize();

    std::unique_ptr<IAxis> m_alpha_i_axis;
    OutputData<double> m_intensity_map;
};

#endif // BORNAGAIN_CORE_SIMULATION_OFFSPECSIMULATION_H
