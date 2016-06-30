// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Tools/Histogram2D.cpp
//! @brief     Implements class Histogram2D.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "Histogram2D.h"
#include "Histogram1D.h"
#include "FixedBinAxis.h"
#include "VariableBinAxis.h"
#include <memory>

Histogram2D::Histogram2D(int nbinsx, double xlow, double xup, int nbinsy, double ylow, double yup)
{
    m_data.addAxis(FixedBinAxis("x-axis", nbinsx, xlow, xup));
    m_data.addAxis(FixedBinAxis("y-axis", nbinsy, ylow, yup));
}

Histogram2D::Histogram2D(
    int nbinsx, const std::vector<double>& xbins, int nbinsy, const std::vector<double>& ybins)
{
    m_data.addAxis(VariableBinAxis("x-axis", nbinsx, xbins));
    m_data.addAxis(VariableBinAxis("y-axis", nbinsy, ybins));
}

Histogram2D::Histogram2D(const IAxis &axis_x, const IAxis &axis_y)
    : IHistogram(axis_x, axis_y)
{

}

Histogram2D::Histogram2D(const OutputData<double>& data)
{
    init_from_data(data);
}

Histogram2D* Histogram2D::clone() const
{
    return new Histogram2D(*this);
}

int Histogram2D::fill(double x, double y, double weight)
{
    if(x < getXaxis()->getMin() || x >= getXaxis()->getMax()) return -1;
    if(y < getYaxis()->getMin() || y >= getYaxis()->getMax()) return -1;

    std::vector<double> coordinates;
    coordinates.push_back(x);
    coordinates.push_back(y);

    size_t index = m_data.findGlobalIndex(coordinates);
    m_data[index].add(weight);
    return (int)index;
}

Histogram1D* Histogram2D::projectionX()
{
    return create_projectionX(0, getXaxis()->getSize()-1);
}

Histogram1D* Histogram2D::projectionX(double yvalue)
{
    int ybin_selected = getYaxis()->findClosestIndex(yvalue);
    return create_projectionX(ybin_selected, ybin_selected);
}

Histogram1D* Histogram2D::projectionX(double ylow, double yup)
{
    int ybinlow = getYaxis()->findClosestIndex(ylow);
    int ybinup = getYaxis()->findClosestIndex(yup);
    return create_projectionX(ybinlow, ybinup);
}

Histogram1D* Histogram2D::projectionY()
{
    return create_projectionY(0, getXaxis()->getSize()-1);
}

Histogram1D* Histogram2D::projectionY(double xvalue)
{
    int xbin_selected = getXaxis()->findClosestIndex(xvalue);
    return create_projectionY(xbin_selected, xbin_selected);
}

Histogram1D* Histogram2D::projectionY(double xlow, double xup)
{
    int xbinlow = getXaxis()->findClosestIndex(xlow);
    int xbinup = getXaxis()->findClosestIndex(xup);
    return create_projectionY(xbinlow, xbinup);
}

Histogram2D* Histogram2D::crop(double xmin, double ymin, double xmax, double ymax)
{
    const std::unique_ptr<IAxis > xaxis(getXaxis()->createClippedAxis(xmin, xmax));
    const std::unique_ptr<IAxis > yaxis(getYaxis()->createClippedAxis(ymin, ymax));

    Histogram2D* result = new Histogram2D(*xaxis, *yaxis);
    OutputData<CumulativeValue>::const_iterator it_origin = m_data.begin();
    OutputData<CumulativeValue>::iterator it_result = result->m_data.begin();
    while (it_origin != m_data.end())
    {
        double x = m_data.getAxisValue(it_origin.getIndex(), 0);
        double y = m_data.getAxisValue(it_origin.getIndex(), 1);
        if(result->getXaxis()->contains(x) && result->getYaxis()->contains(y)) {
            *it_result = *it_origin;
            ++it_result;
        }
        ++it_origin;
    }
    return result;
}

Histogram1D* Histogram2D::create_projectionX(int ybinlow, int ybinup)
{
    Histogram1D* result = new Histogram1D(*this->getXaxis());

    for(size_t index=0; index<getTotalNumberOfBins(); ++index) {

        int ybin = getYaxisIndex(index);

        if(ybin >= ybinlow && ybin <= ybinup) {
            result->fill(getXaxisValue(index), getBinContent(index));
        }
    }
    return result;
}

Histogram1D* Histogram2D::create_projectionY(int xbinlow, int xbinup)
{
    Histogram1D* result = new Histogram1D(*this->getYaxis());

    for(size_t index=0; index<getTotalNumberOfBins(); ++index) {

        int xbin = getXaxisIndex(index);

        if(xbin >= xbinlow && xbin <= xbinup) {
            result->fill(getYaxisValue(index), getBinContent(index));
        }
    }
    return result;
}