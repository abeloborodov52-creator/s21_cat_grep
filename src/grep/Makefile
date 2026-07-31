CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

SRC=main.c grep.c grep_parse.c grep_match.c grep_print.c

OBJ=$(SRC:.c=.o)

TARGET=s21_grep

TEST_SCRIPT=grep_test.sh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

test: s21_grep
	bash $(TEST_SCRIPT)

clean:
	rm -f *.o $(TARGET)

re: clean all