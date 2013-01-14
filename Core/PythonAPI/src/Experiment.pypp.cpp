// This file has been generated by Py++.

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
#include "boost/python/suite/indexing/vector_indexing_suite.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "BasicVector3D.h"
#include "Experiment.h"
#include "FormFactorCrystal.h"
#include "FormFactorCylinder.h"
#include "FormFactorDecoratorDebyeWaller.h"
#include "FormFactorFullSphere.h"
#include "FormFactorGauss.h"
#include "FormFactorLorentz.h"
#include "FormFactorPrism3.h"
#include "FormFactorPyramid.h"
#include "FormFactorSphereGaussianRadius.h"
#include "GISASExperiment.h"
#include "HomogeneousMaterial.h"
#include "ICloneable.h"
#include "IClusteredParticles.h"
#include "ICompositeSample.h"
#include "IDecoration.h"
#include "IFormFactor.h"
#include "IFormFactorBorn.h"
#include "IFormFactorDecorator.h"
#include "IInterferenceFunction.h"
#include "InterferenceFunctionNone.h"
#include "InterferenceFunction1DParaCrystal.h"
#include "IMaterial.h"
#include "IParameterized.h"
#include "ISample.h"
#include "ISampleBuilder.h"
#include "ISelectionRule.h"
#include "ISingleton.h"
#include "Lattice.h"
#include "LatticeBasis.h"
#include "Layer.h"
#include "LayerDecorator.h"
#include "LayerRoughness.h"
#include "MaterialManager.h"
#include "MesoCrystal.h"
#include "MultiLayer.h"
#include "Particle.h"
#include "Crystal.h"
#include "ParticleDecoration.h"
#include "OpticalFresnel.h"
#include "ParameterPool.h"
#include "ParticleInfo.h"
#include "DiffuseParticleInfo.h"
#include "PythonOutputData.h"
#include "PythonPlusplusHelper.h"
#include "RealParameterWrapper.h"
#include "Transform3D.h"
#include "Units.h"
#include "Types.h"
#include "Experiment.pypp.h"

namespace bp = boost::python;

struct Experiment_wrapper : Experiment, bp::wrapper< Experiment > {

    Experiment_wrapper( )
    : Experiment( )
      , bp::wrapper< Experiment >(){
        // null constructor
    
    }

    virtual void normalize(  ) {
        if( bp::override func_normalize = this->get_override( "normalize" ) )
            func_normalize(  );
        else{
            this->Experiment::normalize(  );
        }
    }
    
    void default_normalize(  ) {
        Experiment::normalize( );
    }

    virtual void runSimulation(  ) {
        if( bp::override func_runSimulation = this->get_override( "runSimulation" ) )
            func_runSimulation(  );
        else{
            this->Experiment::runSimulation(  );
        }
    }
    
    void default_runSimulation(  ) {
        Experiment::runSimulation( );
    }

    virtual bool areParametersChanged(  ) {
        if( bp::override func_areParametersChanged = this->get_override( "areParametersChanged" ) )
            return func_areParametersChanged(  );
        else{
            return this->IParameterized::areParametersChanged(  );
        }
    }
    
    bool default_areParametersChanged(  ) {
        return IParameterized::areParametersChanged( );
    }

    virtual ::ParameterPool * createParameterTree(  ) const  {
        if( bp::override func_createParameterTree = this->get_override( "createParameterTree" ) )
            return func_createParameterTree(  );
        else{
            return this->IParameterized::createParameterTree(  );
        }
    }
    
    ::ParameterPool * default_createParameterTree(  ) const  {
        return IParameterized::createParameterTree( );
    }

    virtual void printParameters(  ) const  {
        if( bp::override func_printParameters = this->get_override( "printParameters" ) )
            func_printParameters(  );
        else{
            this->IParameterized::printParameters(  );
        }
    }
    
    void default_printParameters(  ) const  {
        IParameterized::printParameters( );
    }

    virtual void setParametersAreChanged(  ) {
        if( bp::override func_setParametersAreChanged = this->get_override( "setParametersAreChanged" ) )
            func_setParametersAreChanged(  );
        else{
            this->IParameterized::setParametersAreChanged(  );
        }
    }
    
    void default_setParametersAreChanged(  ) {
        IParameterized::setParametersAreChanged( );
    }

};

void register_Experiment_class(){

    bp::class_< Experiment_wrapper, bp::bases< IParameterized, ICloneable >, boost::noncopyable >( "Experiment", bp::init< >() )    
        .def( 
            "normalize"
            , (void ( ::Experiment::* )(  ) )(&::Experiment::normalize)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_normalize) )    
        .def( 
            "runSimulation"
            , (void ( ::Experiment::* )(  ) )(&::Experiment::runSimulation)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_runSimulation) )    
        .def( 
            "setBeamIntensity"
            , (void ( ::Experiment::* )( double ) )( &::Experiment::setBeamIntensity )
            , ( bp::arg("intensity") ) )    
        .def( 
            "setBeamParameters"
            , (void ( ::Experiment::* )( double,double,double ) )( &::Experiment::setBeamParameters )
            , ( bp::arg("lambda"), bp::arg("alpha_i"), bp::arg("phi_i") ) )    
        .def( 
            "setSample"
            , (void ( ::Experiment::* )( ::ISample const & ) )( &::Experiment::setSample )
            , ( bp::arg("p_sample") ) )    
        .def( 
            "setSampleBuilder"
            , (void ( ::Experiment::* )( ::ISampleBuilder const * ) )( &::Experiment::setSampleBuilder )
            , ( bp::arg("p_sample_builder") ) )    
        .def( 
            "areParametersChanged"
            , (bool ( ::IParameterized::* )(  ) )(&::IParameterized::areParametersChanged)
            , (bool ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_areParametersChanged) )    
        .def( 
            "createParameterTree"
            , (::ParameterPool * ( ::IParameterized::* )(  ) const)(&::IParameterized::createParameterTree)
            , (::ParameterPool * ( Experiment_wrapper::* )(  ) const)(&Experiment_wrapper::default_createParameterTree)
            , bp::return_value_policy< bp::manage_new_object >() )    
        .def( 
            "printParameters"
            , (void ( ::IParameterized::* )(  ) const)(&::IParameterized::printParameters)
            , (void ( Experiment_wrapper::* )(  ) const)(&Experiment_wrapper::default_printParameters) )    
        .def( 
            "setParametersAreChanged"
            , (void ( ::IParameterized::* )(  ) )(&::IParameterized::setParametersAreChanged)
            , (void ( Experiment_wrapper::* )(  ) )(&Experiment_wrapper::default_setParametersAreChanged) );

}