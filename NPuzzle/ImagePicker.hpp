#pragma once
#pragma once
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>

#include <vector>



#include <map>

#include "State.hpp"
#include "Game.hpp"




class Gameplay : public Engine::State {
public:
	Gameplay(std::shared_ptr<Context>& context, int _puzzleSize = 3);
	~Gameplay();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;


private:
	std::shared_ptr<Context> m_context;
	sf::Text m_title;

	

	int puzzleSize;





};