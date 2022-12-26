#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include "State.hpp"
#include "Game.hpp"

enum {
	EASY = 0, MEDIUM = 1, HARD = 2
};

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
	sf::Sprite m_icon;
	sf::Text m_gameTitle;

	sf::Sprite m_left;
	sf::Text m_sizeLabel;
	sf::Sprite m_right;

	sf::Text m_playBtn;
	sf::RectangleShape m_playBtnBG;

	sf::Text m_exitBtn;
	sf::RectangleShape m_exitBtnnBG;

	bool isPlayBtnSelected;
	bool isPlayBtnPressed;

	bool isExitBtnSelected;
	bool isExitBtnPressed;

	int selectedDifficulty;

	std::map<int, std::string> difficulties;
	std::map<int, int> puzzleSize;

};