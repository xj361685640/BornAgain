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
#include "PythonFitList.h"
#include "AttLimits.pypp.h"

namespace bp = boost::python;

void register_AttLimits_class(){

    { //::AttLimits
        typedef bp::class_< AttLimits > AttLimits_exposer_t;
        AttLimits_exposer_t AttLimits_exposer = AttLimits_exposer_t( "AttLimits", bp::init< >() );
        bp::scope AttLimits_scope( AttLimits_exposer );
        { //::AttLimits::fixed
        
            typedef ::AttLimits ( *fixed_function_type )(  );
            
            AttLimits_exposer.def( 
                "fixed"
                , fixed_function_type( &::AttLimits::fixed ) );
        
        }
        { //::AttLimits::getLowerLimit
        
            typedef double ( ::AttLimits::*getLowerLimit_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "getLowerLimit"
                , getLowerLimit_function_type( &::AttLimits::getLowerLimit ) );
        
        }
        { //::AttLimits::getUpperLimit
        
            typedef double ( ::AttLimits::*getUpperLimit_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "getUpperLimit"
                , getUpperLimit_function_type( &::AttLimits::getUpperLimit ) );
        
        }
        { //::AttLimits::hasLowerAndUpperLimits
        
            typedef bool ( ::AttLimits::*hasLowerAndUpperLimits_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "hasLowerAndUpperLimits"
                , hasLowerAndUpperLimits_function_type( &::AttLimits::hasLowerAndUpperLimits ) );
        
        }
        { //::AttLimits::hasLowerLimit
        
            typedef bool ( ::AttLimits::*hasLowerLimit_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "hasLowerLimit"
                , hasLowerLimit_function_type( &::AttLimits::hasLowerLimit ) );
        
        }
        { //::AttLimits::hasUpperLimit
        
            typedef bool ( ::AttLimits::*hasUpperLimit_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "hasUpperLimit"
                , hasUpperLimit_function_type( &::AttLimits::hasUpperLimit ) );
        
        }
        { //::AttLimits::isFixed
        
            typedef bool ( ::AttLimits::*isFixed_function_type)(  ) const;
            
            AttLimits_exposer.def( 
                "isFixed"
                , isFixed_function_type( &::AttLimits::isFixed ) );
        
        }
        { //::AttLimits::isInRange
        
            typedef bool ( ::AttLimits::*isInRange_function_type)( double ) const;
            
            AttLimits_exposer.def( 
                "isInRange"
                , isInRange_function_type( &::AttLimits::isInRange )
                , ( bp::arg("value") ) );
        
        }
        { //::AttLimits::limited
        
            typedef ::AttLimits ( *limited_function_type )( double,double );
            
            AttLimits_exposer.def( 
                "limited"
                , limited_function_type( &::AttLimits::limited )
                , ( bp::arg("left_bound_value"), bp::arg("right_bound_value") ) );
        
        }
        { //::AttLimits::limitless
        
            typedef ::AttLimits ( *limitless_function_type )(  );
            
            AttLimits_exposer.def( 
                "limitless"
                , limitless_function_type( &::AttLimits::limitless ) );
        
        }
        { //::AttLimits::lowerLimited
        
            typedef ::AttLimits ( *lowerLimited_function_type )( double );
            
            AttLimits_exposer.def( 
                "lowerLimited"
                , lowerLimited_function_type( &::AttLimits::lowerLimited )
                , ( bp::arg("bound_value") ) );
        
        }
        AttLimits_exposer.def( bp::self != bp::self );
        AttLimits_exposer.def( bp::self == bp::self );
        { //::AttLimits::positive
        
            typedef ::AttLimits ( *positive_function_type )(  );
            
            AttLimits_exposer.def( 
                "positive"
                , positive_function_type( &::AttLimits::positive ) );
        
        }
        { //::AttLimits::removeLimits
        
            typedef void ( ::AttLimits::*removeLimits_function_type)(  ) ;
            
            AttLimits_exposer.def( 
                "removeLimits"
                , removeLimits_function_type( &::AttLimits::removeLimits ) );
        
        }
        { //::AttLimits::removeLowerLimit
        
            typedef void ( ::AttLimits::*removeLowerLimit_function_type)(  ) ;
            
            AttLimits_exposer.def( 
                "removeLowerLimit"
                , removeLowerLimit_function_type( &::AttLimits::removeLowerLimit ) );
        
        }
        { //::AttLimits::removeUpperLimit
        
            typedef void ( ::AttLimits::*removeUpperLimit_function_type)(  ) ;
            
            AttLimits_exposer.def( 
                "removeUpperLimit"
                , removeUpperLimit_function_type( &::AttLimits::removeUpperLimit ) );
        
        }
        { //::AttLimits::setFixed
        
            typedef void ( ::AttLimits::*setFixed_function_type)( bool ) ;
            
            AttLimits_exposer.def( 
                "setFixed"
                , setFixed_function_type( &::AttLimits::setFixed )
                , ( bp::arg("is_fixed") ) );
        
        }
        { //::AttLimits::setLimits
        
            typedef void ( ::AttLimits::*setLimits_function_type)( double,double ) ;
            
            AttLimits_exposer.def( 
                "setLimits"
                , setLimits_function_type( &::AttLimits::setLimits )
                , ( bp::arg("xmin"), bp::arg("xmax") ) );
        
        }
        { //::AttLimits::setLowerLimit
        
            typedef void ( ::AttLimits::*setLowerLimit_function_type)( double ) ;
            
            AttLimits_exposer.def( 
                "setLowerLimit"
                , setLowerLimit_function_type( &::AttLimits::setLowerLimit )
                , ( bp::arg("value") ) );
        
        }
        { //::AttLimits::setUpperLimit
        
            typedef void ( ::AttLimits::*setUpperLimit_function_type)( double ) ;
            
            AttLimits_exposer.def( 
                "setUpperLimit"
                , setUpperLimit_function_type( &::AttLimits::setUpperLimit )
                , ( bp::arg("value") ) );
        
        }
        { //::AttLimits::upperLimited
        
            typedef ::AttLimits ( *upperLimited_function_type )( double );
            
            AttLimits_exposer.def( 
                "upperLimited"
                , upperLimited_function_type( &::AttLimits::upperLimited )
                , ( bp::arg("bound_value") ) );
        
        }
        AttLimits_exposer.staticmethod( "fixed" );
        AttLimits_exposer.staticmethod( "limited" );
        AttLimits_exposer.staticmethod( "limitless" );
        AttLimits_exposer.staticmethod( "lowerLimited" );
        AttLimits_exposer.staticmethod( "positive" );
        AttLimits_exposer.staticmethod( "upperLimited" );
    }

}
