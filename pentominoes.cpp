/* -------------------------------- pentominoes.cpp ------------------------------
Author: Kyle Oliveira

Provides implementation code for solving the pentominoes problem presented in
homework #2. Matrix copying procedure in initalizing functions co-created with
Anton Uzun, ECS110 W07. connectedTo function developed by Anton Uzun and used with
permission.
---------------------------------------------------------------------------- */

#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std; 


// -------------------------------- class Piece ---------------------------------
// Defines a Piece class to hold the piece name and different orientations

class Piece
{
public:
  int orientation[8][5][5];
  int rotations;
  void initI();
  void initL();
  void initY();
  void initT();
  void initZ();
  void initU();
  void initN();
  void initW();
  void initX();
  void initP();
  void initV();
  void initF();
}; // class Piece

// -------------------------------- class Board ---------------------------------
// Defines a Piece class to hold the piece name and different orientations

class Board
{
public:
  int board[8][8];
  bool placed[12];
  void init()
  {
    int initializer[8][8] = {
    {49,0,0,0,0,0,0,49},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {49,0,0,0,0,0,0,49},
    };
    for(int i=0; i<8 ; i++)
      for(int j=0; j<8 ; j++)
        board[i][j] = initializer[i][j]; // initialize board without corners
    for(int i=0; i<12; i++)
      placed[i] = 0;
  }
  void placePiece(int p[5][5], int i, int j, int z);
  void removePiece(int p[5][5], int i, int j, int z);
  void solvePuzzle(Piece *p, int placedCount);
  void printResult();
  void copyBoard(Board& b)
  {
    for(int i=0; i<8 ; i++)
      for(int j=0; j<8 ; j++)
        board[i][j] = b.board[i][j];

    for(int i=0; i<12 ; i++)
      placed[i] = b.placed[i];
  }
  bool validate(int p[5][5], int i, int j);

}; // class Board

// ---------------------------- predeclarations ---------------------------------
// Functions that will come later and global variables

void printResult(Board fb);
void initPieces(Piece *p);
int connectedTo(Board& b, int x, int y);

// ----------------------------------- main() -----------------------------------
// Main function. Durr...

int main()
{
  Board checkerBoard; //create board matrix
  Piece pieces[12]; //create array of pieces
  checkerBoard.init();  //initialize board matrix
  initPieces(pieces); //initialize pieces array
  checkerBoard.solvePuzzle(pieces,0); //solve the puzzle
  return 0;
} //main()


// -------------------------------- initPieces() --------------------------------
// Sets each piece in the pieces array to a particular piece

void initPieces(Piece *p)
{
  p[0].initX(); //set p[0] to piece X
  p[1].initI(); //set p[1] to piece I
  p[2].initT(); //set p[2] to piece T
  p[3].initZ(); //set p[3] to piece Z
  p[4].initU(); //set p[4] to piece U
  p[5].initW(); //set p[5] to piece W
  p[6].initV(); //set p[6] to piece V
  p[7].initL(); //set p[7] to piece L
  p[8].initY(); //set p[8] to piece Y
  p[9].initN(); //set p[9] to piece N
  p[10].initP(); //set p[10] to piece P
  p[11].initF(); //set p[11] to piece F
} //initPieces()

// ---------------------------------- initI() -----------------------------------
// Sets a piece to the I configuration

void Piece::initI()
{
  int or0[5][5] = {
  {73,0,0,0,0},
  {73,0,0,0,0},
  {73,0,0,0,0},
  {73,0,0,0,0},
  {73,0,0,0,0},
  };
  int or1[5][5] = {
  {73,73,73,73,73},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
    };

  rotations = 2;
  return;
} //initI()


// ------------------------------------ initL() -----------------------------------
// Sets a piece to the L configuration

void Piece::initL()
{
  int or0[5][5] = {
  {76,0,0,0,0},
  {76,0,0,0,0},
  {76,0,0,0,0},
  {76,76,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,76,0,0,0},
  {0,76,0,0,0},
  {0,76,0,0,0},
  {76,76,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {76,76,0,0,0},
  {76,0,0,0,0},
  {76,0,0,0,0},
  {76,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {76,76,0,0,0},
  {0,76,0,0,0},
  {0,76,0,0,0},
  {0,76,0,0,0},
  {0,0,0,0,0},
  };
  int or4[5][5] = {
  {0,0,0,76,0},
  {76,76,76,76,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or5[5][5] = {
  {76,76,76,76,0},
  {0,0,0,76,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or6[5][5] = {
  {76,0,0,0,0},
  {76,76,76,76,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or7[5][5] = {
  {76,76,76,76,0},
  {76,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
      orientation[4][i][j] = or4[i][j];
      orientation[5][i][j] = or5[i][j];
      orientation[6][i][j] = or6[i][j];
      orientation[7][i][j] = or7[i][j];
    };

  rotations = 8;
  return;
} //initL()

// ------------------------------------ initY() -----------------------------------
// Sets a piece to the Y configuration

void Piece::initY()
{
  int or0[5][5] = {
  {89,0,0,0,0},
  {89,89,0,0,0},
  {89,0,0,0,0},
  {89,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,89,0,0,0},
  {89,89,0,0,0},
  {0,89,0,0,0},
  {0,89,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {89,0,0,0,0},
  {89,0,0,0,0},
  {89,89,0,0,0},
  {89,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {0,89,0,0,0},
  {0,89,0,0,0},
  {89,89,0,0,0},
  {0,89,0,0,0},
  {0,0,0,0,0},
  };
  int or4[5][5] = {
  {0,0,89,0,0},
  {89,89,89,89,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or5[5][5] = {
  {89,89,89,89,0},
  {0,0,89,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or6[5][5] = {
  {89,89,89,89,0},
  {0,89,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or7[5][5] = {
  {0,89,0,0,0},
  {89,89,89,89,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
      orientation[4][i][j] = or4[i][j];
      orientation[5][i][j] = or5[i][j];
      orientation[6][i][j] = or6[i][j];
      orientation[7][i][j] = or7[i][j];
    };

  rotations = 8;
  return;
} //initY()

// ------------------------------------ initT() -----------------------------------
// Sets a piece to the T configuration

void Piece::initT()
{
  int or0[5][5] = {
  {84,84,84,0,0},
  {0,84,0,0,0},
  {0,84,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,84,0,0,0},
  {0,84,0,0,0},
  {84,84,84,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {84,0,0,0,0},
  {84,84,84,0,0},
  {84,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {0,0,84,0,0},
  {84,84,84,0,0},
  {0,0,84,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
    };

  rotations = 4;
  return;
} //initT()


// ------------------------------------ initZ() -----------------------------------
// Sets a piece to the Z configuration

void Piece::initZ()
{
  int or0[5][5] = {
  {90,90,0,0,0},
  {0,90,0,0,0},
  {0,90,90,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,90,90,0,0},
  {0,90,0,0,0},
  {90,90,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {0,0,90,0,0},
  {90,90,90,0,0},
  {90,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {90,0,0,0,0},
  {90,90,90,0,0},
  {0,0,90,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
    };

  rotations = 4;
  return;
} //initZ()


// ----------------------------------- initU() -----------------------------------
// Sets a piece to the U configuration

void Piece::initU()
{
  int or0[5][5] = {
  {85,0,85,0,0},
  {85,85,85,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {85,85,85,0,0},
  {85,0,85,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {85,85,0,0,0},
  {85,0,0,0,0},
  {85,85,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {85,85,0,0,0},
  {0,85,0,0,0},
  {85,85,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
    };

  rotations = 4;
  return;
} //initU()


// ------------------------------------ initN() -----------------------------------
// Sets a piece to the N configuration

void Piece::initN()
{
  int or0[5][5] = {
  {78,0,0,0,0},
  {78,78,0,0,0},
  {0,78,0,0,0},
  {0,78,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,78,0,0,0},
  {78,78,0,0,0},
  {78,0,0,0,0},
  {78,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {0,78,78,78,0},
  {78,78,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {78,78,78,0,0},
  {0,0,78,78,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or4[5][5] = {
  {78,78,0,0,0},
  {0,78,78,78,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or5[5][5] = {
  {0,0,78,78,0},
  {78,78,78,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or6[5][5] = {
  {0,78,0,0,0},
  {0,78,0,0,0},
  {78,78,0,0,0},
  {78,0,0,0,0},
  {0,0,0,0,0},
  };
  int or7[5][5] = {
  {78,0,0,0,0},
  {78,0,0,0,0},
  {78,78,0,0,0},
  {0,78,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
      orientation[4][i][j] = or4[i][j];
      orientation[5][i][j] = or5[i][j];
      orientation[6][i][j] = or6[i][j];
      orientation[7][i][j] = or7[i][j];
    };

  rotations = 8;
  return;
} //initN()


// ------------------------------------ initW() -----------------------------------
// Sets a piece to the W configuration

void Piece::initW()
{
  int or0[5][5] = {
  {87,0,0,0,0},
  {87,87,0,0,0},
  {0,87,87,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {0,0,87,0,0},
  {0,87,87,0,0},
  {87,87,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {0,87,87,0,0},
  {87,87,0,0,0},
  {87,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {87,87,0,0,0},
  {0,87,87,0,0},
  {0,0,87,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
    };

  rotations = 4;
  return;
} //initW()


// ------------------------------------ initX() -----------------------------------
// Sets a piece to the X configuration

void Piece::initX()
{
  int or0[5][5] = {
  {0,88,0,0,0},
  {88,88,88,0,0},
  {0,88,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
      orientation[0][i][j] = or0[i][j];

  rotations = 1;
  return;
} //initX()


// ------------------------------------ initP() -----------------------------------
// Sets a piece to the P configuration

void Piece::initP()
{
  int or0[5][5] = {
  {80,80,0,0,0},
  {80,80,0,0,0},
  {80,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {80,80,0,0,0},
  {80,80,0,0,0},
  {0,80,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {80,0,0,0,0},
  {80,80,0,0,0},
  {80,80,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {0,80,0,0,0},
  {80,80,0,0,0},
  {80,80,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or4[5][5] = {
  {80,80,80,0,0},
  {0,80,80,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or5[5][5] = {
  {80,80,80,0,0},
  {0,80,80,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or6[5][5] = {
  {80,80,0,0,0},
  {80,80,80,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or7[5][5] = {
  {0,80,80,0,0},
  {80,80,80,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
      orientation[4][i][j] = or4[i][j];
      orientation[5][i][j] = or5[i][j];
      orientation[6][i][j] = or6[i][j];
      orientation[7][i][j] = or7[i][j];
    };

  rotations = 8;
  return;
} //initP()


// ------------------------------------ initV() -----------------------------------
// Sets a piece to the V configuration

void Piece::initV()
{
  int or0[5][5] = {
  {86,86,86,0,0},
  {0,0,86,0,0},
  {0,0,86,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {86,86,86,0,0},
  {86,0,0,0,0},
  {86,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {86,0,0,0,0},
  {86,0,0,0,0},
  {86,86,86,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {0,0,86,0,0},
  {0,0,86,0,0},
  {86,86,86,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
    };

  rotations = 4;
  return;
} //initV()


// ------------------------------------ initF() -----------------------------------
// Sets a piece to the F configuration

void Piece::initF()
{
  int or0[5][5] = {
  {0,70,70,0,0},
  {70,70,0,0,0},
  {0,70,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or1[5][5] = {
  {70,70,0,0,0},
  {0,70,70,0,0},
  {0,70,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or2[5][5] = {
  {0,70,0,0,0},
  {70,70,0,0,0},
  {0,70,70,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or3[5][5] = {
  {0,70,0,0,0},
  {0,70,70,0,0},
  {70,70,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or4[5][5] = {
  {70,0,0,0,0},
  {70,70,70,0,0},
  {0,70,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or5[5][5] = {
  {0,0,70,0,0},
  {70,70,70,0,0},
  {0,70,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or6[5][5] = {
  {0,70,0,0,0},
  {70,70,70,0,0},
  {70,0,0,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };
  int or7[5][5] = {
  {0,70,0,0,0},
  {70,70,70,0,0},
  {0,0,70,0,0},
  {0,0,0,0,0},
  {0,0,0,0,0},
  };

  for(int i=0; i<5; i++)
    for(int j=0; j<5; j++)
    {
      orientation[0][i][j] = or0[i][j];
      orientation[1][i][j] = or1[i][j];
      orientation[2][i][j] = or2[i][j];
      orientation[3][i][j] = or3[i][j];
      orientation[4][i][j] = or4[i][j];
      orientation[5][i][j] = or5[i][j];
      orientation[6][i][j] = or6[i][j];
      orientation[7][i][j] = or7[i][j];
    };

  rotations = 8;
  return;
} //initF()

// -------------------------------- solvePuzzle() ---------------------------------
// Recursive function for solving the puzzle

void Board::solvePuzzle(Piece *p, int placedCount)
{
  int a,b,c,i,j;
  Board copy;

  for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++)
    { 
      copy.copyBoard(*this);
      c = connectedTo(copy,i,j);
      if(!board[i][j] && (c%5 != 0))
        return;
    } //make sure the placement makes sense

  if(placedCount == 12)
  {
    printResult();
    exit(0);
  } //if we've placed every piece

  for(i = 0; i < 8; i++) //rows
    for(j = 0; j < 8; j++) //columns
      for(a = 0; a < 12; a++) //pieces
        if(!placed[a])
        {
          for(b = 0; b < p[a].rotations; b++) //orientations
          {
            if(validate(p[a].orientation[b],i,j))
            {
              placePiece(p[a].orientation[b],i,j,a); //place the piece
              solvePuzzle(p,(placedCount+1));
              removePiece(p[a].orientation[b],i,j,a);
            } //if the piece can actually go there
          }
        } //if the piece hasn't been placed
} //solvePuzzle()


// --------------------------------- placePiece() ---------------------------------
// Piece placing function. Only places one orientation, naturally.

void Board::placePiece(int p[5][5], int i, int j, int z)
{
  //printResult(*this);
  for(int x = 0; x < 5; x++)
    for(int y = 0; y < 5; y++)
    {
      if(p[x][y])
        board[(i+x)][(j+y)] = p[x][y]; //place the piece on the board
    }
  
  placed[z] = 1;
  return;
} //placePiece()


// --------------------------------- removePiece() ---------------------------------
// Piece removing function.

void Board::removePiece(int p[5][5], int i, int j, int z)
{
  for(int x = 0; x < 5; x++)
    for(int y = 0; y < 5; y++)
    {
      if(p[x][y])
        board[(i+x)][(j+y)] = 0; //remove the piece from the board
    }
  
  placed[z] = 0;
  return;
} //removePiece()


// -------------------------------- connectedTo() ---------------------------------
// Checks to see if there are spaces of surrounded, connected spaces of 3 or less

int connectedTo(Board& b, int x, int y)//finds the size of the block that x,y is part of
{
  int total=1;
  if (b.board[x][y])//already filled
    return total;

  b.board[x][y]='!'; //flag as counted

  if (x>0 && !b.board[x-1][y])//look west
    total+=connectedTo(b, x-1, y);
  if (x<7 && !b.board[x+1][y])//look east
    total+=connectedTo(b, x+1, y);
  if (y>0 && !b.board[x][y-1])//look north
    total+=connectedTo(b, x, y-1);
  if (y<7 && !b.board[x][y+1])//look south
    total+=connectedTo(b, x, y+1);
  return total;

} //connectedTo()


// -------------------------------- validate() ---------------------------------
// Tells whether we can place a piece in a particular place

bool Board::validate(int p[5][5], int i, int j)
{
  for(int x = 0; x < 5; x++)
    for(int y = 0; y < 5; y++)
    {
      if(board[(i+x)][(j+y)] && p[x][y])
        return 0; //if the space on the board is not empty and there is a block to place
      if(((i+x) > 7 || (j+y) > 7) && p[x][y])
        return 0; //if we're trying to access a space beyond the board, and there's still part of a piece to place
    }

  return 1;
}

// -------------------------------- printResult() ---------------------------------
// Prints the final route count and finishes gracefully

void Board::printResult()
{
  cout << "\nSolution:" << endl;
  for(int i=0; i<8 ; i++)
  {
    cout << endl;
    for(int j=0; j<8 ; j++)
    {
      cout << "[";
      if(!board[i][j] || board[i][j] == '1')
        cout << " ";
      else
        cout << (char)board[i][j];
      cout << "]";
    }
  }
  cout << endl << endl;
  cout << "Thank you and have a great day!" << endl << endl;
  return;
} //printResult()
 
