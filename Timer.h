

#include <chrono>
#include <iostream>
#include <string>


class Timer
{
private:
    std::string functionName;
    std::chrono::high_resolution_clock::time_point start;
public:
    Timer(const std::string& name);
    ~Timer();
};