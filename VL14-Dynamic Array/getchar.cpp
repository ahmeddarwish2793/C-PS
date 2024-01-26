#include <cstdio>
#include <random>

namespace johannes {
char getchar() { return 'c'; }
}  // namespace johannes

int main() {
  printf("%c\n", johannes::getchar());

  std::random_device random;

  printf("%llu\n", random());
}