#include <SFML/Window/Event.hpp>
#include "GameSettings.hpp"


GameSettings::GameSettings(std::shared_ptr<Context>& context) :m_context(context), isRightBtnSelected(false), isLeftBtnSelected(false), isRightBtnPressed(false), isLeftBtnPressed(false), selectedDifficulty(EASY){
	difficulties[EASY] = "Easy 3x3";
	difficulties[MEDIUM] = "Medium 4x4";
	difficulties[HARD] = "Hard 5x5";
}

GameSettings::~GameSettings() {}

void GameSettings::init() {
	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");

	m_gameSettingsTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_gameSettingsTitle.setString("Game Settings");
	m_gameSettingsTitle.setOrigin(m_gameSettingsTitle.getLocalBounds().width / 2, m_gameSettingsTitle.getLocalBounds().height / 2);
	m_gameSettingsTitle.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 6.f);

	m_difficultyText.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_difficultyText.setString(difficulties[selectedDifficulty]);
	m_difficultyText.setOrigin(m_difficultyText.getLocalBounds().width / 2, m_difficultyText.getLocalBounds().height / 2);
	m_difficultyText.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);

	m_rightBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_rightBtn.setString("<=");
	m_rightBtn.setOrigin(0, m_rightBtn.getLocalBounds().height / 2);
	m_rightBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);

	//m_rightBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 1.5);

	m_leftBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_leftBtn.setString("=>");
	m_leftBtn.setOrigin(0, m_leftBtn.getLocalBounds().height / 2);
	m_leftBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);
}
void GameSettings::processInput() {
	sf::Event event;

	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

		//if (event.type == sf::Event::KeyPressed) {
		//	switch (event.key.code)
		//	{
		//	case sf::Keyboard::Down: {
		//		if (!isExitBtnSelected) {
		//			isExitBtnSelected = true;
		//			isPlayBtnSelected = false;
		//		}
		//		break;
		//	}
		//	case sf::Keyboard::Up: {
		//		if (!isPlayBtnSelected) {
		//			isPlayBtnSelected = true;
		//			isExitBtnSelected = false;
		//		}
		//		break;
		//	}
		//	case sf::Keyboard::Enter: {

		//		break;
		//	}
		//	default:
		//		break;
		//	}
		//}
	}
}
void GameSettings::update(sf::Time) {
	/*m_playBtn.setFillColor(isPlayBtnSelected ? sf::Color::Yellow : sf::Color::White);
	m_exitBtn.setFillColor(isExitBtnSelected ? sf::Color::Yellow : sf::Color::White);*/

}
void GameSettings::draw() {

	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_gameSettingsTitle);
	m_context->m_window->draw(m_difficultyText);
	m_context->m_window->draw(m_rightBtn);
	m_context->m_window->draw(m_leftBtn);


	m_context->m_window->display();
}