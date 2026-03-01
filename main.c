#include <stdio.h>

int fpow(int x, int y) {
  int pow = 1;
  while (y--) {
    pow *= x;
  }
  return pow;
}

int cstrlen(char *str) {
  int l = 0;
  while (str[l] != '\0')
    l++;
  return l;
}
void strrev(char *str) {
  int l = 0, r = cstrlen(str) - 1;
  while (l < r) {
    str[l] ^= str[r];
    str[r] = str[l] ^ str[r];
    str[l] = str[l] ^ str[r];
    l++;
    r--;
  }
}

int toDec(int base, char *val) {
  int dec = 0, l = cstrlen(val) - 2;
  for (int i = 0; l >= 0; i++) {
    if (val[l] >= 48 && val[l] <= 57) {
      dec += (val[l] - 48) * fpow(base, i);
    }
    if (val[l] >= 97 && val[l] <= 122) {
      dec += (val[l] - 87) * fpow(base, i);
    }
    l--;
  }
  return dec;
}

char *toRadix(int base, int dec, char *str) {
  int i = 0, c = 0, rem;
  for (i = 0; dec > 0; i++) {
    rem = (dec % base);
    if (rem >= 10) {
      str[c] = rem + 87;
      c++;
    } else {
      c += sprintf(&str[c], "%d", rem);
    }
    dec /= base;
  }
  str[c] = '\0';
  strrev(str);
  return str;
}

int main() {
  int base, dec;
  char str[100], val[100];
  printf("*** Welcome ***\n");
  printf("Enter base: ");
  scanf("%d", &base);
  printf("Enter value: ");
  getchar();
  fgets(val, 10, stdin);
  dec = toDec(base, val);

  // convertion;
  printf("\n=== Converted Values ===\n");
  printf("Decimal: %s\n", toRadix(10, dec, str));
  printf("Binary: %s\n", toRadix(2, dec, str));
  printf("Octal: %s\n", toRadix(8, dec, str));
  printf("Hex: %s\n", toRadix(16, dec, str));
  return 0;
}
