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
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "ParticleLayout.pypp.h"

namespace bp = boost::python;

struct ParticleLayout_wrapper : ParticleLayout, bp::wrapper< ParticleLayout > {

    ParticleLayout_wrapper( )
    : ParticleLayout( )
      , bp::wrapper< ParticleLayout >(){
        // null constructor
    m_pyobj = 0;
    }

    ParticleLayout_wrapper(::IAbstractParticle const & particle, double abundance=1.0e+0 )
    : ParticleLayout( boost::ref(particle), abundance )
      , bp::wrapper< ParticleLayout >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::ParticleLayout * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->ParticleLayout::clone(  );
        }
    }
    
    ::ParticleLayout * default_clone(  ) const  {
        return ParticleLayout::clone( );
    }

    virtual ::ParticleLayout * cloneInvertB(  ) const  {
        if( bp::override func_cloneInvertB = this->get_override( "cloneInvertB" ) )
            return func_cloneInvertB(  );
        else{
            return this->ParticleLayout::cloneInvertB(  );
        }
    }
    
    ::ParticleLayout * default_cloneInvertB(  ) const  {
        return ParticleLayout::cloneInvertB( );
    }

    virtual double getAbundanceOfParticle( ::std::size_t index ) const  {
        if( bp::override func_getAbundanceOfParticle = this->get_override( "getAbundanceOfParticle" ) )
            return func_getAbundanceOfParticle( index );
        else{
            return this->ParticleLayout::getAbundanceOfParticle( index );
        }
    }
    
    double default_getAbundanceOfParticle( ::std::size_t index ) const  {
        return ParticleLayout::getAbundanceOfParticle( index );
    }

    virtual ::SafePointerVector< IInterferenceFunction > getInterferenceFunctions(  ) const  {
        if( bp::override func_getInterferenceFunctions = this->get_override( "getInterferenceFunctions" ) )
            return func_getInterferenceFunctions(  );
        else{
            return this->ParticleLayout::getInterferenceFunctions(  );
        }
    }
    
    ::SafePointerVector< IInterferenceFunction > default_getInterferenceFunctions(  ) const  {
        return ParticleLayout::getInterferenceFunctions( );
    }

    virtual ::std::size_t getNumberOfInterferenceFunctions(  ) const  {
        if( bp::override func_getNumberOfInterferenceFunctions = this->get_override( "getNumberOfInterferenceFunctions" ) )
            return func_getNumberOfInterferenceFunctions(  );
        else{
            return this->ParticleLayout::getNumberOfInterferenceFunctions(  );
        }
    }
    
    ::std::size_t default_getNumberOfInterferenceFunctions(  ) const  {
        return ParticleLayout::getNumberOfInterferenceFunctions( );
    }

    virtual ::std::size_t getNumberOfParticles(  ) const  {
        if( bp::override func_getNumberOfParticles = this->get_override( "getNumberOfParticles" ) )
            return func_getNumberOfParticles(  );
        else{
            return this->ParticleLayout::getNumberOfParticles(  );
        }
    }
    
    ::std::size_t default_getNumberOfParticles(  ) const  {
        return ParticleLayout::getNumberOfParticles( );
    }

    virtual ::IAbstractParticle const * getParticle( ::std::size_t index ) const  {
        if( bp::override func_getParticle = this->get_override( "getParticle" ) )
            return func_getParticle( index );
        else{
            return this->ParticleLayout::getParticle( index );
        }
    }
    
    ::IAbstractParticle const * default_getParticle( ::std::size_t index ) const  {
        return ParticleLayout::getParticle( index );
    }

    virtual ::std::vector< std::pair<const IParticle*, double> > getParticleInfos(  ) const  {
        if( bp::override func_getParticleInfos = this->get_override( "getParticleInfos" ) )
            return func_getParticleInfos(  );
        else{
            return this->ParticleLayout::getParticleInfos(  );
        }
    }
    
    ::std::vector< std::pair<const IParticle*, double> > default_getParticleInfos(  ) const  {
        return ParticleLayout::getParticleInfos( );
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

    virtual void clearParameterPool(  ) {
        if( bp::override func_clearParameterPool = this->get_override( "clearParameterPool" ) )
            func_clearParameterPool(  );
        else{
            this->IParameterized::clearParameterPool(  );
        }
    }
    
    void default_clearParameterPool(  ) {
        IParameterized::clearParameterPool( );
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

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ICompositeSample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ICompositeSample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ICompositeSample::getCompositeSample( );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer, limits );
        }
        else{
            IParameterized::registerParameter( name, parpointer, boost::ref(limits) );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer, ::AttLimits const & limits=AttLimits::limitless( ) ){
        if( dynamic_cast< ParticleLayout_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ), limits);
        }
    }

    virtual bool setParameterValue( ::std::string const & name, double value ) {
        if( bp::override func_setParameterValue = this->get_override( "setParameterValue" ) )
            return func_setParameterValue( name, value );
        else{
            return this->IParameterized::setParameterValue( name, value );
        }
    }
    
    bool default_setParameterValue( ::std::string const & name, double value ) {
        return IParameterized::setParameterValue( name, value );
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

    virtual ::std::size_t size(  ) const  {
        if( bp::override func_size = this->get_override( "size" ) )
            return func_size(  );
        else{
            return this->ICompositeSample::size(  );
        }
    }
    
    ::std::size_t default_size(  ) const  {
        return ICompositeSample::size( );
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

void register_ParticleLayout_class(){

    { //::ParticleLayout
        typedef bp::class_< ParticleLayout_wrapper, bp::bases< ILayout >, std::auto_ptr< ParticleLayout_wrapper >, boost::noncopyable > ParticleLayout_exposer_t;
        ParticleLayout_exposer_t ParticleLayout_exposer = ParticleLayout_exposer_t( "ParticleLayout", "Decorator class that adds particles to ISample object.", bp::init< >() );
        bp::scope ParticleLayout_scope( ParticleLayout_exposer );
        ParticleLayout_exposer.def( bp::init< IAbstractParticle const &, bp::optional< double > >(( bp::arg("particle"), bp::arg("abundance")=1.0e+0 )) );
        { //::ParticleLayout::addInterferenceFunction
        
            typedef void ( ::ParticleLayout::*addInterferenceFunction_function_type)( ::IInterferenceFunction const & ) ;
            
            ParticleLayout_exposer.def( 
                "addInterferenceFunction"
                , addInterferenceFunction_function_type( &::ParticleLayout::addInterferenceFunction )
                , ( bp::arg("interference_function") )
                , "Adds interference function." );
        
        }
        { //::ParticleLayout::addParticle
        
            typedef void ( ::ParticleLayout::*addParticle_function_type)( ::IParticle const &,::IRotation const &,double ) ;
            
            ParticleLayout_exposer.def( 
                "addParticle"
                , addParticle_function_type( &::ParticleLayout::addParticle )
                , ( bp::arg("particle"), bp::arg("rotation"), bp::arg("abundance")=1.0e+0 )
                , "Adds generic particle." );
        
        }
        { //::ParticleLayout::addParticle
        
            typedef void ( ::ParticleLayout::*addParticle_function_type)( ::IAbstractParticle const &,double ) ;
            
            ParticleLayout_exposer.def( 
                "addParticle"
                , addParticle_function_type( &::ParticleLayout::addParticle )
                , ( bp::arg("particle"), bp::arg("abundance")=1.0e+0 )
                , "Adds particle without rotation." );
        
        }
        { //::ParticleLayout::clone
        
            typedef ::ParticleLayout * ( ::ParticleLayout::*clone_function_type)(  ) const;
            typedef ::ParticleLayout * ( ParticleLayout_wrapper::*default_clone_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "clone"
                , clone_function_type(&::ParticleLayout::clone)
                , default_clone_function_type(&ParticleLayout_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ParticleLayout::cloneInvertB
        
            typedef ::ParticleLayout * ( ::ParticleLayout::*cloneInvertB_function_type)(  ) const;
            typedef ::ParticleLayout * ( ParticleLayout_wrapper::*default_cloneInvertB_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ParticleLayout::cloneInvertB)
                , default_cloneInvertB_function_type(&ParticleLayout_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ParticleLayout::getAbundanceOfParticle
        
            typedef double ( ::ParticleLayout::*getAbundanceOfParticle_function_type)( ::std::size_t ) const;
            typedef double ( ParticleLayout_wrapper::*default_getAbundanceOfParticle_function_type)( ::std::size_t ) const;
            
            ParticleLayout_exposer.def( 
                "getAbundanceOfParticle"
                , getAbundanceOfParticle_function_type(&::ParticleLayout::getAbundanceOfParticle)
                , default_getAbundanceOfParticle_function_type(&ParticleLayout_wrapper::default_getAbundanceOfParticle)
                , ( bp::arg("index") ) );
        
        }
        { //::ParticleLayout::getInterferenceFunction
        
            typedef ::IInterferenceFunction const * ( ::ParticleLayout::*getInterferenceFunction_function_type)( ::std::size_t ) const;
            
            ParticleLayout_exposer.def( 
                "getInterferenceFunction"
                , getInterferenceFunction_function_type( &::ParticleLayout::getInterferenceFunction )
                , ( bp::arg("index") )
                , bp::return_value_policy< bp::reference_existing_object >()
                , "Returns interference function with index." );
        
        }
        { //::ParticleLayout::getInterferenceFunctions
        
            typedef ::SafePointerVector< IInterferenceFunction > ( ::ParticleLayout::*getInterferenceFunctions_function_type)(  ) const;
            typedef ::SafePointerVector< IInterferenceFunction > ( ParticleLayout_wrapper::*default_getInterferenceFunctions_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "getInterferenceFunctions"
                , getInterferenceFunctions_function_type(&::ParticleLayout::getInterferenceFunctions)
                , default_getInterferenceFunctions_function_type(&ParticleLayout_wrapper::default_getInterferenceFunctions) );
        
        }
        { //::ParticleLayout::getNumberOfInterferenceFunctions
        
            typedef ::std::size_t ( ::ParticleLayout::*getNumberOfInterferenceFunctions_function_type)(  ) const;
            typedef ::std::size_t ( ParticleLayout_wrapper::*default_getNumberOfInterferenceFunctions_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "getNumberOfInterferenceFunctions"
                , getNumberOfInterferenceFunctions_function_type(&::ParticleLayout::getNumberOfInterferenceFunctions)
                , default_getNumberOfInterferenceFunctions_function_type(&ParticleLayout_wrapper::default_getNumberOfInterferenceFunctions) );
        
        }
        { //::ParticleLayout::getNumberOfParticles
        
            typedef ::std::size_t ( ::ParticleLayout::*getNumberOfParticles_function_type)(  ) const;
            typedef ::std::size_t ( ParticleLayout_wrapper::*default_getNumberOfParticles_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "getNumberOfParticles"
                , getNumberOfParticles_function_type(&::ParticleLayout::getNumberOfParticles)
                , default_getNumberOfParticles_function_type(&ParticleLayout_wrapper::default_getNumberOfParticles) );
        
        }
        { //::ParticleLayout::getParticle
        
            typedef ::IAbstractParticle const * ( ::ParticleLayout::*getParticle_function_type)( ::std::size_t ) const;
            typedef ::IAbstractParticle const * ( ParticleLayout_wrapper::*default_getParticle_function_type)( ::std::size_t ) const;
            
            ParticleLayout_exposer.def( 
                "getParticle"
                , getParticle_function_type(&::ParticleLayout::getParticle)
                , default_getParticle_function_type(&ParticleLayout_wrapper::default_getParticle)
                , ( bp::arg("index") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ParticleLayout::getParticleInfos
        
            typedef ::std::vector< std::pair<const IParticle*, double> > ( ::ParticleLayout::*getParticleInfos_function_type)(  ) const;
            typedef ::std::vector< std::pair<const IParticle*, double> > ( ParticleLayout_wrapper::*default_getParticleInfos_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "getParticleInfos"
                , getParticleInfos_function_type(&::ParticleLayout::getParticleInfos)
                , default_getParticleInfos_function_type(&ParticleLayout_wrapper::default_getParticleInfos) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type)(  ) ;
            typedef bool ( ParticleLayout_wrapper::*default_areParametersChanged_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&ParticleLayout_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type)(  ) ;
            typedef void ( ParticleLayout_wrapper::*default_clearParameterPool_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&ParticleLayout_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type)(  ) const;
            typedef bool ( ParticleLayout_wrapper::*default_containsMagneticMaterial_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&ParticleLayout_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type)(  ) const;
            typedef ::ParameterPool * ( ParticleLayout_wrapper::*default_createParameterTree_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&ParticleLayout_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) ;
            typedef ::ICompositeSample * ( ParticleLayout_wrapper::*default_getCompositeSample_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&ParticleLayout_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type)(  ) const;
            typedef ::ICompositeSample const * ( ParticleLayout_wrapper::*default_getCompositeSample_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&ParticleLayout_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type)(  ) const;
            typedef void ( ParticleLayout_wrapper::*default_printParameters_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&ParticleLayout_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type)(  ) ;
            typedef void ( ParticleLayout_wrapper::*default_printSampleTree_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&ParticleLayout_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int,::AttLimits const & );
            
            ParticleLayout_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &ParticleLayout_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer"), bp::arg("limits")=AttLimits::limitless( ) )
                , "main method to register data address in the pool." );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type)( ::std::string const &,double ) ;
            typedef bool ( ParticleLayout_wrapper::*default_setParameterValue_function_type)( ::std::string const &,double ) ;
            
            ParticleLayout_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&ParticleLayout_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type)(  ) ;
            typedef void ( ParticleLayout_wrapper::*default_setParametersAreChanged_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&ParticleLayout_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type)(  ) const;
            typedef ::std::size_t ( ParticleLayout_wrapper::*default_size_function_type)(  ) const;
            
            ParticleLayout_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&ParticleLayout_wrapper::default_size) );
        
        }
        { //::ICloneable::transferToCPP
        
            typedef void ( ::ICloneable::*transferToCPP_function_type)(  ) ;
            typedef void ( ParticleLayout_wrapper::*default_transferToCPP_function_type)(  ) ;
            
            ParticleLayout_exposer.def( 
                "transferToCPP"
                , transferToCPP_function_type(&::ICloneable::transferToCPP)
                , default_transferToCPP_function_type(&ParticleLayout_wrapper::default_transferToCPP) );
        
        }
    }

}
