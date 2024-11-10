/*
    Michał Markuzel, 275417
    13.03.2023

    Link do git'a:
   https://zts.ita.pwr.wroc.pl/gitlab/michal.markuzel_275417/saper_michal_markuzel
*/

// główna klasa sapera
#include "minesweeperboard.h"
// biblioteka graficzna
#include <SFML/Graphics.hpp>
// sfml output
#include "MSSFMLController.h"
#include "MSSFMLView.h"
// text output
#include "MSBoardTextView.h"
#include "MSTextController.h"
// reszta bibliotek
#include <iostream>
#include <sys/types.h>

// zmienne potrzebne do wywołania klas sapera i widoku
#define WIDTH 10
#define HEIGHT 10
#define GAP 50
#define MODE GameMode::NORMAL

int main() {

  /*
    //===== Gra w trybie tekstowym =====
    MinesweeperBoard board(6, 6, MODE);
    MSBoardTextView view(board);
    view.display();

    MSTextController ctrl(board, view);

    ctrl.play();
  */

  //============ Gra w SFML ============
  sf::RenderWindow window(
      sf::VideoMode(2 * GAP + WIDTH * 51, 2 * GAP + HEIGHT * 51), "SAPER");

  // wyłączenie synchronizacji z GPU
  window.setVerticalSyncEnabled(false);
  window.setFramerateLimit(30);

  MinesweeperBoard board(WIDTH, HEIGHT, MODE);
  MSSFMLView view(board);
  MSSFMLController controller(board, view);

  // ustawienie marginesów w widoku
  view.parameters(GAP);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed)
        controller.handleEvent(event);
    }

    window.clear(sf::Color::Black);
    view.draw(window);
    window.display();
  }

  return 0;
}
