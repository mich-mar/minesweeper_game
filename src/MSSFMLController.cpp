#include "MSSFMLController.h"
#include "minesweeperboard.h"
#include <SFML/Graphics.hpp>

MSSFMLController::MSSFMLController(MinesweeperBoard &b, MSSFMLView &v)
    : board{b}, view{v} {}

void MSSFMLController::handleEvent(sf::Event &event) {
  if (board.getGameState() == RUNNING) {
    if (event.type == sf::Event::MouseButtonPressed) {
      // sprawdza czy klikamy na planszy bo inaczej dzielenie
      // całkowite dla mniejszych wartości i tak daje 0
      if ((event.mouseButton.x > view.getGap()) &&
          (event.mouseButton.y > view.getGap())) {
        x = (event.mouseButton.x - view.getGap()) / 51;
        y = (event.mouseButton.y - view.getGap()) / 51;

        if (event.mouseButton.button == sf::Mouse::Right) {
          board.toggleFlag(y, x);
        }

        if (event.mouseButton.button == sf::Mouse::Left) {
          board.revealField(y, x);
        }
      }
    }
  }
}
