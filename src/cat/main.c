#include "s21_cat.h"

int main(int argc, char *argv[]) {
  CatFlags flags = {0};

  flags_handle(argc, argv, &flags);

  int err = 0;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      if (process_file(argv[i], flags) != 0) {
        err = 1;
      }
    }
  }

  return err;
}