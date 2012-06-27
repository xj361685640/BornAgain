#include "TestIsGISAXS10.h"
#include "IsGISAXSTools.h"
#include "Types.h"
#include "Units.h"

#include "TCanvas.h"
#include "TH2.h"
#include "TStyle.h"

#include <cmath>
#include <iostream>
#include <fstream>

TestIsGISAXS10::TestIsGISAXS10()
: m_dwba_ff(new FormFactorCylinder(5*Units::nanometer, 5*Units::nanometer))
, m_interference_function(20.0*Units::nanometer, 7*Units::nanometer, 1e7*Units::nanometer)
{
	complex_t n_substrate(1.0-5e-6, 2e-8);
    m_dwba_ff.setReflectionFunction(new ReflectionFresnelFunctionWrapper(n_substrate));
    m_dwba_ff.setTransmissionFunction(new DoubleToComplexFunctionWrapper(transmission_fresnel));
    mp_intensity_output = new OutputData<double>();
    NamedVector<double> *p_y_axis = new NamedVector<double>(std::string("detector y-axis"));
    initialize_angles_sine(p_y_axis, 0.0, 2.0, 100);
    NamedVector<double> *p_z_axis = new NamedVector<double>(std::string("detector z-axis"));
    initialize_angles_sine(p_z_axis, 0.0, 2.0, 100);
    mp_intensity_output->addAxis(p_y_axis);
    mp_intensity_output->addAxis(p_z_axis);
}

TestIsGISAXS10::~TestIsGISAXS10()
{
	delete mp_intensity_output;
}

void TestIsGISAXS10::execute()
{
    MultiIndex& index = mp_intensity_output->getIndex();
    NamedVector<double> *p_y_axis = dynamic_cast<NamedVector<double>*>(mp_intensity_output->getAxis("detector y-axis"));
    NamedVector<double> *p_z_axis = dynamic_cast<NamedVector<double>*>(mp_intensity_output->getAxis("detector z-axis"));
    double lambda = 1*Units::angstrom;
    double alpha_i = 0.2*M_PI/180.0;
    complex_t n_island(1.0-5e-5, +2e-8);
    double normalizing_factor = std::norm((complex_t(1.0,0.0) - n_island*n_island)*M_PI/lambda/lambda);
    kvector_t k_i;
    k_i.setLambdaAlphaPhi(lambda, -alpha_i, 0.0);
    while (!index.endPassed())
    {
        size_t index_y = index.getCurrentIndexOfAxis("detector y-axis");
        size_t index_z = index.getCurrentIndexOfAxis("detector z-axis");
        double phi_f = M_PI*(*p_y_axis)[index_y]/180.0;
        double alpha_f = M_PI*(*p_z_axis)[index_z]/180.0;
        kvector_t k_f;
        k_f.setLambdaAlphaPhi(lambda, alpha_f, phi_f);
        double intensity = normalizing_factor*std::pow(std::abs(m_dwba_ff.evaluate(k_i, k_f)),2)
          *m_interference_function.evaluate(k_i-k_f);
        mp_intensity_output->currentValue() = intensity;
        ++index;
    }
    draw();
    write();
}

void TestIsGISAXS10::draw()
{
    // creation of 2D histogram from calculated intensities
    TCanvas *c1 = new TCanvas("c1_test_isgisaxs_10", "1D paracrystal islands", 0, 0, 1024, 768);
    (void)c1;

    MultiIndex& index = mp_intensity_output->getIndex();
    index.reset();
    NamedVector<double> *p_y_axis = dynamic_cast<NamedVector<double>*>(mp_intensity_output->getAxis("detector y-axis"));
    NamedVector<double> *p_z_axis = dynamic_cast<NamedVector<double>*>(mp_intensity_output->getAxis("detector z-axis"));
    size_t y_size = p_y_axis->getSize();
    size_t z_size = p_z_axis->getSize();
    double y_start = (*p_y_axis)[0];
    double y_end = (*p_y_axis)[y_size-1];
    double z_start = (*p_z_axis)[0];
    double z_end = (*p_z_axis)[z_size-1];
    TH2D *p_hist2D = new TH2D("p_hist2D", "1D paracrystal islands", y_size, y_start, y_end, z_size, z_start, z_end);
    //p_hist2D->UseCurrentStyle();
    p_hist2D->GetXaxis()->SetTitle("phi_f");
    p_hist2D->GetYaxis()->SetTitle("alpha_f");

    while (!index.endPassed())
    {
        size_t index_y = index.getCurrentIndexOfAxis("detector y-axis");
        size_t index_z = index.getCurrentIndexOfAxis("detector z-axis");
        double x_value = (*p_y_axis)[index_y];
        double y_value = (*p_z_axis)[index_z];
        double z_value = mp_intensity_output->currentValue();
        p_hist2D->Fill(x_value, y_value, z_value);
        ++index;
    }
    p_hist2D->SetContour(50);
    gStyle->SetPalette(1);
    gStyle->SetOptStat(0);
    gPad->SetLogz();
    gPad->SetRightMargin(0.12);
    p_hist2D->SetMinimum(1.0);
    p_hist2D->Draw("CONT4 Z");
}

void TestIsGISAXS10::write()
{
    std::ofstream file;
    file.open("./IsGISAXS_examples/ex-10/para1dcyl.ima", std::ios::out);
    mp_intensity_output->resetIndex();
    size_t row_length = mp_intensity_output->getAxes()[0]->getSize();
    int counter = 1;
    while(mp_intensity_output->hasNext()) {
        double z_value = mp_intensity_output->next();
        file << z_value << "    ";
        if(counter%row_length==0) {
            file << std::endl;
        }
        ++counter;
    }
}