#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
  struct stat *s;
  stat("makefile", s);
  printf("File size: %ld\n", s->st_size);
  printf("Mode (permissions): \n");
  printf("Time of last access: \n");
  return 0;
}
