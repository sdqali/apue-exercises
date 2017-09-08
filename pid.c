#include "apue.h"

int main() {
  printf("Hello world from process %ld originating from %ld\n",
    (long)getpid(), (long)getppid());
  exit(0);
}
