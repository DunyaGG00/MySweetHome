/**
 * @file SmokeDetector.h
 * @brief Concrete Smoke Detector implementation
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 220208041: Detectors & Alarm - Smoke Detector implementation
 * 
 * @patterns Factory Method (Product)
 */

#ifndef SMOKEDETECTOR_H
#define SMOKEDETECTOR_H

#include "Detector.h"

// Base Smoke Detector class
class SmokeDetector : public Detector {
protected:
    int smokeLevel;  // 0-100 percentage

public:
    SmokeDetector(const std::string& brand, const std::string& model);
    virtual ~SmokeDetector();

    virtual std::string getDeviceType() const;
    virtual std::string getStatus() const;
    virtual Device* clone() const = 0;
    virtual void detect();
    virtual void trigger(); // Override pure virtual
    
    int getSmokeLevel() const;
    void setSmokeLevel(int level);  // For simulation
};

// Concrete Smoke Detector - Nest Protect
class NestSmokeDetector : public SmokeDetector {
public:
    NestSmokeDetector();
    virtual ~NestSmokeDetector();
    virtual Device* clone() const;
};

// Concrete Smoke Detector - First Alert
class FirstAlertSmokeDetector : public SmokeDetector {
public:
    FirstAlertSmokeDetector();
    virtual ~FirstAlertSmokeDetector();
    virtual Device* clone() const;
};

#endif // SMOKEDETECTOR_H
