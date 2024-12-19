#include <iostream>
#include "Map.h"
#include<utility>
#include<vector>
#include "Tank.h"

#include "routing.h"



#include "Player.h"

using namespace http;
int main()
{
	/*Map map(3);
	map.GenerateWalls(3);
	map.DisplayMap();*/

	/*Tank t(Tank::ColorTank::Blue);
	std::cout<<t.GetColor();*/
	//Routing r;
	//r.Run();
    // 
    // for database 
        // Inițializăm baza de date
        //Database db("clients.db");

        //// Adăugăm un client nou
        //if (db.addClient("user1", 100)) {
        //    std::cout << "Client 'user1' added successfully!" << std::endl;
        //}
        //else {
        //    std::cerr << "Failed to add client 'user1'." << std::endl;
        //}

        //// Verificăm dacă utilizatorul există
        //if (db.clientExists("user1")) {
        //    std::cout << "Client 'user1' exists in the database." << std::endl;
        //}
        //else {
        //    std::cerr << "Client 'user1' does not exist in the database." << std::endl;
        //}

        //// Salvăm tastele de control pentru utilizator
        //if (db.saveKeyBindings("user1", "W", "S", "A", "D")) {
        //    std::cout << "Key bindings for 'user1' saved successfully!" << std::endl;
        //}
        //else {
        //    std::cerr << "Failed to save key bindings for 'user1'." << std::endl;
        //}

        //// Actualizăm punctajul utilizatorului
        //if (db.updateScore("user1", 150)) {
        //    std::cout << "Score for 'user1' updated successfully!" << std::endl;
        //}
        //else {
        //    std::cerr << "Failed to update score for 'user1'." << std::endl;
        //}

        //// Obținem punctajul utilizatorului
        //int score = db.getScore("user1");
        //if (score != -1) {
        //    std::cout << "Score for 'user1': " << score << std::endl;
        //}
        //else {
        //    std::cerr << "Failed to retrieve score for 'user1'." << std::endl;
        //}

        //// Ștergem utilizatorul din baza de date
        //if (db.deleteClient("user1")) {
        //    std::cout << "Client 'user1' deleted successfully!" << std::endl;
        //}
        //else {
        //    std::cerr << "Failed to delete client 'user1'." << std::endl;
        //}


    // for player
    //Database db("clients.db");

    //// Adăugăm jucători
    //Player player1("Player1", db, false);
    //Player player2("Player2", db, false);

    //// Afișăm starea inițială
    //std::cout << player1.getName() << " starts with " << player1.getLives() << " lives." << std::endl;
    //std::cout << player2.getName() << " starts with " << player2.getLives() << " lives." << std::endl;

    //// Simulăm pierderi și câștiguri de vieți
    //player1.loseLife();
    //player1.loseLife();
    //player1.gainLife();

    //player2.loseLife();

    //// Salvăm starea în baza de date
    //player1.saveState();
    //player2.saveState();

    //// Afișăm starea finală
    //std::cout << player1.getName() << " has " << player1.getLives() << " lives left." << std::endl;
    //std::cout << player2.getName() << " has " << player2.getLives() << " lives left." << std::endl;


	return 0;
}
