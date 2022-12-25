#include <SFML/Window/Event.hpp>
#include "Gameplay.hpp"
#include <string>
#include <iostream>


Gameplay::Gameplay(std::shared_ptr<Context>& context, int _puzzleSize) :m_context(context), stepNum(0), puzzleSize(_puzzleSize) {

	

}

Gameplay::~Gameplay() {}

void Gameplay::init() {
	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");

	m_title.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_title.setString("Start");
	m_title.setOrigin(m_title.getLocalBounds().width / 2, m_title.getLocalBounds().height / 2);
	m_title.setPosition(m_context->m_window->getSize().x / 3.f, m_context->m_window->getSize().y / 6.f);

	m_stepNumText.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_stepNumText.setString(std::to_string(stepNum));
	m_stepNumText.setOrigin(m_stepNumText.getLocalBounds().width / 2, m_stepNumText.getLocalBounds().height / 2);
	m_stepNumText.setPosition(m_context->m_window->getSize().x / 1.5, m_context->m_window->getSize().y / 6.f);

	board.setSize(sf::Vector2f(500, 500));
	board.setOrigin(250, 250);
	board.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);
	board.setFillColor(sf::Color::White);
	
	int size = 400;
	int spriteSize = size / puzzleSize;

	sf::Texture t;

	std::cout << t.loadFromFile("assets\\images\\imagepuzzle.png");

	imagePieces = new sf::Sprite[puzzleSize];


	//for (int i = 0; i < puzzleSize * puzzleSize - 1; i++) {
	//	(i % puzzleSize) * puzzleSize
	//}

	imagePieces[0].setTexture(t);
	//imagePieces[0].setTextureRect(sf::IntRect(0 * spriteSize, 0 * spriteSize, spriteSize, spriteSize));
	imagePieces[0].setOrigin(5, 5);

	/*int n = 0;
	for (int i = 0; i < puzzleSize; i++) {

		for (int j = 0; j < puzzleSize; j++) {
			
			imagePieces[n].setTexture(t);
			imagePieces[n].setTextureRect(sf::IntRect(i * spriteSize, j * spriteSize, spriteSize, spriteSize));
			n++;
		}
	}*/

}
void Gameplay::processInput() {
	sf::Event event;

	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

	/*	if (event.type == sf::Event::KeyPressed) {
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
		}*/
	}
}
void Gameplay::update(sf::Time) {
	//m_difficultyText.setString(difficulties[selectedDifficulty]);
	//m_difficultyText.setOrigin(m_difficultyText.getLocalBounds().width / 2, m_difficultyText.getLocalBounds().height / 2);
	//m_difficultyText.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);


	//float textLeftEdge = m_difficultyText.getPosition().x - m_difficultyText.getLocalBounds().width / 2 - 5.f;
	//float textRightEdge = m_difficultyText.getPosition().x + m_difficultyText.getLocalBounds().width / 2 + 5.f;

	//m_rightBtn.setPosition(textRightEdge, m_context->m_window->getSize().y / 2.f);
	//m_leftBtn.setPosition(textLeftEdge, m_context->m_window->getSize().y / 2.f);

}
void Gameplay::draw() {

	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_stepNumText);
	m_context->m_window->draw(m_title);
	m_context->m_window->draw(board);
	m_context->m_window->draw(imagePieces[0]);

	std::cout << imagePieces[0].getOrigin().x;
	
	/*for (int i = 0; i < puzzleSize * puzzleSize; i++) {
		m_context->m_window->draw(imagePieces[i]);
	}*/





	m_context->m_window->display();
}