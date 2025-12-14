/**
 * @file HomeController.h
 * @brief Facade class for managing the smart home system
 * @version 5.0
 * @date 03/12/2025
 * 
 * @authors
 * - 220201013: System Integration - Facade, Main Loop, Module Integration
 * 
 * @patterns Facade
 */

#ifndef HOMECONTROLLER_H
#define HOMECONTROLLER_H

#include <vector>
#include <string>

// Forward declarations
class Device;
class Light;
class Camera;
class Television;
class Detector;
class SmokeDetector;
class GasDetector;
class SoundSystem;
class Alarm;
class Menu;
class Storage;
class ModeManager;
class DeviceFactory;
class DetectorFactory;

// Facade Pattern - Main controller for the entire system
class HomeController {
private:
    // Devices organized by type
    std::vector<Device*> lights;
    std::vector<Device*> cameras;
    std::vector<Device*> televisions;
    std::vector<Device*> smokeDetectors;
    std::vector<Device*> gasDetectors;
    std::vector<Device*> soundSystems;
    std::vector<Device*> allDevices;
    
    // Light pointers for subsystems (if needed later)
    std::vector<Light*> lightPtrs;
    
    // Singleton instances
    Alarm* alarm;
    Storage* storage;
    
    // Managers
    Menu* menu;
    ModeManager* modeManager;
    
    // System state
    bool isRunning;
    
    // Helper methods
    void initializeDefaultDevices();
    void registerDevice(Device* device);
    void unregisterDevice(Device* device);
    void updateLightPtrs();
    
    // Menu handlers
    void handleGetStatus();
    void handleAddDevice();
    void handleRemoveDevice();
    void handlePowerOn();
    void handlePowerOff();
    void handleChangeMode();
    void handleChangeState();
    void handleManual();
    void handleAbout();
    void handleShutdown();
    
    // Device operations
    void addDevices(char deviceType, int count, int brandChoice);
    void removeDevice(char deviceType, int index);
    void powerOnDevices(char deviceType);
    void powerOffDevices(char deviceType);
    
    // Display helpers
    void displayDeviceList(const std::vector<Device*>& devices, const std::string& title) const;
    void displayAllDevices() const;

public:
    HomeController();
    ~HomeController();
    
    // Main system control
    void start();
    void run();
    void shutdown();
    
    // Device management
    void addLight(int brandChoice = 1);
    void addCamera(int brandChoice = 1);
    void addTV(int brandChoice = 1);
    void addDetectorPair(int brandChoice = 1);
    void addSoundSystem(int brandChoice = 1);
    
    // Status
    void displayStatus() const;
    bool isSystemRunning() const;
    
    // Simulation methods for testing
    void simulateMotionDetection();
    void simulateDeviceFailure(int deviceIndex);
};

#endif // HOMECONTROLLER_H
