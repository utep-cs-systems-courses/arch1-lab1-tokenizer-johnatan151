#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"
#define BUFFER_SIZE 300


int main()
{
  char input[BUFFER_SIZE];
  List *history = init_history();
  char **tokens;
  int history_length = 0;
  char c;
  
  puts("hello welcome to tokenizer\n");
  puts("Select one of the following\n1: New string\n2: !<entry> to print past entry\n3: Print history\n4: End process");

  while(1){
    printf("$ ");
    fgets(input,BUFFER_SIZE,stdin);
    if(input[0] == '!'){
      goto done;
      }
    if(input[0] == '1'){
      puts("what word yould you like to add");
      c = getchar();
      add_history(history,*c);
    }
    if(input[0] == '3');{
      print_history(*history);
    }
    if(input [0] == '4'){
	goto done;
    }
  }

  done:
      return 0;
}

