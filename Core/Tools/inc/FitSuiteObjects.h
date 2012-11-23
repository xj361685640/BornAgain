#ifndef FITSUITEOBJECTS_H
#define FITSUITEOBJECTS_H
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   FitSuiteObjects.h
//! @brief  Definition of FitSuiteObjects class
//! @author Scientific Computing Group at FRM II
//! @date   15.11.2012


#include "Experiment.h"
#include "OutputData.h"
#include "FitObject.h"


#include <vector>


//- -------------------------------------------------------------------
//! @class FitSuiteObjects
//! @brief Class containing vector FitObject's (experiment and real data) to fit
//- -------------------------------------------------------------------
class FitSuiteObjects
{
public:
    typedef std::vector<FitObject *> FitObjects_t;

    FitSuiteObjects(){}
    virtual ~FitSuiteObjects(){}

    //! clear all data
    void clear();

    //! return number of items
    size_t size() const { return m_fit_objects.size(); }

    //! add to kit pair of (experiment, real data) for consecutive simulation and chi2 module
    void add(const Experiment &experiment, const OutputData<double > &real_data, const IChiSquaredModule &chi2_module);

    //! loop through all defined experiments and run they simulation
    void runSimulation();

    //! get chi squared value calculated for all pairs of (experiment, real data)
    double getChiSquaredValue();

    //! get experiment
    const Experiment *getExperiment(int i_item = 0) const { return m_fit_objects[check_index(i_item)]->getExperiment(); }

    //! get real data
    const OutputData<double> * getRealData(int i_item = 0) const { return m_fit_objects[check_index(i_item)]->getRealData(); }
    //! set real data
    void setRealData(const OutputData<double > &real_data, int i_item = 0) { m_fit_objects[check_index(i_item)]->setRealData(real_data);}

    //! get chi2 module
    const IChiSquaredModule *getChiSquaredModule(int i_item = 0) const { return m_fit_objects[check_index(i_item)]->getChiSquaredModule(); }
    IChiSquaredModule *getChiSquaredModule(int i_item = 0) { return m_fit_objects[check_index(i_item)]->getChiSquaredModule(); }

    //! get simulated data
    const OutputData<double> * getSimulatedData(int i_item = 0) const { return m_fit_objects[check_index(i_item)]->getSimulatedData(); }

    //! get fit object
    const FitObject *getObject(int i_item = 0) const { return m_fit_objects[check_index(i_item)]; }
    FitObject *getObject(int i_item = 0) { return m_fit_objects[check_index(i_item)]; }
private:
    //! disabled copy constructor and assignment operator
    FitSuiteObjects &operator=(const FitSuiteObjects &);
    FitSuiteObjects(const FitSuiteObjects &);

    //! check if index inside vector bounds
    inline size_t check_index(size_t index) const { return index < m_fit_objects.size() ? index : throw OutOfBoundsException("FitSuiteKit::check() -> Index outside of range"); }

    FitObjects_t m_fit_objects; //  set of experiments and corresponding real data
};




#endif // FITSUITEKIT_H