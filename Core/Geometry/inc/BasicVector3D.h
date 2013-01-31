// -*- C++ -*-
// $Id: BasicVector3D.h,v 1.5 2010/06/16 16:21:27 garren Exp $
// ---------------------------------------------------------------------------
//
// This file is a part of the CLHEP - a Class Library for High Energy Physics.
//
// History:
// 12.06.01 E.Chernyaev - CLHEP-1.7: initial  version
// 14.03.03 E.Chernyaev - CLHEP-1.9: template version
//

#ifndef GEOMETRY_BASICVECTOR3D_H
#define GEOMETRY_BASICVECTOR3D_H

//#include <iosfwd>
//#include "CLHEP/Geometry/defs.h"
//#include "CLHEP/Vector/ThreeVector.h"
#include <cmath>
//#include <iostream>
#include <complex>
#include "Exceptions.h"

namespace Geometry {
class Transform3D;


  /**
   * Base class for Point3D<T>, Vector3D<T> and Normal3D<T>.
   * It defines only common functionality for those classes and
   * should not be used as separate class.
   *
   * @author Evgeni Chernyaev <Evgueni.Tcherniaev@cern.ch>
   * @ingroup geometry
   */
  template<class T> class BasicVector3D {
  protected:
    T v_[3];

  public:
    /**
     * Default constructor.
     * It is protected - this class should not be instantiated directly.
     */
    BasicVector3D() { v_[0] = 0.0; v_[1] = 0.0; v_[2] = 0.0; }

    /**
     * Safe indexing of the coordinates when using with matrices, arrays, etc.
     */
    enum {
      X = 0,                 /**< index for x-component */
      Y = 1,                 /**< index for y-component */
      Z = 2,                 /**< index for z-component */
      NUM_COORDINATES = 3,   /**< number of components  */
      SIZE = NUM_COORDINATES /**< number of components  */
    };

    /**
     * Constructor from three numbers. */
    BasicVector3D(const T &x1, const T &y1, const T &z1) { v_[0] = x1; v_[1] = y1; v_[2] = z1; }

//    /**
//     * Copy constructor.
//     * Note: BasicVector3D<double> has constructors
//     * from BasicVector3D<double> (provided by compiler) and
//     * from BasicVector3D<float> (defined in this file);
//     * BasicVector3D<float> has only the last one.
//     */
//    BasicVector3D(const BasicVector3D<float> & v) {
//      v_[0] = v.x(); v_[1] = v.y(); v_[2] = v.z();
//    }

    /**
     * Destructor. */
    virtual ~BasicVector3D() {}

    // -------------------------
    // Interface to "good old C"
    // -------------------------

//    /**
//     * Conversion (cast) to ordinary array. */
//    operator T * () { return v_; }

//    /**
//     * Conversion (cast) to ordinary const array. */
//    operator const T * () const { return v_; }

//    /**
//     * Conversion (cast) to CLHEP::Hep3Vector.
//     * This operator is needed only for backward compatibility and
//     * in principle should not exit.
//     */
//    operator CLHEP::Hep3Vector () const { return CLHEP::Hep3Vector(x(),y(),z()); }

    // -----------------------------
    // General arithmetic operations
    // -----------------------------

    /**
     * Assignment. */
    inline BasicVector3D<T> & operator= (const BasicVector3D<T> & v) {
      v_[0] = v.v_[0]; v_[1] = v.v_[1]; v_[2] = v.v_[2]; return *this;
    }
    /**
     * Addition. */
    inline BasicVector3D<T> & operator+=(const BasicVector3D<T> & v) {
      v_[0] += v.v_[0]; v_[1] += v.v_[1]; v_[2] += v.v_[2]; return *this;
    }
    /**
     * Subtraction. */
    inline BasicVector3D<T> & operator-=(const BasicVector3D<T> & v) {
      v_[0] -= v.v_[0]; v_[1] -= v.v_[1]; v_[2] -= v.v_[2]; return *this;
    }
    /**
     * Multiplication by scalar. */
    inline BasicVector3D<T> & operator*=(double a) {
      v_[0] *= a; v_[1] *= a; v_[2] *= a; return *this;
    }
    /**
     * Division by scalar. */
    inline BasicVector3D<T> & operator/=(double a) {
      v_[0] /= a; v_[1] /= a; v_[2] /= a; return *this;
    }

    // ------------
    // Subscripting
    // ------------

//    /**
//     * Gets components by index. */
//    T operator()(int i) const { return v_[i]; }
    /**
     * Gets components by index. */
    inline T operator[](int i) const { return v_[i]; }

//    /**
//     * Sets components by index. */
//    T & operator()(int i) { return v_[i]; }
    /**
     * Sets components by index. */
    inline T & operator[](int i) { return v_[i]; }

    // ------------------------------------
    // Cartesian coordinate system: x, y, z
    // ------------------------------------

    /**
     * Gets x-component in cartesian coordinate system. */
    inline T x() const { return v_[0]; }
    /**
     * Gets y-component in cartesian coordinate system. */
    inline T y() const { return v_[1]; }
    /**
     * Gets z-component in cartesian coordinate system. */
    inline T z() const { return v_[2]; }

    /**
     * Sets x-component in cartesian coordinate system. */
    inline void setX(const T &a) { v_[0] = a; }
    /**
     * Sets y-component in cartesian coordinate system. */
    inline void setY(const T &a) { v_[1] = a; }
    /**
     * Sets z-component in cartesian coordinate system. */
    inline void setZ(const T &a) { v_[2] = a; }

    /**
     * Sets components in cartesian coordinate system.  */
//    inline void set(const T &x1, const T &y1, const T &z1) { v_[0] = x1; v_[1] = y1; v_[2] = z1; }
    inline void setXYZ(const T &x1, const T &y1, const T &z1) { v_[0] = x1; v_[1] = y1; v_[2] = z1; }

    // ------------------------------------------
    // Cylindrical coordinate system: rho, phi, z
    // ------------------------------------------

    /**
     * Gets transverse component squared. */
//    inline T perp2() const { return x()*x()+y()*y(); }
    /**
     * Gets transverse component. */
//    inline T perp() const { return std::sqrt(perp2()); }
    /**
     * Gets rho-component in cylindrical coordinate system */
    //inline T rho() const { return perp(); }
    inline T rho() const { return magxy(); }

    /**
     * Gets rho-component in cylindrical coordinate system */
    inline T magxy2() const { return x()*x()+y()*y(); }

    inline T magxy() const { return std::sqrt(magxy2()); }

    /**
     * Sets transverse component keeping phi and z constant. */
//    inline void setPerp(T rh) {
//      T factor = perp();
//      if (factor > 0.0) {
//	factor = rh/factor; v_[0] *= factor; v_[1] *= factor;
//      }
//    }

    // ------------------------------------------
    // Spherical coordinate system: r, phi, theta
    // ------------------------------------------

    /**
     * Gets magnitude squared of the vector. */
    inline T mag2() const { return x()*x()+y()*y()+z()*z(); }
    /**
     * Gets magnitude of the vector. */
    inline T mag() const { return std::sqrt(mag2()); }
    /**
     * Gets r-component in spherical coordinate system */
    inline T r() const { return mag(); }
    /**
     * Gets azimuth angle. */
    inline T phi() const {
      return x() == 0.0 && y() == 0.0 ? 0.0 : std::atan2(y(),x());
    }
    /**
     * Gets polar angle. */
    inline T theta() const {
      return x() == 0.0 && y() == 0.0 && z() == 0.0 ? 0.0 : std::atan2(magxy(),z());
    }
    /**
     * Gets cosine of polar angle. */
    inline T cosTheta() const { T ma = mag(); return std::abs(ma) == 0 ? 1 : z()/ma; }
    /**
     * Gets r-component in spherical coordinate system */
    //inline T getR() const { return r(); }
    /**
     * Gets phi-component in spherical coordinate system */
    //inline T getPhi() const { return phi(); }
    /**
     * Gets theta-component in spherical coordinate system */
    //inline T getTheta() const { return theta(); }

    /**
     * Sets magnitude. */
    inline void setMag(T ma) {
      T factor = mag();
      if (factor > 0.0) {
	factor = ma/factor; v_[0] *= factor; v_[1] *= factor; v_[2] *= factor;
      }
    }
    /**
     * Sets r-component in spherical coordinate system. */
    inline void setR(T ma) { setMag(ma); }
    /**
     * Sets phi-component in spherical coordinate system. */
    //inline void setPhi(T ph) { T xy = perp(); setX(xy*std::cos(ph)); setY(xy*std::sin(ph)); }
    inline void setPhi(T ph) { T xy = magxy(); setX(xy*std::cos(ph)); setY(xy*std::sin(ph)); }
    /**
     * Sets theta-component in spherical coordinate system. */
    inline void setTheta(T th) {
      T ma = mag();
      T ph = phi();
      setXYZ(ma*std::sin(th)*std::cos(ph), ma*std::sin(th)*std::sin(ph), ma*std::cos(th));
    }

    // ---------------
    // Pseudo rapidity
    // ---------------

//    /**
//     * Gets pseudo-rapidity: -ln(std::tan(theta/2)) */
//    T pseudoRapidity() const;
//    /**
//     * Gets pseudo-rapidity. */
//    T eta() const { return pseudoRapidity(); }
//    /**
//     * Gets pseudo-rapidity. */
//    T getEta() const { return pseudoRapidity(); }

//    /**
//     * Sets pseudo-rapidity, keeping magnitude and phi fixed. */
//    void setEta(T a);

    // -------------------
    // Combine two vectors
    // -------------------

    /**
     * Scalar product. */
    inline T dot(const BasicVector3D<T> & v) const {
      return x()*v.x()+y()*v.y()+z()*v.z();
    }

    /**
     * Vector product. */
    inline BasicVector3D<T> cross(const BasicVector3D<T> & v) const {
      return BasicVector3D<T>(y()*v.z()-v.y()*z(),
			      z()*v.x()-v.z()*x(),
			      x()*v.y()-v.x()*y());
    }

    /**
     * Returns transverse component w.r.t. given axis squared. */
    inline T perp2(const BasicVector3D<T> & v) const {
      T tot = v.mag2(), s = dot(v);
      return tot > 0.0 ? mag2()-s*s/tot : mag2();
    }

    /**
     * Returns transverse component w.r.t. given axis. */
    inline T perp(const BasicVector3D<T> & v) const {
      return std::sqrt(perp2(v));
    }

    /**
     * Returns angle w.r.t. another vector. */
    T angle(const BasicVector3D<T> & v) const;

    // ---------------
    // Related vectors
    // ---------------

    /**
     * Returns unit vector parallel to this. */
    inline BasicVector3D<T> unit() const {
      T len = mag();
      return (len > 0.0) ?
	BasicVector3D<T>(x()/len, y()/len, z()/len) : BasicVector3D<T>();
    }

    /**
     * Returns orthogonal vector. */
    BasicVector3D<T> orthogonal() const {
      T dx = x() < 0.0 ? -x() : x();
      T dy = y() < 0.0 ? -y() : y();
      T dz = z() < 0.0 ? -z() : z();
      if (dx < dy) {
        return dx < dz ?
        BasicVector3D<T>(0.0,z(),-y()) : BasicVector3D<T>(y(),-x(),0.0);
      }else{
        return dy < dz ?
        BasicVector3D<T>(-z(),0.0,x()) : BasicVector3D<T>(y(),-x(),0.0);
      }
    }

    // ---------
    // Rotations
    // ---------

    /**
     * Rotates around x-axis. */
    BasicVector3D<T> & rotateX(T a);
    /**
     * Rotates around y-axis. */
    BasicVector3D<T> & rotateY(T a);
    /**
     * Rotates around z-axis. */
    BasicVector3D<T> & rotateZ(T a);
    /**
     * Rotates around the axis specified by another vector. */
    BasicVector3D<T> & rotate(T a, const BasicVector3D<T> & v);

    // ---------
    // Specific
    // ---------

    inline void setLambdaAlphaPhi(const T &_lambda, const T &_alpha, const T &_phi)
    {
        T k = 2.*M_PI/_lambda;
        v_[0] = k*std::cos(_alpha) * std::cos(_phi);
        v_[1] = k*std::cos(_alpha) * std::sin(_phi);
        v_[2] = k*std::sin(_alpha);
     }

    /**
     * Transformation by Transform3D. */
    BasicVector3D<T> &transform(const Transform3D &m);

  };


  /*************************************************************************
   *                                                                       *
   * Non-member functions for BasicVector3D<double>                        *
   *                                                                       *
   *************************************************************************/

  /**
   * Output to stream.
   * @relates BasicVector3D
   */
  std::ostream &
  operator<<(std::ostream &, const BasicVector3D<double> &);

//  /**
//   * Input from stream.
//   * @relates BasicVector3D
//   */
//  std::istream &
//  operator>>(std::istream &, BasicVector3D<double> &);

  /**
   * Unary plus.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator+(const BasicVector3D<double> & v) { return v; }

  /**
   * Addition of two vectors.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator+(const BasicVector3D<double> & a,const BasicVector3D<double> & b) {
    return BasicVector3D<double>(a.x()+b.x(), a.y()+b.y(), a.z()+b.z());
  }

  /**
   * Unary minus.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator-(const BasicVector3D<double> & v) {
    return BasicVector3D<double>(-v.x(), -v.y(), -v.z());
  }

  /**
   * Subtraction of two vectors.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator-(const BasicVector3D<double> & a,const BasicVector3D<double> & b) {
    return BasicVector3D<double>(a.x()-b.x(), a.y()-b.y(), a.z()-b.z());
  }

  /**
   * Multiplication vector by scalar.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator*(const BasicVector3D<double> & v, double a) {
    return BasicVector3D<double>(v.x()*a, v.y()*a, v.z()*a);
  }

  /**
   * Scalar product of two vectors.
   * @relates BasicVector3D
   */
  inline double
  operator*(const BasicVector3D<double> & a,const BasicVector3D<double> & b) {
    return a.dot(b);
  }

  /**
   * Multiplication scalar by vector.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator*(double a, const BasicVector3D<double> & v) {
    return BasicVector3D<double>(a*v.x(), a*v.y(), a*v.z());
  }

  /**
   * Division vector by scalar.
   * @relates BasicVector3D
   */
  inline BasicVector3D<double>
  operator/(const BasicVector3D<double> & v, double a) {
    return BasicVector3D<double>(v.x()/a, v.y()/a, v.z()/a);
  }

  /**
   * Comparison of two vectors for equality.
   * @relates BasicVector3D
   */
  inline bool
  operator==(const BasicVector3D<double> & a, const BasicVector3D<double> & b)
  {
    return (a.x()==b.x() && a.y()==b.y() && a.z()==b.z());
  }

  /**
   * Comparison of two vectors for inequality.
   * @relates BasicVector3D
   */
  inline bool
  operator!=(const BasicVector3D<double> & a, const BasicVector3D<double> & b)
  {
    return (a.x()!=b.x() || a.y()!=b.y() || a.z()!=b.z());
  }

  inline BasicVector3D<double> CrossProduct(const BasicVector3D<double> &vectorLeft, const BasicVector3D<double> &vectorRight)
  {
      double x = vectorLeft.y()*vectorRight.z() - vectorLeft.z()*vectorRight.y();
      double y = vectorLeft.z()*vectorRight.x() - vectorLeft.x()*vectorRight.z();
      double z = vectorLeft.x()*vectorRight.y() - vectorLeft.y()*vectorRight.x();
      return BasicVector3D<double> (x, y, z);
  }

  inline double DotProduct(const BasicVector3D<double> &left, const BasicVector3D<double> &right)
  {
      return left.x()*right.x() + left.y()*right.y() + left.z()*right.z();
  }

  /**
   * Transformation of BasicVector3D<double> by Transform3D.
   */
  BasicVector3D<double>
  operator*(const Transform3D & m, const BasicVector3D<double> & v);

//  template<>
//  BasicVector3D<std::complex<double> > BasicVector3D<std::complex<double> >::orthogonal() const {
//      throw NotImplementedException("Not implemented in BasicVector3D<std::complex<double> > BasicVector3D<std::complex<double> >::orthogonal()");
//      return BasicVector3D<std::complex<double> >(0.0,0.0,0.0);
//  }

//  template<>
//  inline BasicVector3D<std::complex<double> > BasicVector3D<std::complex<double> >::unit() const {
//      throw NotImplementedException("Not implemented in BasicVector3D<std::complex<double> > BasicVector3D<std::complex<double> >::orthogonal()");
//      return BasicVector3D<std::complex<double> >(0.0,0.0,0.0);
//  }

//  template<>
//  inline std::complex<double> BasicVector3D<std::complex<double> >::perp2(const BasicVector3D<std::complex<double> > & v) const {
//      throw NotImplementedException("Not implemented in BasicVector3D<std::complex<double> > BasicVector3D<std::complex<double> >::orthogonal()");
//    return 0.0;
//  }

  /*************************************************************************
   *                                                                       *
   * Non-member functions for BasicVector3D<std::complex<double> >                        *
   *                                                                       *
   *************************************************************************/

  /**
   * Output to stream.
   * @relates BasicVector3D
   */
  std::ostream &
  operator<<(std::ostream &, const BasicVector3D<std::complex<double> > &);

//  /**
//   * Input from stream.
//   * @relates BasicVector3D
//   */
//  std::istream &
//  operator>>(std::istream &, BasicVector3D<double> &);

  /**
   * Unary plus.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator+(const BasicVector3D<std::complex<double> > & v) { return v; }

  /**
   * Addition of two vectors.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator+(const BasicVector3D<std::complex<double> > & a,const BasicVector3D<std::complex<double> > & b) {
    return BasicVector3D<std::complex<double> >(a.x()+b.x(), a.y()+b.y(), a.z()+b.z());
  }

  /**
   * Unary minus.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator-(const BasicVector3D<std::complex<double> > & v) {
    return BasicVector3D<std::complex<double> >(-v.x(), -v.y(), -v.z());
  }

  /**
   * Subtraction of two vectors.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator-(const BasicVector3D<std::complex<double> > & a,const BasicVector3D<std::complex<double> > & b) {
    return BasicVector3D<std::complex<double> >(a.x()-b.x(), a.y()-b.y(), a.z()-b.z());
  }

  /**
   * Multiplication vector by scalar.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator*(const BasicVector3D<const std::complex<double> > & v, const std::complex<double> &a) {
    return BasicVector3D<std::complex<double> >(v.x()*a, v.y()*a, v.z()*a);
  }

  /**
   * Scalar product of two vectors.
   * @relates BasicVector3D
   */
  inline std::complex<double>
  operator*(const BasicVector3D<std::complex<double> > & a,const BasicVector3D<std::complex<double> > & b) {
    return a.dot(b);
  }

  /**
   * Multiplication scalar by vector.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator*(const std::complex<double>  &a, const BasicVector3D<std::complex<double> > & v) {
    return BasicVector3D<std::complex<double> >(a*v.x(), a*v.y(), a*v.z());
  }

  /**
   * Division vector by scalar.
   * @relates BasicVector3D
   */
  inline BasicVector3D<std::complex<double> >
  operator/(const BasicVector3D<std::complex<double> > & v, const std::complex<double> &a) {
    return BasicVector3D<std::complex<double> >(v.x()/a, v.y()/a, v.z()/a);
  }

  /**
   * Comparison of two vectors for equality.
   * @relates BasicVector3D
   */
  inline bool
  operator==(const BasicVector3D<std::complex<double> > & a, const BasicVector3D<std::complex<double> > & b)
  {
    return (a.x()==b.x() && a.y()==b.y() && a.z()==b.z());
  }

  /**
   * Comparison of two vectors for inequality.
   * @relates BasicVector3D
   */
  inline bool
  operator!=(const BasicVector3D<std::complex<double> > & a, const BasicVector3D<std::complex<double> > & b)
  {
    return (a.x()!=b.x() || a.y()!=b.y() || a.z()!=b.z());
  }

  inline BasicVector3D<std::complex<double> > CrossProduct(const BasicVector3D<std::complex<double> > &vectorLeft, const BasicVector3D<std::complex<double> > &vectorRight)
  {
      std::complex<double> x = vectorLeft.y()*vectorRight.z() - vectorLeft.z()*vectorRight.y();
      std::complex<double> y = vectorLeft.z()*vectorRight.x() - vectorLeft.x()*vectorRight.z();
      std::complex<double> z = vectorLeft.x()*vectorRight.y() - vectorLeft.y()*vectorRight.x();
      return BasicVector3D<std::complex<double> > (x, y, z);
  }

  inline std::complex<double> DotProduct(const BasicVector3D<std::complex<double> > &left, const BasicVector3D<std::complex<double> > &right)
  {
      return left.x()*right.x() + left.y()*right.y() + left.z()*right.z();
  }

  /**
   * Transformation of BasicVector3D<double> by Transform3D.
   */
  BasicVector3D<std::complex<double> >
  operator*(const Transform3D & m, const BasicVector3D<std::complex<double> > & v);


} /* namespace Geometry */


#endif /* GEOMETRY_BASICVECTOR3D_H */
