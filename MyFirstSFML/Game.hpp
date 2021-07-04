//
//  Game.hpp
//  MyFirstSFML
//
//  Created by Vicente Ochoa on 6/28/21.
//  Copyright © 2021 Vicente Ochoa. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <ctime>

class Game {
    
private:
    // variables
    
    // window
    sf::RenderWindow* window;
    sf::VideoMode vidMode;
    sf::Event ev;
    
    // Mouse positions
    sf::Vector2i mousePosWindow;
    
    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    int maxEnemies;
    
    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;
    
    
    // private functions
    void initVariables();
    
    void initWindow();
    void initEnemies();

public:
    // constructors and destructors
    Game();
    virtual ~Game();
    
    // Accessors
    const bool running();
    
    // functions
    void update();
    void render();
    void pollEvents();
    void updateMousePositions();
    void spawnEnemy();
    void updateEnemies();
    void renderEnemies();
    
    // getters
    
    // setters
};

#endif /* Game_hpp */
