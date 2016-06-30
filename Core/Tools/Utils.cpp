// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Tools/Utils.cpp
//! @brief     Implements various stuff in namespace Utils.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Utils.h"
#include "Exceptions.h"

#include <iostream>
#include <iomanip>
#include <boost/regex.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>
#include <string>
#include <thread>
#include <locale>

#include "Macros.h"


#ifdef DEBUG_FPE
#include <fenv.h>
#ifdef Q_OS_MAC
#include "fp_exception_glibc_extension.h"
#endif
#endif

//! Round double numbers in string to given precision.

//! If precision is 6, then 7.2908527770e+03 -> 7.290853e+03.
//! This method is used to compare IsGisaxs and our ASCII files
//! at equal precision.
//!
std::string Utils::String::round_doubles(const std::string& str, int precision)
{
    std::string newline;
    std::istringstream is0(str.c_str());
    double number;
    while( is0 >> number ) {
        std::ostringstream os;
        os << std::scientific << std::setprecision(precision) << number;
        newline += os.str() + std::string("    ");
    }
    return newline;
}

//! Returns true if text matches pattern with wildcards '*' and '?'.

bool Utils::String::MatchPattern(
    const std::string& text, std::string wildcardPattern)
{
    bool caseSensitive(true);

    // escape all regex special characters, except '?' and '*'
    boost::replace_all(wildcardPattern, "\\", "\\\\");
    boost::replace_all(wildcardPattern, "^", "\\^");
    boost::replace_all(wildcardPattern, ".", "\\.");
    boost::replace_all(wildcardPattern, "$", "\\$");
    boost::replace_all(wildcardPattern, "|", "\\|");
    boost::replace_all(wildcardPattern, "(", "\\(");
    boost::replace_all(wildcardPattern, ")", "\\)");
    boost::replace_all(wildcardPattern, "[", "\\[");
    boost::replace_all(wildcardPattern, "]", "\\]");
    boost::replace_all(wildcardPattern, "+", "\\+");
    boost::replace_all(wildcardPattern, "/", "\\/");

    // Convert chars '*?' to their regex equivalents
    boost::replace_all(wildcardPattern, "?", ".");
    boost::replace_all(wildcardPattern, "*", ".*");

    // constructing regexp pattern
    wildcardPattern = "^" + wildcardPattern + "$";
    boost::regex pattern(wildcardPattern,
                         caseSensitive ? boost::regex::normal : boost::regex::icase);

    // applaying match
    return boost::regex_match(text, pattern);
}

//! Split string into vector of string using delimeter.

std::vector<std::string> Utils::String::Split(
    const std::string& text, const std::string& delimeter)
{
    std::vector<std::string> tokens;
    boost::split(tokens, text, boost::is_any_of(delimeter));
    return tokens;
}


void Utils::String::replaceItemsFromString(
    std::string &text, const std::vector<std::string> &items, const std::string &replacement)
{
    for(size_t i=0; i<items.size(); ++i) {
        boost::replace_all(text, items[i], replacement);
    }
}

std::string Utils::String::getScientificDoubleString(double value, size_t precision)
{
    std::ostringstream svalue;
    size_t total_width = precision+5;
    svalue << std::setw(total_width) << std::left << std::scientific << std::setprecision(precision)
           << value;
    return svalue.str();
}


int Utils::System::getThreadHardwareConcurrency()
{
    return std::thread::hardware_concurrency();
}

std::string Utils::System::getCurrentDateAndTime()
{
    using boost::posix_time::ptime;
    using boost::posix_time::second_clock;
    using boost::posix_time::to_simple_string;
    using boost::gregorian::day_clock;

    ptime todayUtc(day_clock::universal_day(), second_clock::universal_time().time_of_day());
    return to_simple_string(todayUtc);
}


//! enables exception throw in the case of NaN, Inf
void Utils::EnableFloatingPointExceptions()
{
#ifdef DEBUG_FPE
#ifndef _WIN32
    std::cout << "Utils::EnableFloatingPointExceptions() -> "
        "Enabling floating point exception debugging\n";
    feenableexcept(FE_DIVBYZERO | FE_INVALID | FE_OVERFLOW);
//    feenableexcept(-1);
#endif // _WIN32
#else
    std::cout << "Utils::EnableFloatingPointExceptions() -> "
        "Can't enable floating point exceptions. Available in debug mode only.\n";
#endif
}