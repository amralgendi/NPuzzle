#include <SFML/Window/Event.hpp>
#include "ImagePicker.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <experimental/filesystem>
#include "Gameplay.hpp"
#include "MainMenu.hpp"

ImagePicker::ImagePicker(std::shared_ptr<Context>& context, int _puzzleSize) :m_context(context), isReady(false), selectedImageIndex(0), puzzleSize(_puzzleSize) {
	std::string IMAGE_DIRECTORY = "assets/images";
	std::cout << puzzleSize << std::endl;
	for (const auto& entry : std::experimental::filesystem::directory_iterator(IMAGE_DIRECTORY)) {

		//std::string fileName = entry.path();
		std::cout << entry.path().u8string().substr(entry.path().u8string().find_last_of('\\') + 1, entry.path().u8string().find('.')) << std::endl;

		imagePaths.push_back(entry.path().u8string());

		sf::Text t;
		imageSelectionTexts.push_back(t);
	}
}

ImagePicker::~ImagePicker() {}

void ImagePicker::init() {
	m_context->m_assets->addFont(MAIN_FONT, "assets\\fonts\\Pacifico-Regular.ttf");
	m_context->m_assets->addTexture(1022, "assets\\images\\left.png", true);

	m_left.setPosition(50, 110);
	m_left.setTexture(m_context->m_assets->getTexture(1022));

	m_title.setFont(m_context->m_assets->getFont(MAIN_FONT));
	m_title.setString("Choose Img");
	m_title.setPosition((m_context->m_window->getSize().x / 2) - (m_title.getLocalBounds().width / 2), m_left.getTexture()->getSize().y +(m_left.getTexture()->getSize().y / 2)-(m_title.getPosition().y / 2));

	for (int i = 0; i < imagePaths.size(); i++) {
		imageSelectionTexts[i].setFont(m_context->m_assets->getFont(MAIN_FONT));
		imageSelectionTexts[i].setString(imagePaths[i].substr(imagePaths[i].find_last_of('\\') + 1, imagePaths[i].find('.'))); //imagePaths[i].substr(imagePaths[i].find_last_of('\\') + 1, imagePaths[i].find('.'))
		imageSelectionTexts[i].setOrigin(imageSelectionTexts[i].getLocalBounds().width / 2, imageSelectionTexts[i].getLocalBounds().height / 2);
		imageSelectionTexts[i].setPosition(m_context->m_window->getSize().x /2.f, m_title.getPosition().y + ((i + 1) * 100));
	}

	
}
bool lock_click;
void ImagePicker::processInput() {
	sf::Event event;


	while (m_context->m_window->pollEvent(event))
	{

		if (event.type == sf::Event::MouseButtonPressed) { //Mouse button Pressed 

			sf::Vector2f mouse = m_context->m_window->mapPixelToCoords(sf::Mouse::getPosition(*(m_context->m_window)));

			// retrieve the bounding box of the sprite
			sf::FloatRect bounds = m_left.getGlobalBounds();

			if (bounds.contains(mouse) && event.mouseButton.button == sf::Mouse::Left && lock_click != true) //specifies
			{
				/* your code here*/
				m_context->m_states->add(std::make_unique<MainMenu>(m_context));
				lock_click = true; //And now, after all your code, this will lock the loop and not print "lmb" in a x held time. 
				/* or here idk */
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) //Mouse button Released now.
		{
			if (event.mouseButton.button == sf::Mouse::Left) //specifies the held button       again. (You can make a variable for that if you want)
			{
				lock_click = false; //unlock when the button has been released.
			}
		}
		if (event.type == sf::Event::Closed)
			m_context->m_window->close();

			if (event.type == sf::Event::KeyPressed) {
				switch (event.key.code)
				{
				case sf::Keyboard::Down: {
					if (selectedImageIndex != imagePaths.size() - 1) selectedImageIndex++;
					break;
				}
				case sf::Keyboard::Up: {
					if (selectedImageIndex != 0) selectedImageIndex--;
					break;
				}
				case sf::Keyboard::Return: {
					isReady = true;
					break;
				}
				default:
					break;
				}
			}
	}
}
void ImagePicker::update(sf::Time) {
	if (isReady) {
		std::cout << imagePaths[selectedImageIndex] << ' ' << puzzleSize << '\n';
		m_context->m_states->add(std::make_unique<Gameplay>(m_context,imagePaths[selectedImageIndex], puzzleSize));
	}

	for (int i = 0; i < imageSelectionTexts.size(); i++) {
		imageSelectionTexts[i].setFillColor(selectedImageIndex == i ? sf::Color{ 239, 65, 124 } : sf::Color::White);
	}
	//m_difficultyText.setString(difficulties[selectedDifficulty]);
	//m_difficultyText.setOrigin(m_difficultyText.getLocalBounds().width / 2, m_difficultyText.getLocalBounds().height / 2);
	//m_difficultyText.setPosition(m_context->m_window->getSize().x / 2.f, m_context->m_window->getSize().y / 2.f);


	//float textLeftEdge = m_difficultyText.getPosition().x - m_difficultyText.getLocalBounds().width / 2 - 5.f;
	//float textRightEdge = m_difficultyText.getPosition().x + m_difficultyText.getLocalBounds().width / 2 + 5.f;

	//m_rightBtn.setPosition(textRightEdge, m_context->m_window->getSize().y / 2.f);
	//m_leftBtn.setPosition(textLeftEdge, m_context->m_window->getSize().y / 2.f);

}
void ImagePicker::draw() {
	m_context->m_window->clear(sf::Color{ 19, 26, 64 });
	m_context->m_window->draw(m_left);
	m_context->m_window->draw(m_title);

	for (int i = 0; i < imagePaths.size(); i++) {
		m_context->m_window->draw(imageSelectionTexts[i]);
	}
	
	//m_context->m_window->draw(imagePieces[0]);
	//std::cout << imagePieces[0].getOrigin().x;



	m_context->m_window->display();
}