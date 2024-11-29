//
// Created by Bradley Remedios on 11/18/24.
//
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

#include <bpl/sys/Batteries.h>
#include <bpl/sys/Battery.h>

#include "Debug.h"

#define SYSMON_VERSION  "0.0.1"

int main() {
    int logInterval = 5000;

    std::cout << "System Monitor v" << SYSMON_VERSION << std::endl;

    bpl::sys::Batteries batteries;

    if (!batteries.Load()) {
        ERROR_MSG("ERROR: Failed to load batteries.");

        return -1;
    }
    std::string timestamp = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());

    batteries.Update();
    batteries.StartLog(timestamp + "-" + "battery_monitor");

    for (;;) {
        timestamp = std::to_string(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());

        batteries.Update();
        batteries.Log(timestamp);

        std::this_thread::sleep_for(std::chrono::milliseconds(logInterval));
    }

    batteries.StopLog();

    for (auto const& battery : batteries.getBatteryMap()) {
        std::cout << battery.first << std::endl;
        std::cout << "    Capacity: " << battery.second->getCapacity() << std::endl;
    }

    return 0;
} // main