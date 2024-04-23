#include <iostream>

// Function to calculate the Fibonacci number at a given index
int fibonacci(int n) {
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
      std::cerr << "Usage: " << argv[0] << " <index>" << std::endl;
      return 1;
  }

  int index = std::atoi(argv[1]);

  if (index < 0) {
      std::cerr << "Index must be a non-negative integer." << std::endl;
      return 1;
  }

  unsigned long long fib_number = fibonacci(index);
  std::cout << "Fibonacci number at index " << index << " is: " << fib_number << std::endl;

  return 0;
}
