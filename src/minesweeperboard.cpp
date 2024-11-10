#include "minesweeperboard.h"

void MinesweeperBoard::debug_display() {
  int width = this->width;
  int height = this->height;

  std::cout << std::endl;

  for (int i = 0; i < width; i++) {
    std::cout << "   " << i;
  }

  std::cout << std::endl;

  for (int row = 0; row < height; row++) {
    std::cout << row;

    for (int col = 0; col < width; col++) {
      std::cout << " [";
      if (board[row][col].hasMine == true)
        std::cout << "x";
      else
        std::cout << " ";
      std::cout << "]";
    }
    std::cout << std::endl;
  }
}

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode) {
  this->width = width;
  this->height = height;
  this->mode = mode;
  this->first_move = true;

  int mines_quantity = 0;
  int licznik = 0;
  int width_x, height_y;

  // stworzenie planszy
  for (int row = 0; row < height; row++) {
    for (int col = 0; col < width; col++) {
      board[row][col].hasFlag = false;
      board[row][col].hasMine = false;
      board[row][col].isRevealed = false;
    }
  }

  // ustawienie losowo min dla mode EASY
  if (mode == EASY) {
    if ((height * width) % 10 == 0) {
      mines_quantity = (height * width) / 10;
    } else {
      mines_quantity = (height * width) / 10 + 1;
    }
    while (licznik < mines_quantity) {
      width_x = rand() % width;
      height_y = rand() % height;

      if (board[height_y][width_x].hasMine == false) {
        board[height_y][width_x].hasMine = true;
        licznik++;
      }
    }
  }

  // ustawienie losowo min dla mode NORMAL
  if (mode == NORMAL) {
    if ((height * width * 2) % 10 == 0) {
      mines_quantity = height * width * 0.2;
    } else {
      mines_quantity = (height * width * 0.2) + 1;
    }
    while (licznik < mines_quantity) {
      width_x = rand() % width;
      height_y = rand() % height;

      if (board[height_y][width_x].hasMine == false) {
        board[height_y][width_x].hasMine = true;
        licznik++;
      }
    }
  }

  // ustawienie losowo min dla mode HARD
  if (mode == HARD) {
    if ((height * width * 3) % 10 == 0) {
      mines_quantity = height * width * 0.3;
    } else {
      mines_quantity = (height * width * 0.3) + 1;
    }
    while (licznik < mines_quantity) {
      width_x = rand() % width;
      height_y = rand() % height;

      if (board[height_y][width_x].hasMine == false) {
        board[height_y][width_x].hasMine = true;
        licznik++;
      }
    }
  }

  // fukcja DEBUG ustawia miny w pierwszym rzedzie, po skosie,
  // i co druga w pionie w pierwszej kolumnie
  if (mode == DEBUG) {
    for (int col = 0; col < width; col++) {
      board[0][col].hasMine = true;
      mines_quantity++;
    }

    for (int row = 2; row < height; row += 2) {
      board[row][0].hasMine = true;
      mines_quantity++;
    }

    for (int row = 1; row < height; row++) {
      for (int col = 1; col < width; col++) {
        if (col == row) {
          board[row][col].hasMine = true;
          mines_quantity++;
        }
      }
    }
  }

  this->how_much_mines = mines_quantity;
}

int MinesweeperBoard::getBoardWidth() const { return (this->width); }

int MinesweeperBoard::getBoardHeight() const { return (this->height); }

int MinesweeperBoard::getMineCount() const { return (this->how_much_mines); }

int MinesweeperBoard::getGameMode() const { return (this->mode); }

bool MinesweeperBoard::is_on_board(int row, int col) const {
  if (row < 0 || row >= this->height || col < 0 || col >= this->width)
    return false;
  else
    return true;
}

int MinesweeperBoard::countMines(int row, int col) const {
  int count = 0;

  if (board[row][col].isRevealed == false)
    return -1;

  if (is_on_board(row, col) == false)
    return -1;

  for (int x_row = row - 1; x_row <= row + 1; x_row++)
    for (int y_col = col - 1; y_col <= col + 1; y_col++)
      if (is_on_board(x_row, y_col) and board[x_row][y_col].hasMine == true) {
        count++;
      }

  return (count);
}

bool MinesweeperBoard::hasFlag(int row, int col) const {

  if (!is_on_board(row, col))
    return (false);

  if (board[row][col].isRevealed == true)
    return (false);

  if (board[row][col].hasFlag == true)
    return (true);
  else
    return (false);
}

void MinesweeperBoard::toggleFlag(int row, int col) {
  if (is_on_board(row, col))
    if (board[row][col].isRevealed == false)
      if (this->game_state == RUNNING)
        board[row][col].hasFlag = !board[row][col].hasFlag;
}

bool MinesweeperBoard::can_i_revealField(int row, int col) {

  if (is_on_board(row, col))
    if (board[row][col].isRevealed == false)
      if (this->game_state == RUNNING)
        if (board[row][col].hasFlag == false)
          return true;

  return false;
}

void MinesweeperBoard::revealField(int row, int col) {
  int licznik = 0;
  int width_x, height_y;

  if (can_i_revealField(row, col)) {
    if (board[row][col].hasMine == false) {
      board[row][col].isRevealed = true;

      // dla pola z ilością min do okoła = 0
      if (countMines(row, col) == 0)
        for (int x_row = row - 1; x_row <= row + 1; x_row++)
          for (int y_col = col - 1; y_col <= col + 1; y_col++)
            if (is_on_board(x_row, y_col))
              revealField(x_row, y_col);

      // zmienia first_move po wykonaniu pierwszego ruchu
      if (first_move == true)
        this->first_move = false;
    } else {
      if (mode == DEBUG)
        board[row][col].isRevealed = true;

      if (first_move == false) {
        board[row][col].isRevealed = true;
        this->game_state = FINISHED_LOSS;
      } else {
        board[row][col].hasMine = false;
        board[row][col].isRevealed = true;

        // losowanie nowych współrzędnych dla miny
        while (licznik == 0) {
          width_x = rand() % width;
          height_y = rand() % height;

          if (board[height_y][width_x].hasMine == false) {
            board[height_y][width_x].hasMine = true;
            licznik++;
          }
        }
        // zmienia first_move po wykonaniu pierwszego ruchu
        this->first_move = false;
      }
    }
  }

  // sprawdza czy ten ruch był końcowym
  is_it_finished();
}

bool MinesweeperBoard::isRevealed(int row, int col) const {
  if (board[row][col].isRevealed == true)
    return true;
  else
    return false;
}

GameState MinesweeperBoard::getGameState() const {
  if (game_state == RUNNING)
    return RUNNING;
  else if (game_state == FINISHED_LOSS)
    return FINISHED_LOSS;
  else
    return FINISHED_WIN;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const {

  // poza planszą
  if (!is_on_board(row, col))
    return '#';

  // ma flagę
  if (board[row][col].isRevealed == false && board[row][col].hasFlag == true)
    return 'F';

  // pole nieodkryte
  if (board[row][col].isRevealed == false && board[row][col].hasFlag == false)
    return ' ';

  // pole z miną
  if (board[row][col].isRevealed == true && board[row][col].hasMine == true)
    return 'x';

  // il. min do okoła pola
  if (board[row][col].isRevealed == true && board[row][col].hasMine == false) {
    if (MinesweeperBoard::countMines(row, col) == 0)
      return '0';
    else
      return MinesweeperBoard::countMines(row, col) + '0';
  }

  return '@';
}

void MinesweeperBoard::is_it_finished() {
  int width = this->width;
  int height = this->height;
  int counter_reveal = 0;

  for (int row = 0; row < height; row++)
    for (int col = 0; col < width; col++) {
      if (board[row][col].hasMine == false &&
          board[row][col].isRevealed == true)
        counter_reveal++;
    }

  if (counter_reveal == (this->width * this->height - how_much_mines))
    this->game_state = FINISHED_WIN;
}