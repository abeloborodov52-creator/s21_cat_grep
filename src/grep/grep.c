// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

#include "grep.h"

// #define LINE_SIZE 4096

#include "grep.h"

int grep_run(int argc, char **argv) {
  t_options opt = {0};
  int index = 1;

  parse_options(argc, argv, &opt, &index);

  if (opt.pattern_count == 0) {
    opt.patterns[0] = argv[index++];
    opt.pattern_count = 1;
  }

  opt.file_count = argc - index;

  int status = 0;

  for (int i = index; i < argc; i++) {
    status |= process_file(argv[i], &opt);
  }

  return status;
}