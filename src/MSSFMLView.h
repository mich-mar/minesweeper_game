#ifndef MS_SFML_VIEW
#define MS_SFML_VIEW

#include "Array2D.h"
#include "minesweeperboard.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/*****************************************************/
//  =========== KLASA WYŚWIETLAJĄCA SAPERA ===========
//  - kożysta z geterów do pozystakania szerokości i
//    wysokości
//  - wyświetla dane za pomocą funkcji getFieldInfo()
//  - wczytuje tekstury z MS_textures/
/*****************************************************/
class MSSFMLView {
  MinesweeperBoard &board;

  // zmienne do wczytywania textur
  sf::Sprite num[9];
  sf::Sprite flag;
  sf::Sprite mine;
  sf::Sprite blank;
  sf::Sprite loss_sign;
  sf::Sprite win_sign;
  sf::Sprite free_space;
  sf::Texture texture[14];

  int gap = 50;
  float field_size = 51;
  int xpos, ypos;

public:
  // konstruktor z referencją do board
  MSSFMLView(MinesweeperBoard &board);

  // funkcja rysująca planszę
  void draw(sf::RenderWindow &win);

  // funkcja wczytująca wielkość marginesów
  void parameters(int gap);

  // funkcja zwracająca wielkość marginesów
  int getGap();
};

#endif