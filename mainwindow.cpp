#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ProcessManager *manager = new ProcessManager();

   connect(manager, &ProcessManager::processesFetched, this, &MainWindow::updateProcessTable);

    manager->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProcessTable(const std::vector<Process>& processes){
    ui->processTable->setRowCount(processes.size());

    for (size_t i = 0; i < processes.size(); ++i) {
        ui->processTable->setItem(i, 0, new QTableWidgetItem(QString::number(processes[i].getPID())));
        ui->processTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(processes[i].getName())));
        ui->processTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(processes[i].getStatus())));
    }
}
