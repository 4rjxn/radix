#include <stdio.h>

void decToBinary(int val) {
  int binArr[100] = {};
  int i = 0;
  while (val) {
    binArr[i] = val % 2;
    val /= 2;
    i++;
  }
  for (i--; i >= 0; i--)
    printf("%d", binArr[i]);
  printf("\n");
}

int main() {
  int val;
  printf("*** Welcome ***\n");
  printf("Enter value: ");
  scanf("%d", &val);
  decToBinary(val);
  return 0;
}
