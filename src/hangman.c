#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void print_menu()
{
    system("clear");
    printf("What do you whant to do ?\n");
    printf("1. Start game\n");
    printf("2. Description\n");
    printf("3. Exit\n");
    printf(">");
}
void print_word()
{
    printf("Hangman is a classic word game in which you must guess the secret "
           "word one letter at a time.\nChallenge friends from Facebook, "
           "Twitter, Google+ or The Free Dictionary (Wait 10 seconds)\n");
}
int get_variant(int count)
{
    setlocale(LC_ALL, "Rus");
    int variant;
    char s[100]; // строчка для считывания введенных данных
    scanf("%s", s); // считываем строку
    //пока ввод некоректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: ");
        scanf("%s", s); //считываем строку повторно
    }
    return variant;
}
void PrintHang(int i)
{
    system("clear");
    switch (i) {
    case 6:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_ / \\|  \n\n");
        break;
    case 5:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_ /  |  \n\n");
        break;
    case 4:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_    |  \n\n");
        break;
    case 3:
        printf("  ____ \n |   | |\n |   O |\n |  /| |\n_|_    |  \n\n");
        break;
    case 2:
        printf("  ____ \n |   | |\n |   O |\n |   | |\n_|_    |  \n\n");
        break;
    case 1:
        printf("  ____ \n |     |\n |     |\n |     |\n_|_    |  \n\n");
        break;
    case 0:
        printf("       \n       |\n       |\n       |\n___    |  \n\n");
        break;
    }
}
void hangman()
{
    char word[20];
    char stars[20];
    int counter = 0;
    int lenght;
    char scanChar;
    int strikes = 0;
    int trigger = 0;
    int wincounter = 0;
    int i;

    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                    __/ |                      \n");
    printf("                   |___/  \n");

    printf("\n\nEnter a word:");
    scanf("%s", word);
    lenght = strlen(word);

    system("clear");

    for (counter = 0; counter < lenght; counter++) {
        stars[counter] = '*';
    }

    stars[lenght] = '\0';

    for (counter = 0; counter < 26; counter++) {
        if (wincounter == lenght) {
            printf("\n\nThe word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }

        PrintHang(strikes);

        if (strikes == 6) {
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }

        printf("\n\n\n\n%s", stars);

        printf("\n\nGuess a letter:");
        scanf(" %c", &scanChar);

        for (i = 0; i < lenght; i++) {
            if (word[i] == scanChar) {
                stars[i] = scanChar;
                trigger++;
                wincounter++;
            }
        }

        if (trigger == 0) {
            strikes++;
        }

        trigger = 0;
    }
    sleep(3);
}
int main()
{
    setlocale(LC_ALL, "Rus");
    int variant; // выбранный пункт меню
    do {
        print_menu(); // выводим меню на экран
        variant = get_variant(3); // получаем номер выбранного пункта меню
        switch (variant) {
        case 1:
            hangman();
            break;
        case 2:
            print_word();
            break;
        }
        if (variant != 3) {
            if (variant == 2)
                sleep(10);
        } else {
            return 0;
        };
    } while (variant != 3);
    return 0;
}