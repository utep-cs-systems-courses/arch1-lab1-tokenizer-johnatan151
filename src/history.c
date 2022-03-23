#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history(){
  
  List *list =(List*) calloc(1,sizeof(list));
  if(!list){
    fprintf(stderr,"Method: init_history\nError:Memory allocation error!");
    exit(EXIT_FAILURE);
  }
  return list;
  
}


void add_history(List *list,char *str){
  Item *new_item = (Item*) malloc(sizeof(Item));
  Item *curr = list->root;
  int index;
  int length = str_length(str);
  new_item -> str = copy_str(str,length);

  if(!new_item){
    fprintf(stderr,"Method: add_history\nError: Memory allocation error!");
    exit(EXIT_FAILURE);
  }
  if(curr == NULL){
    list -> root = new_item;
    new_item->id = 1;
  }
  else{
    while(curr->next != NULL){
      curr = curr->next;
      index++;
    }
    curr->next = new_item;
    new_item->id = curr->id+1;
  }
}
char *get_history(List *list,int id){
  Item *current = list->root;
  while(current){
    if(current->id == id){
      return current->str;
    }
    current= current->next;
  }
}
void print_history(List *list){
  Item *current = list->root;
  int counter =0;
  while(current){
    counter++;

    if(current->id == 1){
      printf("[%d] - %s", counter,current->str);
    }
    else{
      printf("[d] - %s",counter,current->str);
    }
    current = current->next;
  }
}

void free_history(List *list){
  Item *current = list->root;
  Item *prev_item;

  while(current){
    prev_item = current;
    current = current->next;

    free(prev_item->str);
    free(prev_item);
  }
  free(list);
}

int str_length(char *str){
  char *ptr = str;
  while(*ptr != '\0'){
    ptr++;
  }
  return ptr-str;
}
