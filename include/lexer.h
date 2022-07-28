#ifndef __H__
#define __H__

#include<ctype.h>
#include<stdint.h>
#include<stdlib.h>
//#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/**

id: [a-zA-Z_][a-zA-Z0-9_]*
type: 'string' | 'number' | 'boolean'
declaration: {id} ':' {type} ';'
number: [0-9]+
expression: {id}
assignment: {id} '=' {expression}

print: 'print' {expression}; 

*/


static const uint8_t* KEYWORDS[]={"string","number","boolean","print"};
static const uint8_t* TYPES[]={"string","number","boolean","print"};
static const uint8_t ATOMICS[]={':',';','='};

typedef enum{
	     TOKEN_ID,
	     TOKEN_TYPE,
	     TOKEN_COLON,
	     TOKEN_SEMICOLON,
	     TOKEN_ASSIGNMENT,
	     TOKEN_VALUE,
	     TOKEN_PRINT,
	     TOKEN_UNKNOWN
}TokenType;//les types de jetons qui rassemblent le contexte lexical(le vocabulaire) cad. le jeton relatif a id/type/,/;/value/print et +.(unknown)///


typedef struct{//c'est quoi un jeton?(stdint.h)
  uint8_t* val;//peut pas deborder le int, c'est cadre.
  TokenType type;
  //on définit en quoi consiste un jeton un pointeur vers une valeur soit un
  //adressage et un type de type TokenType
}Token;


typedef struct Tokens{
  Token token;
  struct Tokens * prev;
}Tokens;//liste chainee a l'arriere.


uint8_t* read_entry(char* filename);//pointeur debut flux text par exemple..///
Tokens * new_tokens();//un tableau de listes de jetons nouveaux..
void add_token(Tokens** tokens, uint8_t * val, size_t size_val);//ajouter dans cette "table de hachage" de tokens l'adresse val repertorie par le contenu size_val.
void display(Tokens* tokens);
void free_all(Tokens* tokens);

//---------------------Les autres fonctions:(unknown non:::!!!!!!!).

Token init_token(uint8_t *val, size_t size_val);
TokenType tokenof(uint8_t *val);
uint8_t *stringof_type(TokenType type);


//------------------------------DEUXIEME SECTION:


bool isid(uint8_t * val);
bool istype(uint8_t * val);
bool isvalue(uint8_t * val);

//--------------------------------------TROISIEME SECTION:
bool iskeyword(uint8_t * val);
static bool strcontains(const uint8_t** strings,size_t size, uint8_t * s);

//--------------------------------------4ieme section de fonctions:


//-------------------------------------------
void tokenize(Tokens** tokens, uint8_t* seq);

//

uint8_t* process_validstr(Tokens **tokens, uint8_t *seq);
uint8_t* process_atomic(Tokens **tokens, uint8_t *seq);
bool isatomic(uint8_t* seq);

//(la suite;leurs utilisations<<<).


#endif

