#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void get_control_character(char *);
void process_line(char line[]);
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

    if (state == 'i') {

      printf("please enter some data : ");

      process_line(words[line_count]);
      printf("...%c%c%c\n", words[line_count][0], words[line_count][1], 
	     words[line_count][2]);
    }
  }
  return 0;

  
}

void get_control_character(char * state) {

  // grabs characters, makes each one 'state', returning after grabbing newline

  printf("enter q to quit or e to enter a string : ");

  char local_state = 'z';

  *state = local_state;

  while(local_state != '\n') {

    local_state = getchar();
    if (local_state == '\n') {
      break;
    }
    *state = local_state;
    
  }

  printf("state = %c\n", *state);
}

void process_line(char line[]) {

  int position = 0;
  char current_char = 0;

  do {

    current_char = getchar();
    line[position++] = current_char;
  } while (current_char != '\n');
  printf("...%d...\n", position);


  
}
