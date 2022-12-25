#include <SFML/Window/Event.hpp>
#include "GameSettings.hpp"


GameSettings::GameSettings(std::shared_ptr<Context>& context) :m_context(context), isRightBtnSelected(false), isLeftBtnSelected(false), isRightBtnPressed(false), isLeftBtnPressed(false), selectedDifficulty(MEDIUM){
	difficulties[EASY] = "Easy 3x3";
	difficulties[MEDIUM] = "Medium 4x4";
	difficulties[HARD] = "Hard 5x5";

	puzzleSize[EASY] = 3;
	puzzleSize[MEDIUM] = 4;
	puzzleSize[HARD] = 5;
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

	float textLeftEdge = m_difficultyText.getPosition().x - m_difficultyText.getLocalBounds().width / 2 - 5.f;
	float textRightEdge = m_difficultyText.getPosition().x + m_difficultyText.getLocalBounds().width / 2 + 5.f;

	m_rightBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_rightBtn.setString("Right");
	m_rightBtn.setOrigin(0, m_rightBtn.getLocalBounds().height / 2);
	m_rightBtn.setPosition(textRightEdge, m_context->m_window->getSize().y / 2.f);

	

	//m_rightBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 1.5);


	m_leftBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_leftBtn.setString("Left");
	m_leftBtn.setOrigin(m_leftBtn.getLocalBounds().width, m_leftBtn.getLocalBounds().height / 2);
	m_leftBtn.setPosition(textLeftEdge, m_context->m_window->getSize().y / 2.f);
}
void GameSettings::processInput() {
	sf::Event event;

	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)
			{
			case sf::Keyboard::Right: {
				selectedDifficulty++;
				break;
			}
			case sf::Keyboard::Left: {
				selectedDifficulty--;
				break;
			}
			default:
				break;
			}
		}
	}
}
void GameSettings::update(sf::Time) {
	/*m_playBtn.setFillColor(isPlayBtnSelected ? sf::Color::Yellow : sf::Color::White);
	m_exitBtn.setFillColor(isExitBtnSelected ? sf::Color::Yellow : sf::Color::White);*/
	m_difficultyText.setString(difficulties[selectedDifficulty]);
	m_difficultyText.setOrigin(m_difficultyText.getLocalBounds().width / 2, m_difficultyText.getLocalBounds().height / 2);
	m_difficultyText.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);


	float textLeftEdge = m_difficultyText.getPosition().x - m_difficultyText.getLocalBounds().width / 2 - 5.f;
	float textRightEdge = m_difficultyText.getPosition().x + m_difficultyText.getLocalBounds().width / 2 + 5.f;

	m_rightBtn.setPosition(textRightEdge, m_context->m_window->getSize().y / 2.f);
	m_leftBtn.setPosition(textLeftEdge, m_context->m_window->getSize().y / 2.f);

}
void GameSettings::draw() {

	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_gameSettingsTitle);
	m_context->m_window->draw(m_difficultyText);
	m_context->m_window->draw(m_rightBtn);
	m_context->m_window->draw(m_leftBtn);


	m_context->m_window->display();
}