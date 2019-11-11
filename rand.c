#include "rand.h"

int rand_num() {
  int fd = open("/dev/urandom", O_RDONLY);
  if (fd < 0) {
    printf("\nerrno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }
  int out;
  int i = read(fd, &out, sizeof(int));
  if (i < 0) {
    printf("\nerrno: %d, error message: %s", errno, strerror(errno));
    return errno;
  }
  close(fd);
  return out;
}
