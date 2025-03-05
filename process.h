#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process
{
public:
    Process(int pid, const std::string &name, const std::string &status) : pid(pid),name(name),status(status){};

    int getPID() const { return pid; }
    std::string getStatus() const { return status; }
    std::string getName() const { return name; }
private:
    int pid;
    std::string name;
    std::string status;
};

#endif // PROCESS_H
