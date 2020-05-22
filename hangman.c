#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_menu()
{
    system("cls"); // очищаем экран
    printf("What do you whant to do ?\n");
    printf("1. Start game\n");
    printf("2. Description\n");
    printf("3. Command list\n");
    printf("4. Exit\n");
    printf(">");
}
void print_word()
{
    printf("Hangman is a classic word game in which you must guess the secret word one letter at a time.\nChallenge friends from Facebook, Twitter, Google+ or The Free Dictionary\n");
}
void print_list()
{
    printf("GO- start game\n");
}

int get_variant(int count)
{
    int variant;
    char s[100]; // строчка для считывания введенных данных
    scanf("%s", s); // считываем строку

    //пока ввод некоректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again: "); // выводим сообщение об ошибке
        scanf("%s", s); //считываем строку повторно
    }
    return variant;
}

void print_hang(int number_of_mistakes) //вывод изображения виселицы
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
int hangman()
{
    system("chcp 1251");
    system("cls");
    FILE* txt;
    char word[80], scanChar;
    double buffer;
    int i, flag = 0, sizeFile = 0, rndStr, sizeWord, guessChar,
           number_of_mistakes = 0, countLetter = 0;
           char enterLetter[33] = {0};
    srand(time(NULL));
    if (!(txt
          = fopen("slova.txt", "r"))) { // проверяем открыт ли файл со словами
        printf("Error file not open!");
        return 1;
    }
    while (fscanf(txt, "%s", &buffer)
           != EOF) // получаем количество строк к файле со словами
        sizeFile++;
    rndStr = rand() % sizeFile; // получаем случайный номер строки из файла
    fseek(txt, 0, SEEK_SET); // переводим курсор на начало файла
    for (i = 0; i < rndStr; i++) { // получаем случайную строку с номером rndStr
                                   // (это будет загаданное слово)
        fscanf(txt, "%s", word);
    }
    fclose(txt);
    sizeWord = strlen(word); // плучаем количество букв в строке
    char* secretWord = (char*)calloc(
            sizeWord,
            sizeof(char)); // динамически задаём второй массив, в котором будут
                           // показываться отк=гаданные буквы
    memset(secretWord, '_', sizeWord); // заполняем его нижними подчёркиваниями
    memset(enterLetter, '_', 9 + sizeWord);
    guessChar = sizeWord;
    while (guessChar >= 0 && number_of_mistakes <= 9) {
        if (flag == 1) {
            number_of_mistakes++;
        } // флаг равен 1 при неотгаданной букве
        system("cls");
        print_hang(number_of_mistakes);
        if (guessChar
            == 0) { // если количество неотгаданных букв = 0, то победа
            printf("%s", word);
            printf("\nYou win!");
            free(secretWord);
            getchar();
            return 0;
        }
        if (number_of_mistakes == 9) { // если количество ошибочно отгаданных
                                       // букв = 9, то поражение
            printf("%s", word);
            printf("\nYou lose(");
            free(secretWord);
            getchar();
            return 0;
        }
        printf("%s", secretWord);
        printf("\nThe letter:\n");
        printf("%s", enterLetter);
        printf("\n(Write GO to start game)Enter a leter: ");
        scanChar = getchar();
        getchar();
        if (!((((int)scanChar >= -64 && (int)scanChar <= -33)
               || (int)scanChar == -88)
              || (((int)scanChar >= -32 && (int)scanChar <= -1)
                  || (int)scanChar == -72))) { // символы не русского алфавита
                                               // не учитываются
            continue;
        } else if ((int)scanChar >= -32 && (int)scanChar <= -1) { // трочные
                                                                  // буквы
                                                                  // преобразуются
                                                                  // в прописные
            scanChar = (char)((int)scanChar - 32);
        } else if ((int)scanChar == -72) { // для буквыы ё
            scanChar = (char)(-88);
        }
        flag = 1;
        for (i = 0; i < sizeWord;
             i++) { // цикл проверяет каждую букву на соответствие введённой
            if (word[i] == scanChar) {
                if (!(
                            strchr(secretWord + i,
                                   scanChar))) { // если такая буква ещё не была
                                                 // отгадана, то выполняется
                    flag = 0;
                    guessChar--;
                    secretWord[i] = word[i];
                }
            } else if (strchr(enterLetter,
                              scanChar)) { // если буква уже была введена
                flag = 0;
            }
        }
        if (!(strchr(
                    enterLetter, scanChar))) { // запись в массив введённых букв
            enterLetter[countLetter++] = scanChar;
        }
    }
    free(secretWord);
}

int main()
{
    int variant; // выбранный пункт меню

    do {
        print_menu(); // выводим меню на экран
        variant = get_variant(5); // получаем номер выбранного пункта меню
        switch (variant) {
        case 1:
            hangman(); // здесь будет функция Валеры
            break;
        case 2:
            print_word();
            break;
        case 3:
            print_list();
            break;
        }
        if (variant != 4)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог
                             // увидеть резульат выбранного пункта
    } while (variant != 4);
    return 0;
}