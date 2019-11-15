#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main() {
  struct stat s;
  stat("./makefile", &s);
  int bytes = s.st_size;
  char * end[] = {"B", "KB", "MB", "GB"};
  int endI = 0;
  while (bytes >= 1024 && endI < 3) {
    bytes = bytes / 1024;
    endI += 1;
  }
  char bytesR [10];
  int n = sprintf(bytesR, "%d %s", bytes, end[endI]);
  printf("File size: %s\n", bytesR);

  printf("Mode (permissions): %o\n", s.st_mode % 4096);

  time_t time = s.st_atime;
  printf("Time of last access: %s\n", ctime(&time));
  return 0;
}
