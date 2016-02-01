// This file has been generated by Py++.

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Automatically generated boost::python code for BornAgain Python bindings
//! @brief     Automatically generated boost::python code for BornAgain Python bindings
//!
//! @homepage  http://bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Juelich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter)
GCC_DIAG_OFF(missing-field-initializers)
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter)
GCC_DIAG_ON(missing-field-initializers)
#include "PythonCoreList.h"
#include "InterferenceFunctionRadialParaCrystal.pypp.h"

namespace bp = boost::python;

struct InterferenceFunctionRadialParaCrystal_wrapper : InterferenceFunctionRadialParaCrystal, bp::wrapper< InterferenceFunctionRadialParaCrystal > {

    InterferenceFunctionRadialParaCrystal_wrapper(double peak_distance, double damping_length=0.0 )
    : InterferenceFunctionRadialParaCrystal( peak_distance, damping_length )
      , bp::wrapper< InterferenceFunctionRadialParaCrystal >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::InterferenceFunctionRadialParaCrystal * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->InterferenceFunctionRadialParaCrystal::clone(  );
        }
    }
    
    ::InterferenceFunctionRadialParaCrystal * default_clone(  ) const  {
        return InterferenceFunctionRadialParaCrystal::clone( );
    }

    virtual double evaluate( ::kvector_t const & q ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(q) );
        else{
            return this->InterferenceFunctionRadialParaCrystal::evaluate( boost::ref(q) );
        }
    }
    
    double default_evaluate( ::kvector_t const & q ) const  {
        return InterferenceFunctionRadialParaCrystal::evaluate( boost::ref(q) );
    }

    virtual double getKappa(  ) const  {
        if( bp::override func_getKappa = this->get_override( "getKappa" ) )
            return func_getKappa(  );
        else{
            return this->InterferenceFunctionRadialParaCrystal::getKappa(  );
        }
    }
    
    double default_getKappa(  ) const  {
        return InterferenceFunctionRadialParaCrystal::getKappa( );
    }

    virtual ::ISample * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ISample::cloneInvertB(  );
        }
    }
    
    ::ISample * default_cloneInvertB(  ) const  {
        return ISample::cloneInvertB( );
    }

    virtual bool containsMagneticMaterial(  ) const  {
        if( bp::override func_containsMagneticMaterial = this->get_override( "containsMagneticMaterial" ) )
            return func_containsMagneticMaterial(  );
        else{
            return this->ISample::containsMagneticMaterial(  );
        }
    }
    
    bool default_containsMagneticMaterial(  ) const  {
        return ISample::containsMagneticMaterial( );
    }

    virtual ::std::vector< const ISample* > getChildren(  ) const  {
        if( bp::override func_getChildren = this->get_override( "getChildren" ) )
            return func_getChildren(  );
        else{
            return this->ISample::getChildren(  );
        }
    }
    
    ::std::vector< const ISample* > default_getChildren(  ) const  {
        return ISample::getChildren( );
    }

    virtual double getParticleDensity(  ) const  {
        if( bp::override func_getParticleDensity = this->get_override( "getParticleDensity" ) )
            return func_getParticleDensity(  );
        else{
            return this->IInterferenceFunction::getParticleDensity(  );
        }
    }
    
    double default_getParticleDensity(  ) const  {
        return IInterferenceFunction::getParticleDensity( );
    }

    virtual void printSampleTree(  ) {
        if( bp::override func_printSampleTree = this->get_override( "printSampleTree" ) )
            func_printSampleTree(  );
        else{
            this->ISample::printSampleTree(  );
        }
    }
    
    void default_printSampleTree(  ) {
        ISample::printSampleTree( );
    }

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ISample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ISample::size( );
    }

    virtual void transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        if( bp::override func_transferToCPP = this->get_override( "transferToCPP" ) )
            func_transferToCPP(  );
        else{
            this->ICloneable::transferToCPP(  );
        }
    }
    
    void default_transferToCPP(  ) {
        
        if( !this->m_pyobj) {
            this->m_pyobj = boost::python::detail::wrapper_base_::get_owner(*this);
            Py_INCREF(this->m_pyobj);
        }
        
        ICloneable::transferToCPP( );
    }

    PyObject* m_pyobj;

};

void register_InterferenceFunctionRadialParaCrystal_class(){

    { //::InterferenceFunctionRadialParaCrystal
        typedef bp::class_< InterferenceFunctionRadialParaCrystal_wrapper, bp::bases< IInterferenceFunction >, std::auto_ptr< InterferenceFunctionRadialParaCrystal_wrapper >, boost::noncopyable > InterferenceFunctionRadialParaCrystal_exposer_t;
        InterferenceFunctionRadialParaCrystal_exposer_t InterferenceFunctionRadialParaCrystal_exposer = InterferenceFunctionRadialParaCrystal_exposer_t( "InterferenceFunctionRadialParaCrystal", bp::init< double, bp::optional< double > >(( bp::arg("peak_distance"), bp::arg("damping_length")=0.0 ), "constructor of radial paracrystal interference function @param peak_distance  The distance to the first neighbor peak.\n\n:Parameters:\n  - 'peak_distance' - The distance to the first neighbor peak.\n  - 'width' - Width parameter in the pair correlation function.\n  - 'm_corr_length' - Correlation length of paracrystal.\n") );
        bp::scope InterferenceFunctionRadialParaCrystal_scope( InterferenceFunctionRadialParaCrystal_exposer );
        { //::InterferenceFunctionRadialParaCrystal::FTPDF
        
            typedef ::complex_t ( ::InterferenceFunctionRadialParaCrystal::*FTPDF_function_type)( double ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "FTPDF"
                , FTPDF_function_type( &::InterferenceFunctionRadialParaCrystal::FTPDF )
                , ( bp::arg("qpar") ) );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::clone
        
            typedef ::InterferenceFunctionRadialParaCrystal * ( ::InterferenceFunctionRadialParaCrystal::*clone_function_type)(  ) const;
            typedef ::InterferenceFunctionRadialParaCrystal * ( InterferenceFunctionRadialParaCrystal_wrapper::*default_clone_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "clone"
                , clone_function_type(&::InterferenceFunctionRadialParaCrystal::clone)
                , default_clone_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::evaluate
        
            typedef double ( ::InterferenceFunctionRadialParaCrystal::*evaluate_function_type)( ::kvector_t const & ) const;
            typedef double ( InterferenceFunctionRadialParaCrystal_wrapper::*default_evaluate_function_type)( ::kvector_t const & ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::InterferenceFunctionRadialParaCrystal::evaluate)
                , default_evaluate_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_evaluate)
                , ( bp::arg("q") ) );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::getDampingLength
        
            typedef double ( ::InterferenceFunctionRadialParaCrystal::*getDampingLength_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getDampingLength"
                , getDampingLength_function_type( &::InterferenceFunctionRadialParaCrystal::getDampingLength ) );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::getDomainSize
        
            typedef double ( ::InterferenceFunctionRadialParaCrystal::*getDomainSize_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getDomainSize"
                , getDomainSize_function_type( &::InterferenceFunctionRadialParaCrystal::getDomainSize )
                , "Gets size of coherence domain." );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::getKappa
        
            typedef double ( ::InterferenceFunctionRadialParaCrystal::*getKappa_function_type)(  ) const;
            typedef double ( InterferenceFunctionRadialParaCrystal_wrapper::*default_getKappa_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getKappa"
                , getKappa_function_type(&::InterferenceFunctionRadialParaCrystal::getKappa)
                , default_getKappa_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_getKappa) );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::getPeakDistance
        
            typedef double ( ::InterferenceFunctionRadialParaCrystal::*getPeakDistance_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getPeakDistance"
                , getPeakDistance_function_type( &::InterferenceFunctionRadialParaCrystal::getPeakDistance )
                , "Gets the Fourier transformed probability distribution of the nearest particle " );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::getProbabilityDistribution
        
            typedef ::IFTDistribution1D const * ( ::InterferenceFunctionRadialParaCrystal::*getProbabilityDistribution_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getProbabilityDistribution"
                , getProbabilityDistribution_function_type( &::InterferenceFunctionRadialParaCrystal::getProbabilityDistribution )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Gets the Fourier transformed probability distribution of the nearest particle " );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::setDomainSize
        
            typedef void ( ::InterferenceFunctionRadialParaCrystal::*setDomainSize_function_type)( double ) ;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "setDomainSize"
                , setDomainSize_function_type( &::InterferenceFunctionRadialParaCrystal::setDomainSize )
                , ( bp::arg("size") )
                , "Sets size of coherence domain.\n\n:Parameters:\n  - 'size:' - size in lattice direction\n" );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::setKappa
        
            typedef void ( ::InterferenceFunctionRadialParaCrystal::*setKappa_function_type)( double ) ;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "setKappa"
                , setKappa_function_type( &::InterferenceFunctionRadialParaCrystal::setKappa )
                , ( bp::arg("kappa") )
                , "Sets size-spacing coupling parameter.\n\n:Parameters:\n  - 'kappa:' - size-spacing coupling parameter\n" );
        
        }
        { //::InterferenceFunctionRadialParaCrystal::setProbabilityDistribution
        
            typedef void ( ::InterferenceFunctionRadialParaCrystal::*setProbabilityDistribution_function_type)( ::IFTDistribution1D const & ) ;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "setProbabilityDistribution"
                , setProbabilityDistribution_function_type( &::InterferenceFunctionRadialParaCrystal::setProbabilityDistribution )
                , ( bp::arg("pdf") )
                , "Sets the Fourier transformed probability distribution of the nearest particle " );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type)(  ) const;
            typedef ::ISample * ( InterferenceFunctionRadialParaCrystal_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( InterferenceFunctionRadialParaCrystal_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::ISample::getChildren
        
            typedef ::std::vector< const ISample* > ( ::ISample::*getChildren_function_type)(  ) const;
            typedef ::std::vector< const ISample* > ( InterferenceFunctionRadialParaCrystal_wrapper::*default_getChildren_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getChildren"
                , getChildren_function_type(&::ISample::getChildren)
                , default_getChildren_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_getChildren) );
        
        }
        { //::IInterferenceFunction::getParticleDensity
        
            typedef double ( ::IInterferenceFunction::*getParticleDensity_function_type)(  ) const;
            typedef double ( InterferenceFunctionRadialParaCrystal_wrapper::*default_getParticleDensity_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "getParticleDensity"
                , getParticleDensity_function_type(&::IInterferenceFunction::getParticleDensity)
                , default_getParticleDensity_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_getParticleDensity) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( InterferenceFunctionRadialParaCrystal_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_printSampleTree) );
        
        }
        { //::ISample::size
        
            typedef ::std::size_t ( ::ISample::*size_function_type)(  ) const;
            typedef ::std::size_t ( InterferenceFunctionRadialParaCrystal_wrapper::*default_size_function_type)(  ) const;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "size"
                , size_function_type(&::ISample::size)
                , default_size_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( InterferenceFunctionRadialParaCrystal_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            InterferenceFunctionRadialParaCrystal_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&InterferenceFunctionRadialParaCrystal_wrapper::default_transferToCPP) );
        
        }
    }

}
