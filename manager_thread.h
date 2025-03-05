#ifndef MANAGERTHREAD_H
#define MANAGERTHREAD_H

#include <QThread>

class ProcessManagerThread : public QThread {
    Q_OBJECT

public:
    ProcessManagerThread(QObject *parent = nullptr) : QThread(parent) {}

protected:
    void run() override {
        emit requestProcessFetch();
    }

signals:
    void requestProcessFetch();
    void requestProcessFetch(const std::vector<Process>& processes);
};

#endif // MANAGERTHREAD_H
