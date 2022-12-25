#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class MainMenu: public Engine::State {
public:
	MainMenu(std::shared_ptr<Context> &context);
	~MainMenu();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;


private: 
	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle;

	sf::Text m_playBtn;
	sf::Text m_exitBtn;

	bool isPlayBtnSelected;
	bool isPlayBtnPressed;

	bool isExitBtnSelected;
	bool isExitBtnPressed;
};