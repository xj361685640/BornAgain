#ifndef INTERFERENCEFUNCTION2DLATTICE_H_
#define INTERFERENCEFUNCTION2DLATTICE_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   InterferenceFunction2DLattice.h
//! @brief  Definition of InterferenceFunction2DLattice class
//! @author Scientific Computing Group at FRM II
//! @date   Jan 22, 2013

#include "IInterferenceFunction.h"
#include "Lattice2DIFParameters.h"
#include "FTDistributions.h"

class InterferenceFunction2DLattice : public IInterferenceFunction
{
public:
    InterferenceFunction2DLattice(const Lattice2DIFParameters &lattice_params);
    virtual ~InterferenceFunction2DLattice();

    virtual InterferenceFunction2DLattice *clone() const {
        InterferenceFunction2DLattice *p_clone = new InterferenceFunction2DLattice(m_lattice_params);
        p_clone->setProbabilityDistribution(*mp_pdf);
        return p_clone;
    }

    void setProbabilityDistribution(const IFTDistribution2D &pdf);

    virtual double evaluate(const cvector_t &q) const;
protected:
    //! get interference from a single reciprocal lattice vector
    double interferenceAtOneRecLatticePoint(double qx, double qy) const;

    //! calculate reciprocal coordinates in the principal axis system
    void transformToPrincipalAxes(double qx, double qy, double gamma,
            double delta, double &q_pa_1, double &q_pa_2) const;

    //! calculate qx,qy coordinates of q - qint, where qint is a reciprocal lattice vector
    //! bounding the reciprocal unit cell to which q belongs
    void calculateReciprocalVectorFraction(double qx, double qy,
            double &qx_frac, double &qy_frac) const;

    Lattice2DIFParameters m_lattice_params;
    IFTDistribution2D *mp_pdf;
    static const int nmax = 20; //!< maximum value for qx*Lambdax and qy*lambday
private:
    //! initialize pool parameters, i.e. register some of class members for later access via parameter pool
    virtual void init_parameters();

    //! initialize the x,y coordinates of the a*,b* reciprocal bases
    void initialize_rec_vectors();

    //! initialize factors needed in each calculation
    void initialize_calc_factors();

    double m_asx, m_asy; //!< x,y coordinates of a*
    double m_bsx, m_bsy; //!< x,y coordinates of b*
    int m_n_a, m_n_b; //!< limits for reciprocal lattice sum
    double m_prefactor; //!< fixed prefactor for normalization
    int m_na, m_nb; //!< determines the number of reciprocal lattice points to use
};

#endif /* INTERFERENCEFUNCTION2DLATTICE_H_ */