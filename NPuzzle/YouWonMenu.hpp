#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

class YouWonMenu : public Engine::State {
public:
	YouWonMenu(std::shared_ptr<Context>& context);
	~YouWonMenu();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;


private:
	std::shared_ptr<Context> m_context;
	sf::Sprite m_icon;
	sf::Text m_gameTitle;

	sf::Text m_title;

	sf::Text m_playBtn;
	sf::RectangleShape m_playBtnBG;

	sf::Text m_exitBtn;
	sf::RectangleShape m_exitBtnnBG;

	bool isPlayBtnSelected;
	bool isPlayBtnPressed;

	bool isExitBtnSelected;
	bool isExitBtnPressed;

};