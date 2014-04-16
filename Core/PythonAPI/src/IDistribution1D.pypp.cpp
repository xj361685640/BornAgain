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
#include "IDistribution1D.pypp.h"

namespace bp = boost::python;

struct IDistribution1D_wrapper : IDistribution1D, bp::wrapper< IDistribution1D > {

    IDistribution1D_wrapper( )
    : IDistribution1D( )
      , bp::wrapper< IDistribution1D >(){
        // null constructor
    
    }

    virtual ::IDistribution1D * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->IDistribution1D::clone(  );
        }
    }
    
    ::IDistribution1D * default_clone(  ) const  {
        return IDistribution1D::clone( );
    }

    virtual ::std::vector< double > generateValueList( ::std::size_t nbr_samples, double sigma_factor ) const {
        bp::override func_generateValueList = this->get_override( "generateValueList" );
        return func_generateValueList( nbr_samples, sigma_factor );
    }

    virtual double getMean(  ) const {
        bp::override func_getMean = this->get_override( "getMean" );
        return func_getMean(  );
    }

    virtual double probabilityDensity( double x ) const {
        bp::override func_probabilityDensity = this->get_override( "probabilityDensity" );
        return func_probabilityDensity( x );
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
        if( dynamic_cast< IDistribution1D_wrapper * >( boost::addressof( inst ) ) ){
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

void register_IDistribution1D_class(){

    { //::IDistribution1D
        typedef bp::class_< IDistribution1D_wrapper, bp::bases< IParameterized >, boost::noncopyable > IDistribution1D_exposer_t;
        IDistribution1D_exposer_t IDistribution1D_exposer = IDistribution1D_exposer_t( "IDistribution1D", bp::init< >() );
        bp::scope IDistribution1D_scope( IDistribution1D_exposer );
        { //::IDistribution1D::clone
        
            typedef ::IDistribution1D * ( ::IDistribution1D::*clone_function_type )(  ) const;
            typedef ::IDistribution1D * ( IDistribution1D_wrapper::*default_clone_function_type )(  ) const;
            
            IDistribution1D_exposer.def( 
                "clone"
                , clone_function_type(&::IDistribution1D::clone)
                , default_clone_function_type(&IDistribution1D_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IDistribution1D::generateValueList
        
            typedef ::std::vector<double, std::allocator<double> > ( ::IDistribution1D::*generateValueList_function_type )( ::std::size_t,double ) const;
            
            IDistribution1D_exposer.def( 
                "generateValueList"
                , bp::pure_virtual( generateValueList_function_type(&::IDistribution1D::generateValueList) )
                , ( bp::arg("nbr_samples"), bp::arg("sigma_factor") ) );
        
        }
        { //::IDistribution1D::getMean
        
            typedef double ( ::IDistribution1D::*getMean_function_type )(  ) const;
            
            IDistribution1D_exposer.def( 
                "getMean"
                , bp::pure_virtual( getMean_function_type(&::IDistribution1D::getMean) ) );
        
        }
        { //::IDistribution1D::probabilityDensity
        
            typedef double ( ::IDistribution1D::*probabilityDensity_function_type )( double ) const;
            
            IDistribution1D_exposer.def( 
                "probabilityDensity"
                , bp::pure_virtual( probabilityDensity_function_type(&::IDistribution1D::probabilityDensity) )
                , ( bp::arg("x") ) );
        
        }
        { //::IParameterized::areParametersChanged
        
            typedef bool ( ::IParameterized::*areParametersChanged_function_type )(  ) ;
            typedef bool ( IDistribution1D_wrapper::*default_areParametersChanged_function_type )(  ) ;
            
            IDistribution1D_exposer.def( 
                "areParametersChanged"
                , areParametersChanged_function_type(&::IParameterized::areParametersChanged)
                , default_areParametersChanged_function_type(&IDistribution1D_wrapper::default_areParametersChanged) );
        
        }
        { //::IParameterized::clearParameterPool
        
            typedef void ( ::IParameterized::*clearParameterPool_function_type )(  ) ;
            typedef void ( IDistribution1D_wrapper::*default_clearParameterPool_function_type )(  ) ;
            
            IDistribution1D_exposer.def( 
                "clearParameterPool"
                , clearParameterPool_function_type(&::IParameterized::clearParameterPool)
                , default_clearParameterPool_function_type(&IDistribution1D_wrapper::default_clearParameterPool) );
        
        }
        { //::IParameterized::createParameterTree
        
            typedef ::ParameterPool * ( ::IParameterized::*createParameterTree_function_type )(  ) const;
            typedef ::ParameterPool * ( IDistribution1D_wrapper::*default_createParameterTree_function_type )(  ) const;
            
            IDistribution1D_exposer.def( 
                "createParameterTree"
                , createParameterTree_function_type(&::IParameterized::createParameterTree)
                , default_createParameterTree_function_type(&IDistribution1D_wrapper::default_createParameterTree)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IParameterized::printParameters
        
            typedef void ( ::IParameterized::*printParameters_function_type )(  ) const;
            typedef void ( IDistribution1D_wrapper::*default_printParameters_function_type )(  ) const;
            
            IDistribution1D_exposer.def( 
                "printParameters"
                , printParameters_function_type(&::IParameterized::printParameters)
                , default_printParameters_function_type(&IDistribution1D_wrapper::default_printParameters) );
        
        }
        { //::IParameterized::registerParameter
        
            typedef void ( *default_registerParameter_function_type )( ::IParameterized &,::std::string const &,long unsigned int );
            
            IDistribution1D_exposer.def( 
                "registerParameter"
                , default_registerParameter_function_type( &IDistribution1D_wrapper::default_registerParameter )
                , ( bp::arg("inst"), bp::arg("name"), bp::arg("parpointer") ) );
        
        }
        { //::IParameterized::setParameterValue
        
            typedef bool ( ::IParameterized::*setParameterValue_function_type )( ::std::string const &,double ) ;
            typedef bool ( IDistribution1D_wrapper::*default_setParameterValue_function_type )( ::std::string const &,double ) ;
            
            IDistribution1D_exposer.def( 
                "setParameterValue"
                , setParameterValue_function_type(&::IParameterized::setParameterValue)
                , default_setParameterValue_function_type(&IDistribution1D_wrapper::default_setParameterValue)
                , ( bp::arg("name"), bp::arg("value") ) );
        
        }
        { //::IParameterized::setParametersAreChanged
        
            typedef void ( ::IParameterized::*setParametersAreChanged_function_type )(  ) ;
            typedef void ( IDistribution1D_wrapper::*default_setParametersAreChanged_function_type )(  ) ;
            
            IDistribution1D_exposer.def( 
                "setParametersAreChanged"
                , setParametersAreChanged_function_type(&::IParameterized::setParametersAreChanged)
                , default_setParametersAreChanged_function_type(&IDistribution1D_wrapper::default_setParametersAreChanged) );
        
        }
    }

}
