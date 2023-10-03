#include <iostream>
#include <cstring>

using namespace std;
/* TicTacToe creates a two player tictactoe game 
Author: Rowan Miller
09/21/23 */


void playAgain(bool &stillPlaying, int board[3][3]);
void printBoard(int board[3][3]); 
bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);
void clearBoard(int board[3][3]); 
void restartGame(int board[3][3]);

const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 1;
const int O_TURN = 2;


int main() {
  int board[3][3];
  int turn = X_TURN;
  int xWin = 0;
  int oWin = 0;
  bool stillPlaying = true;
  
  //functions of the board and game
  clearBoard(board);
  while(stillPlaying == true) {
    while(checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false &&
	  checkTie(board) == false) { 
      printBoard(board);
      //checks to see if input is correct
      char input[4];
      cin.get(input, 4);
      cin.get(); 
      if (strlen(input) != 2) {
	cout << "Enter a letter followed by a number" << endl; 
      }
      else if (input[0] != 'a' &&
	       input[0] != 'b' &&
	       input[0] != 'c') {
	cout << "Row must be an a, b, or c." << endl;
      }
      else if (input[1] != '1' &&
	       input[1] != '2' &&
	       input[1] != '3') {
	cout << "Column must be an 1, 2, or 3." << endl;
      }
      //converts inputs and determines whose turn it is
      else {
	int row = input[0] - 'a';
	int column = input[1] - '1';
	if (board[row][column] == BLANK) {
	  if (turn == X_TURN) {
	    board[row][column] = X_MOVE;
	    turn = O_TURN;
	  }
	  else {
	    board[row][column] = O_MOVE;
	    turn = X_TURN;
	  }
	}
	else {
	  cout << "There is a piece there!" << endl;
	}
      }
    }
    //stating who won and running the playAgain method
    if (checkWin(X_MOVE, board) == true) {
      cout << "X Wins!" << endl;
      xWin++;
      cout << "Number of O Wins: " << oWin << endl;
      cout << "Number of X Wins: " << xWin << endl;
      playAgain(stillPlaying, board);
    }
    else if (checkWin(O_MOVE, board) == true) {
      cout << "O Wins!" << endl;
      oWin++;
      cout << "Number of O Wins: " << oWin << endl;
      cout << "Number of X Wins: "<< xWin << endl;
      playAgain(stillPlaying, board);
    }
    if (checkTie(board) == true) {
      cout << "It's a Tie!" << endl;
      cout << "Number of O Wins: " << oWin << endl;
      cout << "Number of X Wins: " << xWin << endl;
      playAgain(stillPlaying, board);
    }
 }
  return 0;
}
//determines whether the player wants to play again
void playAgain(bool &stillPlaying, int board[3][3]) {
  cout << "Play Again?" << endl;
  char yesno[20]; 
  cin.get(yesno, 20);
  cin.get();
  if (yesno[0] == 'y') {
    stillPlaying = true;
    restartGame(board);
  }
  else if (yesno[0] == 'n') {
    stillPlaying = false;
    cout << "Game Over" << endl;
  }
}
//prints the board
void printBoard(int board[3][3]) {
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row++) {
    char output[50];
    output[0] = row + 'a'; 
    int i = 1; 
    for (int column = 0; column < 3; column++) {
	if (board[row][column] == BLANK) {
	  output[i] = '\t';
	  i++;  
	}
	else if (board[row][column] == X_MOVE) {
	  output[i] = '\t';
	  i++;
	  output[i] = 'X';
	  i++;
	}
	else if (board[row][column] == O_MOVE) {
	  output[i] = '\t';
	  i++;
	  output[i] = 'O';
	  i++;
      }
    }
    output[i] = '\0'; 
    cout<< output << endl;
  }
 }
//checks who won the game
bool checkWin(int player, int board[3][3]) {
  //rows
  if (board[0][0] == player && board[0][1] == player && board [0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board [1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board [2][2] == player) {
    return true;
  }
  //columns
  if (board[0][0] == player && board[1][0] == player && board [2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board [2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board [2][2] == player) {
    return true;
  }
  //diagonals
  if (board[0][0] == player && board [1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][2] == player && board[1][1] == player && board [2][0] == player) {
    return true;
  }
  return false;
}
//to check for a tie
bool checkTie(int board[3][3]) {
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == BLANK) {
	return false;
     }
    }
  }
  return true;
}
//clears the board and starts a new game
void clearBoard(int board[3][3]) {
  board [0][0] = BLANK;
  board [0][1] = BLANK;
  board [0][2] = BLANK;
  board [1][0] = BLANK;
  board [1][1] = BLANK;
  board [1][2] = BLANK;
  board [2][0] = BLANK;
  board [2][1] = BLANK;
  board [2][2] = BLANK;
}
//restarts the game
void restartGame(int board[3][3]) {
  clearBoard(board);
}


