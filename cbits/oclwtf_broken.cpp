#include "OpenCL.h"
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

int main(int argc, char** argv) {
  void* result = mmap((void*) 0x200000000, 1099512676352l, PROT_NONE, MAP_PRIVATE|MAP_ANONYMOUS|MAP_NORESERVE, 0, 0);
  printf("%p %p\n", result, MAP_FAILED);
  listPlatforms();
}