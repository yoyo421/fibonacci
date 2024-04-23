#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Fibonacci number at a given index
unsigned long long fibonacci(int n) {
  if (n <= 1)
      return n;
  
  unsigned long long prev = 0;
  unsigned long long current = 1;
  unsigned long long next;

  for (unsigned int i = 2; i <= n; ++i) {
      next = prev + current;
      prev = current;
      current = next;
  }

  return current;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
      fprintf(stderr, "Usage: %s <index>\n", argv[0]);
      return 1;
  }

  int index = atoi(argv[1]);

  if (index < 0) {
      fprintf(stderr, "Index must be a non-negative integer.\n");
      return 1;
  }

  unsigned long long fib_number = fibonacci(index);
  printf("Fibonacci number at index %d is: %llu\n", index, fib_number);

  return 0;
}