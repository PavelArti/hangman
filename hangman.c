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
    printf("3. Command list\n");
    printf("4. Exit\n");
    printf(">");
}
void print_word()
{
    printf("Hangman is a classic word game in which you must guess the secret "
           "word one letter at a time.\nChallenge friends from Facebook, "
           "Twitter, Google+ or The Free Dictionary (Wait 10 seconds)\n");
}
void print_list()
{
    printf("GO- start game (Wait 3 seconds)\n");
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
void print_hang(int number_of_mistakes)
{
    switch (number_of_mistakes) {
    case 9:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_ / \\|  \n\n");
        break;
    case 8:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_ /  |  \n\n");
        break;
    case 7:
        printf("  ____ \n |   | |\n |   O |\n |  /|\\|\n_|_    |  \n\n");
        break;
    case 6:
        printf("  ____ \n |   | |\n |   O |\n |  /| |\n_|_    |  \n\n");
        break;
    case 5:
        printf("  ____ \n |   | |\n |   O |\n |   | |\n_|_    |  \n\n");
        break;
    case 4:
        printf("  ____ \n |   | |\n |   O |\n |     |\n_|_    |  \n\n");
        break;
    case 3:
        printf("  ____ \n |     |\n |     |\n |     |\n_|_    |  \n\n");
        break;
    case 2:
        printf("       \n |     |\n |     |\n |     |\n_|_    |  \n\n");
        break;
    case 1:
        printf("       \n       |\n       |\n       |\n___    |  \n\n");
        break;
    case 0:
        printf("       \n       |\n       |\n       |\n       |  \n\n");
        break;
    };
}
void hangman()
{
    setlocale(LC_ALL, "Rus");
    system("clear");
    /*FILE *txt = fopen("slova.txt", "r");
    if (txt == NULL)
    {
        printf("file open error");
    }*/

    char scanChar;
    int i, flag = 0, sizeFile = 0, rndStr, sizeWord, guessChar;
    int number_of_mistakes = 0, countLetter = 0;
    char enterLetter[33] = {0};
    /*srand(time(NULL));
    // получаем количество строк к файле со словами
    while (!feof(txt))
    {
        if (fgetc(txt) == '\n')
            sizeFile++;
    }*/
    // rndStr = rand() % sizeFile; // получаем случайный номер строки из файла
    // fseek(txt, 0, SEEK_SET);    // переводим курсор на начало файла
    // получаем случайную строку с номером rndStr
    // это будет загаданное слово
    // for (i = 0; i < rndStr; i++)
    //{
    //    fscanf(txt, "%s", word);
    //}
    // fclose(txt);
    // sizeWord = strlen(word); // плучаем количество букв в строке

    char word[] = "СЛОВО";
    sizeWord = 5;

    // int random_word(char word); //ФУНКЦИЯ ВЫБОРА СЛОВА, КОТОРОЕ БУДУТ
    // ОТГАДЫВАТЬ. ДОЛЖНА ВОЗВРАЩАТЬ КОЛИЧЕСТВО БУКВ В СЛОВЕ
    // НА ВХОД ПОЛУЧАЕТ УКАЗАТЕЛЬ НА БУФЕР, В КОТОРОМ БУДЕТ СЛОВО

    char* secretWord = (char*)calloc(sizeWord, sizeof(char));
    // динамически задаём второй массив, в котором будут
    // показываться отгаданные буквы
    memset(secretWord, '_', sizeWord); // заполняем нижними подчёркиваниями
    memset(enterLetter, '_', 9 + sizeWord);
    guessChar = sizeWord;
    while (guessChar >= 0 && number_of_mistakes <= 9) {
        if (flag == 1) {
            number_of_mistakes++;
        } // флаг равен 1 при неотгаданной букве
        system("clear");
        print_hang(number_of_mistakes);
        printf("\nThe letter:\n");
        printf("%s", secretWord);
        printf("\nEnter a leter: ");
        printf("%s\n", enterLetter);
        scanChar = getchar();
        getchar();
        if (guessChar == 0) {
            printf("%s", word);
            // если количество неотгаданных букв = 0, то победа
            printf("\nYou win!");
            sleep(3);
            free(secretWord);
            getchar();
        }
        // если количество ошибочно отгаданных
        // букв = 9, то поражение
        if (number_of_mistakes == 9) {
            printf("%s", word);
            printf("\nYou lose(");
            sleep(3);
            free(secretWord);
            getchar();
        }
        // символы не русского алфавита
        // не учитываются
        if (!((((int)scanChar >= -64 && (int)scanChar <= -33)
               || (int)scanChar == -88)
              || (((int)scanChar >= -32 && (int)scanChar <= -1)
                  || (int)scanChar == -72))) {
            continue;
            //строчные буквы преобразуются в прописные
        } else if ((int)scanChar >= -32 && (int)scanChar <= -1) {
            scanChar = (char)((int)scanChar - 32);
        } else if ((int)scanChar == -72) {
            scanChar = (char)(-88);
        }
        // для буквы ё
        flag = 1;
        // цикл проверяет каждую букву на соответствие введённой
        for (i = 0; i < sizeWord; i++) {
            if (word[i] == scanChar) {
                // если такая буква ещё не была отгадана, то выполняется
                if (!(strchr(secretWord + i, scanChar))) {
                    flag = 0;
                    guessChar--;
                    secretWord[i] = word[i];
                }
                // если буква уже была введена
            } else if (!(strchr(enterLetter, scanChar))) {
                flag = 0;
            }
        }
        // запись в массив введённых букв
        if (!(strchr(enterLetter, scanChar))) {
            enterLetter[countLetter++] = scanChar;
        }
    }
    free(secretWord);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int variant; // выбранный пункт меню
    do {
        print_menu(); // выводим меню на экран
        variant = get_variant(5); // получаем номер выбранного пункта меню
        switch (variant) {
        case 1:
            hangman();
            break;
        case 2:
            print_word();
            break;
        case 3:
            print_list();
            break;
        }
        if (variant != 4) {
            if (variant == 2)
                sleep(10);
            if (variant == 3)
                sleep(3);
        } else {
            return 0;
        };
    } while (variant != 4);
    return 0;
}