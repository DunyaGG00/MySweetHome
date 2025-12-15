#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include "Device.h"
#include <string>
#include <vector>

// Strategy Pattern - Notification strategies
class NotificationStrategy {
protected:
    std::string strategyName;

public:
    NotificationStrategy(const std::string& name);
    virtual ~NotificationStrategy();
    
    virtual void notify(const std::string& deviceName, const std::string& message) = 0;
    std::string getName() const;
};

// Concrete Strategies
class LogNotification : public NotificationStrategy {
public:
    LogNotification();
    virtual void notify(const std::string& deviceName, const std::string& message);
};

class AlarmNotification : public NotificationStrategy {
public:
    AlarmNotification();
    virtual void notify(const std::string& deviceName, const std::string& message);
};

class SMSNotification : public NotificationStrategy {
private:
    std::string phoneNumber;
public:
    SMSNotification(const std::string& phone = "+90-555-123-4567");
    virtual void notify(const std::string& deviceName, const std::string& message);
    void setPhoneNumber(const std::string& phone);
};

// Observer Pattern - Notification System as Observer
class NotificationSystem : public IDeviceObserver {
private:
    std::vector<NotificationStrategy*> strategies;
    bool logEnabled;
    bool alarmEnabled;
    bool smsEnabled;
    
    LogNotification* logStrategy;
    AlarmNotification* alarmStrategy;
    SMSNotification* smsStrategy;

public:
    NotificationSystem();
    virtual ~NotificationSystem();
    
    // IDeviceObserver implementation
    virtual void onDeviceFailure(const std::string& deviceName, const std::string& message);
    
    // Enable/disable notifications
    void enableLog(bool enable);
    void enableAlarm(bool enable);
    void enableSMS(bool enable);
    
    // Status
    bool isLogEnabled() const;
    bool isAlarmEnabled() const;
    bool isSMSEnabled() const;
    
    void setPhoneNumber(const std::string& phone);
    void displayStatus() const;
};

#endif // NOTIFICATIONSYSTEM_H
