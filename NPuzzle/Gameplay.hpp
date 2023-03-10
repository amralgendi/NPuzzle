#pragma once
#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <stack>
#include <vector>
#include "PuzzleState.hpp"



#include <map>

#include "State.hpp"
#include "Game.hpp"

enum KEYS {
	UP, RIGHT, DOWN, LEFT, NONE
};




class Gameplay : public Engine::State {
public:
	Gameplay(std::shared_ptr<Context>& context, std::string _imagePath, int _puzzleSize = 3);
	~Gameplay();

	void init() override;
	void processInput() override;
	void update(sf::Time deltaTime) override;
	void draw() override;





private:


	int X_MOVING[5] = { 0, 1, 0, -1, 0 } ;
	int Y_MOVING[5] = { -1, 0, 1, 0, 0 } ;

	void startSolveAnimation(stack<PuzzleState*>& st);


	void FindLocationOf(int** state, int item, int size, int& x, int& y) {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (state[i][j] == item) {
					x = i;
					y = j;
					return;
				}
			}
		}
	}
	void solveYalla();


	void FindEmptyLocation(int** state, int size, int& x, int& y) {
		return FindLocationOf(state, size * size - 1, size, x, y);
	}


	std::shared_ptr<Context> m_context;
	sf::Text m_title;
	sf::Text m_stepNumText;

	sf::RectangleShape board;

	int puzzleSize;

	int** puzzleState;


	sf::Sprite m_left;
	sf::Sprite m_solveBtn;

	sf::Sprite* imagePieces;

	int stepNum;
	std::string imagePath;

	bool animationStarted = false;
	int imageIndexToMove;
	KEYS keyPressed;
	int maxMove = -1;
	float amountMoved = 0.f;
	float animationSpeed = 3.f;
	bool doneSolving = false;

	std::stack<PuzzleState*> solvingStack ;


};