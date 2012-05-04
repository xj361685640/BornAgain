#include "MathFunctions.h"

#include <cmath>
#include <stdexcept>
#include <fftw3.h>


double MathFunctions::Gaussian(double value, double average, double std_dev)
{
    return StandardNormal((value-average)/std_dev)/std_dev;
}

double MathFunctions::StandardNormal(double value)
{
    return std::exp(- value*value / 2.0) / std::sqrt(2.0*M_PI);
}

double MathFunctions::GenerateStandardNormalRandom()  // using Box-Muller transform
{
    double u1 = GenerateUniformRandom();
    double u2 = GenerateUniformRandom();
    return std::sqrt(-2.0*std::log(u1))*std::cos(2*M_PI*u2);
}


/* ************************************************************************* */
// simple (and unoptimized) wrapper function for the discrete fast fourier
// transformation library (fftw3)
/* ************************************************************************* */
std::vector<complex_t > MathFunctions::FastFourierTransform(const std::vector<complex_t > &data, MathFunctions::TransformCase ftCase)
{
    double scale(1.);
    size_t npx = data.size();

    fftw_complex *ftData = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * npx);
    fftw_complex *ftResult = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * npx);
    memset(ftData, 0, sizeof(fftw_complex) * npx);
    memset(ftResult, 0, sizeof(fftw_complex) * npx);

    for(size_t i=0; i<npx; i++){
        ftData[i][0] = data[i].real();
        ftData[i][1] = data[i].imag();
    }

    fftw_plan plan;
    switch (ftCase)
    {
        case MathFunctions::ForwardFFT:
            plan = fftw_plan_dft_1d( npx, ftData, ftResult, FFTW_FORWARD, FFTW_ESTIMATE );
            break;
        case MathFunctions::BackwardFFT:
            plan = fftw_plan_dft_1d( npx, ftData, ftResult, FFTW_BACKWARD, FFTW_ESTIMATE );
            scale = 1./double(npx);
            break;
        default:
            throw std::runtime_error("MathFunctions::FastFourierTransform -> Panic! Unknown transform case.");
    }

    fftw_execute(plan);

    // saving data for user
    std::vector<complex_t > outData;
    outData.resize(npx);
    for(size_t i=0; i<npx; i++){
        outData[i] = scale*complex_t(ftResult[i][0], ftResult[i][1]);
    }

    fftw_destroy_plan(plan);
    fftw_free(ftData);
    fftw_free(ftResult);

    return outData;
}


/* ************************************************************************* */
// simple (and unoptimized) wrapper function for the discrete fast fourier
// transformation library (fftw3)
//
// transforms real to complex
/* ************************************************************************* */
std::vector<complex_t > MathFunctions::FastFourierTransform(const std::vector<double > &data, MathFunctions::TransformCase ftCase)
{
    std::vector<complex_t> cdata;
    cdata.resize(data.size());
    for(size_t i=0; i<data.size(); i++) { cdata[i] = complex_t(data[i], 0); }
    return MathFunctions::FastFourierTransform(cdata, ftCase);
}

