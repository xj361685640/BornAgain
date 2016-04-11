// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      FormFactors/src/FormFactorCone6.cpp
//! @brief     Implements class FormFactorCone6.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorCone6.h"
#include "BornAgainNamespace.h"

#include <cmath>

using namespace  BornAgain;

FormFactorCone6::FormFactorCone6(double radius, double height, double alpha)
    : FormFactorPolyhedron( polyhedral_faces( radius, height, alpha ), 0. )
{
    setName(FFCone6Type);
    m_radius = radius;
    m_height = height;
    m_alpha = alpha;
    check_initialization();
    init_parameters();
}

FormFactorCone6::~FormFactorCone6()
{
}

std::vector<PolyhedralFace> FormFactorCone6::polyhedral_faces(
    double radius, double height, double alpha)
{
    double a = radius;
    double as = a/2;
    double ac = a*sqrt(3)/2;
    double b = radius - 2*height/sqrt(3)/std::tan(alpha);
    double bs = b/2;
    double bc = b*sqrt(3)/2;

    kvector_t V[12] = {
        // base:
        {  a,   0., 0. },
        {  as,  ac, 0. },
        { -as,  ac, 0. },
        { -a,   0., 0. },
        { -as, -ac, 0. },
        {  as, -ac, 0. },
        // top:
        {  b,   0., height },
        {  bs,  bc, height },
        { -bs,  bc, height },
        { -b,   0., height },
        { -bs, -bc, height },
        {  bs, -bc, height } };
    std::vector<PolyhedralFace> faces;
    faces.push_back( PolyhedralFace( { V[ 5], V[ 4], V[ 3], V[ 2], V[ 1], V[ 0] }, true ) );
    faces.push_back( PolyhedralFace( { V[ 0], V[ 1], V[ 7], V[ 6] } ) );
    faces.push_back( PolyhedralFace( { V[ 1], V[ 2], V[ 8], V[ 7] } ) );
    faces.push_back( PolyhedralFace( { V[ 2], V[ 3], V[ 9], V[ 8] } ) );
    faces.push_back( PolyhedralFace( { V[ 3], V[ 4], V[10], V[ 9] } ) );
    faces.push_back( PolyhedralFace( { V[ 4], V[ 5], V[11], V[10] } ) );
    faces.push_back( PolyhedralFace( { V[ 5], V[ 0], V[ 6], V[11] } ) );
    faces.push_back( PolyhedralFace( { V[ 6], V[ 7], V[ 8], V[ 9], V[10], V[11] }, true ) );

    return faces;
}

bool FormFactorCone6::check_initialization() const
{
    bool result(true);
    if(m_height > m_radius*std::tan(m_alpha)) {
        std::ostringstream ostr;
        ostr << "FormFactorCone6() -> Error in class initialization with parameters";
        ostr << " radius:" << m_radius;
        ostr << " height:" << m_height;
        ostr << " alpha[rad]:" << m_alpha << "\n\n";
        ostr << "Check for 'height <= radius*tan(alpha)' failed.";
        throw Exceptions::ClassInitializationException(ostr.str());
    }
    return result;
}

void FormFactorCone6::init_parameters()
{
    clearParameterPool();
    registerParameter(Radius, &m_radius, AttLimits::n_positive());
    registerParameter(Height, &m_height, AttLimits::n_positive());
    registerParameter(Alpha, &m_alpha, AttLimits::n_positive());
}

FormFactorCone6* FormFactorCone6::clone() const
{
   return new FormFactorCone6(m_radius, m_height, m_alpha);
}

void FormFactorCone6::accept(ISampleVisitor *visitor) const
{
    visitor->visit(this);
}
