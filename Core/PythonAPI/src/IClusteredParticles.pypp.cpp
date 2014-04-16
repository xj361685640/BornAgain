// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonCoreAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "__call_policies.pypp.hpp"
#include "__convenience.pypp.hpp"
#include "PythonCoreList.h"
#include "IClusteredParticles.pypp.h"

namespace bp = boost::python;

struct IClusteredParticles_wrapper : IClusteredParticles, bp::wrapper< IClusteredParticles > {

    IClusteredParticles_wrapper( )
    : IClusteredParticles( )
      , bp::wrapper< IClusteredParticles >(){
        // null constructor
    
    }

    virtual void accept( ::ISampleVisitor * visitor ) const {
        bp::override func_accept = this->get_override( "accept" );
        func_accept( boost::python::ptr(visitor) );
    }

    virtual void applyTransformation( ::Geometry::Transform3D const & transform ) {
        if( bp::override func_applyTransformation = this->get_override( "applyTransformation" ) )
            func_applyTransformation( boost::ref(transform) );
        else{
            this->IClusteredParticles::applyTransformation( boost::ref(transform) );
        }
    }
    
    void default_applyTransformation( ::Geometry::Transform3D const & transform ) {
        IClusteredParticles::applyTransformation( boost::ref(transform) );
    }

    virtual ::IClusteredParticles * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual ::IClusteredParticles * cloneInvertB(  ) const {
        bp::override func_cloneInvertB = this->get_override( "cloneInvertB" );
        return func_cloneInvertB(  );
    }

    virtual ::IFormFactor * createTotalFormFactor( ::IFormFactor const & meso_crystal_form_factor, ::IMaterial const & p_ambient_material, ::complex_t wavevector_scattering_factor ) const  {
        if( bp::override func_createTotalFormFactor = this->get_override( "createTotalFormFactor" ) )
            return func_createTotalFormFactor( boost::ref(meso_crystal_form_factor), boost::ref(p_ambient_material), wavevector_scattering_factor );
        else{
            return this->IClusteredParticles::createTotalFormFactor( boost::ref(meso_crystal_form_factor), boost::ref(p_ambient_material), wavevector_scattering_factor );
        }
    }
    
    ::IFormFactor * default_createTotalFormFactor( ::IFormFactor const & meso_crystal_form_factor, ::IMaterial const & p_ambient_material, ::complex_t wavevector_scattering_factor ) const  {
        return IClusteredParticles::createTotalFormFactor( boost::ref(meso_crystal_form_factor), boost::ref(p_ambient_material), wavevector_scattering_factor );
    }

    virtual ::Geometry::Transform3D const * getTransform(  ) const  {
        if( bp::override func_getTransform = this->get_override( "getTransform" ) )
            return func_getTransform(  );
        else{
            return this->IClusteredParticles::getTransform(  );
        }
    }
    
    ::Geometry::Transform3D const * default_getTransform(  ) const  {
        return IClusteredParticles::getTransform( );
    }

    virtual void setAmbientMaterial( ::IMaterial const * p_ambient_material ){
        bp::override func_setAmbientMaterial = this->get_override( "setAmbientMaterial" );
        func_setAmbientMaterial( boost::python::ptr(p_ambient_material) );
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

    virtual void registerParameter( ::std::string const & name, double * parpointer ) {
        namespace bpl = boost::python;
        if( bpl::override func_registerParameter = this->get_override( "registerParameter" ) ){
            bpl::object py_result = bpl::call<bpl::object>( func_registerParameter.ptr(), name, parpointer );
        }
        else{
            IParameterized::registerParameter( name, parpointer );
        }
    }
    
    static void default_registerParameter( ::IParameterized & inst, ::std::string const & name, long unsigned int parpointer ){
        if( dynamic_cast< IClusteredParticles_wrapper * >( boost::addressof( inst ) ) ){
            inst.::IParameterized::registerParameter(name, reinterpret_cast< double * >( parpointer ));
        }
        else{
            inst.registerParameter(name, reinterpret_cast< double * >( parpointer ));
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

};

void register_IClusteredParticles_class(){

    { //::IClusteredParticles
        typedef bp::class_< IClusteredParticles_wrapper, bp::bases< ICompositeSample >, boost::noncopyable > IClusteredParticles_exposer_t;
        IClusteredParticles_exposer_t IClusteredParticles_exposer = IClusteredParticles_exposer_t( "IClusteredParticles", bp::init< >() );
        bp::scope IClusteredParticles_scope( IClusteredParticles_exposer );
        { //::IClusteredParticles::accept
        
            typedef void ( ::IClusteredParticles::*accept_function_type )( ::ISampleVisitor * ) const;
            
            IClusteredParticles_exposer.def( 
                "accept"
                , bp::pure_virtual( accept_function_type(&::IClusteredParticles::accept) )
                , ( bp::arg("visitor") ) );
        
        }
        { //::IClusteredParticles::applyTransformation
        
            typedef void ( ::IClusteredParticles::*applyTransformation_function_type )( ::Geometry::Transform3D const & ) ;
            typedef void ( IClusteredParticles_wrapper::*default_applyTransformation_function_type )( ::Geometry::Transform3D const & ) ;
            
            IClusteredParticles_exposer.def( 
                "applyTransformation"
                , applyTransformation_function_type(&::IClusteredParticles::applyTransformation)
                , default_applyTransformation_function_type(&IClusteredParticles_wrapper::default_applyTransformation)
                , ( bp::arg("transform") ) );
        
        }
        { //::IClusteredParticles::clone
        
            typedef ::IClusteredParticles * ( ::IClusteredParticles::*clone_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IClusteredParticles::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IClusteredParticles::cloneInvertB
        
            typedef ::IClusteredParticles * ( ::IClusteredParticles::*cloneInvertB_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "cloneInvertB"
                , bp::pure_virtual( cloneInvertB_function_type(&::IClusteredParticles::cloneInvertB) )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IClusteredParticles::createTotalFormFactor
        
            typedef ::IFormFactor * ( ::IClusteredParticles::*createTotalFormFactor_function_type )( ::IFormFactor const &,::IMaterial const &,::complex_t ) const;
            typedef ::IFormFactor * ( IClusteredParticles_wrapper::*default_createTotalFormFactor_function_type )( ::IFormFactor const &,::IMaterial const &,::complex_t ) const;
            
            IClusteredParticles_exposer.def( 
                "createTotalFormFactor"
                , createTotalFormFactor_function_type(&::IClusteredParticles::createTotalFormFactor)
                , default_createTotalFormFactor_function_type(&IClusteredParticles_wrapper::default_createTotalFormFactor)
                , ( bp::arg("meso_crystal_form_factor"), bp::arg("p_ambient_material"), bp::arg("wavevector_scattering_factor") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IClusteredParticles::getTransform
        
            typedef ::Geometry::Transform3D const * ( ::IClusteredParticles::*getTransform_function_type )(  ) const;
            typedef ::Geometry::Transform3D const * ( IClusteredParticles_wrapper::*default_getTransform_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "getTransform"
                , getTransform_function_type(&::IClusteredParticles::getTransform)
                , default_getTransform_function_type(&IClusteredParticles_wrapper::default_getTransform)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IClusteredParticles::setAmbientMaterial
        
            typedef void ( ::IClusteredParticles::*setAmbientMaterial_function_type )( ::IMaterial const * ) ;
            
            IClusteredParticles_exposer.def( 
                "setAmbientMaterial"
                , bp::pure_virtual( setAmbientMaterial_function_type(&::IClusteredParticles::setAmbientMaterial) )
                , ( bp::arg("p_ambient_material") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( IClusteredParticles_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            IClusteredParticles_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IClusteredParticles_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( IClusteredParticles_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            IClusteredParticles_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IClusteredParticles_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type )(  ) const;
            typedef bool ( IClusteredParticles_wrapper::*default_containsMagneticMaterial_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&IClusteredParticles_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( IClusteredParticles_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IClusteredParticles_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ICompositeSample::*getCompositeSample_function_type )(  ) ;
            typedef ::ICompositeSample * ( IClusteredParticles_wrapper::*default_getCompositeSample_function_type )(  ) ;
            
            IClusteredParticles_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&IClusteredParticles_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ICompositeSample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ICompositeSample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( IClusteredParticles_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ICompositeSample::getCompositeSample)
                , default_getCompositeSample_function_type(&IClusteredParticles_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( IClusteredParticles_wrapper::*default_printParameters_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IClusteredParticles_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type )(  ) ;
            typedef void ( IClusteredParticles_wrapper::*default_printSampleTree_function_type )(  ) ;
            
            IClusteredParticles_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&IClusteredParticles_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            IClusteredParticles_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &IClusteredParticles_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( IClusteredParticles_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            IClusteredParticles_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IClusteredParticles_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( IClusteredParticles_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            IClusteredParticles_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IClusteredParticles_wrapper::default_setParametersAreChanged) );
        
        }
        { //::ICompositeSample::size
        
            typedef ::std::size_t ( ::ICompositeSample::*size_function_type )(  ) const;
            typedef ::std::size_t ( IClusteredParticles_wrapper::*default_size_function_type )(  ) const;
            
            IClusteredParticles_exposer.def( 
                "size"
                , size_function_type(&::ICompositeSample::size)
                , default_size_function_type(&IClusteredParticles_wrapper::default_size) );
        
        }
    }

}
