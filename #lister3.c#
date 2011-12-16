#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void get_control_character(char *);
void process_line();
void print_line(char []);

void print_list(int, char[][100]);

struct letter_chain {
  char letter;
  struct letter_chain *next;
};
struct line_chain {
  struct letter_chain *line;
  struct line_chain *next;
};

struct letter_chain * get_line(void);
void print_line_2(struct letter_chain* current);

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

      process_line();
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

void process_line(void) {

  struct letter_chain* line = get_line();
  
  struct letter_chain* temp = line;

  while (temp != NULL) {
    printf("...%c,,,", temp->letter);
    temp = temp->next;
  }
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

struct letter_chain * get_line(void) {


  char input = getchar();

  struct letter_chain *head = malloc(sizeof(struct letter_chain));

  struct letter_chain *tail = head;
  head->letter = input;
  head->next = NULL;
  while (input != '\n') {
    input = getchar();
    struct letter_chain *new = malloc(sizeof(struct letter_chain));
    new->letter = input;
    new->next = NULL;

    tail->next = new;
    tail = new;
  
  }
  return head;
}

void print_line_2(struct letter_chain* line) {
  struct letter_chain *current = line;

  do {
    printf("%c", current->letter);

    current = current->next;
  } while (current != NULL);
}
