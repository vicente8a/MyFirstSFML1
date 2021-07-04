//
//  Game.cpp
//  MyFirstSFML
//
//  Created by Vicente Ochoa on 6/28/21.
//  Copyright © 2021 Vicente Ochoa. All rights reserved.
//
#include "Game.hpp"
#include <iostream>
#include <stdio.h>

// private functions
void Game::initVariables() {
    this->window = nullptr;
    
    // Game logic
    this->points = 0;
    this->enemySpawnTimerMax = 1000.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;

    this->maxEnemies = 5;
}

void Game::initWindow() {
    int height = this->vidMode.getDesktopMode().height;
    int width = this->vidMode.getDesktopMode().width;
    //this->vidMode.height = height/2;
    //this->vidMode.width = width/2;
    std::cout << height << std::endl;
    std::cout << width << std::endl;
    this->window = new sf::RenderWindow(sf::VideoMode(width/1.33, height/1.33), "My First Game",
                                        sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initEnemies() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(2.f);
    
    
}

// constructors and destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}
Game::~Game() {
    delete this->window;
}

// Accessors
const bool Game::running() {
    return this->window->isOpen();
}

// functions
void Game::update() {
    this->pollEvents();
    this->updateMousePositions();
    this->updateEnemies();
}

void Game::spawnEnemy() {
    /**
     @return void
     Spawns enemies and sets their colors and positions
     Sets a random position
     Sets a random color
     Adds enemy to the vector
     */
    
    this->enemy.setPosition(
        static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
        0.f
        //static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
    );
    
    this->enemy.setFillColor(sf::Color::Green);
    
    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies() {
    // update the timer for enemy spawning
    if(this->enemies.size() < this->maxEnemies) {
        if(this->enemySpawnTimer >= this->enemySpawnTimerMax) {
            this->spawnEnemy();
            this->enemySpawnTimer = 0.f;
        }
        else {
            this->enemySpawnTimer += 1.f;
        }
    }
    
    // Move the enemies
    for(auto &e : this->enemies) {
        e.move(0.f, 1.f);
    }
}

void Game::renderEnemies() {
    for(auto &e : this->enemies) {
        this->window->draw(e);
    }
}

void Game::updateMousePositions() {
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}

void Game::pollEvents() {
    // event polling
    while(this->window->pollEvent(this->ev)) {
        switch(ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                std::cout << static_cast<char>(ev.text.unicode) << std::endl;
                break;
            case sf::Event::KeyPressed:
                if(ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
        }
    }
}

void Game::render() {
    this->window->clear();
    this->renderEnemies();
    this->window->display();
    
    
}

#include "Game.hpp"
