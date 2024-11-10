#ifndef MINESWEEPER_BOARD
#define MINESWEEPER_BOARD

#include "Array2D.h"
#include <iostream>

// poziomy trudnosci
enum GameMode { DEBUG, EASY, NORMAL, HARD };

// status gry
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

// struktura z informacjami do kazdego pola
struct Field {
  bool hasMine;
  bool hasFlag;
  bool isRevealed;
};

/************************************************/
//  ============ GŁÓWNA KLASA SAPERA ============
//  - posiada info o wymiarach planszy
//  - posiada info o każdym polu na planszy
//  - proste funkcje "get" zwracające info
//    np. o szerokości planszy, il. min
//  - funkcje do odkrywania pól, stawiania
//    flag etc. (oraz funkcje pomocnicze do nich)
/************************************************/
class MinesweeperBoard {
  //  tablica przechowująca struktury pól
  Field board[100][100];

  // rzeczywista wysokość planszy
  int width, height;

  // poziom trudnosci
  GameMode mode;

  // aktualny stan gry
  GameState game_state;

  // info o ilosci min na planszy
  int how_much_mines;

  // zmienna bool do pierwszego ruchu
  // (true = pierwszy ruch, false = każdy kolejny)
  bool first_move;

  // sprawdza czy wszystkie pola bez min są odkryte
  void is_it_finished();

public:
  // konstruktor planszy, stawia miny zależnie od poziomu
  MinesweeperBoard(int width, int height, GameMode mode);

  // proste "getters"
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;
  int getGameMode() const;

  // sprawdza czy pole jest na planszy
  bool is_on_board(int row, int col) const;

  // wyswietla same miny - funkcja do debug'u
  void debug_display();

  // liczy miny do okoła, lub zwraca (-1) dla nieudanego liczenia
  int countMines(int row, int col) const;

  // sprawdza czy jest flaga
  bool hasFlag(int row, int col) const;

  // ustawia flagę
  void toggleFlag(int row, int col);

  // pomocnicza funkcja do revealField,
  // sprawdza czy można odkryć polę
  bool can_i_revealField(int row, int col);
  // odkrywa pole. dla pola z il. min = 0
  // odkrywa wszystkie pola do okoła niego
  void revealField(int row, int col);

  // return true if the field was revealed
  bool isRevealed(int row, int col) const;

  // zwaraca stan gry
  GameState getGameState() const;

  // zwraca info o polu (mina, flaga, puste etc.)
  char getFieldInfo(int row, int col) const;
};

#endif