#ifndef MS_SFML_CONTROLER
#define MS_SFML_CONTROLER

#include "Array2D.h"
#include "minesweeperboard.h"
#include "MSSFMLView.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace sf{
class Event;
}

/************************************************/
//  ========= KLASA STERUJĄCA SFML VIEW =========
//  - posiada info o wymiarach planszy
//  - posiada info o marginesach
//  - ma dostęp do klasy board i view
/************************************************/
class MSSFMLController {
  MinesweeperBoard &board;
  MSSFMLView &view;

  int x, y;
  int xoffset = 100;
  int yoffset = 50;
  float field_size = 51;

public:
  // konstruktor z referencją do board i view
  MSSFMLController(MinesweeperBoard &b, MSSFMLView &v);

  // funkcja odpowiedzialna za obsługę myszy 
  // (L: odkryj, R: flaga)
  void handleEvent (sf::Event &event);
};

#endif