%{
#include <stdio.h>
#include <stdlib.h>

#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

char parseType = '\0';
int charConstant = 0;

enum ParseTreeNodeType{PROGRAM, BLOCK, DECLARATION, DECLARATION_BLOCK, TYPE, STATEMENT_LIST, STATEMENT, 
					   STATEMENT_ASSIGNMENT, STATEMENT_IF, STATEMENT_DO, STATEMENT_WHILE, STATEMENT_FOR, STATEMENT_WRITE, 
					   STATEMENT_READ, ASSIGNMENT_STATEMENT, IF_STATEMENT, DO_STATEMENT, WHILE_STATEMENT,
					   FOR_STATEMENT, WRITE_STATEMENT, NEWLINE_STATEMENT, READ_STATEMENT, OUTPUT_LIST, CONDITIONAL,
					   CONDITION, NOT_CONDITION, COMPARATOR, EXPRESSION, TERM, VALUE, CONSTANT, CONSTANT_VALUE, 
					   IDENTIFIER_VALUE, EXPRESSION_VALUE, CHAR_CONSTANT, NUMBER_INT, NUMBER_REAL, MINUS_NUM_INT, 
					   MINUS_NUM_REAL, DECLARATION_LIST, BLOCK_ALT, DECLARATION_BLOCK_ALT, IF_STATEMENT_ALT, 
					   STATEMENT_LIST_ALT,OUTPUT_LIST_ALT, CONDITIONAL_AND, CONDITIONAL_OR, COMPARATOR_EQUALS, 
					   COMPARATOR_GREATER_THAN, COMPARATOR_GREATER_THAN_OR_EQUAL, COMPARATOR_LESS_THAN, 
					   COMPARATOR_LESS_THAN_OR_EQUAL, COMPARATOR_NOT_EQUALS, EXPRESSION_MINUS, EXPRESSION_PLUS,
					   TERM_DIVIDE, TERM_TIMES, MINUS_NUMBER_INT, MINUS_NUMBER_REAL};
					   
char *NodeName[] = {"PROGRAM", "BLOCK", "DECLARATION", "DECLARATION_BLOCK", "TYPE", "STATEMENT_LIST", "STATEMENT", 
					"STATEMENT_ASSIGNMENT", "STATEMENT_IF", "STATEMENT_DO", "STATEMENT_WHILE", "STATEMENT_FOR", "STATEMENT_WRITE", 
					"STATEMENT_READ", "ASSIGNMENT_STATEMENT", "IF_STATEMENT", "DO_STATEMENT", "WHILE_STATEMENT",
					"FOR_STATEMENT", "WRITE_STATEMENT", "NEWLINE_STATEMENT", "READ_STATEMENT", "OUTPUT_LIST", "CONDITIONAL", 
					"CONDITION", "NOT_CONDITION", "COMPARATOR", "EXPRESSION", "TERM", "VALUE", "CONSTANT", "CONSTANT_VALUE", 
					"IDENTIFIER_VALUE", "EXPRESSION_VALUE", "CHAR_CONSTANT", "NUMBER_INT", "NUMBER_REAL", "MINUS_NUM_INT", 
					"MINUS_NUM_REAL", "DECLARATION_LIST", "BLOCK_ALT", "DECLARATION_BLOCK_ALT", "IF_STATEMENT_ALT", 
					"STATEMENT_LIST_ALT","OUTPUT_LIST_ALT", "CONDITIONAL_AND", "CONDITIONAL_OR", "COMPARATOR_EQUALS", 
					"COMPARATOR_GREATER_THAN", "COMPARATOR_GREATER_THAN_OR_EQUAL", "COMPARATOR_LESS_THAN", 
					"COMPARATOR_LESS_THAN_OR_EQUAL", "COMPARATOR_NOT_EQUALS", "EXPRESSION_MINUS", "EXPRESSION_PLUS",
					"TERM_DIVIDE", "TERM_TIMES", "MINUS_NUMBER_INT", "MINUS_NUMBER_REAL"};

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
	struct treeNode *fourth;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */
TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
#ifdef DEBUG
  void PrintTree(TERNARY_TREE,int);
#endif
	void WriteCode(TERNARY_TREE);
	void yyerror(char *);
	int yylex(void);

/* ------------- symbol table definition --------------------------- */
struct symTabNode {
    char identifier[IDLENGTH];
	char type;
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;
%}

/****************/
/* Start symbol */
/****************/
%start  program

/**********************/
/* Action value types */
/**********************/
%union {
    int iVal;
    TERNARY_TREE  tVal;
}

%token APOS COLON SEMICOLON PERIOD ASSIGNMENT OPEN_BRACKET CLOSE_BRACKET COMMA EQUALS NOT_EQUALS 
	   LESS_THAN_OR_EQUAL LESS_THAN GREATER_THAN_OR_EQUAL GREATER_THAN PLUS MINUS TIMES DIVIDE 
	   SPL_ENDP SPL_IF SPL_THEN SPL_ELSE SPL_WHILE SPL_DO SPL_DECLARATIONS SPL_CODE SPL_CHARACTER 
	   SPL_INTEGER SPL_REAL SPL_OF SPL_TYPE SPL_ENDIF SPL_ENDDO SPL_ENDWHILE SPL_ENDFOR SPL_FOR 
	   SPL_IS SPL_BY SPL_TO SPL_WRITE SPL_NEWLINE SPL_READ SPL_NOT SPL_AND SPL_OR 
	   
%token<iVal> SPL_IDENTIFIER INTEGER_NUM CHARACTER_CONSTANT REAL_NUM 
	   
	   
%type<tVal> program block declaration declaration_block type statement_list
			statement assignment_statement if_statement do_statement while_statement
			for_statement write_statement read_statement output_list conditional 
			condition comparator expression term value constant number_constant 
%%	

program : SPL_IDENTIFIER COLON block SPL_ENDP SPL_IDENTIFIER PERIOD
			{ TERNARY_TREE ParseTree;
                  ParseTree = create_node($1, PROGRAM, $3, NULL, NULL, NULL);
				  #ifdef DEBUG
					PrintTree(ParseTree, 0);
				  #else 
					WriteCode(ParseTree);
			      #endif
            }
		;
		
block : SPL_DECLARATIONS declaration_block SPL_CODE statement_list
				{ 
					$$ = create_node(NOTHING, BLOCK, $2, $4, NULL, NULL);
				}
			| SPL_CODE statement_list
				{ 
					$$ = create_node(NOTHING, BLOCK, $2, NULL, NULL, NULL);
				}
		;
	
declaration : SPL_IDENTIFIER 
					{ 
						$$ = create_node($1, DECLARATION, NULL, NULL, NULL, NULL);
					}
				| SPL_IDENTIFIER COMMA declaration
					{ 
						$$ = create_node($1, DECLARATION_LIST, $3, NULL, NULL, NULL);
					}

		;	
	
declaration_block : declaration SPL_OF SPL_TYPE type SEMICOLON
						{ 
							$$ = create_node(NOTHING, DECLARATION_BLOCK, $1, $4, NULL, NULL);
						}
					| declaration SPL_OF SPL_TYPE type SEMICOLON declaration_block
						{ 
							$$ = create_node(NOTHING, DECLARATION_BLOCK, $1, $4, $6, NULL);
						}

	;	
	
type : SPL_CHARACTER 
			{ 
				$$ = create_node(SPL_CHARACTER, TYPE, NULL, NULL, NULL, NULL);
			}
		| SPL_INTEGER
			{ 
				$$ = create_node(SPL_INTEGER, TYPE, NULL, NULL, NULL, NULL);
			}
		| SPL_REAL
			{ 
				$$ = create_node(SPL_REAL, TYPE, NULL, NULL, NULL, NULL);
			}
	;
	
statement_list : statement SEMICOLON statement_list
				 { 
						$$ = create_node(NOTHING, STATEMENT_LIST, $1, $3, NULL, NULL);
        		 }
				| statement 
				  { 
						$$ = create_node(NOTHING, STATEMENT_LIST, $1, NULL, NULL, NULL);
        		  }       		
	;

statement : assignment_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_ASSIGNMENT, $1, NULL, NULL, NULL);
				}
			| if_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_IF, $1, NULL, NULL, NULL);
				}
			| do_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_DO, $1, NULL, NULL, NULL);
				}
			| while_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_WHILE, $1, NULL, NULL, NULL);
				}
			| for_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_FOR, $1, NULL, NULL, NULL);
				}
			| write_statement
				{ 
					$$ = create_node(NOTHING, STATEMENT_WRITE, $1, NULL, NULL, NULL);
				}
			| read_statement 
				{ 
					$$ = create_node(NOTHING, STATEMENT_READ, $1, NULL, NULL, NULL);
				}
	;
	
assignment_statement : expression ASSIGNMENT SPL_IDENTIFIER
					{ 
	                  $$ = create_node($3, ASSIGNMENT_STATEMENT, $1, NULL, NULL, NULL);
	            	}
	;

if_statement : SPL_IF conditional SPL_THEN statement_list SPL_ELSE statement_list SPL_ENDIF 
					{ 
						$$ = create_node(NOTHING, IF_STATEMENT, $2, $4, $6, NULL);
					}
				| SPL_IF conditional SPL_THEN statement_list SPL_ENDIF
					{ 
						$$ = create_node(NOTHING, IF_STATEMENT, $2, $4, NULL, NULL);
					}
	;

do_statement : SPL_DO statement_list SPL_WHILE conditional SPL_ENDDO
					{ 
						$$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL, NULL);
					}
	;

while_statement : SPL_WHILE conditional SPL_DO statement_list SPL_ENDWHILE
					{ 
						$$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL, NULL);
					}
	;

for_statement : SPL_FOR SPL_IDENTIFIER SPL_IS expression SPL_BY expression 
				SPL_TO expression SPL_DO statement_list SPL_ENDFOR
					{ 
						$$ = create_node($2, FOR_STATEMENT, $4, $6, $8, $10);
					}
	;

write_statement : SPL_WRITE OPEN_BRACKET output_list CLOSE_BRACKET
					{ 
						$$ = create_node(NOTHING, WRITE_STATEMENT, $3, NULL, NULL, NULL);
					}	
				| SPL_NEWLINE
					{ 
						$$ = create_node(SPL_NEWLINE, NEWLINE_STATEMENT, NULL, NULL, NULL, NULL);
					}
	;

read_statement : SPL_READ OPEN_BRACKET SPL_IDENTIFIER CLOSE_BRACKET
					{ 
						$$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL, NULL);
					}
	;	
	
output_list : value COMMA output_list 
					{ 
						$$ = create_node(NOTHING, OUTPUT_LIST, $1, $3, NULL, NULL);
					}
				|
				value
					{ 
						$$ = create_node(NOTHING, OUTPUT_LIST_ALT, $1, NULL, NULL, NULL);
					}	
	;
	
conditional : conditional SPL_AND condition
					{ 
						$$ = create_node(NOTHING, CONDITIONAL_AND, $1, $3, NULL, NULL);
					}
				| conditional SPL_OR condition
					{ 
						$$ = create_node(NOTHING, CONDITIONAL_OR, $1, $3, NULL, NULL);
					}
				| condition
					{ 
						$$ = create_node(NOTHING, CONDITIONAL, $1, NULL, NULL, NULL);
					}	
	;
	
condition : expression comparator expression 
					{ 
						$$ = create_node(NOTHING, CONDITION, $1, $2, $3, NULL);
					}
				| 
				SPL_NOT condition
					{ 
						$$ = create_node(NOTHING, NOT_CONDITION, $2, NULL, NULL, NULL);
					}
	;

comparator : EQUALS
					{ 
						$$ = create_node(EQUALS, COMPARATOR_EQUALS, NULL, NULL, NULL, NULL);
					} 
				| NOT_EQUALS 
					{ 
						$$ = create_node(NOT_EQUALS, COMPARATOR_NOT_EQUALS, NULL, NULL, NULL, NULL);
					} 
				| LESS_THAN 
					{ 
						$$ = create_node(LESS_THAN, COMPARATOR_LESS_THAN, NULL, NULL, NULL, NULL);
					} 
				| GREATER_THAN 
					{ 
						$$ = create_node(GREATER_THAN, COMPARATOR_GREATER_THAN, NULL, NULL, NULL, NULL);
					} 
				| LESS_THAN_OR_EQUAL 
					{ 
						$$ = create_node(LESS_THAN_OR_EQUAL, COMPARATOR_LESS_THAN_OR_EQUAL, NULL, NULL, NULL, NULL);
					} 
				| GREATER_THAN_OR_EQUAL
					{ 
						$$ = create_node(GREATER_THAN_OR_EQUAL, COMPARATOR_GREATER_THAN_OR_EQUAL, NULL, NULL, NULL, NULL);
					} 	
	;
	
expression : expression PLUS term 
					{ 
						$$ = create_node(NOTHING, EXPRESSION_PLUS, $1, $3, NULL, NULL);
					} 
				| expression MINUS term
					{ 
						$$ = create_node(NOTHING, EXPRESSION_MINUS, $1, $3, NULL, NULL);
					} 
				| term 
					{ 
						$$ = create_node(NOTHING, EXPRESSION, $1, NULL, NULL, NULL);
					} 	

term : term TIMES value
			{ 
				$$ = create_node(NOTHING, TERM_TIMES, $1, $3, NULL, NULL);
			} 
		| term DIVIDE value
			{ 
				$$ = create_node(NOTHING, TERM_DIVIDE, $1, $3, NULL, NULL);
			} 
		| value
			{ 
				$$ = create_node(NOTHING, TERM, $1, NULL, NULL, NULL);
			} 	
    ;
	
value : SPL_IDENTIFIER 
			{ 
				$$ = create_node($1, IDENTIFIER_VALUE, NULL, NULL, NULL, NULL);
			}
		| constant
			{ 
				$$ = create_node(NOTHING, CONSTANT_VALUE, $1, NULL, NULL, NULL);
			}	
		| OPEN_BRACKET expression CLOSE_BRACKET
			{ 
				$$ = create_node(NOTHING, EXPRESSION_VALUE, $2, NULL, NULL, NULL);
			}
    ;
	
constant : number_constant 
			{ 
				$$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL, NULL);
			}
			| CHARACTER_CONSTANT
			{ 
				$$ = create_node($1, CHAR_CONSTANT, NULL, NULL, NULL, NULL);
			}
	;	
	
number_constant : INTEGER_NUM 
					{ 
						$$ = create_node($1, NUMBER_INT, NULL, NULL, NULL, NULL);
					}
				| REAL_NUM
					{ 
						$$ = create_node($1, NUMBER_REAL, NULL, NULL, NULL, NULL);
					}
				| MINUS INTEGER_NUM
					{ 
						$$ = create_node($2, MINUS_NUMBER_INT, NULL, NULL, NULL, NULL);
					}
				| MINUS REAL_NUM
					{ 
						$$ = create_node($2, MINUS_NUMBER_REAL, NULL, NULL, NULL, NULL);
					}				
	;
	
%%

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3, TERNARY_TREE p4)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
	t->fourth = p4;
    return (t);
}


void WriteCode(TERNARY_TREE t) 
{
	if (t == NULL) return;
	switch(t->nodeIdentifier) 
	{
		case(PROGRAM) :
			printf("#include <stdio.h>\n");
			printf("\tint main(void) {\n");
			WriteCode(t->first);
			printf("\n");
			printf("return 0;\n");
			printf("}");
			break;
		case(BLOCK) :
			WriteCode(t->first);
			if(t->second != NULL)
				WriteCode(t->second);
			break;		
		case(DECLARATION_BLOCK) :
			WriteCode(t->second);		
			WriteCode(t->first);
			if (t->third != NULL)
				WriteCode(t->third);
			break;
        case(DECLARATION) :	
			printf("%s", symTab[t->item]->identifier);
			symTab[t->item]->type = parseType;
			printf(";");
			printf("\n");
			break;
		case(DECLARATION_LIST) :
			printf("%s", symTab[t->item]->identifier);
			symTab[t->item]->type = parseType;
			printf(", ");
			WriteCode(t->first);	
			break;
			
		case(TYPE) :
			switch(t->item) 
			{
				case SPL_CHARACTER:
					parseType = 'c';
					printf("char ");
					break;
				case SPL_REAL:
					parseType = 'f';
					printf("float ");
					break;
				case SPL_INTEGER:
					parseType = 'i';
					printf("int ");
					break;					
			}
			break;	
			
		case (STATEMENT_LIST) :
			WriteCode(t->first);
			if(t->second != NULL) 
			{
				WriteCode(t->second);
			}
			else 
			{
				printf("\n");			
			}
			break;
								
		case (WRITE_STATEMENT) :
			printf("\n");
			WriteCode(t->first);
			break;
		
		case (NEWLINE_STATEMENT) :
            printf("printf(\"\\n\");\n");
            break;
			
		case (READ_STATEMENT):
			printf("\n");;
			printf("scanf(\"");
			switch(symTab[t->item]->type)
			{
				case 'c':
					printf("%%c");
					break;
				case 'i':
					printf("%%d");
					break;
				case 'f':
					printf("%%f");
					break;
			}
			printf("\",");
			printf("&");
			printf("%s",  symTab[t->item]->identifier);
			printf(");\n");
			break;

		case (IF_STATEMENT) :
			printf("\n");
			printf("if (");
			WriteCode(t->first);
			printf(") {\n");
			WriteCode(t->second);
			printf("}\n");
			if(t->third != NULL)
			{
				printf("else\n{\n");
				WriteCode(t->third);
				printf("}\n");
			}			
			break;	
		
		case (WHILE_STATEMENT) :
			printf("\n");		
			printf("while (");
			WriteCode(t->first);
			printf("){\n");	
			WriteCode(t->second);	
			printf("}");	
			printf("\n");
			break;
			
		case (DO_STATEMENT) :
			printf("\n");		
			printf("do{\n");
			WriteCode(t->first);
			printf("\n");
			printf("}\n");
			printf("while(");
			WriteCode(t->second);
			printf(");");
			printf("\n");
			break;
			
		
		case (FOR_STATEMENT):	
        	 	printf("register int _by0;");
        	 	printf("\n");
            	printf("for (");
            	printf("%s",symTab[t->item]->identifier);
            	printf(" = ");
            	WriteCode(t->first);
            	printf("; ");
            	printf("_by0=");
            	WriteCode(t->second);
            	printf(", ((");
            	printf("%s",symTab[t->item]->identifier);
            	printf("-(");
            	WriteCode(t->third);
       			printf("))");
            	printf("*");
            	printf("((");
            	printf("_by0 > 0)");
            	printf(" - ");
            	printf("(_by0 < 0))) ");
            	printf("<= 0; ");
            	printf("%s",symTab[t->item]->identifier);
            	printf(" += _by0");
            	printf(") {\n");
            	WriteCode(t->fourth);
            	printf("\n}");
            	break;
			
			
		case (ASSIGNMENT_STATEMENT) :
			if (t->item >= 0 && t->item < SYMTABSIZE)
				printf("%s", symTab[t->item]->identifier);
			else printf("Unknown Identifier:%d",t->item);
			printf(" = ");
			WriteCode(t->first);
			printf(";");
			printf("\n");
			break;
		
		case (STATEMENT_ASSIGNMENT):
			WriteCode(t->first);
			break;
		
		case (STATEMENT_DO):
			WriteCode(t->first);
			break;

		case (STATEMENT_WHILE):
			WriteCode(t->first);
			break;

		case (STATEMENT_FOR):
			WriteCode(t->first);
			break;

		case (STATEMENT_WRITE):
			WriteCode(t->first);
			break;		

		case (STATEMENT_READ):
			WriteCode(t->first);
			break;	
			
		case (STATEMENT_IF):
			WriteCode(t->first);
			break;				
					
		
		case (OUTPUT_LIST_ALT) :
			if (t->first->nodeIdentifier == IDENTIFIER_VALUE) 
			{
				printf("printf(\"");
				switch(symTab[t->first->item]->type) 
				{
					case 'c':
						printf("%%c\""", ");
						break;
					case 'i':
						printf("%%d\""", ");
						break;
					case 'f':
						printf("%%f\""", ");
						break;
				}
				WriteCode(t->first);
				printf(");\n");
			}
			else if(t->first != NULL && t->first->nodeIdentifier == CONSTANT_VALUE) 
			{
				printf("printf(\"");
				charConstant = 1;
				WriteCode(t->first);
				printf(");\n");
				charConstant = 0;
			}
			else if (t->first->nodeIdentifier == NUMBER_INT)
			{
				printf("printf(\"");
				printf("%%d\", ");
				WriteCode(t->first);
				printf(")\n");
			}	
			else 
			{
				printf("printf(\"");
				printf("%%f\", ");
				WriteCode(t->first);
				printf(");\n");
			}
			break;

		case (OUTPUT_LIST) :
			if (t->first->nodeIdentifier == IDENTIFIER_VALUE) 
			{
				printf("printf(\"");
				switch(symTab[t->first->item]->type) 
				{
					case 'c':
						printf("%%c \""", ");
						break;
					case 'i':
						printf("%%d\""", ");
						break;
					case 'f':
						printf("%%f\""", ");
						break;
				}
				WriteCode(t->first);
				printf(");\n");
				WriteCode(t->second);
			}
			else if(t->first->nodeIdentifier == CONSTANT_VALUE) 
			{
				printf("printf(\"");
				charConstant = 1;
				WriteCode(t->first);
				printf(");\n");
				WriteCode(t->second);
				charConstant = 0;
			}
			else if (t->first->nodeIdentifier == NUMBER_INT)
			{
				printf("printf(\"");
				printf("%%d\", ");
				WriteCode(t->first);
				printf(")\n");
			}	
			else 
			{
				printf("printf(\"");
				printf("%%f\", ");
				WriteCode(t->first);
				printf(")\n");
			}
			break;
		
		case (CONSTANT) : 
			WriteCode(t->first);
			break;
		
		case (CHAR_CONSTANT):
			if(charConstant == 1) 
			{
				printf("%%c\""", ");
				printf("%s", symTab[t->item]->identifier);			
			}
			else 
			{
				printf("%s", symTab[t->item]->identifier);
			}
			break;	
		
		case (CONDITIONAL_AND):
			WriteCode(t->first);
			printf(" && ");
			WriteCode(t->second);
			break;
			
		case (CONDITIONAL_OR):
			WriteCode(t->first);
			printf(" || ");
			WriteCode(t->second);
			break;
		
		case (CONDITIONAL):
			WriteCode(t->first);
			break;
			
		case (CONDITION):
			WriteCode(t->first);
			printf(" ");
			WriteCode(t->second);
			printf(" ");
			WriteCode(t->third);
			break;
			
		case (NOT_CONDITION):
			printf("!(");
			WriteCode(t->first);
			printf(")");
			break;
				
        case (COMPARATOR_EQUALS) :
           	printf("==");
           	break;
			
        case (COMPARATOR_NOT_EQUALS) :
           	printf("!=");
           	break;

        case (COMPARATOR_LESS_THAN) :
           	printf("<");
           	break;

        case (COMPARATOR_GREATER_THAN) :
           	printf(">");
           	break;

        case (COMPARATOR_LESS_THAN_OR_EQUAL) :
           	printf("<=");
           	break;

        case (COMPARATOR_GREATER_THAN_OR_EQUAL) :
           	printf(">=");
           	break;	

		case (EXPRESSION_MINUS):
			WriteCode(t->first);
			printf(" - ");
			WriteCode(t->second);
			break;
			
		case (EXPRESSION_PLUS):
			WriteCode(t->first);
			printf(" + ");
			WriteCode(t->second);
			break;		

		case (EXPRESSION):
			WriteCode(t->first);
			break;
			
		case (TERM_DIVIDE):
			WriteCode(t->first);
			printf(" / ");
			WriteCode(t->second);
			break;
			
		case (TERM_TIMES):
			WriteCode(t->first);
			printf(" * ");
			WriteCode(t->second);
			break;		

		case (TERM):
			WriteCode(t->first);
			break;
			
		case (CONSTANT_VALUE):
			WriteCode(t->first);
			break;
		
		case (IDENTIFIER_VALUE):
			printf("%s", symTab[t->item]->identifier);
			break;
			
		case (NUMBER_REAL):
			if (charConstant == 1) 
			{		
    			printf("%%f\""", ");
    			printf("%s\n", symTab[t->item]->identifier);
			}
			else 
			{
				printf("%s\n", symTab[t->item]->identifier);
			}
			break;
			
		case (MINUS_NUMBER_REAL):
			if (charConstant == 1) 
			{		
    			printf("%%f\""", ");
    			printf("-%s\n", symTab[t->item]->identifier);
			}
			else 
			{
				printf("-%s\n", symTab[t->item]->identifier);
			}
			break;			
			
		case (NUMBER_INT):
			if (charConstant == 1) 
			{
				printf("%d\n", t->item);
				symTab[t->item]->type = 'i';				
			}
			else 
			{
				printf("%d", t->item);
			}	
			break;
			
		case (MINUS_NUMBER_INT):
			if (charConstant == 1) 
			{
				printf("-%d\n", t->item);
				symTab[t->item]->type = 'i';				
			}
			else 
			{
				printf("-%d", t->item);
			}	
			break;			
			
		case (EXPRESSION_VALUE):
			printf(" (");
			WriteCode(t->first);
			printf(") ");
			break;

		case (SPL_IDENTIFIER):
			printf("%s",symTab[t->item]->identifier);
			printf(");\n");			
			break;			
									
		default :
			WriteCode(t->first);
			WriteCode(t->second);
			WriteCode(t->third);		
			break;
	}
}


#ifdef DEBUG
/* Put other auxiliary functions here */
void PrintTree(TERNARY_TREE t, int indent)
{
	int i;
	if(t == NULL) return;
	for(i=indent;i;i--)printf(" ");
	if (t->item != NOTHING) {
		if(t->nodeIdentifier == NUMBER_INT)
		{
			printf(" INTEGER: %d\n", t->item);
		}
		
		else if(t->nodeIdentifier == MINUS_NUMBER_INT)
		{
			printf(" INTEGER: -%d\n", t->item);
		}
		
		else if(t->nodeIdentifier == NUMBER_REAL)
		{
			printf(" REAL: %s\n", symTab[t->item]->identifier);
		}
		
		else if(t->nodeIdentifier == MINUS_NUMBER_REAL)
		{
			printf(" REAL: -%s\n", symTab[t->item]->identifier);
		}
		
		else if(t->nodeIdentifier == IDENTIFIER_VALUE)
		{
			printf(" VAL IDENTIFIER: %s\n", symTab[t->item]->identifier);
		}
		else if(t->nodeIdentifier == CHAR_CONSTANT)
		{
			printf(" CHAR_CONSTANT: %s\n", symTab[t->item]->identifier);		
		}
		else if(t->nodeIdentifier == DECLARATION_BLOCK)
		{
				printf(" DECLARATION_BLOCK: %s\n", symTab[t->item]->identifier);
				
		}
		else if(t->nodeIdentifier == DECLARATION_BLOCK_ALT)
		{
				printf(" DECLARATION_BLOCK: %s\n", symTab[t->item]->identifier);
				
		}		
		else if(t->nodeIdentifier == DECLARATION_LIST)
		{
				printf(" DECLARATION_LIST: %s\n", symTab[t->item]->identifier);
				
		}
		else if(t->nodeIdentifier == DECLARATION)
		{
				printf(" DECLARATION: %s\n", symTab[t->item]->identifier);
				
		}	
		
		/*else if(t->nodeIdentifier == TYPE)
		{
				printf(" TYPE: %d\n", symTab[t->type]->type);
				
		}*/			
	}
	
	else printf("%s\n", NodeName[t->nodeIdentifier]);
	
	PrintTree(t->first,indent+2);
	PrintTree(t->second,indent+2);
	PrintTree(t->third,indent+2);
}
#endif 
#include "lex.yy.c"
	
	
   