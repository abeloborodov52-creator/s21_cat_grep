#ifndef GREP_H
#define GREP_H

#include <regex.h>

#define LINE_SIZE 4096
#define MAX_PATTERNS 128

typedef struct s_options {
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int e;

  char *patterns[MAX_PATTERNS];
  int pattern_count;

  int file_count;

} t_options;

int grep_run(int argc, char **argv);

void parse_options(int argc, char **argv, t_options *opt, int *index);

int process_file(const char *filename, t_options *opt);

int match_patterns(const char *line, t_options *opt);

#endif