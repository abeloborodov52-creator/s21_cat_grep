#include "grep.h"

void parse_options(int argc, char **argv, t_options *opt, int *index) {
  int i = 1;

  while (i < argc && argv[i][0] == '-') {
    for (int j = 1; argv[i][j]; j++) {
      if (argv[i][j] == 'i')
        opt->i = 1;

      else if (argv[i][j] == 'v')
        opt->v = 1;

      else if (argv[i][j] == 'c')
        opt->c = 1;

      else if (argv[i][j] == 'l')
        opt->l = 1;

      else if (argv[i][j] == 'n')
        opt->n = 1;

      else if (argv[i][j] == 'h')
        opt->h = 1;

      else if (argv[i][j] == 's')
        opt->s = 1;

      else if (argv[i][j] == 'e') {
        if (i + 1 < argc) {
          opt->patterns[opt->pattern_count++] = argv[++i];
        }
      }
    }

    i++;
  }

  *index = i;
}