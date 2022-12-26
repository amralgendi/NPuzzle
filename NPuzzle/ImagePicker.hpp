#pragma once
#pragma once
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include <vector>



#include <map>

#include "State.hpp"
#include "Game.hpp"




class ImagePicker : public Engine::State {
public:
	ImagePicker(std::shared_ptr<Context>& context, int _puzzleSize = 3);
	~ImagePicker();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;


private:
	std::shared_ptr<Context> m_context;
	sf::Text m_title;

	std::vector<std::string> imagePaths;
	std::vector<sf::Text> imageSelectionTexts;

	int puzzleSize;
	int selectedImageIndex;

	bool isReady;

};