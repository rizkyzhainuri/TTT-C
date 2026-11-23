/*
    TicTacToe 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    playing,
    winning,
    gameover,
    draw
} state;

void get_player_input(int *chosen_number, char number[]);
void game_check(int chosen_number, char number[], state *current_state);
void draw_game(char number[]);
void get_computer_num(char number[]);

int main() {
    srand(time(NULL));
    state current_state = playing;
    char number[9] = {'1', '2', '3', '4', '5' , '6', '7', '8', '9'};
    int chosen_number = 0;
    int play_count = 0;

    while (current_state == playing) {
        //Deaw
        draw_game(number);
        //Input
        if (play_count == 9) {
            current_state = draw;
            draw_game(number);
            printf("\nDRAW");
        }
        get_player_input(&chosen_number, number);
        play_count++;
        if (play_count < 9) {
            get_computer_num(number);
            play_count++;
        }
        //Check
        game_check(chosen_number, number, &current_state);
    }
    scanf(" ");

    return 0;
}

void get_player_input(int *chosen_number, char number[]) {

    printf("Enter the number 1 - 9 where you want to draw : ");

    int temporary_num = 0;
    scanf("%d", &temporary_num);
    temporary_num -= 1;
    if (temporary_num > 9 | temporary_num < 0 | number[temporary_num] == 'X' | number[temporary_num] == 'O') {
        scanf("%d", temporary_num);
    }
    *chosen_number = temporary_num;
    number[*chosen_number] = 'X';
}

void get_computer_num(char number[]) {
    int com_num = rand() % 9; // 0 -8
    /*
    if (number[com_num] == 'X' || number[com_num] == 'O') {
        for (int i = 8; i > -1; i--) {
            if (number[i] != 'X' && number[i] != 'O') {
                com_num = i;
                break;
            }
            
        }
    }
    */
    do {

        com_num = rand() % 9;
    } while (number[com_num] == 'X' || number[com_num] == 'O');
    number[com_num] = 'O';
}

void draw_game(char number[]) {
    system("cls");
    printf("\n======[TicTacToe]======\n\n\n");
    printf("     %c  |  %c  |   %c      \n", number[0], number[1], number[2]);
    printf("   _____+_____+_____    \n\n");
    printf("     %c  |  %c  |   %c      \n", number[3], number[4], number[5]);
    printf("   _____+_____+_____    \n\n");
    printf("     %c  |  %c  |   %c      \n\n", number[6], number[7], number[8]);
    printf("\n=======================\n\n");
}

void game_check(int chosen_number, char number[], state *current_state) {
    // PLAYER X
    if (number[0] == 'X' && number[1] == 'X' && number[2] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[3] == 'X' && number[4] == 'X' && number[5] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[6] == 'X' && number[7] == 'X' && number[8] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[0] == 'X' && number[3] == 'X' && number[6] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[1] == 'X' && number[4] == 'X' && number[7] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[2] == 'X' && number[5] == 'X' && number[8] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[0] == 'X' && number[4] == 'X' && number[8] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    } else if (number[2] == 'X' && number[4] == 'X' && number[6] == 'X') {
        draw_game(number);
        *current_state = winning;
        printf("\n\\(^_^)/  YEAY ! CONGRATULATIONS - YOU'RE REALLY GOOD !!\n");
    }
    
    // COM
    if (number[0] == 'O' && number[1] == 'O' && number[2] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[3] == 'O' && number[4] == 'O' && number[5] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[6] == 'O' && number[7] == 'O' && number[8] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[0] == 'O' && number[3] == 'O' && number[6] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[1] == 'O' && number[4] == 'O' && number[7] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[2] == 'O' && number[5] == 'O' && number[8] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[0] == 'O' && number[4] == 'O' && number[8] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    } else if (number[2] == 'O' && number[4] == 'O' && number[6] == 'O') {
        draw_game(number);
        *current_state = gameover;
        printf("\n/(-_-)\\  Game Over.\n");
    }
}