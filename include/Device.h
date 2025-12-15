#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

// Base Device class - Template Method Pattern
class Device {
protected:
    std::string name;
    std::string brand;
    std::string model;
    bool powerState;      // true = on, false = off
    bool operationMode;   // true = active, false = inactive (failed)

public:
    Device(const std::string& brand, const std::string& model);
    virtual ~Device();

    // Template Method Pattern
    void powerOn();
    void powerOff();
    
    // Primitive operations to be overridden
    virtual void doPowerOn() = 0;
    virtual void doPowerOff() = 0;
    
    // Common operations
    virtual std::string getStatus() const;
    virtual std::string getDeviceType() const = 0;
    
    // Getters and Setters
    std::string getName() const;
    std::string getBrand() const;
    std::string getModel() const;
    bool isPoweredOn() const;
    bool isActive() const;
    
    void setOperationMode(bool active);
    
    // Prototype Pattern - Clone method
    virtual Device* clone() const = 0;
    
    // For copying configuration
    virtual void copyConfigurationFrom(const Device* other);
};

#endif // DEVICE_H
