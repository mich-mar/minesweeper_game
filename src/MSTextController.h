#ifndef MST_TEXT_CONTROLLER
#define MST_TEXT_CONTROLLER

#include "MSBoardTextView.h"
#include "minesweeperboard.h"
#include <iostream>

// funkcja do interakcji z graczem
void get_row_and_col(int *x, int *y);

/************************************************/
//  ======== KLASA KONTROLUJĄCA TextView ========
//  - posiada referencje na obie klasy
//  - pyta gracza o ruch, wykonuje go oraz
//    wyświetla planszę po ruchu
/************************************************/
class MSTextController {
  MinesweeperBoard &board;
  MSBoardTextView &view;

public:
  // konstruktor z referencjami na planszę i wyświetlanie
  MSTextController(MinesweeperBoard &b, MSBoardTextView &v);

  // funkcja która prowadzi grę, aż do jej zakończenia
  void play();
};

#endif