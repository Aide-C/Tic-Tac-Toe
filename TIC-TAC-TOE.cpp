#include <iostream>

std::string board_space[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int player = 1;
int index = 0;


bool is_winner();
bool filled_up();
void introduction();
void loop();
void set_position();
void update_board();
void change_player();
void board();
void end_game();


int main () {
    introduction();
    loop();
    end_game();
}


void board () {
    std::cout << "          |          |          \n"
              << "     " << board_space[0] << "    |    " << board_space[1] << "     |    " << board_space[2] << "    \n"
              << "          |          |          \n"
              << "________________________________\n"
              << "          |          |          \n"
              << "     " << board_space[3] << "    |    " << board_space[4] << "     |    " << board_space[5] << "    \n"
              << "          |          |          \n"
              << "________________________________\n"
              << "          |          |          \n"
              << "     " << board_space[6] << "    |    " << board_space[7] << "     |    " << board_space[8] << "    \n"
              << "\n\n";
  }


bool is_winner() {
  bool winner = false;

  if (board_space[0] != " " && board_space[1] != " " && board_space[2] != " ") {
    winner = true;
  }
  else if (board_space[3] != " " && board_space[4] != " " && board_space[5] != " ") {
    winner = true;
  }
  else if (board_space[6] != " " && board_space[7] != " " && board_space[8] != " ") {
    winner = true;
  }
  else if (board_space[0] != " " && board_space[3] != " " && board_space[6] != " ") {
    winner = true;
  }
  else if (board_space[1] != " " && board_space[4] != " " && board_space[7] != " ") {
    winner = true;
  }
  else if (board_space[2] != " " && board_space[5] != " " && board_space[8] != " ") {
    winner = true;
  }
  else if (board_space[0] != " " && board_space[4] != " " && board_space[8] != " ") {
    winner = true;
  }
  else if (board_space[2] != " " && board_space[4] != " " && board_space[6] != " ") {
    winner = true;
  }
  return winner;
}


bool filled_up() {
  bool full = true;
  for (int i = 0; i < 9; i++) {
    if (board_space[i] != " ") {
      full = false;
    }
  }
}


void introduction() {
  std::cout << "===========\n"
            << "TIC-TAC-TOE\n"
            << "===========\n"
            << "Just like on paper; two players, X and O, who take turns marking the spaces in a 3x3 grid. The player\n"
            << "who succeeds in placing three of their marks in a horizontal, vertical or diagonal row wins the game.\n";
  std::cout << "Player 1) X\n"
            << "Player 2) O\n\n"
            << "This is the boards order:\n"
            << "          |          |          \n"
            << "    1     |    2     |    3     \n"
            << "          |          |          \n"
            << "________________________________\n"
            << "          |          |          \n"
            << "    4     |    5     |    6     \n"
            << "          |          |          \n"
            << "________________________________\n"
            << "          |          |          \n"
            << "    7     |    8     |    9     \n"
            << "          |          |          \n\n";
}


void loop() {
  while ( !filled_up() && !is_winner() ) {
    set_position();
    update_board();
    change_player();
    board();
  }
}


void set_position() {
    std::cout << "Player " << player << "'s turn (Enter 1-9): ";

    while (!(std::cin >> index)) {
        std::cout << "Player " << player << ", please enter a vaild number between 1 and 9: ";
        std::cin.clear();
        std::cin.ignore();
    }
    std::cout << "\n";
    while (board_space[index - 1] != " ") {
        std::cout << "Sorry that space is already taken. Please choose another one (1-9): ";
        std::cin >> index;
        std::cout << "\n";
    }
}


void update_board() {
   if (player == 2) {
    board_space[index - 1] = "O";
  }
  else {
     board_space[index - 1] = "X";
  }
}



void change_player() {
  if (player == 1) {
    ++player;
  }
  else {
    --player;
  }
}


void end_game() {
  if (is_winner()) {
    std::cout << "Player " << player << " is the winner!\n";
  }
  else if (filled_up()){
    std::cout << "Oops looks like it is a tie!\n";
  }
}
