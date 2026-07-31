#ifndef S21_CAT_H
#define S21_CAT_H

typedef struct {
  int number;
  int number_blank;
  int blank_compress;
  int show_ends;
  int show_tabs;
} CatFlags;

void flags_handle(int argc, char *argv[], CatFlags *flags);

int process_file(const char *filename, CatFlags flags);
void process_line(char *line, CatFlags flags, int *line_number,
                  int *previous_empty);
void print_line(char *line, CatFlags flags);

#endif