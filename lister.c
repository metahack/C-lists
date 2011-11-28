#include <stdio.h>

int main (void) {

  char status_char = 'a';

  while (status_char != 'q') {

    printf("\nenter an option : ");
    status_char = getchar();

    if (status_char == 'q') {
      printf("\nbreaking\n");
      break;
    }
    printf("\nnot q\n");
  }
  printf("...\nbye\n");
} // int main void
