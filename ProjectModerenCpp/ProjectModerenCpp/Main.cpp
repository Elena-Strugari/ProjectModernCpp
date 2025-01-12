#include <iostream>
#include<utility>
#include<vector>

#include "routing.h"

int main() {

    http::Routing r;
    r.Run();
    return 0;
}



//#include "Game.h"
//#include "PlayerGameObjectManager.h"

//#include "Map.h";
//#include "GameObject.h"
//#include "MovementObject.h"
//#include "Player.h"
//#include "PlayerManager.h"
//#include "Game.h"
//
//using namespace http;
//int main()
//{

    //testare map si tot ce are
    /*Bomb bomb(5, 5);
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

    //test 2 -
    //try {
    //    // Create a map at level 1
    //    Map map(1);

    //    std::cout << "Initial Map:" << std::endl;
    //    map.DisplayMap();

    //    // Place a tank on the map
    //    uint16_t tankX = 3, tankY = 3;
    //    map.PlaceTank(tankX, tankY, Map::Tank());
    //    std::cout << "\nMap After Placing Tank at (" << tankX << ", " << tankY << "):" << std::endl;
    //    map.DisplayMap();

    //    // Place a bomb on the map
    //    uint16_t bombX = 5, bombY = 5;
    //    map.PlaceBomb(bombX, bombY);
    //    std::cout << "\nMap After Placing Bomb at (" << bombX << ", " << bombY << "):" << std::endl;
    //    map.DisplayMap();

    //    // Place a bonus life on the map
    //    uint16_t lifeX = 7, lifeY = 7;
    //    map.PlaceBonusLife(lifeX, lifeY);
    //    std::cout << "\nMap After Placing Bonus Life at (" << lifeX << ", " << lifeY << "):" << std::endl;
    //    map.DisplayMap();

    //    // Try accessing a valid cell
    //    auto cell = map.GetCell(tankX, tankY);
    //    std::cout << "\nCell at (" << tankX << ", " << tankY << ") contains: ";
    //    std::visit([](const auto& content) {
    //        using T = std::decay_t<decltype(content)>;
    //        if constexpr (std::is_same_v<T, Map::Tank>) {
    //            std::cout << "Tank";
    //        }
    //        else if constexpr (std::is_same_v<T, Map::Bomb>) {
    //            std::cout << "Bomb";
    //        }
    //        else if constexpr (std::is_same_v<T, Map::BonusLife>) {
    //            std::cout << "BonusLife";
    //        }
    //        else if constexpr (std::is_same_v<T, Wall::TypeWall>) {
    //            std::cout << "Wall";
    //        }
    //        else {
    //            std::cout << "Empty";
    //        }
    //        }, cell.content);
    //    std::cout << std::endl;

    //}
    //catch (const std::exception& ex) {
    //    std::cerr << "Error: " << ex.what() << std::endl;
    //}


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

//playerManager
    //Database db("clients.db");
    //PlayerManager manager;

    //// Create players using shared_ptr
    //auto player1 = std::make_shared<Player>("Player1", db, GameObject(Tank(Tank::ColorTank::Red)));
    //auto player2 = std::make_shared<Player>("Player2", db, GameObject(Tank(Tank::ColorTank::Blue)));

    //// Add players to the manager
    //manager.AddPlayer(player1);
    //manager.AddPlayer(player2);

    //// Display all players
    //std::cout << "All players:" << std::endl;
    //manager.DisplayAllPlayers();

    //// Get a specific player
    //auto retrievedPlayer = manager.GetPlayer("Player1");
    //if (retrievedPlayer) {
    //    std::cout << "Retrieved Player: " << retrievedPlayer->GetName() << std::endl;
    //}

    //// Remove a player
    //manager.RemovePlayer("Player2");
    //std::cout << "After removing Player2:" << std::endl;
    //manager.DisplayAllPlayers();



// test game
   // Database db("game_database.db");
   // Game game(1);

   // // Creează jucători și îi adaugă în joc
   // auto tank1 = std::make_shared<Tank>(Tank::ColorTank::Red);
   // auto tank2 = std::make_shared<Tank>(Tank::ColorTank::Blue);

   // auto gameObject1 = GameObject(std::move(*tank1));
   // auto gameObject2 = GameObject(std::move(*tank2));

   // auto player1 = std::make_shared<Player>("Player1", db, std::move(gameObject1));
   // auto player2 = std::make_shared<Player>("Player2", db, std::move(gameObject2));

   // game.AddPlayer(player1);
   // game.AddPlayer(player2);

   // // Afișează starea inițială
   // std::cout << "Initial Game State:\n";
   // //game.Display();

   // // Mută jucătorii
   // std::cout << "\nMoving players:\n";
   // game.MovePlayer("Player1", MovementObject::Direction::Up);
   // game.MovePlayer("Player2", MovementObject::Direction::Right);

   // // Actualizează starea jocului
   // //game.Update();

   // // Afișează starea finală
   // std::cout << "\nFinal Game State:\n";
   //// game.Display();

// test 2 game
    // Initialize game
    //Database db("game_database.db");
    //Game game(1);

    //// Create players
    //auto player1 = std::make_shared<Player>("Player1", db, GameObject(Tank(Tank::ColorTank::Red)));
    //auto player2 = std::make_shared<Player>("Player2", db, GameObject(Tank(Tank::ColorTank::Blue)));

    //// Add players to the game
    //game.AddPlayer(player1);
    //game.AddPlayer(player2);

    //// Display the map with players
    //game.Start();

    //// Move Player1
    //game.MovePlayer("Player1", MovementObject::Direction::Right);
    //game.MovePlayer("Player1", MovementObject::Direction::Down);

    //// Display the map again
    //game.Start();

    // test 3

    */
    /*Database db("players.db");
    Game game(1);

    auto player1 = std::make_shared<Player>("Player1", db, GameObject(Tank(Tank::ColorTank::Red)));
    auto player2 = std::make_shared<Player>("Player2", db, GameObject(Tank(Tank::ColorTank::Blue)));

    game.AddPlayer(player1);
    game.AddPlayer(player2);

    game.Start();

    game.MovePlayer(player1, MovementObject::Direction::Right);
    game.MovePlayer(player2, MovementObject::Direction::Up);
    game.Start();

    game.MovePlayer(player1, MovementObject::Direction::Down);
    game.MovePlayer(player2, MovementObject::Direction::Left);
    game.Start();*/


    //testare bullet 
        //Database db("players.db");

        //Game game(1);

        //auto player1 = std::make_shared<Player>("Player1", db, GameObject(Tank(Tank::ColorTank::Red)));
        //game.AddPlayer(player1);

        //game.ShootBulletS(player1);

        //for (int i = 0; i < 5; ++i) {
        //    game.MoveBullets();
        //    game.Start();
        //  //  game.m_map.DisplayMap();
        //    std::this_thread::sleep_for(std::chrono::milliseconds(500));
        //}

    //test 2
//    int main()
//    {
//    Database db("players.db");
//    Game game(1);
//
//    // Create players
//    auto player1 = std::make_shared<Player>("Player1", db, GameObject(Tank(Tank::ColorTank::Red)));
//    auto player2 = std::make_shared<Player>("Player2", db, GameObject(Tank(Tank::ColorTank::Blue)));
//    auto player3 = std::make_shared<Player>("Player3", db, GameObject(Tank(Tank::ColorTank::Green)));
//    auto player4 = std::make_shared<Player>("Player4", db, GameObject(Tank(Tank::ColorTank::Yellow)));
//
//    // Add players to the game
//    game.AddPlayer(player1);
//    game.AddPlayer(player2);
//    game.AddPlayer(player3);
//    game.AddPlayer(player4);
//
//    // Start the game
//    game.Start();
//
//    //Players move their tanks
//    game.MovePlayer(player1, MovementObject::Direction::Right);
//    //game.MovePlayer(player2, MovementObject::Direction::Up);
//
//     //Player1 shoots a bullet
//    std::cout << "Player1 shoots a bullet!\n";
//    player1->GetMovementObject().Shoot();
//
//    // Move Player2
//    game.MovePlayer(player2, MovementObject::Direction::Up);
//    game.MovePlayer(player3, MovementObject::Direction::Left);
//    game.MovePlayer(player4, MovementObject::Direction::Up);
//    game.Start();
//
//
//    //  Move Player1's bullet until it deactivates
//    while (player1->GetMovementObject().IsBulletActive()) {
//        player1->GetMovementObject().Move(player1->GetMovementObject().GetDirection(), 1);
//        game.Start();
//
//        // Check for bullet collision or boundary (dummy condition here)
//        game.MoveBullets();
//
//    }
//    return 0;
//
//}
//

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
    


	/*return 0;
}*/

