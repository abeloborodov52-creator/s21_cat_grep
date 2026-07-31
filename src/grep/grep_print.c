#include <stdio.h>

#include "grep.h"

int process_file(const char *filename, t_options *opt) {
  FILE *fp = fopen(filename, "r");

  if (!fp) {
    if (!opt->s) perror(filename);

    return 1;
  }

  char line[LINE_SIZE];

  int line_num = 0;
  int match_count = 0;

  while (fgets(line, sizeof(line), fp)) {
    line_num++;

    if (match_patterns(line, opt)) {
      match_count++;

      if (!opt->c && !opt->l) {
        if (opt->file_count > 1 && !opt->h) printf("%s:", filename);

        if (opt->n) printf("%d:", line_num);

        printf("%s", line);
      }
    }
  }

  if (opt->c) {
    if (opt->file_count > 1 && !opt->h) printf("%s:", filename);

    printf("%d\n", match_count);
  }

  if (opt->l && match_count > 0) {
    printf("%s\n", filename);
  }

  fclose(fp);

  return 0;
}