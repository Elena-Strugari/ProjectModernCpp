#pragma once
#include <crow.h>
#include <thread>
#include <atomic>
#include <iostream>
#include <conio.h> // Pentru _kbhit() și _getch()

class ServerController {
public:
    ServerController(crow::SimpleApp& app);
    void StartServer(); // Pornire server
    void StopServer();  // Oprire server
    void MonitorInput(); // Monitorizare tastatură (pentru ESC)
    void Run();
private:
    crow::SimpleApp& m_app;
    std::thread m_serverThread;
    std::atomic<bool> m_running{ true }; // Flag pentru a controla serverul
};
