#include <iostream>
#include<utility>
#include<vector>

#include "routing.h"



//#include "Game.h"
//#include "PlayerGameObjectManager.h"

//#include "Map.h";
//#include "GameObject.h"
//#include "MovementObject.h"
#include "Player.h"


using namespace http;
int main()
{

    //testare map si tot ce are
   /* Bomb bomb(5, 5);
    std::cout << bomb << std::endl;

    bomb.explode();
    bomb.isExploded();
    std::cout << bomb << std::endl;
    Bomb bomb2(5, 5);
    bomb2.setX(6);
    bomb2.explode();
    std::cout<<bomb2.isExploded()<<std::endl;
    std::cout << bomb2 << std::endl;


    BonusLife bonusLife(5, 5);
    std::cout << bonusLife << std::endl;

    bonusLife.collected();
    bonusLife.isCollected();
    std::cout << bonusLife << std::endl;
    BonusLife bonusLife2(5, 5);
    bonusLife2.setX(6);
    bonusLife2.collected();
    std::cout << bonusLife2.isCollected() << std::endl;
    std::cout << bonusLife2 << std::endl;

    Map map(3);
    map.DisplayMap();*/


    // Test creating tanks with different colors
    //Tank redTank(Tank::ColorTank::Red);
    //Tank blueTank(Tank::ColorTank::Blue);
    //Tank greenTank(Tank::ColorTank::Green);
    //Tank yellowTank(Tank::ColorTank::Yellow);

    //// Print tank colors
    //std::cout << "Red Tank Color: " << static_cast<int>(redTank.GetColor()) << std::endl;
    //std::cout << "Blue Tank Color: " << static_cast<int>(blueTank.GetColor()) << std::endl;
    //std::cout << "Green Tank Color: " << static_cast<int>(greenTank.GetColor()) << std::endl;
    //std::cout << "Yellow Tank Color: " << static_cast<int>(yellowTank.GetColor()) << std::endl;

    //// Create GameObjects with tanks
    //GameObject redGameObject(std::move(redTank));
    //GameObject blueGameObject(std::move(blueTank)); // rvalue reference

    //// Print GameObject tanks
    //std::cout << redGameObject << std::endl;
    //std::cout << blueGameObject << std::endl;

    //// Test shooting bullets
    //std::cout << "Shooting red tank's bullet:" << std::endl;
    //redGameObject.ShootBullet();

    //std::cout << "Shooting blue tank's bullet:" << std::endl;
    //blueGameObject.ShootBullet();

    //// Check if bullets are active
    //std::cout << "Red tank bullet active? " << (redGameObject.GetBullet().IsActive() ? "Yes" : "No") << std::endl;
    //std::cout << "Blue tank bullet active? " << (blueGameObject.GetBullet().IsActive() ? "Yes" : "No") << std::endl;

    //// Deactivate bullets manually and test again
    //std::cout << "Deactivating bullets..." << std::endl;
    //redGameObject.GetBullet().SetBullet(false);
    //blueGameObject.GetBullet().SetBullet(false);

    //std::cout << "Red tank bullet active? " << (redGameObject.GetBullet().IsActive() ? "Yes" : "No") << std::endl;
    //std::cout << "Blue tank bullet active? " << (blueGameObject.GetBullet().IsActive() ? "Yes" : "No") << std::endl;

    //
    //testare move
        //Tank redTank(Tank::ColorTank::Red);
        //Bullet bullet;

        //GameObject gameObject(std::move(redTank), std::move(bullet));
        //MovementObject movement(gameObject);

        //movement.SetPosition(5, 5); // Initial position
        //movement.Move(MovementObject::Direction::Up);    // Move up
        //movement.print();
        //movement.Move(MovementObject::Direction::Right); // Move right
        //movement.print();
      
//pt player 
    // Initialize database
   // Database db("clients.db");

   // // Create a tank and a bullet
   // Tank redTank(Tank::ColorTank::Red);
   // Bullet bullet;

   // // Create a game object with the tank and bullet
   // GameObject gameObject(std::move(redTank), std::move(bullet));

   // // Create a player using the game object
   // Player player("Player1", db, std::move(gameObject));

   // // Display player information
   // std::cout << "Player name: " << player.GetName() << std::endl;
   // std::cout << "Player score: " << player.GetScore() << std::endl;
   // std::cout << "Player lives: " << player.GetLives() << std::endl;

   // player.LoseLife();
   // std::cout << "Player lives: " << player.GetLives() << std::endl;
   // player.GainLife();
   // std::cout << "Player lives after get: " << player.GetLives() << std::endl;
   //// player.AddScore(2);
   // //std::cout << "Player score: " << player.GetScore() << std::endl;

   // // Test player actions
   // player.GetMovementObject().Move(MovementObject::Direction::Up);
   // player.GetMovementObject().Move(MovementObject::Direction::Right);
   // //player.GetObject().ShootBullet();
   // 

   // // Save the player's state
   // player.SaveState();








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


    //game 
    //Database db("clients.db");

    //// Creează jocul (nivelul 1)
    //Game game(1);

    //// Creează un Player
    //Player player1("Player1", db, false);

    //// Creează un GameObject (tank)
    //Tank tank(Tank::ColorTank::Blue);
    //GameObject gameObject(Tank::ColorTank::Blue);

    //// Creează un MovementObject
    //MovementObject movement(&gameObject);

    //// Adaugă jucătorul în joc
    //game.addPlayer(&player1, &movement);

    //// Mută jucătorul
    //game.movePlayer(&player1, MovementObject::Direction::Up);
    //game.movePlayer(&player1, MovementObject::Direction::Right);

    //// Actualizează starea jocului (de exemplu, coliziuni)
    //game.update();
    


	return 0;
}

