#include "rand.h"

int main() {
  int a1[10];
  printf("\nGenerating random numbers:");
  int i = 0;
  for (; i < 10; i++) {
    a1[i] = rand_num();
    printf("\nrandom %d: %d", i, a1[i]);
  }
  
  int fd = open("file.txt", O_RDWR | O_CREAT, 0666);
  if (fd < 0) {
    printf("OPEN errno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }
  
  printf("\nWriting numbers to file...");
  int i1 = write(fd, a1, sizeof(a1));
  if (i1 < 0) {
    printf("WRITE errno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }
  close(fd);

  fd = open("file.txt", O_RDWR | O_CREAT, 0666);
  if (fd < 0) {
    printf("OPEN errno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }

  printf("\nReading numbers to file...");
  int a2[10];
  int i2 = read(fd, a2, sizeof(a2));
  if (i2 < 0) {
    printf("READ errno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }
  printf("\nVerification that written values were the same:");
  for (i = 0; i < 10; i++) {
    printf("\nrandom %d: %d", i, a2[i]);
  }
  close(fd);
  return 0;
}
