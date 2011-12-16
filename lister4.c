#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void get_control_character(char *);

void print_line(char []);


struct letter_chain {
  char letter;
  struct letter_chain *next;
};
struct line_chain {
  struct letter_chain *line;
  struct line_chain *next;
};

void print_list(struct line_chain * top);
void process_line(struct line_chain ** top);
struct letter_chain * get_line(void);
void print_line_2(struct letter_chain* current);

int main (void) {

  char state = 'x';
  char words[100][100];
  int line_count = 0;

  struct line_chain* top = NULL;
 while (1) {

    get_control_character(&state);

    if (state == 'q') {
      printf("Bye\n");
      break;

    }

    if (state == 'p') {
      print_list(top);
    }

    if (state == 'i') {

      printf("please enter some data : ");

      process_line(&top);
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

void process_line(struct line_chain ** top) {

  
  struct letter_chain* line = get_line();
  
  struct letter_chain* temp = line;
  
  struct line_chain* line_node = malloc(sizeof(struct line_chain));

  line_node->line = line;
  line_node->next = *top;
  *top = line_node;

  struct line_chain* top_temp = *top;

  while (temp != NULL) {
    printf("...%c,,,", temp->letter);
    temp = temp->next;
  }
  printf("\n");
  while (top_temp != NULL) {
    printf("--%c--", top_temp->line->letter);
    top_temp = top_temp->next;
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

void print_list(struct line_chain * top) {

  printf("print_list start\n");
  struct line_chain * temp_chain = top;
  while (temp_chain != NULL) {
    printf("outside outer while\n");
    struct letter_chain * temp_letters = temp_chain->line;
    while(temp_letters != NULL) {
      printf("%c", temp_letters->letter);
      temp_letters = temp_letters->next;
    }
    temp_chain = temp_chain->next;
    printf("\n");
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
