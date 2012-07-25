#ifndef CONVOLUTIONDETECTORRESOLUTION_H_
#define CONVOLUTIONDETECTORRESOLUTION_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   ConvolutionDetectorResolution.h
//! @brief  Definition of
//! @author Scientific Computing Group at FRM II
//! @date   Jul 10, 2012

#include "IDetectorResolution.h"

//- -------------------------------------------------------------------
//! @class ConvolutionDetectorResolution
//! @brief This class applies a 1 or 2 dimensional convolution of the intensity with a resolution function
//!
//! Limitation: this class assumes that the data points are evenly distributed on each axis
//- -------------------------------------------------------------------

class ConvolutionDetectorResolution : public IDetectorResolution
{
public:
    typedef double (*cumulative_DF_1d)(double);
    typedef double (*cumulative_DF_2d)(double, double);
    //! Constructor taking a 1 dimensional resolution function as argument
    ConvolutionDetectorResolution(cumulative_DF_1d res_function_1d);
    //! Constructor taking a 2 dimensional resolution function as argument
    ConvolutionDetectorResolution(cumulative_DF_2d res_function_2d);
    //! Destructor
    virtual ~ConvolutionDetectorResolution();

    //! Apply the encapsulated resolution function to the given intensity map by using a convolution
    virtual void applyDetectorResolution(OutputData<double> *p_intensity_map) const;
private:
    size_t m_dimension;
    cumulative_DF_1d m_res_function_1d;
    cumulative_DF_2d m_res_function_2d;
    void apply1dConvolution(const std::vector<NamedVectorBase *> &axes, OutputData<double> *p_intensity_map) const;
    void apply2dConvolution(const std::vector<NamedVectorBase *> &axes, OutputData<double> *p_intensity_map) const;
    double getIntegratedPDF1d(double x, double step) const;
    double getIntegratedPDF2d(double x, double step_x, double y, double step_y) const;
};


#endif /* CONVOLUTIONDETECTORRESOLUTION_H_ */