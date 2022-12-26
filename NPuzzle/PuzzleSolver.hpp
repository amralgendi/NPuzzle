//
//  PuzzleSolver.hpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#ifndef PuzzleSolver_hpp
#define PuzzleSolver_hpp

#include <stdio.h>
#include "PuzzleState.hpp"

/// Function to calculate the number of misplaced tiles. This returns the number of non-blank tiles not in their goal final position.
/// @param state the state to calculate for the cost
/// @param finalState the final ending state
int calculateCost(PuzzleState & state, PuzzleState & finalState);

/// Function to check if (x, y) is a valid matrix coordinate. Used to check if the random generated move is in bounds.
/// @param x newX value
/// @param y newY Value
/// @param N  Dynamic array size
int isSafe(int x, int y, int N);

/// The main solving function.
/// @param initialState  the state of the puzlle in which the algorithm starts from.
/// @param finalState the state of the puzzle in which the user must match to win the game.
void solve(PuzzleState & initialState, PuzzleState & finalState, PuzzleState*& result, int emptySpace);


// MARK: - IsSolvable Utils

/// Function that calculates the number of inversion in the matix spread out into a one dimensional array
/// @param arr initial puzzle matrix
/// @param N  number of rows in the matrix
int getInvCount(int arr[], int N);

/// Gets the row index of the blank tile X
/// @param puzzleState Puzzle state given
int findXPosition(PuzzleState & puzzleState);

/// Description Checks if the puzzle given is solvable
/// @param puzzleState Puzzle state given
bool isSolvable(PuzzleState & puzzleState);

#endif /* PuzzleSolver_hpp */
