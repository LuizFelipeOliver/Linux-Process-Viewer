#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include <QObject>
#include <QThread>
#include <vector>
#include <QString>
#include "process.h"

class ProcessManager : public QThread {
    Q_OBJECT

public:
    explicit ProcessManager(QObject *parent = nullptr);
    ~ProcessManager() override;

private slots:
    void startFetchingProcesses();

signals:
    void processesFetched(const std::vector<Process>& processes);

protected:
    void run() override;

private:
    std::vector<Process> fetchProcesses();
};

#endif // PROCESSMANAGER_H
