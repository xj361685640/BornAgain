/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.2
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef SWIG_libBornAgainCore_WRAP_H_
#define SWIG_libBornAgainCore_WRAP_H_

#include <map>
#include <string>


class SwigDirector_FitObjective : public FitObjective, public Swig::Director {

public:
    SwigDirector_FitObjective(PyObject *self);
    virtual ~SwigDirector_FitObjective();
    virtual double evaluate(Fit::Parameters const &params);
    virtual std::vector< double, std::allocator< double > > evaluate_residuals(Fit::Parameters const &params);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class FitObjective doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[2];
#endif

};


class SwigDirector_IParameterized : public IParameterized, public Swig::Director {

public:
    SwigDirector_IParameterized(PyObject *self, std::string const &name = "");
    SwigDirector_IParameterized(PyObject *self, IParameterized const &other);
    virtual ~SwigDirector_IParameterized();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IParameterized doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[2];
#endif

};


class SwigDirector_INode : public INode, public Swig::Director {

public:
    SwigDirector_INode(PyObject *self);
    SwigDirector_INode(PyObject *self, NodeMeta const &meta, std::vector< double, std::allocator< double > > const &PValues);
    virtual ~SwigDirector_INode();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual void accept(INodeVisitor *visitor) const;
    virtual std::string treeToString() const;
    virtual std::vector< INode const *, std::allocator< INode const * > > getChildren() const;
    virtual void setParent(INode const *newParent);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class INode doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[6];
#endif

};


class SwigDirector_ISample : public ISample, public Swig::Director {

public:
    SwigDirector_ISample(PyObject *self);
    SwigDirector_ISample(PyObject *self, NodeMeta const &meta, std::vector< double, std::allocator< double > > const &PValues);
    virtual ~SwigDirector_ISample();
    virtual ISample *clone() const;
    virtual void transferToCPP();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual void accept(INodeVisitor *visitor) const;
    virtual std::string treeToString() const;
    virtual std::vector< INode const *, std::allocator< INode const * > > getChildren() const;
    virtual void setParent(INode const *newParent);
    virtual Material const *material() const;

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class ISample doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[9];
#endif

};


class SwigDirector_IFormFactor : public IFormFactor, public Swig::Director {

public:
    SwigDirector_IFormFactor(PyObject *self);
    SwigDirector_IFormFactor(PyObject *self, NodeMeta const &meta, std::vector< double, std::allocator< double > > const &PValues);
    virtual ~SwigDirector_IFormFactor();
    virtual IFormFactor *clone() const;
    virtual void transferToCPP();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual void accept(INodeVisitor *visitor) const;
    virtual std::string treeToString() const;
    virtual std::vector< INode const *, std::allocator< INode const * > > getChildren() const;
    virtual void setParent(INode const *newParent);
    virtual Material const *material() const;
    virtual void setAmbientMaterial(Material arg0);
    virtual complex_t evaluate(WavevectorInfo const &wavevectors) const;
    virtual double volume() const;
    virtual double radialExtension() const;
    virtual double bottomZ(IRotation const &rotation) const;
    virtual double topZ(IRotation const &rotation) const;
    virtual bool canSliceAnalytically(IRotation const &rot) const;
    virtual bool canSliceAnalyticallySwigPublic(IRotation const &rot) const {
      return IFormFactor::canSliceAnalytically(rot);
    }
    virtual IFormFactor *sliceFormFactor(ZLimits limits, IRotation const &rot, kvector_t translation) const;
    virtual IFormFactor *sliceFormFactorSwigPublic(ZLimits limits, IRotation const &rot, kvector_t translation) const {
      return IFormFactor::sliceFormFactor(limits,rot,translation);
    }

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IFormFactor doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[17];
#endif

};


class SwigDirector_IFormFactorBorn : public IFormFactorBorn, public Swig::Director {

public:
    SwigDirector_IFormFactorBorn(PyObject *self);
    SwigDirector_IFormFactorBorn(PyObject *self, NodeMeta const &meta, std::vector< double, std::allocator< double > > const &PValues);
    virtual ~SwigDirector_IFormFactorBorn();
    virtual IFormFactorBorn *clone() const;
    virtual void transferToCPP();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual void accept(INodeVisitor *visitor) const;
    virtual std::string treeToString() const;
    virtual std::vector< INode const *, std::allocator< INode const * > > getChildren() const;
    virtual void setParent(INode const *newParent);
    virtual Material const *material() const;
    virtual void setAmbientMaterial(Material arg0);
    virtual complex_t evaluate(WavevectorInfo const &wavevectors) const;
    virtual double volume() const;
    virtual double radialExtension() const;
    virtual double bottomZ(IRotation const &rotation) const;
    virtual double topZ(IRotation const &rotation) const;
    virtual bool canSliceAnalytically(IRotation const &rot) const;
    virtual bool canSliceAnalyticallySwigPublic(IRotation const &rot) const {
      return IFormFactorBorn::canSliceAnalytically(rot);
    }
    virtual IFormFactor *sliceFormFactor(ZLimits limits, IRotation const &rot, kvector_t translation) const;
    virtual IFormFactor *sliceFormFactorSwigPublic(ZLimits limits, IRotation const &rot, kvector_t translation) const {
      return IFormFactor::sliceFormFactor(limits,rot,translation);
    }
    virtual complex_t evaluate_for_q(cvector_t q) const;

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IFormFactorBorn doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[18];
#endif

};


class SwigDirector_PyBuilderCallback : public PyBuilderCallback, public Swig::Director {

public:
    SwigDirector_PyBuilderCallback(PyObject *self);
    virtual ~SwigDirector_PyBuilderCallback();
    virtual Simulation *build_simulation(Fit::Parameters arg0);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class PyBuilderCallback doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[1];
#endif

};


class SwigDirector_PyObserverCallback : public PyObserverCallback, public Swig::Director {

public:
    SwigDirector_PyObserverCallback(PyObject *self);
    virtual ~SwigDirector_PyObserverCallback();
    virtual void update(FitObjective const &arg0);

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class PyObserverCallback doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[1];
#endif

};


class SwigDirector_IInterferenceFunction : public IInterferenceFunction, public Swig::Director {

public:
    SwigDirector_IInterferenceFunction(PyObject *self, NodeMeta const &meta, std::vector< double, std::allocator< double > > const &PValues);
    SwigDirector_IInterferenceFunction(PyObject *self, double position_var);
    virtual ~SwigDirector_IInterferenceFunction();
    virtual IInterferenceFunction *clone() const;
    virtual void transferToCPP();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual void accept(INodeVisitor *visitor) const;
    virtual std::string treeToString() const;
    virtual std::vector< INode const *, std::allocator< INode const * > > getChildren() const;
    virtual void setParent(INode const *newParent);
    virtual Material const *material() const;
    virtual double evaluate(kvector_t const q, double outer_iff = 1.0) const;
    virtual double getParticleDensity() const;
    virtual bool supportsMultilayer() const;
    virtual double iff_without_dw(kvector_t const q) const;

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IInterferenceFunction doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[14];
#endif

};


class SwigDirector_IMultiLayerBuilder : public IMultiLayerBuilder, public Swig::Director {

public:
    SwigDirector_IMultiLayerBuilder(PyObject *self);
    virtual ~SwigDirector_IMultiLayerBuilder();
    virtual ParameterPool *createParameterTree() const;
    virtual void onChange();
    virtual MultiLayer *buildSample() const;
    virtual MultiLayer *createSample(size_t index);
    virtual size_t size();

/* Internal director utilities */
public:
    bool swig_get_inner(const char *swig_protected_method_name) const {
      std::map<std::string, bool>::const_iterator iv = swig_inner.find(swig_protected_method_name);
      return (iv != swig_inner.end() ? iv->second : false);
    }
    void swig_set_inner(const char *swig_protected_method_name, bool swig_val) const {
      swig_inner[swig_protected_method_name] = swig_val;
    }
private:
    mutable std::map<std::string, bool> swig_inner;

#if defined(SWIG_PYTHON_DIRECTOR_VTABLE)
/* VTable implementation */
    PyObject *swig_get_method(size_t method_index, const char *method_name) const {
      PyObject *method = vtable[method_index];
      if (!method) {
        swig::SwigVar_PyObject name = SWIG_Python_str_FromChar(method_name);
        method = PyObject_GetAttr(swig_get_self(), name);
        if (!method) {
          std::string msg = "Method in class IMultiLayerBuilder doesn't exist, undefined ";
          msg += method_name;
          Swig::DirectorMethodException::raise(msg.c_str());
        }
        vtable[method_index] = method;
      }
      return method;
    }
private:
    mutable swig::SwigVar_PyObject vtable[5];
#endif

};


#endif
