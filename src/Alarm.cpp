#include "Alarm.h"
#include <sstream>

// Initialize static instance pointer
Alarm* Alarm::instance = NULL;

Alarm::Alarm() 
    : Device("MSH", "Integrated Alarm"), isRinging(false), volumeLevel(100) {
    // Alarm is always on
    powerState = true;
}

Alarm* Alarm::getInstance() {
    if (instance == NULL) {
        instance = new Alarm();
    }
    return instance;
}

Alarm::~Alarm() {}

void Alarm::powerOff() {
    std::cout << "[WARNING] Alarm is a CRITICAL device and cannot be powered off!" << std::endl;
}

void Alarm::doPowerOn() {
    std::cout << "  -> Alarm system activated." << std::endl;
}

void Alarm::doPowerOff() {
    std::cout << "  -> Alarm cannot be turned off (critical device)." << std::endl;
}

std::string Alarm::getDeviceType() const {
    return "Alarm (Singleton)";
}

std::string Alarm::getStatus() const {
    std::ostringstream oss;
    oss << Device::getStatus() << " | Volume: " << volumeLevel << "%";
    oss << ", Status: " << (isRinging ? "RINGING!" : "Silent");
    return oss.str();
}

Device* Alarm::clone() const {
    // Singleton - return same instance
    return Alarm::getInstance();
}

void Alarm::ring() {
    isRinging = true;
    std::cout << "!!! ALARM RINGING !!! Volume: " << volumeLevel << "%" << std::endl;
}

void Alarm::stop() {
    isRinging = false;
    std::cout << "[INFO] Alarm stopped." << std::endl;
}

bool Alarm::isAlarmRinging() const {
    return isRinging;
}

void Alarm::setVolume(int vol) {
    if (vol < 0) vol = 0;
    if (vol > 100) vol = 100;
    volumeLevel = vol;
    std::cout << "[INFO] Alarm volume set to: " << volumeLevel << "%" << std::endl;
}

int Alarm::getVolume() const {
    return volumeLevel;
}
