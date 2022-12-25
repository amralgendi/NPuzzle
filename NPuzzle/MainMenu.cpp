#include <SFML/Window/Event.hpp>
#include "MainMenu.hpp"
#include "GameSettings.hpp"

MainMenu::MainMenu(std::shared_ptr<Context>& context):m_context(context),isPlayBtnSelected(true ), isExitBtnSelected(false), isPlayBtnPressed(false), isExitBtnPressed(false) {}

MainMenu::~MainMenu() {}

void MainMenu::init() {
	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");

	m_gameTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_gameTitle.setString("Puzzle Fuzzle");
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 6.f);

	m_playBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_playBtn.setString("Play");
	m_playBtn.setOrigin(m_playBtn.getLocalBounds().width / 2, m_playBtn.getLocalBounds().height / 2);
	m_playBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);

	m_exitBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_exitBtn.setString("Exit");
	m_exitBtn.setOrigin(m_exitBtn.getLocalBounds().width / 2, m_gameTitle.getLocalBounds().height / 2);
	m_exitBtn.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 1.5);

}
void MainMenu::processInput() {
	sf::Event event;

	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code)
			{
			case sf::Keyboard::Down: {
				if (!isExitBtnSelected) {
					isExitBtnSelected = true;
					isPlayBtnSelected = false;
				}
				break;
			}
			case sf::Keyboard::Up: {
				if (!isPlayBtnSelected) {
					isPlayBtnSelected = true;
					isExitBtnSelected = false;
				}
				break;
			}
			case sf::Keyboard::Enter: {
				if (isPlayBtnSelected)isPlayBtnPressed = true;
				else isExitBtnPressed = true;
				break;
			}
			default:
				break;
			}
		}
	}
}
void MainMenu::update(sf::Time) {

	if (isPlayBtnPressed) {
		m_context->m_states->add(std::make_unique<GameSettings>(m_context));
	}
	m_playBtn.setFillColor(isPlayBtnSelected ? sf::Color::Yellow : sf::Color::White);
	m_exitBtn.setFillColor(isExitBtnSelected ? sf::Color::Yellow : sf::Color::White);


}
void MainMenu::draw() {

	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->draw(m_playBtn);
	m_context->m_window->draw(m_exitBtn);

	m_context->m_window->display();
}