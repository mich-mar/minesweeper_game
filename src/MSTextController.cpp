#include "MSTextController.h"
#include "MSBoardTextView.h"
#include "minesweeperboard.h"

void get_row_and_col(int *x, int *y) {
  std::cout << "Podaj row: ";
  std::cin >> *x;
  std::cout << "Podaj col: ";
  std::cin >> *y;
}

MSTextController::MSTextController(MinesweeperBoard &b, MSBoardTextView &v)
    : board(b), view(v) {}

void MSTextController::play() {
  int choice;
  int x, y;

  while (board.getGameState() == RUNNING) {
    std::cout << std::endl << "=== MENU CZYNNOSCI ===" << std::endl;
    std::cout << "1) Odkryj pole" << std::endl;
    std::cout << "2) Postaw flage" << std::endl;
    if (board.getGameMode() == DEBUG) {
      std::cout << "3) Debug view" << std::endl;
    }
    std::cout << "Twoj wybor: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
      // odkrywanie pola
      get_row_and_col(&x, &y);
      board.revealField(x, y);
      view.display();
      break;

    case 2:
      // stawianie flagi
      get_row_and_col(&x, &y);
      board.toggleFlag(x, y);
      view.display();
      break;

    case 3:
      // funkcja debug
      if (board.getGameMode() == DEBUG)
        board.debug_display();
      break;
    }
  }

  // kończenie gry
  if (board.getGameState() == FINISHED_LOSS)
    std::cout << "PRZEGRALES, powodzenia nastepnym razem.";
  else
    std::cout << "WYGRALES, gratulacje!";
}