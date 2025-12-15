#include "NotificationSystem.h"
#include <iostream>

// NotificationStrategy Implementation
NotificationStrategy::NotificationStrategy(const std::string& name)
    : strategyName(name) {
}

NotificationStrategy::~NotificationStrategy() {}

std::string NotificationStrategy::getName() const {
    return strategyName;
}

// LogNotification Implementation
LogNotification::LogNotification()
    : NotificationStrategy("Log Notification") {
}

void LogNotification::notify(const std::string& deviceName, const std::string& message) {
    std::cout << "[LOG NOTIFICATION] Device: " << deviceName << " - " << message << std::endl;
}

// AlarmNotification Implementation
AlarmNotification::AlarmNotification()
    : NotificationStrategy("Alarm Notification") {
}

void AlarmNotification::notify(const std::string& deviceName, const std::string& message) {
    std::cout << "[ALARM NOTIFICATION] !!! ALARM !!! Device: " << deviceName 
              << " - " << message << std::endl;
}

// SMSNotification Implementation
SMSNotification::SMSNotification(const std::string& phone)
    : NotificationStrategy("SMS Notification"), phoneNumber(phone) {
}

void SMSNotification::notify(const std::string& deviceName, const std::string& message) {
    std::cout << "[SMS NOTIFICATION] Sending SMS to " << phoneNumber << std::endl;
    std::cout << "  Message: Device '" << deviceName << "' - " << message << std::endl;
    std::cout << "  (A SMS is sent)" << std::endl;
}

void SMSNotification::setPhoneNumber(const std::string& phone) {
    phoneNumber = phone;
    std::cout << "[INFO] SMS phone number updated to: " << phoneNumber << std::endl;
}

// NotificationSystem Implementation
NotificationSystem::NotificationSystem()
    : logEnabled(true), alarmEnabled(false), smsEnabled(false) {
    
    logStrategy = new LogNotification();
    alarmStrategy = new AlarmNotification();
    smsStrategy = new SMSNotification();
    
    // Log is enabled by default
    strategies.push_back(logStrategy);
}

NotificationSystem::~NotificationSystem() {
    delete logStrategy;
    delete alarmStrategy;
    delete smsStrategy;
}

void NotificationSystem::onDeviceFailure(const std::string& deviceName, const std::string& message) {
    std::cout << std::endl;
    std::cout << "*** DEVICE FAILURE NOTIFICATION ***" << std::endl;
    
    for (size_t i = 0; i < strategies.size(); ++i) {
        strategies[i]->notify(deviceName, message);
    }
    
    std::cout << "***********************************" << std::endl;
    std::cout << std::endl;
}

void NotificationSystem::enableLog(bool enable) {
    if (enable && !logEnabled) {
        strategies.push_back(logStrategy);
        logEnabled = true;
        std::cout << "[INFO] Log notification ENABLED." << std::endl;
    } else if (!enable && logEnabled) {
        for (std::vector<NotificationStrategy*>::iterator it = strategies.begin(); 
             it != strategies.end(); ++it) {
            if (*it == logStrategy) {
                strategies.erase(it);
                break;
            }
        }
        logEnabled = false;
        std::cout << "[INFO] Log notification DISABLED." << std::endl;
    }
}

void NotificationSystem::enableAlarm(bool enable) {
    if (enable && !alarmEnabled) {
        strategies.push_back(alarmStrategy);
        alarmEnabled = true;
        std::cout << "[INFO] Alarm notification ENABLED." << std::endl;
    } else if (!enable && alarmEnabled) {
        for (std::vector<NotificationStrategy*>::iterator it = strategies.begin(); 
             it != strategies.end(); ++it) {
            if (*it == alarmStrategy) {
                strategies.erase(it);
                break;
            }
        }
        alarmEnabled = false;
        std::cout << "[INFO] Alarm notification DISABLED." << std::endl;
    }
}

void NotificationSystem::enableSMS(bool enable) {
    if (enable && !smsEnabled) {
        strategies.push_back(smsStrategy);
        smsEnabled = true;
        std::cout << "[INFO] SMS notification ENABLED." << std::endl;
    } else if (!enable && smsEnabled) {
        for (std::vector<NotificationStrategy*>::iterator it = strategies.begin(); 
             it != strategies.end(); ++it) {
            if (*it == smsStrategy) {
                strategies.erase(it);
                break;
            }
        }
        smsEnabled = false;
        std::cout << "[INFO] SMS notification DISABLED." << std::endl;
    }
}

bool NotificationSystem::isLogEnabled() const {
    return logEnabled;
}

bool NotificationSystem::isAlarmEnabled() const {
    return alarmEnabled;
}

bool NotificationSystem::isSMSEnabled() const {
    return smsEnabled;
}

void NotificationSystem::setPhoneNumber(const std::string& phone) {
    smsStrategy->setPhoneNumber(phone);
}

void NotificationSystem::displayStatus() const {
    std::cout << "=== Notification System Status ===" << std::endl;
    std::cout << "  Log Notification: " << (logEnabled ? "ENABLED" : "DISABLED") << std::endl;
    std::cout << "  Alarm Notification: " << (alarmEnabled ? "ENABLED" : "DISABLED") << std::endl;
    std::cout << "  SMS Notification: " << (smsEnabled ? "ENABLED" : "DISABLED") << std::endl;
}
