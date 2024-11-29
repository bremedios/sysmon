//
// Created by Bradley Remedios on 11/29/24.
//

#ifndef SYSMON_DEBUG_H
#define SYSMON_DEBUG_H

#include <iostream>

//#define __ENABLE_SYSMON_DEBUG    1

#define ERROR_MSG(msg)  { std::cerr << __PRETTY_FUNCTION__ << ":" << msg << std::endl; }

#if defined(__ENABLE_SYSMON_DEBUG)
    #define DEBUG_MSG(msg)  { std::cout << __PRETTY_FUNCTION__ << ":" << msg << std::endl; }
#else
    #define DEBUG_MSG(cmd)
#endif // __ENABLE_SYSMON_DEBUG

#endif // SYSMON_DEBUG_H