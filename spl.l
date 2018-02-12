%{
#ifdef PRINT
#define TOKEN(t) printf("Token: " #t "\n");
#define ID_TOKEN(t) printf("Identifier: %s Token: " #t "\n", yytext);
#define CHAR_TOKEN(t) printf("Char: %s Token: " #t "\n", yytext);
#define INT_TOKEN(t) printf("Integer: %d Token: " #t "\n", atoi(yytext));
#define REAL_TOKEN(t) printf("Real: %f Token: " #t "\n", atof(yytext)); 
#else
#define TOKEN(t) return(t);
#define ID_TOKEN(t) yylval.iVal = installId(yytext,0);return (t);
#define CHAR_TOKEN(t) yylval.iVal = installId(yytext,1);return (t);
#define INT_TOKEN(t) yylval.iVal = atoi(yytext); return(t);
#define REAL_TOKEN(t) yylval.iVal = installId(yytext,2); return(t);
/* Declare Symbol Table Type and Array as imported types */
#include <string.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
int installId(char *, int type);
#endif
%}
delim           	[ \t\r\n]
character			[A-Za-z]
character_constant	\'[A-Za-z]\'
digit           	[0-9]
realNumber 			[0-9]+(\.[0-9]+)
intNumber 			{digit}+
identifier			{character}({character}|{digit})*
ws              	{delim}+
%%
"'"				TOKEN(APOS);
":"				TOKEN(COLON);
";"				TOKEN(SEMICOLON);
"."				TOKEN(PERIOD);
"->"			TOKEN(ASSIGNMENT);
"("				TOKEN(OPEN_BRACKET);
")"				TOKEN(CLOSE_BRACKET);
","				TOKEN(COMMA);
"="				TOKEN(EQUALS);
"<>"			TOKEN(NOT_EQUALS);
"<="			TOKEN(LESS_THAN_OR_EQUAL);
"<"				TOKEN(LESS_THAN);
">="			TOKEN(GREATER_THAN_OR_EQUAL);
">"				TOKEN(GREATER_THAN);
"+"				TOKEN(PLUS);
"-"				TOKEN(MINUS);
"*"				TOKEN(TIMES);
"/"				TOKEN(DIVIDE);
ENDP			TOKEN(SPL_ENDP);
IF				TOKEN(SPL_IF);
THEN			TOKEN(SPL_THEN);
ELSE			TOKEN(SPL_ELSE);
WHILE			TOKEN(SPL_WHILE);
DO				TOKEN(SPL_DO);
DECLARATIONS	TOKEN(SPL_DECLARATIONS);
CODE			TOKEN(SPL_CODE);
CHARACTER		TOKEN(SPL_CHARACTER);
INTEGER			TOKEN(SPL_INTEGER);
REAL			TOKEN(SPL_REAL);
OF				TOKEN(SPL_OF);
TYPE			TOKEN(SPL_TYPE);
ENDIF			TOKEN(SPL_ENDIF);
ENDDO			TOKEN(SPL_ENDDO);
ENDWHILE		TOKEN(SPL_ENDWHILE);
ENDFOR			TOKEN(SPL_ENDFOR);
FOR				TOKEN(SPL_FOR);
IS				TOKEN(SPL_IS);
BY				TOKEN(SPL_BY);
TO				TOKEN(SPL_TO);
WRITE			TOKEN(SPL_WRITE);
NEWLINE			TOKEN(SPL_NEWLINE);
READ			TOKEN(SPL_READ);
NOT				TOKEN(SPL_NOT);
AND				TOKEN(SPL_AND);
OR				TOKEN(SPL_OR);
{identifier}	ID_TOKEN(SPL_IDENTIFIER);
{character_constant}	CHAR_TOKEN(CHARACTER_CONSTANT);
{intNumber}		INT_TOKEN(INTEGER_NUM);
{realNumber}	REAL_TOKEN(REAL_NUM);
{ws}	;
.				printf("Error: Unexpected symbol in lexical analyser: %s (%d)\n",yytext,yytext[0]);
%%
#ifndef PRINT

SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

int installId(char *id, int type) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
	   symTab[currentSymTabSize]->type = type;
	   
       return(currentSymTabSize++);
    }
}
#endif
