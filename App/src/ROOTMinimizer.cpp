#include "ROOTMinimizer.h"
#include "Exceptions.h"
#include "Utils.h"
#include "ROOTMinimizerFunction.h"
#include <iomanip>
#include <sstream>
#include <boost/assign/list_of.hpp>



/* ************************************************************************* */
//
/* ************************************************************************* */
ROOTMinimizer::ROOTMinimizer(const std::string &minimizer_name, const std::string &algo_type)
    : m_minimizer_name(minimizer_name)
    , m_algo_type(algo_type)
    , m_minfunc(0)
    , m_minfunc_element(0)
{

    if( !isValidNames(m_minimizer_name, m_algo_type) ) throw LogicErrorException("ROOTMinimizer::ROOTMinimizer() -> Error! Wrong minimizer initialization parameters.");

    m_root_minimizer = ROOT::Math::Factory::CreateMinimizer(minimizer_name, algo_type );
    if( !m_root_minimizer  ) throw NullPointerException("ROOTMinimizer::ROOTMinimizer() -> Error! Can't create minimizer.");

    m_root_minimizer->SetMaxFunctionCalls(20000);
    m_root_minimizer->SetMaxIterations(20000);
}


ROOTMinimizer::~ROOTMinimizer()
{
    delete m_root_minimizer;
    delete m_minfunc;
    delete m_minfunc_element;
}


/* ************************************************************************* */
// checking validity of the combination minimizer_name and algo_type
/* ************************************************************************* */
bool ROOTMinimizer::isValidNames(const std::string &minimizer_name, const std::string &algo_type)
{
    // valid minimizer names and algo types
    typedef std::map<std::string, std::vector<std::string > > algotypes_t;
    algotypes_t algoTypes;
    algoTypes["Minuit"]      = boost::assign::list_of("Migrad")("Simplex")("Combined")("Scan");
    algoTypes["Minuit2"]     = boost::assign::list_of("Migrad")("Simplex")("Combined")("Scan")("fumili");
    algoTypes["Fumili"]      = boost::assign::list_of("");
    algoTypes["GSLMultiMin"] = boost::assign::list_of("ConjugateFR")("ConjugatePR")("BFGS")("BFGS2")("SteepestDescent");
    algoTypes["GSLMultiFit"] = boost::assign::list_of("");
    algoTypes["GSLSimAn"]    = boost::assign::list_of("");
    algoTypes["Genetic"]     = boost::assign::list_of("");

    // check if given minimizer names are valid
    algotypes_t::iterator it = algoTypes.find(minimizer_name);
    if(it != algoTypes.end() ) {
        // if algo type exists
        for(size_t i=0; i<it->second.size(); ++i ) {
            if(it->second[i] == algo_type ) return true;
        }
    }

    // if not, print complaining and return false
    std::cout << "ROOTMinimizer::isValidNames() -> Warning! Wrong minimizer name '" << minimizer_name << "' and/or algorithm type '" << algo_type << "'." << std::endl;
    std::cout << "List of allowed minimizers (and algos)" << std::endl;
    for(it = algoTypes.begin(); it!= algoTypes.end(); ++it) {
        std::cout << std::setw(20) << std::left<< it->first << "  : ";
        for(size_t i=0; i<it->second.size(); ++i ) {
            std::cout << it->second[i] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return false;
}




void ROOTMinimizer::setVariable(int index, const FitParameter *par)
{
    bool success;
    if( par->isFixed() ) {
        success=m_root_minimizer->SetFixedVariable(index, par->getName().c_str(), par->getValue());
    }else if(par->hasLowerAndUpperLimits() ) {
        success=m_root_minimizer->SetLimitedVariable(index, par->getName().c_str(), par->getValue(), par->getStep(), par->getLowerLimit(), par->getUpperLimit());
    } else if(par->hasLowerLimit() && !par->hasUpperLimit() ) {
        success=m_root_minimizer->SetLowerLimitedVariable(index, par->getName().c_str(), par->getValue(), par->getStep(), par->getLowerLimit());
    } else if( par->hasUpperLimit() && !par->hasLowerLimit() ) {
        success=m_root_minimizer->SetUpperLimitedVariable(index, par->getName().c_str(), par->getValue(), par->getStep(), par->getUpperLimit());
    } else if( !par->hasUpperLimit() && !par->hasLowerLimit() && !par->isFixed() ) {
        success=m_root_minimizer->SetVariable(index, par->getName().c_str(), par->getValue(), par->getStep());
    } else {
        throw LogicErrorException("ROOTMinimizer::setVariable() -> Strange place... I wish I knew how I got here.");
    }
    if( !success ) {
        std::ostringstream ostr;
        ostr << "ROOTMinimizer::setVariable() -> Error! Minimizer returned false while setting the variable." << std::endl;
        ostr << "                                Probably given index has been already used for another variable name." << std::endl;
        ostr << "                                Index:" << index << " name '" << par->getName().c_str() << std::endl;
        throw LogicErrorException(ostr.str());
    }
}


void ROOTMinimizer::minimize()
{
    m_root_minimizer->Minimize();
}


/* ************************************************************************* */
// set fcn function for minimizer
/* ************************************************************************* */
void ROOTMinimizer::setFunction(function_t fcn, int ndims, element_function_t element_fcn, int nelements)
{
    if( fcn && element_fcn ) {
        std::cout << " ROOTMinimizer::setFunction() -> XXX 1.1 making ROOTMinimizerElementFunction " << std::endl;
        delete m_minfunc;
        m_minfunc_element = new ROOTMinimizerElementFunction(fcn, ndims, element_fcn, nelements);
        m_root_minimizer->SetFunction(*m_minfunc_element);
    } else if( fcn ) {
        std::cout << " ROOTMinimizer::setFunction() -> XXX 1.2 making ROOTMinimizerFunction" << std::endl;
        delete m_minfunc;
        m_minfunc = new ROOTMinimizerFunction(fcn, ndims);
        m_root_minimizer->SetFunction(*m_minfunc);
    } else {
        throw LogicErrorException("ROOTMinimizer::minimize() -> Error! Can't guess minimization function type");
    }

}


/* ************************************************************************* */
// print fit results
/* ************************************************************************* */
void ROOTMinimizer::printResults() const
{
    // explanations of minimizer's status
    std::map<int, std::string> minimizerStatus;
    minimizerStatus[0] = std::string("OK, valid minimum");
    minimizerStatus[1] = std::string("Didn't converge, covariance was made pos defined");
    minimizerStatus[2] = std::string("Didn't converge, Hesse is invalid");
    minimizerStatus[3] = std::string("Didn't converge, Edm is above max");
    minimizerStatus[4] = std::string("Didn't converge, reached call limit");
    minimizerStatus[5] = std::string("Didn't converge, unknown failure");
    std::map<int, std::string> validErrorStatus;
    validErrorStatus[0] = std::string("No detailed error validation");
    validErrorStatus[1] = std::string("Performed detailed error validation"); // true if Minimizer has performed a detailed error validation (e.g. run Hesse for Minuit)
    std::map<int, std::string> covMatrixStatus;
    covMatrixStatus[-1] = std::string("not available (inversion failed or Hesse failed)");
    covMatrixStatus[0] = std::string("available but not positive defined");
    covMatrixStatus[1] = std::string("covariance only approximate");
    covMatrixStatus[2] = std::string("full matrix but forced pos def");
    covMatrixStatus[3] = std::string("full accurate");

//     Status code of minimizer is updated according to the following convention (in case Hesse failed)
//     status += 100*hesseStatus where hesse status is:
//     status = 1 : hesse failed
//     status = 2 : matrix inversion failed
//     status = 3 : matrix is not pos defined

    // print initial mimimizer options
    printOptions();
    std::cout << "--- ROOTMinimizer::printResults() ---------------- " << std::endl;

    // final status of the minimizer
    std::cout << std::setw(25) << std::left << "  Status           "      << ": " << m_root_minimizer->Status() << " '" << minimizerStatus[m_root_minimizer->Status()] << "'" << std::endl;
    std::cout << std::setw(25) << std::left << "  IsValidError     "      << ": " << m_root_minimizer->IsValidError() << " '" << validErrorStatus[m_root_minimizer->Status()] << "'" <<std::endl;
    std::cout << std::setw(25) << std::left << "  NCalls"                 << ": " << m_root_minimizer->NCalls() << std::endl;
    if(m_minfunc_element) {
        std::cout << std::setw(25) << std::left << "  NCallsElement "                 << ": " << m_minfunc_element->NCallsElement() << std::endl;
    }
    std::cout << std::setw(25) << std::left << "  MinValue"               << ": " << std::scientific << std::setprecision(8) << getMinValue() << std::endl;
    std::cout << std::setw(25) << std::left << "  Edm"                    << ": " << std::scientific << std::setprecision(8) << m_root_minimizer->Edm() << std::endl;
    std::cout << std::setw(25) << std::left << "  CovMatrixStatus"        << ": " << m_root_minimizer->CovMatrixStatus() << " '" << covMatrixStatus[m_root_minimizer->CovMatrixStatus()] << "'" << std::endl;

    // variables found
    std::cout << std::setw(25) << std::left << "  NumberOfVariables"      << ": "
              << m_root_minimizer->NFree() << " (free), " << m_root_minimizer->NDim() << " (total) " << std::endl;
    if( !m_root_minimizer->Errors() ) {
        std::cout << "Warning! No access to parameter errors" << std::endl;
    }
    std::cout << std::endl;
    std::cout << "  Variables at minimum:" << std::endl;
    std::cout << "      " << std::setw(5) << std::left << "Npar"
              << std::setw(39) << std::left << " Name"
              << std::setw(14) << "Value"
              << std::setw(14) << "Error"
              << std::setw(14) << "GlobalCC" << std::endl;
    for(size_t i=0; i<getNumberOfVariables(); ++i) {
        std::cout << "      " << std::setw(5) << std::left << i
                  << std::setw(38) << std::left << Utils::AdjustStringLength(m_root_minimizer->VariableName((int)i), 38) << " "
                  << std::setw(14) << std::left << std::scientific << std::setprecision(6) << std::left << getValueOfVariableAtMinimum(i)
                  << std::setw(14) << std::left << std::scientific << std::setprecision(6) << std::left << getErrorOfVariable(i)
                  << std::setw(14) << std::left << std::scientific << std::setprecision(6) << std::left << m_root_minimizer->GlobalCC((int)i) << std::endl;
    }

    // correlation between parameters
    std::cout << std::endl;
    std::cout << "  Correlation between variables:" << std::endl;
    for(unsigned int i=0; i<getNumberOfVariables(); ++i) {
        std::cout << "      ";
        for(unsigned int j=0; j<getNumberOfVariables(); ++j) {
            std::cout << std::setw(14) << std::scientific << std::setprecision(6)  << m_root_minimizer->Correlation(i,j);
        }
        std::cout << std::endl;
    }

    // own print method of the minimizer
    //m_root_minimizer->PrintResults();
}


/* ************************************************************************* */
// print minimizer description
/* ************************************************************************* */
void ROOTMinimizer::printOptions() const
{
    std::cout << "--- ROOTMinimizer::printOptions() -------------- " << std::endl;
    ROOT::Math::MinimizerOptions opt = m_root_minimizer->Options();
    //    opt.Print();
    //    std::cout << std::setw(25) << std::left << "  MinimizerType"      << ": " << opt.MinimizerType() << std::endl;
    //    std::cout << std::setw(25) << std::left << "  MinimizerAlgorithm" << ": " << opt.MinimizerAlgorithm() << std::endl;
    std::cout << std::setw(25) << std::left << "  MinimizerType"      << ": " << m_minimizer_name << std::endl;
    std::cout << std::setw(25) << std::left << "  MinimizerAlgorithm" << ": " << m_algo_type << std::endl;
    std::cout << std::setw(25) << std::left << "  Strategy"           << ": " << m_root_minimizer->Strategy() << std::endl;
    std::cout << std::setw(25) << std::left << "  Tolerance"          << ": " << m_root_minimizer->Tolerance() << std::endl;
    std::cout << std::setw(25) << std::left << "  MaxFunctionCalls"   << ": " << m_root_minimizer->MaxFunctionCalls() << std::endl;
    std::cout << std::setw(25) << std::left << "  MaxIterations"      << ": " << m_root_minimizer->MaxIterations() << std::endl;
    std::cout << std::setw(25) << std::left << "  Precision"          << ": " << m_root_minimizer->Precision() << std::endl;
    std::cout << std::setw(25) << std::left << "  ErrorDefinition"    << ": " << m_root_minimizer->ErrorDef() << " (1-chi2, 0.5 likelihood)" << std::endl;
    std::cout << std::setw(25) << std::left << "  ExtraOptions"       << ": " << opt.ExtraOptions() << std::endl;
}



