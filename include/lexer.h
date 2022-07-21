#ifndef __H__
#define __H__

#include<stdint.h>
#include<stdlib.h>
//#include<stdio.h>

/**

id: [a-zA-Z_][a-zA-Z0-9_]*
type: 'string' | 'number' | 'boolean'
declaration: {id} ':' {type} ';'
number: [0-9]+
expression: {id}
assignment: {id} '=' {expression}

print: 'print' {expression}; 

*/



typedef enum{
	     TOKEN_ID,
	     TOKEN_TYPE,
	     TOKEN_COLON,
	     TOKEN_SEMICOLON,
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
#endif
