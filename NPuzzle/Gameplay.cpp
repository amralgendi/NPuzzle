#include <SFML/Window/Event.hpp>
#include "Gameplay.hpp"
#include <string>
#include <iostream>


Gameplay::Gameplay(std::shared_ptr<Context>& context, std::string _imagePath, int _puzzleSize) :keyPressed(NONE), m_context(context), stepNum(0), imagePath(_imagePath), puzzleSize(_puzzleSize) {
	imagePieces = new sf::Sprite[puzzleSize * puzzleSize];
}

Gameplay::~Gameplay() {}

void Gameplay::init() {
	m_context->m_assets->addTexture(IMAGE_PUZZLE, imagePath, true);
	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");

	m_title.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_title.setString("Start");
	m_title.setOrigin(m_title.getLocalBounds().width / 2, m_title.getLocalBounds().height / 2);
	m_title.setPosition(m_context->m_window->getSize().x / 3.f, 50);

	m_stepNumText.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_stepNumText.setString(std::to_string(stepNum));
	m_stepNumText.setOrigin(m_stepNumText.getLocalBounds().width / 2, m_stepNumText.getLocalBounds().height / 2);
	m_stepNumText.setPosition(m_context->m_window->getSize().x / 1.5, 50);

	board.setSize(sf::Vector2f(750, 750));
	board.setOrigin(375, 375);
	board.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);
	board.setFillColor(sf::Color::White);

	int textureSize = m_context->m_assets->getTexture(IMAGE_PUZZLE).getSize().x;


	std::cout << textureSize << '\n';
	int size = 400;
	float spriteSize = float(textureSize) / puzzleSize;

	std::cout << spriteSize << '\n';


	//for (int i = 0; i < puzzleSize * puzzleSize - 1; i++) {
	//	(i % puzzleSize) * puzzleSize
	//}

	//imagePieces[0].setTexture(m_context->m_assets->getTexture(IMAGE_PUZZLE));
	//imagePieces[0].setTextureRect(sf::IntRect(0 * spriteSize, 0 * spriteSize, spriteSize, spriteSize));
	//imagePieces[0].setOrigin(5, 5);
	puzzleState = new int* [puzzleSize];
	for (int i = 0; i < puzzleSize; i++)puzzleState[i] = new int[puzzleSize];


	int arr[4][4] = {
		{0, 1, 2, 3},
		{4, 5, 6, 15},
		{8, 9, 10, 7},
		{12, 13, 14, 11}
	};
	int n1 = 0;
	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize; j++) {
			puzzleState[i][j] = n1;
			n1++;
		}

	}

	int n = 0;

	float scalingFactor = 750.f / textureSize;

	std::cout << scalingFactor;

	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize; j++) {
			if (i == puzzleSize - 1 && j == puzzleSize - 1) { n++; continue; }

			std::cout << i << ' ' << j << ' ' << i * spriteSize << ' ' << j * spriteSize << '\n';

			imagePieces[n].setTexture(m_context->m_assets->getTexture(IMAGE_PUZZLE));
			imagePieces[n].setTextureRect(sf::IntRect(j * spriteSize, i * spriteSize, spriteSize, spriteSize));
			imagePieces[n].setScale(scalingFactor, scalingFactor);
			n++;
		}
	}




	//std::cout << n;
	/*for (int i = 0; i < n ; i++) {
		std::cout << i;
		imagePieces[i].setPosition(500, 500);
	}*/

}
void Gameplay::processInput() {
	sf::Event event;

	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

		if (event.type == sf::Event::KeyPressed) {
			if (animationStarted) return;
			int emptyX, emptyY;
			FindEmptyLocation(puzzleState, puzzleSize, emptyX, emptyY);
			std::cout << emptyX << ' ' << emptyY << "Check \n";
			switch (event.key.code)
			{
			case sf::Keyboard::Left: {
				keyPressed = LEFT;

				break;
			}
			case sf::Keyboard::Right: {
				keyPressed = RIGHT;
				break;
			}
			case sf::Keyboard::Up: {
				keyPressed = UP;
				break;
			}
			case sf::Keyboard::Down: {
				keyPressed = DOWN;
				break;
			}
			case sf::Keyboard::Return: {
				break;
			}
			default:
				break;
			}
			if (keyPressed != NONE) {
				if (emptyX - Y_MOVING[keyPressed] < 0 || emptyX - Y_MOVING[keyPressed] >= puzzleSize
					|| emptyY - X_MOVING[keyPressed] < 0 || emptyY - X_MOVING[keyPressed] >= puzzleSize) {
					std::cout << "ERROR, CANNOT!!" << '\n';
					return;
				}
				imageIndexToMove = puzzleState[emptyX - Y_MOVING[keyPressed]][emptyY - X_MOVING[keyPressed]];

				int temp = puzzleState[emptyX][emptyY];
				puzzleState[emptyX][emptyY] = puzzleState[emptyX - Y_MOVING[keyPressed]][emptyY - X_MOVING[keyPressed]];
				puzzleState[emptyX - Y_MOVING[keyPressed]][emptyY - X_MOVING[keyPressed]] = temp;

				stepNum++;
				animationStarted = true;
			}
		}
	}
}
void Gameplay::update(sf::Time) {
	m_stepNumText.setString(std::to_string(stepNum));
	int textureSize = m_context->m_assets->getTexture(IMAGE_PUZZLE).getSize().x;
	int size = 400;
	float spriteSize = float(textureSize) / puzzleSize;
	float scalingFactor = 750.f / textureSize;

	if (!animationStarted)
		for (int i = 0; i < puzzleSize; i++) {

			for (int j = 0; j < puzzleSize; j++) {
				if (puzzleState[i][j] == puzzleSize * puzzleSize - 1) continue;
				imagePieces[puzzleState[i][j]].setPosition(j * spriteSize * scalingFactor + 125, i * spriteSize * scalingFactor + 125);

			}
		}
	else {
		std::cout << imageIndexToMove << ' ' << keyPressed << '\n';
		if (amountMoved < spriteSize * scalingFactor)

		{

			float currAmount = amountMoved + animationSpeed < spriteSize* scalingFactor ? animationSpeed : spriteSize * scalingFactor - amountMoved;
			amountMoved += animationSpeed;

			
			float newX = imagePieces[imageIndexToMove].getPosition().x + X_MOVING[keyPressed] * currAmount;
			float newY = imagePieces[imageIndexToMove].getPosition().y + Y_MOVING[keyPressed] * currAmount;

			

			imagePieces[imageIndexToMove].setPosition(newX, newY);
		}
		else {
			animationStarted = false;
			keyPressed = NONE;
			amountMoved = 0;
		}
	}

}
void Gameplay::draw() {

	m_context->m_window->clear(sf::Color::Blue);
	m_context->m_window->draw(m_stepNumText);
	m_context->m_window->draw(m_title);
	m_context->m_window->draw(board);
	//m_context->m_window->draw(imagePieces[0]);

	//std::cout << imagePieces[0].getOrigin().x;

	for (int i = 0; i < puzzleSize * puzzleSize - 1; i++) {
		m_context->m_window->draw(imagePieces[i]);
	}
	//m_context->m_window->draw(imagePieces[selectedIndex]);






	m_context->m_window->display();
}