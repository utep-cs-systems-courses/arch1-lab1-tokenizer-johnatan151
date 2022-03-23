#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int space_char(char c){
  if(c == ' ' || '\t'){
    printf("contains a space");
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(c != '\0' || ' ' || '\t'){
    return 1; 
  }
  return 0;
}

char *word_start(char *str){
  while(non_space_char(*str)){
    return str;
  }
}

char *word_terminator(char *word){
  while(*word != '\0' && space_char(*word)==0){
    word++;
  }
  return word;
}

int count_words(char *s){
  int nw = 0;
  char *str = s ;
  while(*s != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    nw++;
  }
  return nw;
 }

char *copy_str(char *inStr,short len){
  int counter = 0;
  char *copy = malloc(sizeof(char) * len+1);
  char *temp = inStr;
  while(counter < len){
    *copy = *temp;
    temp++;
    inStr++;
    counter++;
  }
  *temp = '\0';
  return copy;
}


char **tokenize(char* str){
  
  //creates allocated space for my array

  char **tokens = (char**)malloc(count_words(str) * sizeof(char*)+1);
  char* token = str; 
  int counter = 0;
  
  while(counter < 0 && *str != '\0'){
    char *copy = word_terminator(str);
    tokens[counter] = copy_str(str,copy-str); //here is error
    str = word_start(copy);
    counter++;
  }
  tokens[counter] = 0;
  return tokens;
}

void print_tokens(char **tokens){
  int count = 0;

  while(*tokens != 0){
    printf("[%d],\t%s",count,*tokens);
    printf("\n");
    count++;
    tokens++;
  }
}

void free_tokens(char **tokens){
  char **mem = tokens;

  while(tokens != 0){
    free(*mem);
    mem++;
  }
  free(*mem);
  free(mem);
}

