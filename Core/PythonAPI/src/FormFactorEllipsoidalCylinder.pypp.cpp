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
#include "FormFactorEllipsoidalCylinder.pypp.h"

namespace bp = boost::python;

struct FormFactorEllipsoidalCylinder_wrapper : FormFactorEllipsoidalCylinder, bp::wrapper< FormFactorEllipsoidalCylinder > {

    FormFactorEllipsoidalCylinder_wrapper(double radius_a, double radius_b, double height )
    : FormFactorEllipsoidalCylinder( radius_a, radius_b, height )
      , bp::wrapper< FormFactorEllipsoidalCylinder >(){
        // constructor
    
    }

    virtual ::FormFactorEllipsoidalCylinder * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorEllipsoidalCylinder::clone(  );
        }
    }
    
    ::FormFactorEllipsoidalCylinder * default_clone(  ) const  {
        return FormFactorEllipsoidalCylinder::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorEllipsoidalCylinder::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorEllipsoidalCylinder::evaluate_for_q( boost::ref(q) );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorEllipsoidalCylinder::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorEllipsoidalCylinder::getHeight( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorEllipsoidalCylinder::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorEllipsoidalCylinder::getNumberOfStochasticParameters( );
    }

    virtual double getRadiusB(  ) const  {
        if( bp::override func_getRadiusB = this->get_override( "getRadiusB" ) )
            return func_getRadiusB(  );
        else{
            return this->FormFactorEllipsoidalCylinder::getRadiusB(  );
        }
    }
    
    double default_getRadiusB(  ) const  {
        return FormFactorEllipsoidalCylinder::getRadiusB( );
    }

    virtual void setHeight( double height ) {
        if( bp::override func_setHeight = this->get_override( "setHeight" ) )
            func_setHeight( height );
        else{
            this->FormFactorEllipsoidalCylinder::setHeight( height );
        }
    }
    
    void default_setHeight( double height ) {
        FormFactorEllipsoidalCylinder::setHeight( height );
    }

    virtual void setRadiusA( double radius_a ) {
        if( bp::override func_setRadiusA = this->get_override( "setRadiusA" ) )
            func_setRadiusA( radius_a );
        else{
            this->FormFactorEllipsoidalCylinder::setRadiusA( radius_a );
        }
    }
    
    void default_setRadiusA( double radius_a ) {
        FormFactorEllipsoidalCylinder::setRadiusA( radius_a );
    }

    virtual void setRadiusB( double radius_b ) {
        if( bp::override func_setRadiusB = this->get_override( "setRadiusB" ) )
            func_setRadiusB( radius_b );
        else{
            this->FormFactorEllipsoidalCylinder::setRadiusB( radius_b );
        }
    }
    
    void default_setRadiusB( double radius_b ) {
        FormFactorEllipsoidalCylinder::setRadiusB( radius_b );
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

    virtual void createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        if( bp::override func_createDistributedFormFactors = this->get_override( "createDistributedFormFactors" ) )
            func_createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        else{
            this->IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
        }
    }
    
    void default_createDistributedFormFactors( ::std::vector< IFormFactor* > & form_factors, ::std::vector< double > & probabilities, ::std::size_t nbr_samples ) const  {
        IFormFactor::createDistributedFormFactors( boost::ref(form_factors), boost::ref(probabilities), nbr_samples );
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

    virtual ::complex_t evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        if( bp::override func_evaluate = this->get_override( "evaluate" ) )
            return func_evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        else{
            return this->IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
        }
    }
    
    ::complex_t default_evaluate( ::cvector_t const & k_i, ::Bin1DCVector const & k_f_bin, ::Bin1D const & alpha_f_bin ) const  {
        return IFormFactorBorn::evaluate( boost::ref(k_i), boost::ref(k_f_bin), boost::ref(alpha_f_bin) );
    }

    virtual ::ICompositeSample * getCompositeSample(  ) {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample * default_getCompositeSample(  ) {
        return ISample::getCompositeSample( );
    }

    virtual ::ICompositeSample const * getCompositeSample(  ) const  {
        if( bp::override func_getCompositeSample = this->get_override( "getCompositeSample" ) )
            return func_getCompositeSample(  );
        else{
            return this->ISample::getCompositeSample(  );
        }
    }
    
    ::ICompositeSample const * default_getCompositeSample(  ) const  {
        return ISample::getCompositeSample( );
    }

    virtual double getRadius(  ) const  {
        if( bp::override func_getRadius = this->get_override( "getRadius" ) )
            return func_getRadius(  );
        else{
            return this->IFormFactor::getRadius(  );
        }
    }
    
    double default_getRadius(  ) const  {
        return IFormFactor::getRadius( );
    }

    virtual double getVolume(  ) const  {
        if( bp::override func_getVolume = this->get_override( "getVolume" ) )
            return func_getVolume(  );
        else{
            return this->IFormFactorBorn::getVolume(  );
        }
    }
    
    double default_getVolume(  ) const  {
        return IFormFactorBorn::getVolume( );
    }

    virtual bool isDistributedFormFactor(  ) const  {
        if( bp::override func_isDistributedFormFactor = this->get_override( "isDistributedFormFactor" ) )
            return func_isDistributedFormFactor(  );
        else{
            return this->IFormFactor::isDistributedFormFactor(  );
        }
    }
    
    bool default_isDistributedFormFactor(  ) const  {
        return IFormFactor::isDistributedFormFactor( );
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
        if( dynamic_cast< FormFactorEllipsoidalCylinder_wrapper * >( boost::addressof( inst ) ) ){
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

};

void register_FormFactorEllipsoidalCylinder_class(){

    { //::FormFactorEllipsoidalCylinder
        typedef bp::class_< FormFactorEllipsoidalCylinder_wrapper, bp::bases< IFormFactorBorn >, boost::noncopyable > FormFactorEllipsoidalCylinder_exposer_t;
        FormFactorEllipsoidalCylinder_exposer_t FormFactorEllipsoidalCylinder_exposer = FormFactorEllipsoidalCylinder_exposer_t( "FormFactorEllipsoidalCylinder", bp::init< double, double, double >(( bp::arg("radius_a"), bp::arg("radius_b"), bp::arg("height") )) );
        bp::scope FormFactorEllipsoidalCylinder_scope( FormFactorEllipsoidalCylinder_exposer );
        { //::FormFactorEllipsoidalCylinder::clone
        
            typedef ::FormFactorEllipsoidalCylinder * ( ::FormFactorEllipsoidalCylinder::*clone_function_type )(  ) const;
            typedef ::FormFactorEllipsoidalCylinder * ( FormFactorEllipsoidalCylinder_wrapper::*default_clone_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorEllipsoidalCylinder::clone)
                , default_clone_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorEllipsoidalCylinder::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorEllipsoidalCylinder::*evaluate_for_q_function_type )( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorEllipsoidalCylinder_wrapper::*default_evaluate_for_q_function_type )( ::cvector_t const & ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorEllipsoidalCylinder::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorEllipsoidalCylinder::getHeight
        
            typedef double ( ::FormFactorEllipsoidalCylinder::*getHeight_function_type )(  ) const;
            typedef double ( FormFactorEllipsoidalCylinder_wrapper::*default_getHeight_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorEllipsoidalCylinder::getHeight)
                , default_getHeight_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getHeight) );
        
        }
        { //::FormFactorEllipsoidalCylinder::getNumberOfStochasticParameters
        
            typedef int ( ::FormFactorEllipsoidalCylinder::*getNumberOfStochasticParameters_function_type )(  ) const;
            typedef int ( FormFactorEllipsoidalCylinder_wrapper::*default_getNumberOfStochasticParameters_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::FormFactorEllipsoidalCylinder::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::FormFactorEllipsoidalCylinder::getRadiusA
        
            typedef double ( ::FormFactorEllipsoidalCylinder::*getRadiusA_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getRadiusA"
                , getRadiusA_function_type( &::FormFactorEllipsoidalCylinder::getRadiusA ) );
        
        }
        { //::FormFactorEllipsoidalCylinder::getRadiusB
        
            typedef double ( ::FormFactorEllipsoidalCylinder::*getRadiusB_function_type )(  ) const;
            typedef double ( FormFactorEllipsoidalCylinder_wrapper::*default_getRadiusB_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getRadiusB"
                , getRadiusB_function_type(&::FormFactorEllipsoidalCylinder::getRadiusB)
                , default_getRadiusB_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getRadiusB) );
        
        }
        { //::FormFactorEllipsoidalCylinder::setHeight
        
            typedef void ( ::FormFactorEllipsoidalCylinder::*setHeight_function_type )( double ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_setHeight_function_type )( double ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "setHeight"
                , setHeight_function_type(&::FormFactorEllipsoidalCylinder::setHeight)
                , default_setHeight_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_setHeight)
                , ( bp::arg("height") ) );
        
        }
        { //::FormFactorEllipsoidalCylinder::setRadiusA
        
            typedef void ( ::FormFactorEllipsoidalCylinder::*setRadiusA_function_type )( double ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_setRadiusA_function_type )( double ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "setRadiusA"
                , setRadiusA_function_type(&::FormFactorEllipsoidalCylinder::setRadiusA)
                , default_setRadiusA_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_setRadiusA)
                , ( bp::arg("radius_a") ) );
        
        }
        { //::FormFactorEllipsoidalCylinder::setRadiusB
        
            typedef void ( ::FormFactorEllipsoidalCylinder::*setRadiusB_function_type )( double ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_setRadiusB_function_type )( double ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "setRadiusB"
                , setRadiusB_function_type(&::FormFactorEllipsoidalCylinder::setRadiusB)
                , default_setRadiusB_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_setRadiusB)
                , ( bp::arg("radius_b") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( FormFactorEllipsoidalCylinder_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type )(  ) const;
            typedef ::ISample * ( FormFactorEllipsoidalCylinder_wrapper::*default_cloneInvertB_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type )(  ) const;
            typedef bool ( FormFactorEllipsoidalCylinder_wrapper::*default_containsMagneticMaterial_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IFormFactor::createDistributedFormFactors
        
            typedef void ( ::IFormFactor::*createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "createDistributedFormFactors"
                , createDistributedFormFactors_function_type(&::IFormFactor::createDistributedFormFactors)
                , default_createDistributedFormFactors_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_createDistributedFormFactors)
                , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( FormFactorEllipsoidalCylinder_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            typedef ::complex_t ( FormFactorEllipsoidalCylinder_wrapper::*default_evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_evaluate)
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_f_bin") ) );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ISample::*getCompositeSample_function_type )(  ) ;
            typedef ::ICompositeSample * ( FormFactorEllipsoidalCylinder_wrapper::*default_getCompositeSample_function_type )(  ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( FormFactorEllipsoidalCylinder_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type )(  ) const;
            typedef double ( FormFactorEllipsoidalCylinder_wrapper::*default_getRadius_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getRadius) );
        
        }
        { //::IFormFactorBorn::getVolume
        
            typedef double ( ::IFormFactorBorn::*getVolume_function_type )(  ) const;
            typedef double ( FormFactorEllipsoidalCylinder_wrapper::*default_getVolume_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactorBorn::getVolume)
                , default_getVolume_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_getVolume) );
        
        }
        { //::IFormFactor::isDistributedFormFactor
        
            typedef bool ( ::IFormFactor::*isDistributedFormFactor_function_type )(  ) const;
            typedef bool ( FormFactorEllipsoidalCylinder_wrapper::*default_isDistributedFormFactor_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "isDistributedFormFactor"
                , isDistributedFormFactor_function_type(&::IFormFactor::isDistributedFormFactor)
                , default_isDistributedFormFactor_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_isDistributedFormFactor) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_printParameters_function_type )(  ) const;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type )(  ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_printSampleTree_function_type )(  ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FormFactorEllipsoidalCylinder_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( FormFactorEllipsoidalCylinder_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( FormFactorEllipsoidalCylinder_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            FormFactorEllipsoidalCylinder_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FormFactorEllipsoidalCylinder_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
