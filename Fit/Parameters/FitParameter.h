// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Fit/Parameters/FitParameter.h
//! @brief     Defines class FitParameter.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FITPARAMETER_H
#define FITPARAMETER_H

#include "Attributes.h"
#include "RealLimits.h"
#include <string>

//! Fittable parameter with value, error, step, limits, and fixed flag.
//! @ingroup fitting_internal

class BA_CORE_API_ FitParameter : public RealLimits, public Attributes
{
 public:
    FitParameter();
    FitParameter(
        const std::string& name, double value, double step=0.0,
        const RealLimits& limits=RealLimits::limitless(), const Attributes& attr=Attributes::free(),
        double error=0.0);
    virtual ~FitParameter() {}

    std::string getName() const { return m_name; }

    virtual double getStartValue() const { return m_start_value; }

    virtual void setValue(double value) { m_value = value; }
    double getValue() const { return m_value; }

    void setStep(double value) { m_step = value; }
    double getStep() const { return m_step; }

    void setError(double value) { m_error = value; }
    double getError() const { return m_error; }

    //! Prints class
    friend std::ostream& operator<<(std::ostream& ostr, const FitParameter& m) {
        m.print(ostr); return ostr; }

    std::string limitsToString() const;

 protected:
    void print(std::ostream& ostr) const;

    std::string m_name;
    double m_start_value;
    double m_value;
    double m_step;
    double m_error;
};

#endif // FITPARAMETER_H
