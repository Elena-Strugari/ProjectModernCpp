#include "ServerController.h"

ServerController::ServerController(crow::SimpleApp& app)
    : m_app(app) {}

void ServerController::StartServer() {
    m_serverThread = std::thread([this]() {
        try {
            m_app.port(8080).multithreaded().run();
        }
        catch (const std::exception& e) {
            std::cerr << "Server error: " << e.what() << std::endl;
            m_running = false; // Oprește bucla principală dacă serverul are o eroare
        }
        });

    std::cout << "Server running. Press ESC to stop." << std::endl;
}

void ServerController::StopServer() {
    m_running = false;
    m_app.stop(); // Oprește serverul Crow
    if (m_serverThread.joinable()) {
        m_serverThread.join(); // Așteaptă terminarea thread-ului
    }
    std::cout << "Server stopped." << std::endl;
}

void ServerController::MonitorInput() {
    while (m_running) {
        if (_kbhit()) { // Verifică dacă o tastă a fost apăsată
            char key = _getch(); // Citește tasta
            if (key == 27) { // Cod ASCII pentru ESC
                std::cout << "Stopping server..." << std::endl;
                StopServer();
                break;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Evită consumul excesiv de CPU
    }
}

void ServerController::Run() {
    StartServer();       // Pornește serverul
    MonitorInput();      // Monitorizează tasta ESC
    StopServer();        // Asigură oprirea serverului (în cazul ieșirii din buclă)
}