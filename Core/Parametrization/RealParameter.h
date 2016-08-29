// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Parametrization/RealParameter.h
//! @brief     Defines class RealParameter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef REALPARAMETER_H
#define REALPARAMETER_H

#include "IParameter.h"
#include "Attributes.h"
#include "RealLimits.h"
#include "Unit.h"
#include <string>

class ParameterPool;

//! Wrapper to real parameter for remote access to its value and callback abilities
//! @class RealParameter
//! @ingroup tools_internal

class BA_CORE_API_ RealParameter : public IParameter<double> {
public:
    RealParameter() =delete;
    RealParameter(
        const std::string& name, ParameterPool* parent,
        volatile double* par, const RealLimits& limits=RealLimits::limitless(),
        const Attributes& attr=Attributes::free());
    RealParameter(const RealParameter& other);
    RealParameter(const std::string& name, const RealParameter& other);

    RealParameter* clone( const std::string& new_name="" ) const;

    //! Sets value of wrapped parameter and emit signal
    void setValue(double value);

    //! Returns value of wrapped parameter
    double getValue() const { return *m_data; }

    RealParameter& setLimits(const RealLimits& limits) { m_limits = limits; return *this; }
    RealLimits getLimits() const { return m_limits; }

    RealParameter& setLimited(double lower, double upper);
    RealParameter& setPositive();
    RealParameter& setNonnegative();

    bool operator==(const RealParameter& other) const {
        return (m_limits == other.m_limits) &&
        *static_cast<const IParameter*>(this)==*static_cast<const IParameter*>(&other); }

    RealParameter& setUnit(const std::string& name) { m_unit.setUnit(name); return *this; }
    std::string unit() const { return m_unit.getName(); }

protected:
    Unit m_unit;
    RealLimits m_limits;
    Attributes m_attr;
};

#endif // REALPARAMETER_H
