//
//  PuzzleState.hpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#ifndef PuzzleState_hpp
#define PuzzleState_hpp

#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;

/// Class that stores data of an individual puzzle state
class PuzzleState {
public:
    
    // MARK: - Attributes
    
    /// dynamic 2d array of puzzle state
    int ** mat;
    
    /// dynamic 2d array size
    int N;
    
    /// stores blank tile coordinates
    int x, y;
    
    /// stores the number of misplaced tiles
    int cost;
    
    /// stores the number of moves so far
    int level;

    PuzzleState* parent;
    
    // MARK: - Constructors
    
    /// Constructor for initlizing the puzzle state
    /// @param _parentMat parent matrix to generate from new state by swapping location of empty space
    /// @param _N dynamic 2d array size
    /// @param _x parent blank tile x coordinate
    /// @param _y parent blank tile y coordinate
    /// @param _newX  current state blank tile x coordinate
    /// @param _newY current state blank tile y coordinate
    /// @param _level current state level
    /// @param _cost default val(INT_MAX) the number of moves so far in the tree of states
    PuzzleState(PuzzleState * _parent,
                int ** _parentMat,
                int _N,
                int _x, int _y,
                int _newX, int _newY,
                int _level, int _cost = INT_MAX);
    
    PuzzleState();
    
    // MARK: - Main Methods
    
    /// Print current state's matrix
    void printMatrix() const;


    const PuzzleState& operator=(const PuzzleState& rightHandSide);
};

/// << operator overloading
ostream & operator<< (ostream & out, const PuzzleState & puzzleState);

#endif /* PuzzleState_hpp */
