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
  printf("sample name's file : %s\n",(char*)filename);
  printf("number of simple char:%d\n",len);
  return content;
}



void display(Tokens* tokens){
  Tokens* current=tokens;
  printf("<Tokens[");
  while(current->prev!=NULL){
    printf("{token=%s, type: %s}",current->token.val,"UNKNOWN");
current=current->prev;
}
printf("]");
}
  
Tokens *new_tokens(){
    Tokens* tokens=malloc(sizeof(*tokens));
    if(tokens==NULL){
      printf("Unable to allocate memory while initializing tokens.\n");
      exit(1);
    }
    tokens->prev=NULL;
    return tokens;
}

  void add_token(Tokens** tokens, uint8_t * val, size_t size_val){//ajouter dans cette "table de hachage" de tokens l'adresse val repertorie par le contenu size_val.
    //TODO: get val token since size_val
    Token token = {.val=val,.type=TOKEN_UNKNOWN};
    Tokens* new=new_tokens();
    new->token=token;
    new->prev=*tokens;//ce qui va le preceder c'est tout le tableau des tokens
    *tokens=new;//ET (tjrs des choses{2} a ajouter) sommet de la pile est le nouveau jeton ajoute.
  }


//TOUT EST LOGIQUE JUSQU'A LA.
