//
//  PuzzleSolver.cpp
//  Project
//
//  Created by Mohamed Salah on 05/12/2022.
//

#include "PuzzleSolver.hpp"
#include "PriorityQueue.hpp"

/// Function to calculate the number of misplaced tiles. This returns the number of non-blank tiles not in their goal final position.
/// @param state the state to calculate for the cost
/// @param finalState the final ending state
int calculateCost(PuzzleState & state, PuzzleState & finalState) {
    int count = 0;
    for (int i = 0; i < state.N; i++)
        for (int j = 0; j < state.N; j++)
            if (state.mat[i][j] && state.mat[i][j] != finalState.mat[i][j])
                count++;
    return count;
}

/// Function to check if (x, y) is a valid matrix coordinate. Used to check if the random generated move is in bounds.
/// @param x newX value
/// @param y newY Value
/// @param N  Dynamic array size
int isSafe(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// bottom, left, top, right
int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

/// The main solving function.
/// @param initialState  the state of the puzlle in which the algorithm starts from.
/// @param finalState the state of the puzzle in which the user must match to win the game.
void solve(PuzzleState & initialState, PuzzleState & finalState, PuzzleState * & result) {
    PriorityQueue<PuzzleState> priorityQueue;
    
    // calculate cost of the root node
    initialState.cost = calculateCost(initialState, finalState);
    
    // Add root to priority queue
    priorityQueue.enqueue(initialState, initialState.cost + initialState.level);
    
    while (!priorityQueue.empty()) {
        // Find the state with least estimated cost
        PuzzleState * stateWithLeastCost = priorityQueue.front();
        
        // Delete the state we will currently test
        priorityQueue.dequeue();

        if (stateWithLeastCost->parent != 0) {
            cout << "PARENT" << endl;
            cout << *(stateWithLeastCost->parent) << endl;
        }
        else {
            cout << "NO PARENT" << endl;
        }
        cout << "CHILD" << endl;
        cout << stateWithLeastCost << endl;
        // if the state has a cost of zero, then it's solved
        if (stateWithLeastCost->cost == 0) {
            result = stateWithLeastCost;
            cout << "solved successfully." << endl;
            return;
        }
        
        // Generate (N-1) to (N+1) different states based on the current empty space in the state
        // for example:
        // 1 2 3                                            1 2 3       1 2 3
        // 4 5 6 -> then we will generate 2 new states -->  0 5 6  and  4 5 6
        // 0 7 8                                            4 7 8       7 0 8
        
        for (int i = 0; i < 4; i++) {
            // if the empty space is new position is not within bounds, then don't create new state
            // example
            //   1 2 3
            //   5 6 7 -> this is clearly out of bounds, therefore only the two states above are considered
            // 0 7 8
            if (!isSafe(stateWithLeastCost->x + row[i], stateWithLeastCost->y + col[i], stateWithLeastCost->N)) {
                continue;
            }
            
            // get the new empty space coordinates
            int newX = stateWithLeastCost->x + row[i];
            int newY = stateWithLeastCost->y + col[i];

            cout << "Will assign parent" << endl;
            cout << stateWithLeastCost << endl;
            // create new state based on the current state by swapping the new empty space position and the old one
            PuzzleState* child = new PuzzleState(stateWithLeastCost, stateWithLeastCost->mat, stateWithLeastCost->N, stateWithLeastCost->x, stateWithLeastCost->y, newX, newY, stateWithLeastCost->level + 1);
            child->cost = calculateCost(*child, finalState);
            
            // finally add the state to the queue
            priorityQueue.enqueue(*child, child->cost + child->level);
        }
    }
}



// MARK: - IsSolvable Utils

/// Function that calculates the number of inversion in the matix spread out into a one dimensional array
/// @param arr initial puzzle matrix
/// @param N  number of rows in the matrix
int getInvCount(int arr[], int N) {
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++) {
        for (int j = i + 1; j < N * N; j++) {
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

/// Gets the row index of the blank tile X
/// @param puzzleState Puzzle state given
int findXPosition(PuzzleState & puzzleState) {
    // start from bottom-right corner of matrix
    for (int i = puzzleState.N - 1; i >= 0; i--)
        for (int j = puzzleState.N - 1; j >= 0; j--)
            if (puzzleState.mat[i][j] == 0)
                return puzzleState.N - i;
    return -1;
}


/// Description Checks if the puzzle given is solvable
/// @param puzzleState Puzzle state given
bool isSolvable(PuzzleState & puzzleState) {
    // Count inversions in given puzzle
    int invCount = getInvCount((int*)puzzleState.mat, puzzleState.N);
    
    // If grid is odd, return true if inversion count is even.
    if (puzzleState.N & 1)
        return !(invCount & 1);
    // If grid is even return true if inversion count is odd and the index of X is even
    else {
        int pos = findXPosition(puzzleState);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}
