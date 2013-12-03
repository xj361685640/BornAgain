#include "IsGISAXS06L2.h"
#include "MultiLayer.h"
#include "ParticleDecoration.h"
#include "FormFactorCylinder.h"
#include "Simulation.h"
#include "Units.h"
#include "MaterialManager.h"
#include "InterferenceFunction2DLattice.h"
#include "PositionParticleInfo.h"
#include "OutputDataIOFactory.h"
#include "StochasticSampledParameter.h"
#include "StochasticDoubleGate.h"
#include "Utils.h"
#include "SampleBuilderFactory.h"
#include "IsGISAXS06Builder.h"
#include "MathFunctions.h"
#include "SimulationRegistry.h"

#include <iostream>
#include <cmath>

FunctionalTests::IsGISAXS06L2::IsGISAXS06L2()
    : m_name("IsGISAXS06L2")
    , m_description("2D lattice centered")
    , m_result(0)
	, m_reference(0)
{ }


void FunctionalTests::IsGISAXS06L2::run(const std::string &path_to_data)
{

    SimulationRegistry sim_registry;
    Simulation *simulation = sim_registry.createSimulation("isgisaxs06_lattice2");

    // loading reference data
    std::string filename = path_to_data + "isgisaxs06_reference_centered.ima.gz";
    m_reference = OutputDataIOFactory::readIntensityData(filename);

    simulation->runSimulation();

    m_result = simulation->getIntensityData();
    delete simulation;
}


int FunctionalTests::IsGISAXS06L2::analyseResults()
{
    const double threshold(2e-10);

    // Calculating average relative difference.
    *m_result -= *m_reference;
    *m_result /= *m_reference;

    double diff(0);
    for(OutputData<double>::const_iterator it =
            m_result->begin(); it!=m_result->end(); ++it) {
        diff+= std::fabs(*it);
    }
    diff /= m_result->getAllocatedSize();

    // Assess result.
	bool status_ok(true);
    if( diff > threshold || std::isnan(diff)) status_ok=false;

    std::cout << " diff " << diff << std::endl;
    std::cout << m_name << " " << m_description << " " <<
            (status_ok ? "[OK]" : "[FAILED]") << std::endl;
    return (status_ok ? 0 : 1);
}


#ifdef STANDALONE
std::string GetPathToData(int argc, char **argv)
{
    if(argc == 2) return argv[1];
    return Utils::FileSystem::GetPathToData("../../../ReferenceData/BornAgain/", argv[0]);
}

int main(int argc, char **argv)
{
    FunctionalTests::IsGISAXS06L2 test;
    test.run(GetPathToData(argc, argv));
    return test.analyseResults();
}
#endif

