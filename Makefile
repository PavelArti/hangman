# компилятор
CC=gcc

# флаги
CFLAGS=-c -Wall -Werror

# путь до объектных файлов
OBJDIR=obj/

# путь до исходников
SRCDIR=src/

# общие файлы
FILES=hangman.c

# объектные файлы приложения
OBJ=$(patsubst %.c, $(OBJDIR)$(SRCDIR)%.o, $(FILES))

# выходной файл
EXECUTABLE=bin/hangman

.PHONY: clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^

$(OBJDIR)$(SRCDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJ) $(EXECUTABLE)