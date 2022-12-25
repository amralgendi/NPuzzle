#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>

#include "Gameplay.hpp"

Game::Game():m_context(std::make_shared<Context>()) {
	m_context->m_window->create(sf::VideoMode(1000, 1000), "SFML works!") ;
    //m_context->m_window->setFramerateLimit(60);
    m_context->m_states->add(std::make_unique<Gameplay>(m_context, 3));
}

Game::~Game() {

}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (m_context -> m_window ->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame < TIME_PER_FRAME) {
            timeSinceLastFrame -= TIME_PER_FRAME;

            m_context->m_states->processStateChange();
            m_context->m_states->getCurrent()->processInput();
            m_context->m_states->getCurrent()->update(TIME_PER_FRAME);
            m_context->m_states->getCurrent()->draw();

           
        }


    }
}