/*
Written by Renubic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char fill[9] = {'-','-','-','-','-','-','-','-','-'};
int player;
char symbol;

int cEmpty(char place) {
  if(place != '-'){
    printf("The place is already taken\n");
    return 0;
  }
  return 1;
}

void printBoard(){
  printf("        a     b     c   \n");
  printf("     ___________________\n");
  printf("     |     |     |     |\n");
  printf("  1  |  %c  |  %c  |  %c  |\n", fill[0], fill[1], fill[2]);
  printf("     |_____|_____|_____|\n");
  printf("     |     |     |     |\n");
  printf("  2  |  %c  |  %c  |  %c  |\n", fill[3], fill[4], fill[5]);
  printf("     |_____|_____|_____|\n");
  printf("     |     |     |     |\n");
  printf("  3  |  %c  |  %c  |  %c  |\n", fill[6], fill[7], fill[8]);
  printf("     |_____|_____|_____|\n");

}

void changePlayer(){
  if (player == 1) {
    player = 2;
  }
  else{
    player = 1;
  }
}

int win(int winner){
  if(fill[0] == fill[1] && fill[1] == fill[2] && fill[2] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[3] == fill[4] && fill[4] == fill[5] && fill[5] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[6] == fill[7] && fill[7] == fill[8] && fill[8] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[0] == fill[3] && fill[3] == fill[6] && fill[6] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[1] == fill[4] && fill[4] == fill[7] && fill[7] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[2] == fill[5] && fill[5] == fill[8] && fill[8] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[0] == fill[4] && fill[4] == fill[8] && fill[8] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  if(fill[2] == fill[4] && fill[4] == fill[6] && fill[6] != '-'){
    printf("===========================\n");
    printBoard();
    printf("Player %d Won!!\n", winner);
    return 1;
  }
  return 0;
}

int draw(){
  int val = 1;
  for(int i = 0; i < 9; i++){
    if(fill[i] == '-'){
      val = 0;
      break;
    }
  }
  if (val == 1) {
    printf("=============================\n");
    printBoard();
    return 1;
  }
  return 0;
}

int
main(){
  printf("Welcome to TicTacToe Game\nWould you like to start?(y/n)\n");
  char choice;
  scanf("%c", &choice);

  if (choice == 'y') {
    player = 1;
    printf("Your choice was %c. You are now Player %d\n", choice, player);
  }
  else{
    player = 2;
    printf("Your choice was %c. You are now Player %d\n", choice, player);
  }
  printf("Player 1 :  o  /  Player 2 :  x \n\n");
  if (player % 2 == 0) {
    player = 1;
  }

  int play = 1;
  while (play == 1) {

    int valid = 0;
    char * move;
    while (valid == 0) {
      if (player == 1) {
        symbol = 'o';
      }
      else{
        symbol = 'x';
      }
      printf("Player %d (%c), make your choice. ex) 3a\n", player, symbol);
      printBoard();
      move = (char*)malloc(sizeof(char) * 10);
      scanf("%s", move);
      char * p = move;
      if (*p > '0' && *p < '4') {
        p++;
        if (*p >= 'a' && *p <= 'c') {
          valid = 1;
        }
        else{
          printf("Invalid Move\n");
        }
      }
      else{
        printf("Invalid Move\n");
      }
    }

    if (player == 1) {
      symbol = 'o';
    }
    else{
      symbol = 'x';
    }


    if (strcmp(move, "1a") == 0) {
      if (cEmpty(fill[0]) == 0) {
        continue;
      }
      else{
        fill[0] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "1b") == 0) {
      if (cEmpty(fill[1]) == 0) {
        continue;
      }
      else{
        fill[1] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "1c") == 0) {
      if (cEmpty(fill[2]) == 0) {
        continue;
      }
      else{
        fill[2] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }

        changePlayer();
      }
    }
    else if (strcmp(move, "2a") == 0) {
      if (cEmpty(fill[3]) == 0) {
        continue;
      }
      else{
        fill[3] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "2b") == 0) {
      if (cEmpty(fill[4]) == 0) {
        continue;
      }
      else{
        fill[4] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "2c") == 0) {
      if (cEmpty(fill[5]) == 0) {
        continue;
      }
      else{
        fill[5] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "3a") == 0) {
      if (cEmpty(fill[6]) == 0) {
        continue;
      }
      else{
        fill[6] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "3b") == 0) {
      if (cEmpty(fill[7]) == 0) {
        continue;
      }
      else{
        fill[7] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    else if (strcmp(move, "3c") == 0) {
      if (cEmpty(fill[8]) == 0) {
        continue;
      }
      else{
        fill[8] = symbol;

        if (draw() == 1) {
          printf("The game is a draw\n");
          return 0;
        }

        if (win(player) == 1) {
          return 1;
        }
        changePlayer();
      }
    }
    printf("===============================\n");
  }
  return 0;
}
