﻿#include <iostream>
#include<utility>
#include<vector>

#include "routing.h"



#include "Map.h"
#include "PlayerGameObjectManager.h"

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
    //player2.getScore();

    //// Salvăm starea în baza de date
    //player1.saveState();
    //player2.saveState();

    //player1.chooseKeyBindings("W", "S", "A", "D");
    //// Afișăm starea finală
    //std::cout << player1.getName() << " has " << player1.getLives() << " lives left." << std::endl;
    //std::cout << player2.getName() << " has " << player2.getLives() << " lives left." << std::endl;


    //// verif player move 
    //Database db("clients.db");

    //// Creează un Player
    //Player player1("Player1", db, false);

    //// Creează un GameObject (tank)
    //GameObject gameObject(Tank::ColorTank::Blue);

    //// Creează un MovementObject
    //Map map; // Harta jocului
    //MovementObject movement(&gameObject);

    //// Creează un PlayerGameObjectManager
    //PlayerGameObjectManager manager(&player1, &movement);

    //// Controlează tank-ul
    //manager.moveTank(MovementObject::Direction::Up); // Mută tank-ul în sus
    //manager.moveTank(MovementObject::Direction::Right); // Mută tank-ul spre dreapta
    //manager.shoot(); // Tank-ul trage

    //// Afișează statusul jucătorului
    //manager.displayStatus();


	return 0;
}

//