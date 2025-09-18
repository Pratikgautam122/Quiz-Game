#include "Timer.h"

Timer::Timer(int seconds) : durationSeconds(seconds) {}

void Timer::start() {
    startTime = std::chrono::high_resolution_clock::now();
}

int Timer::getElapsedSeconds() const {
    auto now = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime);
    return static_cast<int>(elapsed.count());
}

int Timer::getRemainingSeconds() const {
    return durationSeconds - getElapsedSeconds();
}

bool Timer::isTimeUp() const {
    return getElapsedSeconds() >= durationSeconds;
}
