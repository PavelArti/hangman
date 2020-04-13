#include <stdio.h>
#include <stdlib.h>

void print_menu() {
    system("cls"); // очищаем экран
    printf("What do you whant to do ?\n");
    printf("1. Start game\n");
    printf("2. Description\n");
    printf("3. Command list\n");
    printf("4. Exit\n");
    printf(">");
}
void print_word() {
    printf("Виселица это хорошо я оформлю текст позже\n");
}
void print_list() {
    printf("Список команд потом оформлю\n");
}

int get_variant(int count){
    int variant;
    char s[100]; // строчка для считывания введенных данных
    scanf("%s", s); // считываем строку

    //пока ввод некоректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) !=1 || variant < 1 || variant > count) {
	printf("Incorrect input. Try again: "); // выводим сообщение об ошибке 
	scanf("%s", s); //считываем строку повторно
    }
    return variant;
}

void print_hang() {
    printf("Валера\n");
}

int main(){
    int variant; // выбранный пункт меню

    do {
	print_menu(); // выводим меню на экран
	variant = get_variant(5); // получаем номер выбранного пункта меню
	switch (variant) {
	    case 1:
		print_hang();// здесь будет функция Валеры
		break;
	    case 2:
		print_word();
		break;
	    case 3:
		print_list();
		break;
       }
       if (variant != 4)
	    system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть резульат выбранного пункта
	} while (variant != 4);
	return 0;
}
