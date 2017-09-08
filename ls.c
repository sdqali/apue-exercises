#include "apue.h"
#include <dirent.h>

int main(int argc, char* argv[]) {
    DIR *dp;
    struct dirent *dirp;
    char* directory_name = ".";

    if(argc == 2) {
      directory_name = argv[1];
    }

    if((dp = opendir(directory_name)) == NULL) {
      err_sys("Can't open %s", argv[1]);
    }

    while((dirp = readdir(dp)) != NULL) {
      printf("%s\n", dirp -> d_name);
    }

    closedir(dp);
    exit(0);
}
