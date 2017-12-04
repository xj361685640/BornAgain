// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Computation/IComputation.cpp
//! @brief     Implements interface IComputation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "IComputation.h"
#include "MultiLayer.h"
#include "ProgressHandler.h"
#include "SimulationElement.h"

IComputation::IComputation(const SimulationOptions& options, ProgressHandler& progress,
                           const std::vector<SimulationElement>::iterator& start,
                           const std::vector<SimulationElement>::iterator& end,
                           const MultiLayer& sample)
    : m_sim_options(options)
    , m_progress(&progress)
    , m_begin_it(start)
    , m_end_it(end)
    , mP_multi_layer(sample.cloneSliced(options.useAvgMaterials()))
{
    if (!mP_multi_layer)
        throw std::runtime_error("Error in IComputation: empty sample passed.");
}

IComputation::~IComputation() = default;

void IComputation::run()
{
    m_status.setRunning();
    try {
        runProtected();
        m_status.setCompleted();
    } catch(const std::exception &ex) {
        m_status.setErrorMessage(std::string(ex.what()));
        m_status.setFailed();
    }
}
