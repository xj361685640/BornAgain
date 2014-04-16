// This file has been generated by Py++.

// BornAgain: simulate and fit scattering at grazing incidence
//! @brief Automatically generated boost::python code for PythonFitAPI

#include "Macros.h"
GCC_DIAG_OFF(unused-parameter);
GCC_DIAG_OFF(missing-field-initializers);
#include "boost/python.hpp"
GCC_DIAG_ON(unused-parameter);
GCC_DIAG_ON(missing-field-initializers);
#include "PythonFitList.h"
#include "FitStrategyAdjustParameters.pypp.h"

namespace bp = boost::python;

struct FitStrategyAdjustParameters_wrapper : FitStrategyAdjustParameters, bp::wrapper< FitStrategyAdjustParameters > {

    FitStrategyAdjustParameters_wrapper(::std::string const & name )
    : FitStrategyAdjustParameters( name )
      , bp::wrapper< FitStrategyAdjustParameters >(){
        // constructor
    
    }

    FitStrategyAdjustParameters_wrapper( )
    : FitStrategyAdjustParameters( )
      , bp::wrapper< FitStrategyAdjustParameters >(){
        // null constructor
    
    }

    virtual void clear(  ) {
        if( bp::override func_clear = this->get_override( "clear" ) )
            func_clear(  );
        else{
            this->FitStrategyAdjustParameters::clear(  );
        }
    }
    
    void default_clear(  ) {
        FitStrategyAdjustParameters::clear( );
    }

    virtual ::FitStrategyAdjustParameters * clone(  ) const  {
        if( bp::override func_clone = this->get_override( "clone" ) )
            return func_clone(  );
        else{
            return this->FitStrategyAdjustParameters::clone(  );
        }
    }
    
    ::FitStrategyAdjustParameters * default_clone(  ) const  {
        return FitStrategyAdjustParameters::clone( );
    }

    virtual void execute(  ) {
        if( bp::override func_execute = this->get_override( "execute" ) )
            func_execute(  );
        else{
            this->FitStrategyAdjustParameters::execute(  );
        }
    }
    
    void default_execute(  ) {
        FitStrategyAdjustParameters::execute( );
    }

    virtual void setPreserveOriginalValues( bool preserve_values ) {
        if( bp::override func_setPreserveOriginalValues = this->get_override( "setPreserveOriginalValues" ) )
            func_setPreserveOriginalValues( preserve_values );
        else{
            this->FitStrategyAdjustParameters::setPreserveOriginalValues( preserve_values );
        }
    }
    
    void default_setPreserveOriginalValues( bool preserve_values ) {
        FitStrategyAdjustParameters::setPreserveOriginalValues( preserve_values );
    }

};

void register_FitStrategyAdjustParameters_class(){

    { //::FitStrategyAdjustParameters
        typedef bp::class_< FitStrategyAdjustParameters_wrapper, bp::bases< IFitStrategy >, boost::noncopyable > FitStrategyAdjustParameters_exposer_t;
        FitStrategyAdjustParameters_exposer_t FitStrategyAdjustParameters_exposer = FitStrategyAdjustParameters_exposer_t( "FitStrategyAdjustParameters", bp::init< std::string const & >(( bp::arg("name") )) );
        bp::scope FitStrategyAdjustParameters_scope( FitStrategyAdjustParameters_exposer );
        FitStrategyAdjustParameters_exposer.def( bp::init< >() );
        { //::FitStrategyAdjustParameters::clear
        
            typedef void ( ::FitStrategyAdjustParameters::*clear_function_type )(  ) ;
            typedef void ( FitStrategyAdjustParameters_wrapper::*default_clear_function_type )(  ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "clear"
                , clear_function_type(&::FitStrategyAdjustParameters::clear)
                , default_clear_function_type(&FitStrategyAdjustParameters_wrapper::default_clear) );
        
        }
        { //::FitStrategyAdjustParameters::clone
        
            typedef ::FitStrategyAdjustParameters * ( ::FitStrategyAdjustParameters::*clone_function_type )(  ) const;
            typedef ::FitStrategyAdjustParameters * ( FitStrategyAdjustParameters_wrapper::*default_clone_function_type )(  ) const;
            
            FitStrategyAdjustParameters_exposer.def( 
                "clone"
                , clone_function_type(&::FitStrategyAdjustParameters::clone)
                , default_clone_function_type(&FitStrategyAdjustParameters_wrapper::default_clone)
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::FitStrategyAdjustParameters::execute
        
            typedef void ( ::FitStrategyAdjustParameters::*execute_function_type )(  ) ;
            typedef void ( FitStrategyAdjustParameters_wrapper::*default_execute_function_type )(  ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "execute"
                , execute_function_type(&::FitStrategyAdjustParameters::execute)
                , default_execute_function_type(&FitStrategyAdjustParameters_wrapper::default_execute) );
        
        }
        { //::FitStrategyAdjustParameters::fix
        
            typedef ::FitStrategyAdjustParameters & ( ::FitStrategyAdjustParameters::*fix_function_type )( ::std::string ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "fix"
                , fix_function_type(&::FitStrategyAdjustParameters::fix)
                , ( bp::arg("parname") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitStrategyAdjustParameters::fix_all
        
            typedef ::FitStrategyAdjustParameters & ( ::FitStrategyAdjustParameters::*fix_all_function_type )(  ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "fix_all"
                , fix_all_function_type(&::FitStrategyAdjustParameters::fix_all)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitStrategyAdjustParameters::release
        
            typedef ::FitStrategyAdjustParameters & ( ::FitStrategyAdjustParameters::*release_function_type )( ::std::string ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "release"
                , release_function_type(&::FitStrategyAdjustParameters::release)
                , ( bp::arg("parname") )
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitStrategyAdjustParameters::release_all
        
            typedef ::FitStrategyAdjustParameters & ( ::FitStrategyAdjustParameters::*release_all_function_type )(  ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "release_all"
                , release_all_function_type(&::FitStrategyAdjustParameters::release_all)
                , bp::return_value_policy< bp::reference_existing_object >() );
        
        }
        { //::FitStrategyAdjustParameters::setPreserveOriginalValues
        
            typedef void ( ::FitStrategyAdjustParameters::*setPreserveOriginalValues_function_type )( bool ) ;
            typedef void ( FitStrategyAdjustParameters_wrapper::*default_setPreserveOriginalValues_function_type )( bool ) ;
            
            FitStrategyAdjustParameters_exposer.def( 
                "setPreserveOriginalValues"
                , setPreserveOriginalValues_function_type(&::FitStrategyAdjustParameters::setPreserveOriginalValues)
                , default_setPreserveOriginalValues_function_type(&FitStrategyAdjustParameters_wrapper::default_setPreserveOriginalValues)
                , ( bp::arg("preserve_values") ) );
        
        }
    }

}
