#include "apue.h"

int main(void) {
  int read_char;

  while((read_char = getc(stdin)) != EOF) {
    if(putc(read_char, stdout) == EOF) {
      err_sys("Output error");
    }
  }

  if(ferror(stdin)) {
    err_sys("input error");
  }

  exit(0);
}
