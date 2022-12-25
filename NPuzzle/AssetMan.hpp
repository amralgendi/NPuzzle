#pragma once

#include <map>
#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Engine {
	class AssetMan {
	private:
		std::map<int, std::unique_ptr<sf::Texture>> m_textures;
		std::map<int, std::unique_ptr<sf::Font>> m_fonts;

	public:
		AssetMan();
		~AssetMan();

		void addTexture(int id, const std::string& filePath, bool wantRepeated);
		void addFont(int id, const std::string& filePath);

		const sf::Texture &getTexture(int id)const;
		const sf::Font &getFont(int id)const;


	};
}
