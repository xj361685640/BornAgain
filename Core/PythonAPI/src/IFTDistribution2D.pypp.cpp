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
#include "IFTDistribution2D.pypp.h"

namespace bp = boost::python;

struct IFTDistribution2D_wrapper : IFTDistribution2D, bp::wrapper< IFTDistribution2D > {

    IFTDistribution2D_wrapper(double coherence_length_x, double coherence_length_y )
    : IFTDistribution2D( coherence_length_x, coherence_length_y )
      , bp::wrapper< IFTDistribution2D >(){
        // constructor
    m_pyobj = 0;
    }

    virtual ::IFTDistribution2D * clone(  ) const {
        bp::override func_clone = this->get_override( "clone" );
        return func_clone(  );
    }

    virtual double evaluate( double qx, double qy ) const {
        bp::override func_evaluate = this->get_override( "evaluate" );
        return func_evaluate( qx, qy );
    }

    PyObject* m_pyobj;

};

void register_IFTDistribution2D_class(){

    { //::IFTDistribution2D
        typedef bp::class_< IFTDistribution2D_wrapper, bp::bases< IParameterized >, std::auto_ptr< IFTDistribution2D_wrapper >, boost::noncopyable > IFTDistribution2D_exposer_t;
        IFTDistribution2D_exposer_t IFTDistribution2D_exposer = IFTDistribution2D_exposer_t( "IFTDistribution2D", "Interface for 2 dimensional distributions in Fourier space.", bp::init< double, double >(( bp::arg("coherence_length_x"), bp::arg("coherence_length_y") )) );
        bp::scope IFTDistribution2D_scope( IFTDistribution2D_exposer );
        { //::IFTDistribution2D::clone
        
            typedef ::IFTDistribution2D * ( ::IFTDistribution2D::*clone_function_type)(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "clone"
                , bp::pure_virtual( clone_function_type(&::IFTDistribution2D::clone) )
                , bp::return_value_policy< bp::manage_new_object >() );
        
        }
        { //::IFTDistribution2D::evaluate
        
            typedef double ( ::IFTDistribution2D::*evaluate_function_type)( double,double ) const;
            
            IFTDistribution2D_exposer.def( 
                "evaluate"
                , bp::pure_virtual( evaluate_function_type(&::IFTDistribution2D::evaluate) )
                , ( bp::arg("qx"), bp::arg("qy") )
                , "evaluate Fourier transformed distribution for q in X,Y coordinates the original distribution (in real space) is assumed to be normalized: total integral is equal to 1 " );
        
        }
        { //::IFTDistribution2D::getCoherenceLengthX
        
            typedef double ( ::IFTDistribution2D::*getCoherenceLengthX_function_type)(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getCoherenceLengthX"
                , getCoherenceLengthX_function_type( &::IFTDistribution2D::getCoherenceLengthX ) );
        
        }
        { //::IFTDistribution2D::getCoherenceLengthY
        
            typedef double ( ::IFTDistribution2D::*getCoherenceLengthY_function_type)(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getCoherenceLengthY"
                , getCoherenceLengthY_function_type( &::IFTDistribution2D::getCoherenceLengthY ) );
        
        }
        { //::IFTDistribution2D::getDelta
        
            typedef double ( ::IFTDistribution2D::*getDelta_function_type)(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getDelta"
                , getDelta_function_type( &::IFTDistribution2D::getDelta ) );
        
        }
        { //::IFTDistribution2D::getGamma
        
            typedef double ( ::IFTDistribution2D::*getGamma_function_type)(  ) const;
            
            IFTDistribution2D_exposer.def( 
                "getGamma"
                , getGamma_function_type( &::IFTDistribution2D::getGamma ) );
        
        }
        { //::IFTDistribution2D::setGamma
        
            typedef void ( ::IFTDistribution2D::*setGamma_function_type)( double ) ;
            
            IFTDistribution2D_exposer.def( 
                "setGamma"
                , setGamma_function_type( &::IFTDistribution2D::setGamma )
                , ( bp::arg("gamma") ) );
        
        }
    }

}
