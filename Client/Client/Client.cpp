#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <conio.h>

void chooseLevel(const std::string& level, const std::string& clientId) {
    cpr::Response r = cpr::Post(
        cpr::Url{ "http://localhost:8080/choose_level" },
        cpr::Header{ {"Client-ID", clientId} },
        cpr::Body{ level }
    );
    if (r.status_code == 200) {
        std::cout << " Client :Nivel ales cu succes: " << r.text << std::endl;
    }
    else {
        std::cout << "Client: Eroare la alegerea nivelului: " << r.text << std::endl;
    }
}

void getMap(const std::string& level, const std::string& clientId) {

    cpr::Response r = cpr::Get(
        cpr::Url{ "http://localhost:8080/get_map" },
        cpr::Header{ {"Client-ID", clientId} },
        cpr::Body{ level }

    );
    if (r.status_code == 200) {
        std::cout << "Client: Harta obtinuta cu succes! Poti vizualiza harta pe web." << std::endl;
        std::cout << "Client: Harta in format JSON este:\n" << r.text << std::endl;

        system("start http://localhost:8080/get_map"); // Deschide browser-ul pentru a vizualiza harta
    }
    else {
        std::cout << "Client: Eroare la obtinerea hartii: " << r.text << std::endl;
    }
}

void getTank(const std::string& clientId) {

    cpr::Response r = cpr::Get(
        cpr::Url{ "http://localhost:8080/get_tank" },
        cpr::Header{ {"Client-ID", clientId} }
    );

    // Verifică răspunsul
    if (r.status_code == 200) {
        std::cout << "Client: Tank exista " << std::endl;
        std::cout << "Client: Tank in format JSON este:\n" << r.text << std::endl;

        // system("start http://localhost:8080/get_tank"); // Deschide browser-ul pentru a vizualiza harta
    }
    else {
        std::cout << "Client: Eroare la obtinere tank: " << r.text << std::endl;
    }
}


void send_move_request(const std::string& clientId, const std::string& direction) {

    std::string url = "http://localhost:8080/move_tank?id=" + clientId + "&direction=" + direction;

    cpr::Response r = cpr::Get(
        cpr::Url{ url });

    if (r.status_code == 200) {
        std::cout << "Raspuns server: " << r.text << std::endl;
    }
    else {
        std::cout << "Eroare la comunicarea cu serverul.\n";
    }
}


char get_input() {
    char input = _getch();
    return input;
}
int main() {


    //std::string clientId;  // ID-ul clientului
    //std::string level;
    //std::cout << "Scrie numele client: ";
    // std::cin >> clientId;
    //std::cout << "Alege un nivel:   {Usor, Mediu , Greu}:  ";
    //std::cin >> level;

    std::string clientId = "client1";
    std::string level = "Usor";


    // POST
    chooseLevel(level, clientId);
    std::cout << "se afiseaza mat";
    //GET
    getMap(level, clientId);
    //getTank(clientId);

    std::cout << "Control tank " << clientId << ". Foloseste sagetile pentru a misca!\n";
    std::cout << "Apasa ESC pentru a iesi.\n";

    while (true) {
        char input = get_input();

        if (input == 27) { //  ESC
            std::cout << "Inchidere...\n";
            break;
        }
        else if (input == -32) { // Secvența de control pentru tasta specială (pe Windows)
            input = get_input(); // Citiți a doua parte a secvenței de tasta

            std::cout << "Input tasta speciala: " << (int)input << std::endl;

            if (input == 72) { //  sus 
                send_move_request(clientId, "U");
            }
            else if (input == 80) { //  jos
                send_move_request(clientId, "D");
            }
            else if (input == 75) { //  stânga
                send_move_request(clientId, "L");
            }
            else if (input == 77) { //  dreapta
                send_move_request(clientId, "R");
            }
        }
        else {
            std::cout << "Client:necunoscuta\n";
        }
    }

    return 0;
}



//incercare 

//void send_move_request(const std::string& clientId, const std::string& direction) {
//
//    CURL* curl;
//    CURLcode res;
//
//    // Construim URL-ul cererii
//    std::string url = "http://localhost:18080/move_tank?id=" + id + "&direction=" + direction;
//
//    // Inițializăm CURL
//    curl_global_init(CURL_GLOBAL_DEFAULT);
//    curl = curl_easy_init();
//    if (curl) {
//        // Setăm URL-ul și opțiunile cererii
//        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//
//        // Executăm cererea
//        res = curl_easy_perform(curl);
//
//        // Verificăm dacă cererea a avut succes
//        if (res != CURLE_OK) {
//            std::cerr << "CURL error: " << curl_easy_strerror(res) << std::endl;
//            curl_easy_cleanup(curl);
//            curl_global_cleanup();
//            return false;
//        }
//
//        // Cleanup
//        curl_easy_cleanup(curl);
//    }
//
//    curl_global_cleanup();
//    return true;
//}
