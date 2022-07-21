#include<stdio.h>
#include<stdlib.h>
#include<lexer.h>
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
  Tokens *tokens=new_tokens();
  add_token(&tokens,"x",1);
  add_token(&tokens,":",1);
  add_token(&tokens,"number",5);
  add_token(&tokens,";",1);
  display(tokens);//affichage normale!!!!!!!
  //conformement aux regles.
  //  printf("%hhn\n",program);
  //  free(program);
  return 0;
}

