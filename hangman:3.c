#include <stdio.h>
#include <stdlib.h>

void print_menu()
{
    system("clear"); // очищаем экран
    printf("What do you whant to do ?\n");
    printf("1. Start game\n");
    printf("2. Description\n");
    printf("3. Command list\n");
    printf("4. Exit\n");
    printf(">");
}
void print_word()
{
    printf("Игра Виселица (hangman) это классическая  популярная во всем мире игра.\n");
    printf("Вам необходимо отгодать скрытое слово по буквам.\n");
    printf("На это вам дается 6 попыток и за каждую ошибку на экране будет появляться часть человека на виселеце\n");
    printf("Если человек будет полностью нарисован, вы проиграете\n");
}
void print_list()
{
    printf("Список команд потом оформлю\n");
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

int main()
{
    int variant; // выбранный пункт меню

    do {
        print_menu(); // выводим меню на экран
        variant = get_variant(5); // получаем номер выбранного пункта меню
        switch (variant) {
        case 1:
            print_hang(); // здесь будет функция Валеры
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
