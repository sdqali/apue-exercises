#include <string.h>
#include "apue.h"

typedef struct command {
  char *program;
  char **args;
} command;

struct command split(char *input, char *delimiter) {
  struct command output;
  char *args[MAXLINE];
  char *token, *string, *tofree;

  tofree = string = strdup(input);

  int i = 0;
  while ((token = strsep(&string, delimiter)) != NULL) {
    if(i == 0) {
      output.program = token;
    }
    args[i] = token;
    i++;
  }
  output.args = args;

  free(tofree);
  return output;
}

int main(void) {
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("> ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    struct command cmd = split(buf, " \t");

    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execvp(cmd.program, cmd.args);
      err_ret("Could not execute: %s", cmd.program);
      exit(127);
    }

    if((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("> ");
  }

  exit(0);
}
