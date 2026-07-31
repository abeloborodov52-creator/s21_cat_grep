CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11

TARGET = s21_cat

SRC = main.c s21_cat.c

TEST_SCRIPT=cat_test.sh

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

test: s21_cat
	bash $(TEST_SCRIPT)

clean:
	rm -f $(TARGET)

re: clean all