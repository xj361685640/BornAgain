#include "IsGISAXS10.h"
#include "FormFactorCylinder.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "MaterialManager.h"
#include "MultiLayer.h"
#include "OutputDataIOFactory.h"
#include "ParticleDecoration.h"
#include "Simulation.h"
#include "Units.h"
#include "Utils.h"
#include "MathFunctions.h"
#include "SimulationRegistry.h"
#include "OutputDataFunctions.h"

#include <iostream>
#include <cmath>


FunctionalTests::IsGISAXS10::IsGISAXS10()
    : m_name("IsGISAXS10")
    , m_description("Cylinders with interference on top of substrate")
    , m_result(0)
    , m_reference(0)
{ }


void FunctionalTests::IsGISAXS10::run(const std::string &path_to_data)
{
    SimulationRegistry sim_registry;
    Simulation *simulation = sim_registry.createSimulation("isgisaxs10");

    // loading reference data
    std::string filename = path_to_data + "isgisaxs10_reference.ima.gz";
    m_reference = OutputDataIOFactory::readIntensityData(filename);

    simulation->runSimulation();

    m_result = simulation->getIntensityData();
    delete simulation;
}


int FunctionalTests::IsGISAXS10::analyseResults()
{
    const double threshold(2e-10);

    // calculating average relative difference
    double diff = OutputDataFunctions::GetDifference(*m_result,*m_reference);

    bool status_ok(true);
    if( diff > threshold ) status_ok=false;

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
    FunctionalTests::IsGISAXS10 test;
    test.run(GetPathToData(argc, argv));
    return test.analyseResults();
}
#endif

