#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void get_control_character(char *);
void process_line(char line[]);
void print_line(char []);
void print_list(int, char[][100]);
int main (void) {

  char state = 'x';
  char words[100][100];
  int line_count = 0;

  while (1) {

    get_control_character(&state);

    if (state == 'q') {
      printf("Bye\n");
      break;

    }

    if (state == 'p') {
      print_list(line_count, words);
    }

    if (state == 'i') {

      printf("please enter some data : ");

      process_line(words[line_count]);
      line_count++;
    }
  }
  return 0;

  
}

void get_control_character(char * state) {

  // grabs characters, makes each one 'state', returning after grabbing newline

  printf("i = input, p = print list, q = quit : ");

  char local_state = 'z';

  *state = local_state;

  while(local_state != '\n') {

    local_state = getchar();
    if (local_state == '\n') {
      break;
    }
    *state = local_state;
    
  }

}

void process_line(char line[]) {

  int position = 0;
  char current_char = 0;

  do {

    current_char = getchar();
    line[position++] = current_char;
  } while (current_char != '\n');

}

void print_line(char list[]) {

  int i = 0;
  
  printf("%c", list[i]);
  do {
    i++;
    printf("%c", list[i]);
  } while (list[i] != '\n');
}

void print_list(int line_count, char words[][100]) {
  int i = 0;

  while (i < line_count) {

    print_line(words[i]);
    i++;
  }
}
