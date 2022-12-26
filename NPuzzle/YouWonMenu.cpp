#include <SFML/Window/Event.hpp>
#include "YouWonMenu.hpp"
#include "ImagePicker.hpp"
#include "MainMenu.hpp"


YouWonMenu::YouWonMenu(std::shared_ptr<Context>& context) :m_context(context), isPlayBtnSelected(true), isExitBtnSelected(false), isPlayBtnPressed(false), isExitBtnPressed(false) {

}

YouWonMenu::~YouWonMenu() {}

void YouWonMenu::init() {

	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");
	m_context->m_assets->addTexture(1021, "assets\\images\\icon.png", true);

	m_icon.setTexture(m_context->m_assets->getTexture(1021));
	m_icon.setPosition(410, 136);

	m_gameTitle.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_gameTitle.setString("Puzzle Fuzzle");
	m_gameTitle.setPosition((m_context->m_window->getSize().x / 2) - (m_gameTitle.getLocalBounds().width / 2), 353);

	m_title.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_title.setString("You Won!!");
	m_title.setPosition((m_context->m_window->getSize().x / 2) - (m_title.getLocalBounds().width / 2), 500);

	m_playBtnBG.setSize(sf::Vector2f(331, 88));
	m_playBtnBG.setPosition(344, 563);
	m_playBtnBG.setFillColor(sf::Color{ 239, 65, 124 });
	m_playBtnBG.setOutlineThickness(3);

	m_playBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_playBtn.setString("Home");
	m_playBtn.setPosition(458, 519);
	m_playBtn.setPosition(m_playBtnBG.getPosition().x + (m_playBtnBG.getLocalBounds().width / 2) - (m_playBtn.getLocalBounds().width / 2), m_playBtnBG.getPosition().y + (m_playBtnBG.getLocalBounds().height / 2) - (m_playBtn.getLocalBounds().height / 2));

	m_exitBtnnBG.setSize(sf::Vector2f(331, 88));
	m_exitBtnnBG.setPosition(344, 690);
	m_exitBtnnBG.setFillColor(sf::Color{ 239, 65, 124 });
	m_exitBtnnBG.setOutlineThickness(3);

	m_exitBtn.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_exitBtn.setString("Exit");
	m_exitBtn.setPosition(m_exitBtnnBG.getPosition().x + (m_exitBtnnBG.getLocalBounds().width / 2) - (m_exitBtn.getLocalBounds().width / 2), m_exitBtnnBG.getPosition().y + (m_exitBtnnBG.getLocalBounds().height / 2) - (m_exitBtn.getLocalBounds().height / 2));

}
void YouWonMenu::processInput() {
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
void YouWonMenu::update(sf::Time) {

	if (isPlayBtnPressed) {
		m_context->m_states->add(std::make_unique<MainMenu>(m_context));
	}

	else if (isExitBtnPressed)m_context->m_window->close();
	m_playBtnBG.setOutlineColor(isPlayBtnSelected ? sf::Color::White : sf::Color{ 239, 65, 124 });
	m_exitBtnnBG.setOutlineColor(isExitBtnSelected ? sf::Color::White : sf::Color{ 239, 65, 124 });

}
void YouWonMenu::draw() {

	m_context->m_window->clear(sf::Color{ 19, 26, 64 });
	m_context->m_window->draw(m_icon);
	m_context->m_window->draw(m_title);

	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->draw(m_playBtnBG);
	m_context->m_window->draw(m_playBtn);
	m_context->m_window->draw(m_exitBtnnBG);
	m_context->m_window->draw(m_exitBtn);

	m_context->m_window->display();
}