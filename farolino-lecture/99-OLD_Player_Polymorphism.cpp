#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Board {
private:
  int rows, cols;
  vector<vector<int> > multiDimensionalBoard;

  void buildBoard() {
    this->multiDimensionalBoard.resize(this->rows);
    
    for (int i = 0; i < multiDimensionalBoard.size(); ++i) {
      multiDimensionalBoard[i].resize(this->cols);
    }
  }

  bool positionAvailable(int x, y) {
    return multiDimensionalBoard.at(x % this->rows).at(y % this->cols) == 0;
  }

  void removePlayer(int x, int y) {
    multiDimensionalBoard.at(x % this->rows).at(y % this->cols) = 0;
  }

  bool addPlayerToBoard(int playerX, int playerY, int playerNumber) {
    multiDimensionalBoard.at(x % this->rows).at(y % this->cols) = playerNumber;
  }

public:
  Board(int inputRows, int inputCols) {
    this->rows = inputRows;
    this->cols = inputCols;
    
    this->buildBoard();
  }

  void printBoard() {
    for (int i = 0; i < multiDimensionalBoard.size(); ++i) {

      for (int j = 0; j < multiDimensionalBoard[i].size(); ++j) {
        cout << multiDimensionalBoard[i][j] << " ";
      }
      cout << endl;
    }
  }

  bool updateBoard(int currentX, int currentY, int updatedX, int updatedY, int playerNumber) {
    if (positionAvailable(updatedX, updatedY)) {
      removePlayer(currentY, currentY);
      addPlayerToBoard(updatedX, updatedY, playerNumber);
      return true;
    }

    return false;
  }

};

class Player {
private:
  int x, y, playerNumber;
  Board* board;

  Player(int inputPlayerNumber, Board* inputBoard) {
    this->playerNumber = inputPlayerNumber;
    this->board = inputBoard;
  }

  virtual void makeMove() = 0;
};

class HumanPlayer : public Player {
public:
  HumanPlayer
};

class HumanPlayer {

};

int main() {
  Board* board = new Board(5, 10);

  for (int i = 0; i < 15; ++i) {
    board->printBoard();
    cin.get();
    system("clear");
    board->updateBoard(0, 0, 0, i, 1);
  }

  delete board;
  return 0;
}