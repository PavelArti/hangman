#### Проект:
##### hangman
##### Участники команды:
##### Шмаков Павел (ИС-941)
##### Милованов Валерий (ИС-941)
---
# Техническое задание
### Краткое описание

Hangman - игра для OS Windows, в которой ваша задача будет угадать недостоющие буквы в слове. Пользователю будет дано 9 попыток, но попытка не будет тратиться, если пользователь поставил любой знак или букву не являющейся русской. Слова будут храниться в исходном файле. 
* Язык программирования: C
* OS: Windows
* Язык приложения: Английский

---
### Работа приложения
При запуске приложения при помощи команды ./hangman:3.exe(так же должен быть запущен текстовый файл slova.txt) пользователь увидит меню, в котором четыри пункта: 1. Начать игру (Этот пункт начинает игру, где пользователь видит на экране слово с недостающими буквами);  2. Об игре (Здесь пользователь сможет прочитать о игре и основные правила к ней); 3. Список команд (Пункт, показывающий список доступных команд и их описание); 4. Выход (Закрывает приложение).

#### Список команд:
 * GO - Начать игру 
---
#### Входные данные
Введеные с клавиатуры буквы русского и английского алфавита
#### Выходные данные
Сообщение о присутсвии или отсутствии входных данных в слове, а так же количество попыток
