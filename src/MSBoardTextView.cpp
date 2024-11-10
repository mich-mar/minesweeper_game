#include "MSBoardTextView.h"

MSBoardTextView::MSBoardTextView(MinesweeperBoard &b) : board(b) {}

void MSBoardTextView::display() const {
  int width = board.getBoardWidth();
  int height = board.getBoardHeight();

  std::cout << std::endl;
  
  for (int i = 0; i < width; i++) {
    std::cout << "   "<< i;
  }

  std::cout << std::endl;

  for (int row = 0; row < height; row++) {
    std::cout << row;
    for (int col = 0; col < width; col++) {
      std::cout << " [";
      std::cout << board.getFieldInfo(row, col);
      std::cout << "]";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
}


