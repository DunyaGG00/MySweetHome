# My Sweet Home (MSH) - Smart Home Management System

## CENG-464 Design Patterns with C++ Term Project

### Project Overview
My Sweet Home (MSH) is a smart home management system that controls IoT devices through a screen panel interface. The system demonstrates the implementation of various design patterns in C++98.

---

## Design Patterns Used

| Pattern | Implementation | Description |
|---------|---------------|-------------|
| **Singleton** | `Alarm`, `Storage` | Single instance devices |
| **Factory Method** | `SimpleDeviceFactory` | Creates devices by type |
| **Abstract Factory** | `DeviceFactory`, `DetectorFactory` | Creates device families |
| **Prototype** | `Device::clone()` | Clone devices with configuration |
| **State** | `ModeState`, `SystemState` | Mode and system states |
| **Memento** | `HomeMemento`, `StateManager` | State history and undo |
| **Observer** | `IDeviceObserver`, `NotificationSystem` | Device failure notifications |
| **Strategy** | `NotificationStrategy` | Different notification methods |
| **Template Method** | `Device::powerOn()`, `Device::powerOff()` | Device operations |
| **Facade** | `HomeController` | Simplified system interface |

---

## Project Structure

```
MySweetHome/
├── CMakeLists.txt
├── include/
│   ├── Alarm.h
│   ├── Camera.h
│   ├── DetectionSystem.h
│   ├── Detector.h
│   ├── Device.h
│   ├── DeviceFactory.h
│   ├── GasDetector.h
│   ├── HomeController.h
│   ├── Light.h
│   ├── Menu.h
│   ├── ModeManager.h
│   ├── NotificationSystem.h
│   ├── SecuritySystem.h
│   ├── SmokeDetector.h
│   ├── SoundSystem.h
│   ├── StateManager.h
│   ├── Storage.h
│   └── Television.h
└── src/
    ├── main.cpp
    ├── Alarm.cpp
    ├── Camera.cpp
    ├── DetectionSystem.cpp
    ├── Detector.cpp
    ├── Device.cpp
    ├── DeviceFactory.cpp
    ├── GasDetector.cpp
    ├── HomeController.cpp
    ├── Light.cpp
    ├── Menu.cpp
    ├── ModeManager.cpp
    ├── NotificationSystem.cpp
    ├── SecuritySystem.cpp
    ├── SmokeDetector.cpp
    ├── SoundSystem.cpp
    ├── StateManager.cpp
    ├── Storage.cpp
    └── Television.cpp
```

---

## Compilation and Running

### Prerequisites
- CMake (version 3.10 or higher)
- C++ Compiler (supporting C++98/11)
- Git

### Build Instructions

1. **Create a build directory:**
   ```bash
   mkdir build
   ```

2. **Configure the project:**
   ```bash
   cmake -B build
   ```

3. **Build the executable:**
   ```bash
   cmake --build build
   ```

### Running the Application

After a successful build, the executable will be located in the `bin` directory inside your build folder.

```bash
./build/bin/msh
```

---

## Device Classes Hierarchy

```
Device (Abstract Base)
├── Light
│   ├── PhilipsHueLight
│   └── IKEATradfriLight
├── Camera
│   ├── SamsungCamera
│   └── XiaomiCamera
├── Television
│   ├── SamsungTV
│   └── LGTV
├── Detector (Cannot be powered off)
│   ├── SmokeDetector
│   │   ├── NestSmokeDetector
│   │   └── FirstAlertSmokeDetector
│   └── GasDetector
│       ├── NestGasDetector
│       └── KiddeGasDetector
├── SoundSystem
│   ├── SonosSoundSystem
│   └── BoseSoundSystem
└── Alarm (Singleton, cannot be powered off)
```

---

## System Modes

| Mode | Light | TV | Music |
|------|-------|-----|-------|
| Normal | ON | OFF | OFF |
| Evening | OFF | OFF | OFF |
| Party | ON | OFF | ON |
| Cinema | OFF | ON | OFF |

---

## System States

- **Normal**: Standard operation - all features available
- **High Performance**: Maximum performance - increased resource usage
- **Low Power**: Energy saving mode - reduced functionality
- **Sleep**: Minimal operation - only critical systems active

---

## High-Level Requirements Mapping

| HLR | Description | Implementation |
|-----|-------------|----------------|
| REQ1 | Operation menu | `Menu` class |
| REQ2 | Manual display | `Menu::displayManual()` |
| REQ3 | Keyboard interaction | `Menu::getMenuChoice()` |
| REQ4 | Persistent logging | `Storage` class (Singleton) |
| REQ5 | Device types | `Light`, `Detector`, `Camera`, `Television` |
| REQ6 | Power on/off | `Device::powerOn()`, `Device::powerOff()` |
| REQ7 | Modes | `ModeManager`, `ModeState` classes |
| REQ8 | Add/remove devices | `HomeController` device management |
| REQ9 | Failure notifications | `NotificationSystem`, `IDeviceObserver` |
| REQ10 | Configuration copy | `Device::copyConfigurationFrom()`, Prototype pattern |
| REQ11 | State history | `StateManager`, `HomeMemento` (Memento pattern) |
| REQ12 | State restore | `StateManager::restorePreviousState()` |

---

## Menu Options

```
MY SWEET HOME (MSH)
[1] Get Home Status
[2] Add Device
[3] Remove Device
[4] Power On Device
[5] Power Off Device
[6] Change Mode
[7] Change State
[8] Manual
[9] About
[10] Shutdown
```

---

## Team Members
- **Integrator**: [Name] - Integration & Build System
- **Developer 1**: [Name] - Device Module
- **Developer 2**: [Name] - Factory Module
- **Developer 3**: [Name] - Mode Manager Module
- **Developer 4**: [Name] - State Manager Module
- **Developer 5**: [Name] - Security System Module
- **Developer 6**: [Name] - Detection System Module

---

## Course Information
- **Course**: CENG-464 Design Patterns with C++
- **Instructor**: Murat Yilmaz
- **University**: OSTIM Technical University
- **Date**: 2025

---

## License
This project is developed for educational purposes as part of the CENG-464 course.
