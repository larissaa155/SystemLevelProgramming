#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define TRIES 8
#define DIGITS 3
#define RANGE 9

void generate_code(int code[]) {
    for(int i = 0; i < DIGITS; i++) {
        code[i] = rand() % (RANGE + 1);
    }
}

void get_user_input(char input[]) {
    printf("What is the code? ");
    scanf("%s", input);
}

int is_valid_input(char input[]) {
    if(strlen(input) != DIGITS) return 0;
    for(int i = 0; i < DIGITS; i++) {
        if(!isdigit(input[i])) return 0;
    }
    return 1;
}

void convert_input_to_array(char input[], int guess[]) {
    for(int i = 0; i < DIGITS; i++) {
        guess[i] = input[i] - '0';
    }
}

void compare_codes(int code[], int guess[], int *correct_place, int *correct_digit) {
    *correct_place = 0;
    *correct_digit = 0;
    int code_used[DIGITS] = {0};
    int guess_used[DIGITS] = {0};

    for(int i = 0; i < DIGITS; i++) {
        if(guess[i] == code[i]) {
            (*correct_place)++;
            code_used[i] = 1;
            guess_used[i] = 1;
        }
    }

    for(int i = 0; i < DIGITS; i++) {
        for(int j = 0; j < DIGITS; j++) {
            if(!code_used[i] && !guess_used[j] && guess[j] == code[i]) {
                (*correct_digit)++;
                code_used[i] = 1;
                guess_used[j] = 1;
            }
        }
    }
}

int main() {
    srand(time(0));
    int code[DIGITS];
    generate_code(code);

    char input[DIGITS + 1];
    int guess[DIGITS];
    int correct_place, correct_digit;

    printf("Guess the %d-digit code. You have %d tries.\n", DIGITS, TRIES);

    for(int tries = TRIES; tries > 0; tries--) {
        printf("%d tries remaining. ", tries);
        get_user_input(input);

        if(input[0] == 'q' || input[0] == 'Q') {
            printf("Game quit.\n");
            return 0;
        }

        if(!is_valid_input(input)) {
            printf("Invalid input. Please enter exactly %d digits.\n", DIGITS);
            tries++; //Invalid attempt doesn't count
            continue;
        }

        convert_input_to_array(input, guess);

        if(memcmp(code, guess, DIGITS * sizeof(int)) == 0) {
            printf("You opened the vault!\n");
            return 0;
        }

        compare_codes(code, guess, &correct_place, &correct_digit);
        printf("Too %s, %d digits are correct and in the right place, %d digits are correct but in the wrong place.\n",
               (memcmp(code, guess, DIGITS * sizeof(int)) > 0) ? "low" : "high",
               correct_place, correct_digit);
    }

    printf("The vault shuts down permanently due to too many incorrect attempts. You failed to open the vault!\n");
    printf("The secret code was ");
    for(int i = 0; i < DIGITS; i++) {
        printf("%d", code[i]);
    }
    printf(".\n");

    return 0;
}
