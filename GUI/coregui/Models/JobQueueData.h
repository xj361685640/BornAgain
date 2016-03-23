// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/JobQueueData.h
//! @brief     Defines class JobQueueData
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef JOBQUEUEDATA_H
#define JOBQUEUEDATA_H

#include <QObject>
#include <QString>
#include <QMap>

//class JobItem;
class JobItem;
class JobModel;
//class JobQueueItem;
class GISASSimulation;
class JobRunner;
class QThread;


//! Main class to run jobs
class BA_CORE_API_ JobQueueData : public QObject
{
    Q_OBJECT
public:
    JobQueueData(JobModel *jobModel);

    QThread *getThread(QString identifier);
    JobRunner *getRunner(QString identifier);
    GISASSimulation *getSimulation(QString identifier);

    bool hasUnfinishedJobs();

//    void setResults(JobItem *jobItem, const GISASSimulation *simulation);

signals:
    void globalProgress(int);
    void focusRequest(const QString &identifier);
    void jobIsFinished(const QString &identifier);

public slots:
    void onStartedJob();
    void onProgressUpdate();
    void onFinishedJob();
    void onFinishedThread();
    void onCancelAllJobs();

    void runJob(const QString &identifier);
    void runJob(JobItem *jobItem);
    void cancelJob(const QString &identifier);
    void removeJob(const QString &identifier);

private:
    void assignForDeletion(QThread *thread);
    void assignForDeletion(JobRunner *runner);
    void clearSimulation(const QString &identifier);

    void updateGlobalProgress();

    QMap<QString, QThread *> m_threads; //! correspondance of JobIdentifier and running threads
    QMap<QString, JobRunner *> m_runners; //! correspondance of JobIdentifier and JobRunner's
    QMap<QString, GISASSimulation *> m_simulations; //! correspondance of JobIdentifier and simulation

    JobModel *m_jobModel;
};

#endif
