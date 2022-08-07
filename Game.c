#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char randomtype() {
    char computer;
    int n = rand() % 3;
    char x[] = {'s', 'e', 'a'};
    return x[n];
}

char *compareChoose(char playerChoose, char BotChoose) {
    char *outcome = malloc(20);
    if (playerChoose == BotChoose) {
        return "tie.";
    }
    if ((playerChoose == 's' && BotChoose == 'a') ||
        (playerChoose == 'e' && BotChoose == 's') ||
        (playerChoose == 'a' && BotChoose == 'e')) {
        strcat(outcome, "you alive.");
    } else {
        strcat(outcome, "you died.");
    }
    return outcome;
}

void demo_random() {
    for (int i = 0; i < 100; ++i) {
        printf("%c\n", randomtype());
    }
}
int main() {
    char playerChoose, BotChoose;
    srand((unsigned int) time(NULL));
    printf(" ---------------- \n War Game with Bot \n---------------- \n [s] = sword \n [e] = egis \n [a] = arrow \n [q] = quit \n---------------- \n Enter the Char: ");
    scanf(" %c", &playerChoose);
    while (playerChoose != 'q') {
        BotChoose = randomtype();
        printf("-------------------------------------- \n you [%c] vs. computer [%c] -> ", playerChoose, BotChoose);
        printf(" %s\n", compareChoose(playerChoose, BotChoose));
         printf("-------------------------------------- \n War Game with Bot \n---------------- \n [s] = sword \n [e] = egis \n [a] = arrow \n [q] = quit \n---------------- \n Enter the Char: ");
        scanf(" %c", &playerChoose);
    }
}