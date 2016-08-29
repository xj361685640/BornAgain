// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/RealParameter.cpp
//! @brief     Implements class RealParameter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "RealParameter.h"
#include <stdexcept>
#include <sstream>

RealParameter::RealParameter(const std::string& name, ParameterPool* parent,
                             volatile double* par, const RealLimits& limits, const Attributes& attr)
    : IParameter<double>(name, parent, par)
    , m_limits(limits)
    , m_attr(attr)
{
    if(par && !m_limits.isInRange(getValue())) {
        std::ostringstream message;
        message << "Parameter " << fullName() << " has invalid initial value " << getValue()
                << ": out of bounds [" << limits << "]\n";
        throw std::runtime_error(message.str());
    }
}

RealParameter::RealParameter(const RealParameter& other )
    : RealParameter( other.getName(), other.m_parent, other.m_data, other.m_limits )
{
    setUnit(other.unit());
}

//! This constructor takes copies 'other' except for the name.
RealParameter::RealParameter(const std::string& name, const RealParameter& other)
    : RealParameter( name, other.m_parent, other.m_data, other.m_limits )
{
    setUnit(other.unit());
}

RealParameter* RealParameter::clone(const std::string& new_name) const
{
    auto* ret = new RealParameter(
        new_name!="" ? new_name : getName(), m_parent, m_data, m_limits );
    ret->setUnit(unit());
    return ret;
}


void RealParameter::setValue(double value)
{
    if(!m_data)
        throw std::runtime_error(
            "Bug in RealParameter::getValue() -> Attempt to access uninitialised pointer.");
    if(value == *m_data)
        return; // nothing to do
    if(!m_limits.isInRange(value)) {
        std::ostringstream message;
        message << "Parameter " << fullName() << " has invalid value " << getValue()
                << ": out of bounds [" << m_limits << "]\n";
        throw std::runtime_error(message.str());
    }
    if(m_attr.isFixed())
        throw std::runtime_error("Parameter "+fullName()+" is fixed");
    *m_data = value;
    m_parent->onChange();
}

RealParameter& RealParameter::setLimited(double lower, double upper)
{
    setLimits( RealLimits::limited(lower, upper) );
    return *this;
}

RealParameter& RealParameter::setPositive()
{
    setLimits( RealLimits::positive() );
    return *this;
}

RealParameter& RealParameter::setNonnegative()
{
    setLimits( RealLimits::nonnegative() );
    return *this;
}
