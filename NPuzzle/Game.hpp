#pragma once

#include <SFML/Graphics/RenderWindow.hpp>


#include "AssetMan.hpp"
#include "StateMan.hpp"

struct Context {
	std::unique_ptr<Engine::AssetMan> m_assets;
	std::unique_ptr<Engine::StateMan> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;

	Context()
	{
		m_states = std::make_unique<Engine::StateMan>();
		m_assets = std::make_unique<Engine::AssetMan>();
		m_window = std::make_unique<sf::RenderWindow>();
	}
};

enum AssetID {
	MAIN_FONT = 0,
	IMAGE_PUZZLE = 1
};

class Game {
private:
	std::shared_ptr<Context> m_context;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.6f);

public:
	Game();
	~Game();

	void run();
};