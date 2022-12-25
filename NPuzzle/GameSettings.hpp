#pragma once

#include <memory>
#include <SFML/Graphics/Text.hpp>

#include <map>

#include "State.hpp"
#include "Game.hpp"

enum {
	EASY = 0, MEDIUM = 1, HARD = 2
};





class GameSettings : public Engine::State {
public:
	GameSettings(std::shared_ptr<Context>& context);
	~GameSettings();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;


private:
	std::shared_ptr<Context> m_context;
	sf::Text m_gameSettingsTitle;
	sf::Text m_difficultyText;


	sf::Text m_rightBtn;
	sf::Text m_leftBtn;

	bool isRightBtnSelected;
	bool isRightBtnPressed;

	int selectedDifficulty;

	std::map<int, std::string> difficulties;


	bool isLeftBtnSelected;
	bool isLeftBtnPressed;

};