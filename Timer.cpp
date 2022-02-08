#include "Timer.h"
Timer::Timer(const std::string& name)
    :
      functionName(name)
{
    start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    auto finish = std::chrono::high_resolution_clock::now();
    auto result = std::chrono::duration<double, std::milli>(finish - start);
    std::cout << functionName << " time:" << result.count() << "ms\n";
}