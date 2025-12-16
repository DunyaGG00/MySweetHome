/**
 * @file AlarmHandler.h
 * @brief Handler that triggers the alarm in the security chain
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 220201047: Security System - Chain of Responsibility (Handler)
 * 
 * @patterns Chain of Responsibility
 */

#ifndef ALARMHANDLER_H
#define ALARMHANDLER_H

#include "SecurityHandler.h"
#include "Alarm.h"

class AlarmHandler : public SecurityHandler {
private:
    Alarm* alarm;
    
public:
    AlarmHandler(Alarm* alarm);
    virtual void handleRequest();
};

#endif // ALARMHANDLER_H
