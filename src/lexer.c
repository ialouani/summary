#include<lexer.h>
#include<stdio.h>
#include<stdlib.h>

uint8_t* read_entry(char* filename){
  FILE* f=fopen(filename,"r");
  //TODO: Handle size malloc
  uint8_t* content=malloc(sizeof(2048));
  uint8_t *tmp=content;
  char c;int len=0;
  if(f!=NULL){
    while((c=(char)fgetc(f))!=EOF){
      *tmp++;len++;
    }
  }
  else{
    printf("Unable to open file%s\n",filename);
    exit(1);
  }
  *tmp='\0';
  printf("number of simple char:%d\n",len);
  return content;
}
