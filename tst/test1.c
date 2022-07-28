#include<stdio.h>
#include<stdlib.h>
#include"../include/lexer.h"
#include<assert.h>
//void usage();

void usage(){
  printf("usage: ba <filename>\n");
  exit(1);
}

int main(int argc, char** argv){
  char* filename;
  uint8_t *program;
  if(argc!=2){
    usage();
  }
  filename=argv[1];
  program=read_entry(filename);
  assert(program!=NULL);
  Tokens *tokens=new_tokens();
  add_token(&tokens,"x",1);
  add_token(&tokens,":",1);
  add_token(&tokens,"number",6);
  add_token(&tokens,";",1);
  add_token(&tokens,"x:number",1);
  add_token(&tokens,"=",1);
  add_token(&tokens,"12",2);
  add_token(&tokens,";",1);
  display(tokens);//affichage normale!!!!!!!*/


  //on ignore les erreurs de valgrind pour le moment.

  /*tokenize(&tokens,program);
    display(tokens);*/
  //L'importance de tokenize.

  
  //conformement aux regles.
  //  printf("%hhn\n",program);
  free(program);
  //fclose((FILE*)filename);
  free_all(tokens);
  //voilà.
  return 0;
}

