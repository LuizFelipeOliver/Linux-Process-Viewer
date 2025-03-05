#include "process_manager.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>

namespace fs = std::filesystem;

ProcessManager::ProcessManager(QObject *parent) : QThread(parent){}

ProcessManager::~ProcessManager() {}

void ProcessManager::run(){
    while(true){
        std::vector<Process> processes = fetchProcesses();
        emit processesFetched(processes);
        QThread::sleep(2);
    }
}

void ProcessManager::startFetchingProcesses(){
    std::vector<Process> processes = fetchProcesses();
    emit processesFetched(processes);
}

std::vector<Process> ProcessManager::fetchProcesses() {
    std::vector<Process> processes;
    for (const auto &entry : fs::directory_iterator("/proc/")) {
        if (!entry.is_directory()) continue;

        std::string pidsStr = entry.path().filename().string();
        if (!std::all_of(pidsStr.begin(), pidsStr.end(), ::isdigit)) continue;

        int pid = std::stoi(pidsStr);
        std::string name, status;

        std::ifstream cmdFile("/proc/" + pidsStr + "/comm");
        if (cmdFile) std::getline(cmdFile, name);

        std::ifstream statusFile("/proc/" + pidsStr + "/status");
        if (statusFile) {
            std::string line;
            while (std::getline(statusFile, line)) {
                if (line.find("State:") == 0) {
                    status = line.substr(7);
                    break;
                }
            }
        }
        processes.emplace_back(pid, name, status);
    }
    return processes;
}
