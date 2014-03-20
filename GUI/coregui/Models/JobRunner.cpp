#include "JobRunner.h"
#include "Simulation.h"
#include "ProgressHandler.h"
#include "ThreadInfo.h"
#include <boost/bind.hpp>
#include <QTimer>
#include <QDebug>


JobRunner::JobRunner(QString identifier, Simulation *simulation)
    : m_identifier(identifier)
    , m_simulation(simulation)
    , m_progress(0)
    , m_run_flag(true)
{

}


JobRunner::~JobRunner()
{
    qDebug() << "JobRunner::~JobRunner()";
}


int JobRunner::getProgress() const
{
    // sometimes simulation underestimate the number of iterations required
    // and progress can be greater than 100
    return m_progress < 100 ? m_progress : 100;
}


void JobRunner::start()
{
    qDebug() << "JobRunner::start() " << m_simulation;
    m_run_flag = true;
    emit started();

    if(m_simulation) {
        ProgressHandler_t progressHandler(new ProgressHandler());
        ProgressHandler::Callback_t callback = boost::bind(&JobRunner::similationProgressCallback, this, _1);
        progressHandler->setCallback(callback);
        m_simulation->setProgressHandler(progressHandler);
//        m_simulation->setProgressCallback(callback);
//        ThreadInfo info;
//        info.n_threads = 1;
//        m_simulation->setThreadInfo(info);
        m_simulation->runSimulation();
        m_progress=100;
        emit progressUpdate();
        emit finished();
    } else {
        runFakeSimulation();
    }
}


//! Fake simulation function to mimic some hard work going on
void JobRunner::runFakeSimulation()
{
    qDebug() << "JobItem::runFakeSimulation()" << m_progress;
    if(m_progress < 100) {
        m_progress = m_progress+4;
        emit progressUpdate();
        QTimer::singleShot(500, this, SLOT(runFakeSimulation()));
    }
    if(m_progress >=100 || !m_run_flag) {
        emit progressUpdate();
        emit finished();
    }
}


//! function which is called by the Simulation to report its progress
bool JobRunner::similationProgressCallback(int progress)
{
    m_progress = progress;
    qDebug() << "JobRunner::getSimilationProgress(int)" << progress;
    emit progressUpdate();
    return m_run_flag;
}


void JobRunner::terminate()
{
    qDebug() << "JobRunner::terminate()";
    m_run_flag = false;
}
