#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
    int durationSeconds;

public:
    Timer(int seconds = 30);

    void start();
    int getElapsedSeconds() const;
    int getRemainingSeconds() const;
    bool isTimeUp() const;
};

#endif
