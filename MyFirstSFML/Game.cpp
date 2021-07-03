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
    
}

// constructors and destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
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
    pollEvents();
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
    this->window->clear(sf::Color::Red);
    this->window->display();
    
    
}

#include "Game.hpp"
