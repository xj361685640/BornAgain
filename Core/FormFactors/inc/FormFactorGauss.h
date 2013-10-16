// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/inc/FormFactorGauss.h
//! @brief     Defines class FormFactorGauss.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef FORMFACTORGAUSS_H_
#define FORMFACTORGAUSS_H_

#include "IFormFactorBorn.h"
#include "IStochasticParameter.h"

//! ?

class BA_CORE_API_ FormFactorGauss : public IFormFactorBorn
{
public:
    FormFactorGauss(double volume);
    FormFactorGauss(double height, double width);
    ~FormFactorGauss() {}
    virtual FormFactorGauss *clone() const;

    virtual void accept(ISampleVisitor *visitor) const { visitor->visit(this); }

    virtual int getNumberOfStochasticParameters() const { return 2; }

    virtual complex_t evaluate_for_q(const cvector_t& q) const;

    virtual double getVolume() const {
        return m_width*m_width*m_height;
    }

protected:
    //! Registers some class members for later access via parameter pool
    virtual void init_parameters();

    //! determine if a large bin size approximation should be used
    virtual bool useLargeBinApproximation(const Bin1DCVector& q_bin) const;
private:
    double m_height;
    double m_width;
    double m_max_ql;
};

#endif /* FORMFACTORGAUSS_H_ */


