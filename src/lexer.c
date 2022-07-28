#include"../include/lexer.h"
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
  *tmp='\0';//invalid write
  //ecriture dans un espace qui est pas alloué
  printf("sample name's file : %s\n",(char*)filename);
  printf("number of simple char:%d\n",len);
  //fclose(f);
  return content;
}



void display(Tokens* tokens){
  Tokens* current=tokens;
  printf("<Tokens[");
  while(current->prev!=NULL){
    printf("{token='%s', type: %s}",current->token.val,stringof_type(current->token.type));
current=current->prev;
}
printf("]>");
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
    Token token = init_token(val,size_val);
    Tokens* new=new_tokens(val,size_val);
    new->token=token;
    new->prev=*tokens;//ce qui va le preceder c'est tout le tableau des tokens
    *tokens=new;//ET (tjrs des choses{2} a ajouter) sommet de la pile est le nouveau jeton ajoute.
  }


//TOUT EST LOGIQUE JUSQU'A LA.

void free_all(Tokens* tokens){
  if(tokens->prev==NULL){
    free(tokens);
    return;
  }
  free_all(tokens->prev);
  free(tokens);
}

Token init_token(uint8_t *val, size_t size_val){
  Token token;
  token.val=malloc(sizeof(uint8_t)*sizeof(size_val+1));
  strncpy(token.val,val,size_val);
  token.type=tokenof(token.val);
  return token;
}

TokenType tokenof(uint8_t* val){
  if(isid(val)) return TOKEN_ID;
  if(istype(val)) return TOKEN_TYPE;
  if(strcmp(val,":")==0) return TOKEN_COLON;
  if(strcmp(val,";")==0) return TOKEN_SEMICOLON;
  if(strcmp(val,"=")==0) return TOKEN_ASSIGNMENT;
  if(isvalue(val)) return TOKEN_VALUE;
  if(strcmp(val,"print")==0) return TOKEN_PRINT;
  
  return TOKEN_UNKNOWN;
}

uint8_t* stringof_type(TokenType type){
  switch(type){
  case TOKEN_ID:
    return "ID";
  case TOKEN_TYPE:
    return "TYPE";
  case  TOKEN_COLON:
    return "COLON";
  case  TOKEN_SEMICOLON:
    return "SEMICOLON";
  case  TOKEN_ASSIGNMENT:
    return "ASSIGNEMENT";
  case  TOKEN_VALUE:
    return "VALUE";
  case TOKEN_PRINT:
    return "PRINT";
  
  }
}
//LEs fonctions essentielles pour la construction d'un language:
//voilà:

bool isid(uint8_t * val){//identificateur? [a-zA-Z]..
  //return false;
  size_t i=0;
  uint8_t* tmp=val;
  
  if(iskeyword(val)){
    return false;
  }

  if(*tmp=='_' || isalpha(*tmp)){
    ++i;
    ++tmp;
  }


  else return false;
  while(i<strlen(val) && (*tmp=='_' || isalnum(*tmp))){
    ++i;
    ++tmp;
  }

  
  return strlen(val)==i;
}

bool istype(uint8_t * val){//est un type dans TYPES (static const uint8_t**).
  //return false;
  size_t size=sizeof(TYPES)/sizeof(uint8_t*);
  return strcontains(TYPES,size,val);
}

//avec cela on peut faire dans notre
//future language: abcde comme variable et int comme TYPE.(TokenType --type).

bool isvalue(uint8_t * val){
  //todo check others value type like string and boolean.
  size_t i=0;
  while(i<strlen(val) && isdigit(val[i])){
    ++i;
  }
  return i==strlen(val);
}


bool iskeyword(uint8_t * val){
  size_t size=sizeof(TYPES)/sizeof(uint8_t*);
  return strcontains(KEYWORDS,size,val);
}

static bool strcontains(const uint8_t** strings,size_t size, uint8_t * s){
  //return false;
  size_t i=0;
  while(i<size && strcmp(strings[i],s)!=0){
    ++i;
  }
  return i!=size;
}


  
void tokenize(Tokens** tokens, uint8_t *seq){
  while(*seq!='\0'){
    if(isspace(*seq)){
      ++seq;
    }else if(isalnum(*seq)){
      seq=process_validstr(tokens,seq);
    }else if(isatomic(seq)){
      seq=process_atomic(tokens,seq);
    }else{
      printf("Syntax error: invalid character %c \n",*seq);
    }
  }
}

uint8_t* process_validstr(Tokens **tokens, uint8_t *seq){
  size_t i=0;
  while(i<strlen(seq) && isalnum(seq[i])){
    ++i;
  }
  add_token(tokens,seq,i);
  return seq+i;
}


  
uint8_t* process_atomic(Tokens **tokens, uint8_t *seq){
  add_token(tokens,seq,1);
  return seq+1;
}


 
bool isatomic(uint8_t* seq){
  size_t size=sizeof(ATOMICS)/sizeof(uint8_t);
  size_t i=0;
  while(i<size && ATOMICS[i]!=*seq){
    ++i;
  }
  return i!=size;
}





	
