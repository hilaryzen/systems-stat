#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat s;
  stat("./makefile", &s);
  int bytes = s.st_size;
  printf("File size: %d\n", bytes);
  printf("Mode (permissions): %d\n", s.st_mode);
  time_t time = s.st_atime;
  printf("Time of last access: %s\n", ctime(&time));
  return 0;
}
