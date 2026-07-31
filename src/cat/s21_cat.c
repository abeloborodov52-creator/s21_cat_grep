#include "s21_cat.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>

#define LINE_SIZE 4096

int process_file(const char *filename, CatFlags flags) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
    return 1;
  }

  char line[LINE_SIZE];
  int line_number = 1;
  int previous_empty = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    process_line(line, flags, &line_number, &previous_empty);
  }

  if (ferror(fp)) {
    fprintf(stderr, "cat: %s: %s\n", filename, strerror(errno));
    fclose(fp);
    return 1;
  }

  fclose(fp);
  return 0;
}

void process_line(char *line, CatFlags flags, int *line_number,
                  int *previous_empty) {
  int current_empty = (line[0] == '\n');

  if (flags.blank_compress) {
    if (current_empty && *previous_empty) {
      return;
    }
  }
  *previous_empty = current_empty;
  if (flags.number_blank) {
    if (line[0] != '\n') {
      printf("%6d\t", *line_number);
      (*line_number)++;
    }
  } else if (flags.number) {
    printf("%6d\t", *line_number);
    (*line_number)++;
  }

  print_line(line, flags);
}
void print_line(char *line, CatFlags flags) {
  for (int i = 0; line[i] != '\0'; i++) {
    char c = line[i];

    if (flags.show_tabs && c == '\t') {
      printf("^I");
    } else if (flags.show_ends && c == '\n') {
      printf("$\n");
    } else {
      putchar(c);
    }
  }
}

void flags_handle(int argc, char *argv[], CatFlags *flags) {
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-n") == 0) {
      flags->number = 1;
    }
    if (strcmp(argv[i], "-b") == 0) {
      flags->number_blank = 1;
    }
    if (strcmp(argv[i], "-s") == 0) {
      flags->blank_compress = 1;
    }
    if (strcmp(argv[i], "-e") == 0) {
      flags->show_ends = 1;
    }
    if (strcmp(argv[i], "-t") == 0) {
      flags->show_tabs = 1;
    }
  }
}