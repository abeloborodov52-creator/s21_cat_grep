#include <stdio.h>

#include "grep.h"

int match_patterns(const char *line, t_options *opt) {
  regex_t regex;
  int flags = REG_EXTENDED;

  if (opt->i) flags |= REG_ICASE;

  for (int i = 0; i < opt->pattern_count; i++) {
    regcomp(&regex, opt->patterns[i], flags);

    int matched = regexec(&regex, line, 0, NULL, 0) == 0;

    regfree(&regex);

    if (matched) return !opt->v;
  }

  return opt->v;
}