# Modern Multiplayer Game – C++ Qt Client

A modular C++ desktop client built with Qt for managing multiplayer sessions, in-game settings, and user interaction windows.

## Features

- User login and session management
- Create or join multiplayer game sessions (multi-gaming support)
- Display room code for easy sharing and joining
- Server-client architecture with real-time communication via `ClientServer` class
- Level and game mode selection with smooth navigation
- In-game and general settings windows (configurable controls, audio, etc.)
- Game over screen with restart or exit options
- Support for multiple users with individual key bindings
- SQLite database integration for storing:
    - Registered players
    - Key mappings (custom controls per player)
- Modular window-based design using Qt for a clean GUI experience


## Technologies Used

- **C++ (Modern OOP practices)**
- **Qt 6 Widgets** – for GUI components
- **CMake** – cross-platform build system
- **Visual Studio (.sln)** – Windows development environment

## Structure Overview

ProjectModernCpp-main/
├── .gitignore
├── CMakeLists.txt
├── Client/
│   ├── Client/
│   │   ├── *.cpp, *.h                # Multiple GUI components (Login, GameOver, etc.)
│   │   ├── ClientServer.cpp/h        # Networking logic
│   │   ├── *.ui                      # Qt Designer UI files
│   │   ├── Client.qrc, Resource.qrc  # Qt resource files
│   │   ├── libs/
│   │   │   └── nlohmann/json.hpp     # JSON handling
│   │   ├── resources/
│   │   │   └── *.png, *.jpg          # Game assets (astronauts, oxygen, UI icons)
│   │   └── main.cpp
│   └── Client.sln                    # Visual Studio solution
├── ProjectModerenCpp/
│   ├── ProjectModerenCpp/
│   │   ├── *.cpp, *.h                # Game logic (Bomb, Bullet, GameManager, etc.)
│   │   ├── *.db                      # SQLite databases for testing or persistence
│   │   ├── CMakeLists.txt
│   │   └── Main.cpp
└──        


## Video Demo link :
https://youtu.be/ethhUT_XoZE
