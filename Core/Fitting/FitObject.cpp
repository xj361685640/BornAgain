// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Fitting/FitObject.cpp
//! @brief     Implements class FitObject.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FitObject.h"
#include "FitElement.h"
#include "GISASSimulation.h"
#include "IIntensityNormalizer.h"
#include "SimulationArea.h"
#include "BornAgainNamespace.h"
#include "DetectorFunctions.h"

FitObject::FitObject(const GISASSimulation& simulation, const OutputData<double >& real_data,
    double weight)
    : m_simulation(simulation.clone())
    , m_weight(weight)
{
    setName("FitObject");
    init_dataset(real_data);
}

FitObject::~FitObject()
{}

//! Adds parameters from local pool to external pool
std::string FitObject::addParametersToExternalPool(
    const std::string& path, ParameterPool* external_pool, int copy_number) const
{
    // add own parameters
    std::string new_path = IParameterized::addParametersToExternalPool(
        path, external_pool, copy_number);

    // add parameters of the simulation
    if(m_simulation)
        m_simulation->addParametersToExternalPool(new_path, external_pool, -1);

    return new_path;
}

//! Initialize detector, if necessary, to match experimental data
void FitObject::init_dataset(const OutputData<double >& real_data)
{
    check_realdata(real_data);

    m_chi2_data.reset(m_simulation->getInstrument().createDetectorMap());
    m_real_data = DetectorFunctions::createDataSet(m_simulation->getInstrument(), real_data);

}

//! Checks if real data and the detector have same dimensions. If not, exception will be thrown.

void FitObject::check_realdata(const OutputData<double> &real_data) const
{
    const IDetector2D *detector = m_simulation->getInstrument().getDetector();
    if(!DetectorFunctions::hasSameDimensions(*detector, real_data)){
        std::ostringstream message;
        message << "FitObject::check_realdata() -> Error. Axes of the real data doesn't match "
                << "the detector. Real data:" << DetectorFunctions::axesToString(real_data)
                        << ", detector:" << DetectorFunctions::axesToString(*detector) << ".";
        throw Exceptions::RuntimeErrorException(message.str());
    }
}


size_t FitObject::getSizeOfData() const
{
    return m_simulation->getInstrument().getDetector()->numberOfSimulationElements();
}

//! Runs simulation and put results (the real and simulated intensities) into
//! external vector. Masked channels will be excluded from the vector.
void FitObject::prepareFitElements(std::vector<FitElement> &fit_elements, double weight,
                                   IIntensityNormalizer* normalizer)
{
    m_simulation->runSimulation();
    m_simulation_data.reset(m_simulation->getDetectorIntensity());

    if(normalizer)
        normalizer->apply(*m_simulation_data.get());

    SimulationArea area(m_simulation->getInstrument().getDetector());
    for(SimulationArea::iterator it = area.begin(); it!=area.end(); ++it) {
        FitElement element(it.roiIndex(), (*m_simulation_data)[it.roiIndex()],
                (*m_real_data)[it.roiIndex()], weight);
        fit_elements.push_back(element);
    }

}

//!Creates ChiSquared map from external vector.
// It is used from Python in one example, didn't find nicer way/place to create such map.
const OutputData<double>* FitObject::getChiSquaredMap(
    std::vector<FitElement>::const_iterator first,
    std::vector<FitElement>::const_iterator last) const
{
    m_chi2_data->setAllTo(0.0);
//    SimulationArea area(m_simulation->getInstrument().getDetector());
//    for(SimulationArea::iterator it = area.begin(); it!=area.end(); ++it) {
//        (*m_chi2_data)[it->rotIndex()] = it->getSquaredDifference();
//    }

    for(std::vector<FitElement>::const_iterator it=first; it!=last; ++it)
        (*m_chi2_data)[it->getIndex()] = it->getSquaredDifference();
    return m_chi2_data.get();
}
