#include "MSSFMLView.h"
#include "minesweeperboard.h"
#include <SFML/Graphics.hpp>
#include <cassert>

MSSFMLView::MSSFMLView(MinesweeperBoard &b) : board{b} {
  assert(texture[0].loadFromFile("MS_textures/MS_number_1.PNG"));
  num[1].setTexture(texture[0]);

  assert(texture[1].loadFromFile("MS_textures/MS_number_2.PNG"));
  num[2].setTexture(texture[1]);

  assert(texture[2].loadFromFile("MS_textures/MS_number_3.PNG"));
  num[3].setTexture(texture[2]);

  assert(texture[3].loadFromFile("MS_textures/MS_number_4.PNG"));
  num[4].setTexture(texture[3]);

  assert(texture[4].loadFromFile("MS_textures/MS_number_5.PNG"));
  num[5].setTexture(texture[4]);

  assert(texture[5].loadFromFile("MS_textures/MS_number_6.PNG"));
  num[6].setTexture(texture[5]);

  assert(texture[6].loadFromFile("MS_textures/MS_number_7.PNG"));
  num[7].setTexture(texture[6]);

  assert(texture[7].loadFromFile("MS_textures/MS_number_8.PNG"));
  num[8].setTexture(texture[7]);

  assert(texture[8].loadFromFile("MS_textures/MS_mine.PNG"));
  mine.setTexture(texture[8]);

  assert(texture[9].loadFromFile("MS_textures/MS_blank.PNG"));
  blank.setTexture(texture[9]);

  assert(texture[10].loadFromFile("MS_textures/MS_flag.PNG"));
  flag.setTexture(texture[10]);

  assert(texture[11].loadFromFile("MS_textures/MS_free_space.PNG"));
  free_space.setTexture(texture[11]);

  assert(texture[12].loadFromFile("MS_textures/LOSS.PNG"));
  loss_sign.setTexture(texture[12]);

  assert(texture[13].loadFromFile("MS_textures/WIN.PNG"));
  win_sign.setTexture(texture[13]);
}

void MSSFMLView::draw(sf::RenderWindow &win) {

  // wyświetla teksturę w zależności od getFieldInfo
  for (int row = 0; row < board.getBoardHeight(); row++) {
    for (int col = 0; col < board.getBoardWidth(); col++) {
      xpos = gap + col * (field_size);
      ypos = gap + row * (field_size);

      switch (board.getFieldInfo(row, col)) {
      case 'F':
        flag.setPosition(xpos, ypos);
        win.draw(flag);
        break;
      case ' ':
        blank.setPosition(xpos, ypos);
        win.draw(blank);
        break;
      case 'x':
        mine.setPosition(xpos, ypos);
        win.draw(mine);
        break;
      case '0':
        free_space.setPosition(xpos, ypos);
        win.draw(free_space);
        break;
      case '1':
        num[1].setPosition(xpos, ypos);
        win.draw(num[1]);
        break;
      case '2':
        num[2].setPosition(xpos, ypos);
        win.draw(num[2]);
        break;
      case '3':
        num[3].setPosition(xpos, ypos);
        win.draw(num[3]);
        break;
      case '4':
        num[4].setPosition(xpos, ypos);
        win.draw(num[4]);
        break;
      case '5':
        num[5].setPosition(xpos, ypos);
        win.draw(num[5]);
        break;
      case '6':
        num[6].setPosition(xpos, ypos);
        win.draw(num[6]);
        break;
      case '7':
        num[7].setPosition(xpos, ypos);
        win.draw(num[7]);
        break;
      case '8':
        num[8].setPosition(xpos, ypos);
        win.draw(num[8]);
      }
    }
  }

  // sprawdza stan gry i wyświetla komunikat
  if (board.getGameState() != RUNNING) {
    int x = (2 * gap + board.getBoardWidth() * field_size) / 2 - 124;
    int y = (2 * gap + board.getBoardHeight() * field_size) / 2 - 62;

    if (board.getGameState() == FINISHED_WIN) {
      // wysrodkowywanie komunikatu wygranej
      win_sign.setPosition(x, y);
      win.draw(win_sign);
    }
    if (board.getGameState() == FINISHED_LOSS) {
      // wysrodkowywanie komunikatu przegranej
      loss_sign.setPosition(x, y);
      win.draw(loss_sign);
    }
  }
}

void MSSFMLView::parameters(int gap) { this->gap = gap; }

int MSSFMLView::getGap() { return (this->gap); }