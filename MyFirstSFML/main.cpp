
/*
 Vicente Ochoa
 */

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include "Game.hpp"

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

int main(int, char const**)
{
    // init srand
    std::srand(static_cast<unsigned>(time(NULL)));
    
    // init game engine
    Game game;
    
    // Game Loop
    while(game.running()) {
        
        // event polling
        // whenever the window gets an event it saves it to ev
        // then we can use ev to decide what to do
        // test git
        
        
        // Update
        game.update();
        
        // Render
        game.render();
        
        // here draw your game
        // between clear and display
        
    }
    
    return 0;
}
