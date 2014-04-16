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
#include "FormFactorPrism3.pypp.h"

namespace bp = boost::python;

struct FormFactorPrism3_wrapper : FormFactorPrism3, bp::wrapper< FormFactorPrism3 > {

    FormFactorPrism3_wrapper(double length, double height )
    : FormFactorPrism3( length, height )
      , bp::wrapper< FormFactorPrism3 >(){
        // constructor
    
    }

    virtual ::FormFactorPrism3 * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FormFactorPrism3::clone(  );
        }
    }
    
    ::FormFactorPrism3 * default_clone(  ) const  {
        return FormFactorPrism3::clone( );
    }

    virtual ::complex_t evaluate_for_q( ::cvector_t const & q ) const  {
        if( bp::override func_evaluate_for_q = this->get_override( "evaluate_for_q" ) )
            return func_evaluate_for_q( boost::ref(q) );
        else{
            return this->FormFactorPrism3::evaluate_for_q( boost::ref(q) );
        }
    }
    
    ::complex_t default_evaluate_for_q( ::cvector_t const & q ) const  {
        return FormFactorPrism3::evaluate_for_q( boost::ref(q) );
    }

    virtual double getHeight(  ) const  {
        if( bp::override func_getHeight = this->get_override( "getHeight" ) )
            return func_getHeight(  );
        else{
            return this->FormFactorPrism3::getHeight(  );
        }
    }
    
    double default_getHeight(  ) const  {
        return FormFactorPrism3::getHeight( );
    }

    virtual double getLength(  ) const  {
        if( bp::override func_getLength = this->get_override( "getLength" ) )
            return func_getLength(  );
        else{
            return this->FormFactorPrism3::getLength(  );
        }
    }
    
    double default_getLength(  ) const  {
        return FormFactorPrism3::getLength( );
    }

    virtual int getNumberOfStochasticParameters(  ) const  {
        if( bp::override func_getNumberOfStochasticParameters = this->get_override( "getNumberOfStochasticParameters" ) )
            return func_getNumberOfStochasticParameters(  );
        else{
            return this->FormFactorPrism3::getNumberOfStochasticParameters(  );
        }
    }
    
    int default_getNumberOfStochasticParameters(  ) const  {
        return FormFactorPrism3::getNumberOfStochasticParameters( );
    }

    virtual void setHeight( double height ) {
        if( bp::override func_setHeight = this->get_override( "setHeight" ) )
            func_setHeight( height );
        else{
            this->FormFactorPrism3::setHeight( height );
        }
    }
    
    void default_setHeight( double height ) {
        FormFactorPrism3::setHeight( height );
    }

    virtual void setLength( double length ) {
        if( bp::override func_setLength = this->get_override( "setLength" ) )
            func_setLength( length );
        else{
            this->FormFactorPrism3::setLength( length );
        }
    }
    
    void default_setLength( double length ) {
        FormFactorPrism3::setLength( length );
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
        if( dynamic_cast< FormFactorPrism3_wrapper * >( boost::addressof( inst ) ) ){
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

void register_FormFactorPrism3_class(){

    { //::FormFactorPrism3
        typedef bp::class_< FormFactorPrism3_wrapper, bp::bases< IFormFactorBorn >, boost::noncopyable > FormFactorPrism3_exposer_t;
        FormFactorPrism3_exposer_t FormFactorPrism3_exposer = FormFactorPrism3_exposer_t( "FormFactorPrism3", bp::init< double, double >(( bp::arg("length"), bp::arg("height") )) );
        bp::scope FormFactorPrism3_scope( FormFactorPrism3_exposer );
        { //::FormFactorPrism3::clone
        
            typedef ::FormFactorPrism3 * ( ::FormFactorPrism3::*clone_function_type )(  ) const;
            typedef ::FormFactorPrism3 * ( FormFactorPrism3_wrapper::*default_clone_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "clone"
                , clone_function_type(&::FormFactorPrism3::clone)
                , default_clone_function_type(&FormFactorPrism3_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FormFactorPrism3::evaluate_for_q
        
            typedef ::complex_t ( ::FormFactorPrism3::*evaluate_for_q_function_type )( ::cvector_t const & ) const;
            typedef ::complex_t ( FormFactorPrism3_wrapper::*default_evaluate_for_q_function_type )( ::cvector_t const & ) const;
            
            FormFactorPrism3_exposer.def( 
                "evaluate_for_q"
                , evaluate_for_q_function_type(&::FormFactorPrism3::evaluate_for_q)
                , default_evaluate_for_q_function_type(&FormFactorPrism3_wrapper::default_evaluate_for_q)
                , ( bp::arg("q") ) );
        
        }
        { //::FormFactorPrism3::getHeight
        
            typedef double ( ::FormFactorPrism3::*getHeight_function_type )(  ) const;
            typedef double ( FormFactorPrism3_wrapper::*default_getHeight_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getHeight"
                , getHeight_function_type(&::FormFactorPrism3::getHeight)
                , default_getHeight_function_type(&FormFactorPrism3_wrapper::default_getHeight) );
        
        }
        { //::FormFactorPrism3::getLength
        
            typedef double ( ::FormFactorPrism3::*getLength_function_type )(  ) const;
            typedef double ( FormFactorPrism3_wrapper::*default_getLength_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getLength"
                , getLength_function_type(&::FormFactorPrism3::getLength)
                , default_getLength_function_type(&FormFactorPrism3_wrapper::default_getLength) );
        
        }
        { //::FormFactorPrism3::getNumberOfStochasticParameters
        
            typedef int ( ::FormFactorPrism3::*getNumberOfStochasticParameters_function_type )(  ) const;
            typedef int ( FormFactorPrism3_wrapper::*default_getNumberOfStochasticParameters_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getNumberOfStochasticParameters"
                , getNumberOfStochasticParameters_function_type(&::FormFactorPrism3::getNumberOfStochasticParameters)
                , default_getNumberOfStochasticParameters_function_type(&FormFactorPrism3_wrapper::default_getNumberOfStochasticParameters) );
        
        }
        { //::FormFactorPrism3::setHeight
        
            typedef void ( ::FormFactorPrism3::*setHeight_function_type )( double ) ;
            typedef void ( FormFactorPrism3_wrapper::*default_setHeight_function_type )( double ) ;
            
            FormFactorPrism3_exposer.def( 
                "setHeight"
                , setHeight_function_type(&::FormFactorPrism3::setHeight)
                , default_setHeight_function_type(&FormFactorPrism3_wrapper::default_setHeight)
                , ( bp::arg("height") ) );
        
        }
        { //::FormFactorPrism3::setLength
        
            typedef void ( ::FormFactorPrism3::*setLength_function_type )( double ) ;
            typedef void ( FormFactorPrism3_wrapper::*default_setLength_function_type )( double ) ;
            
            FormFactorPrism3_exposer.def( 
                "setLength"
                , setLength_function_type(&::FormFactorPrism3::setLength)
                , default_setLength_function_type(&FormFactorPrism3_wrapper::default_setLength)
                , ( bp::arg("length") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( FormFactorPrism3_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            FormFactorPrism3_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&FormFactorPrism3_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( FormFactorPrism3_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            FormFactorPrism3_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&FormFactorPrism3_wrapper::default_clearParameterPool) );
        
        }
        { //::ISample::cloneInvertB
        
            typedef ::ISample * ( ::ISample::*cloneInvertB_function_type )(  ) const;
            typedef ::ISample * ( FormFactorPrism3_wrapper::*default_cloneInvertB_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "cloneInvertB"
                , cloneInvertB_function_type(&::ISample::cloneInvertB)
                , default_cloneInvertB_function_type(&FormFactorPrism3_wrapper::default_cloneInvertB)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::containsMagneticMaterial
        
            typedef bool ( ::ISample::*containsMagneticMaterial_function_type )(  ) const;
            typedef bool ( FormFactorPrism3_wrapper::*default_containsMagneticMaterial_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "containsMagneticMaterial"
                , containsMagneticMaterial_function_type(&::ISample::containsMagneticMaterial)
                , default_containsMagneticMaterial_function_type(&FormFactorPrism3_wrapper::default_containsMagneticMaterial) );
        
        }
        { //::IFormFactor::createDistributedFormFactors
        
            typedef void ( ::IFormFactor::*createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            typedef void ( FormFactorPrism3_wrapper::*default_createDistributedFormFactors_function_type )( ::std::vector< IFormFactor* > &,::std::vector< double > &,::std::size_t ) const;
            
            FormFactorPrism3_exposer.def( 
                "createDistributedFormFactors"
                , createDistributedFormFactors_function_type(&::IFormFactor::createDistributedFormFactors)
                , default_createDistributedFormFactors_function_type(&FormFactorPrism3_wrapper::default_createDistributedFormFactors)
                , ( bp::arg("form_factors"), bp::arg("probabilities"), bp::arg("nbr_samples") )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( FormFactorPrism3_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&FormFactorPrism3_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFormFactorBorn::evaluate
        
            typedef ::complex_t ( ::IFormFactorBorn::*evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            typedef ::complex_t ( FormFactorPrism3_wrapper::*default_evaluate_function_type )( ::cvector_t const &,::Bin1DCVector const &,::Bin1D const & ) const;
            
            FormFactorPrism3_exposer.def( 
                "evaluate"
                , evaluate_function_type(&::IFormFactorBorn::evaluate)
                , default_evaluate_function_type(&FormFactorPrism3_wrapper::default_evaluate)
                , ( bp::arg("k_i"), bp::arg("k_f_bin"), bp::arg("alpha_f_bin") ) );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample * ( ::ISample::*getCompositeSample_function_type )(  ) ;
            typedef ::ICompositeSample * ( FormFactorPrism3_wrapper::*default_getCompositeSample_function_type )(  ) ;
            
            FormFactorPrism3_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorPrism3_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::ISample::getCompositeSample
        
            typedef ::ICompositeSample const * ( ::ISample::*getCompositeSample_function_type )(  ) const;
            typedef ::ICompositeSample const * ( FormFactorPrism3_wrapper::*default_getCompositeSample_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getCompositeSample"
                , getCompositeSample_function_type(&::ISample::getCompositeSample)
                , default_getCompositeSample_function_type(&FormFactorPrism3_wrapper::default_getCompositeSample)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::IFormFactor::getRadius
        
            typedef double ( ::IFormFactor::*getRadius_function_type )(  ) const;
            typedef double ( FormFactorPrism3_wrapper::*default_getRadius_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getRadius"
                , getRadius_function_type(&::IFormFactor::getRadius)
                , default_getRadius_function_type(&FormFactorPrism3_wrapper::default_getRadius) );
        
        }
        { //::IFormFactorBorn::getVolume
        
            typedef double ( ::IFormFactorBorn::*getVolume_function_type )(  ) const;
            typedef double ( FormFactorPrism3_wrapper::*default_getVolume_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "getVolume"
                , getVolume_function_type(&::IFormFactorBorn::getVolume)
                , default_getVolume_function_type(&FormFactorPrism3_wrapper::default_getVolume) );
        
        }
        { //::IFormFactor::isDistributedFormFactor
        
            typedef bool ( ::IFormFactor::*isDistributedFormFactor_function_type )(  ) const;
            typedef bool ( FormFactorPrism3_wrapper::*default_isDistributedFormFactor_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "isDistributedFormFactor"
                , isDistributedFormFactor_function_type(&::IFormFactor::isDistributedFormFactor)
                , default_isDistributedFormFactor_function_type(&FormFactorPrism3_wrapper::default_isDistributedFormFactor) );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( FormFactorPrism3_wrapper::*default_printParameters_function_type )(  ) const;
            
            FormFactorPrism3_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&FormFactorPrism3_wrapper::default_printParameters) );
        
        }
        { //::ISample::printSampleTree
        
            typedef void ( ::ISample::*printSampleTree_function_type )(  ) ;
            typedef void ( FormFactorPrism3_wrapper::*default_printSampleTree_function_type )(  ) ;
            
            FormFactorPrism3_exposer.def( 
                "printSampleTree"
                , printSampleTree_function_type(&::ISample::printSampleTree)
                , default_printSampleTree_function_type(&FormFactorPrism3_wrapper::default_printSampleTree) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            FormFactorPrism3_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &FormFactorPrism3_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( FormFactorPrism3_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            FormFactorPrism3_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&FormFactorPrism3_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( FormFactorPrism3_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            FormFactorPrism3_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&FormFactorPrism3_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
