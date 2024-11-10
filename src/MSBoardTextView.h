#ifndef MS_BOARD_TEXT_VIEW
#define MS_BOARD_TEXT_VIEW

#include "Array2D.h"
#include "minesweeperboard.h"
#include <SFML/Graphics/Texture.hpp>
#include <iostream>


/*****************************************************/
//  =========== KLASA WYŚWIETLAJĄCA SAPERA ===========
//  - kożysta z geterów do pozystakania szerokości i
//    wysokości
//  - wyświetla dane za pomocą funkcji getFieldInfo()
/*****************************************************/
class MSBoardTextView {
  MinesweeperBoard &board;

public:
  // konstruktor z referencją do board
  MSBoardTextView(MinesweeperBoard &board);

  // funkcja wyświetlająca całą planszę w trybie tekstowym
  void display() const;
};

#endif