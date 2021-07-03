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

class Game {
    
private:
    // variables
    
    // window
    sf::RenderWindow* window;
    sf::VideoMode vidMode;
    sf::Event ev;
    
    // Game objects
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
    
    // getters
    
    // setters
};

#endif /* Game_hpp */
