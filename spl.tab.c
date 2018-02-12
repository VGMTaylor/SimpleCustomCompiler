
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "spl.y"

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


/* Line 189 of yacc.c  */
#line 159 "spl.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     APOS = 258,
     COLON = 259,
     SEMICOLON = 260,
     PERIOD = 261,
     ASSIGNMENT = 262,
     OPEN_BRACKET = 263,
     CLOSE_BRACKET = 264,
     COMMA = 265,
     EQUALS = 266,
     NOT_EQUALS = 267,
     LESS_THAN_OR_EQUAL = 268,
     LESS_THAN = 269,
     GREATER_THAN_OR_EQUAL = 270,
     GREATER_THAN = 271,
     PLUS = 272,
     MINUS = 273,
     TIMES = 274,
     DIVIDE = 275,
     SPL_ENDP = 276,
     SPL_IF = 277,
     SPL_THEN = 278,
     SPL_ELSE = 279,
     SPL_WHILE = 280,
     SPL_DO = 281,
     SPL_DECLARATIONS = 282,
     SPL_CODE = 283,
     SPL_CHARACTER = 284,
     SPL_INTEGER = 285,
     SPL_REAL = 286,
     SPL_OF = 287,
     SPL_TYPE = 288,
     SPL_ENDIF = 289,
     SPL_ENDDO = 290,
     SPL_ENDWHILE = 291,
     SPL_ENDFOR = 292,
     SPL_FOR = 293,
     SPL_IS = 294,
     SPL_BY = 295,
     SPL_TO = 296,
     SPL_WRITE = 297,
     SPL_NEWLINE = 298,
     SPL_READ = 299,
     SPL_NOT = 300,
     SPL_AND = 301,
     SPL_OR = 302,
     SPL_IDENTIFIER = 303,
     INTEGER_NUM = 304,
     CHARACTER_CONSTANT = 305,
     REAL_NUM = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 94 "spl.y"

    int iVal;
    TERNARY_TREE  tVal;



/* Line 214 of yacc.c  */
#line 253 "spl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 265 "spl.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    15,    18,    20,    24,    30,    37,
      39,    41,    43,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    67,    75,    81,    87,    93,   105,   110,   112,
     117,   121,   123,   127,   131,   133,   137,   140,   142,   144,
     146,   148,   150,   152,   156,   160,   162,   166,   170,   172,
     174,   176,   180,   182,   184,   186,   188,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      53,     0,    -1,    48,     4,    54,    21,    48,     6,    -1,
      27,    56,    28,    58,    -1,    28,    58,    -1,    48,    -1,
      48,    10,    55,    -1,    55,    32,    33,    57,     5,    -1,
      55,    32,    33,    57,     5,    56,    -1,    29,    -1,    30,
      -1,    31,    -1,    59,     5,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    71,     7,    48,    -1,    22,    68,    23,
      58,    24,    58,    34,    -1,    22,    68,    23,    58,    34,
      -1,    26,    58,    25,    68,    35,    -1,    25,    68,    26,
      58,    36,    -1,    38,    48,    39,    71,    40,    71,    41,
      71,    26,    58,    37,    -1,    42,     8,    67,     9,    -1,
      43,    -1,    44,     8,    48,     9,    -1,    73,    10,    67,
      -1,    73,    -1,    68,    46,    69,    -1,    68,    47,    69,
      -1,    69,    -1,    71,    70,    71,    -1,    45,    69,    -1,
      11,    -1,    12,    -1,    14,    -1,    16,    -1,    13,    -1,
      15,    -1,    71,    17,    72,    -1,    71,    18,    72,    -1,
      72,    -1,    72,    19,    73,    -1,    72,    20,    73,    -1,
      73,    -1,    48,    -1,    74,    -1,     8,    71,     9,    -1,
      75,    -1,    50,    -1,    49,    -1,    51,    -1,    18,    49,
      -1,    18,    51,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   125,   129,   135,   139,   146,   150,   157,
     161,   165,   171,   175,   181,   185,   189,   193,   197,   201,
     205,   211,   217,   221,   227,   233,   239,   246,   250,   256,
     262,   267,   273,   277,   281,   287,   292,   298,   302,   306,
     310,   314,   318,   324,   328,   332,   337,   341,   345,   351,
     355,   359,   365,   369,   375,   379,   383,   387
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "APOS", "COLON", "SEMICOLON", "PERIOD",
  "ASSIGNMENT", "OPEN_BRACKET", "CLOSE_BRACKET", "COMMA", "EQUALS",
  "NOT_EQUALS", "LESS_THAN_OR_EQUAL", "LESS_THAN", "GREATER_THAN_OR_EQUAL",
  "GREATER_THAN", "PLUS", "MINUS", "TIMES", "DIVIDE", "SPL_ENDP", "SPL_IF",
  "SPL_THEN", "SPL_ELSE", "SPL_WHILE", "SPL_DO", "SPL_DECLARATIONS",
  "SPL_CODE", "SPL_CHARACTER", "SPL_INTEGER", "SPL_REAL", "SPL_OF",
  "SPL_TYPE", "SPL_ENDIF", "SPL_ENDDO", "SPL_ENDWHILE", "SPL_ENDFOR",
  "SPL_FOR", "SPL_IS", "SPL_BY", "SPL_TO", "SPL_WRITE", "SPL_NEWLINE",
  "SPL_READ", "SPL_NOT", "SPL_AND", "SPL_OR", "SPL_IDENTIFIER",
  "INTEGER_NUM", "CHARACTER_CONSTANT", "REAL_NUM", "$accept", "program",
  "block", "declaration", "declaration_block", "type", "statement_list",
  "statement", "assignment_statement", "if_statement", "do_statement",
  "while_statement", "for_statement", "write_statement", "read_statement",
  "output_list", "conditional", "condition", "comparator", "expression",
  "term", "value", "constant", "number_constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    60,    61,    61,    62,    63,    64,    65,    65,    66,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    73,
      73,    73,    74,    74,    75,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     1,     3,     5,     6,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     7,     5,     5,     5,    11,     4,     1,     4,
       3,     1,     3,     3,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
      49,    54,    53,    55,     4,    13,    14,    15,    16,    17,
      18,    19,    20,     0,    45,    48,    50,    52,     0,     0,
       0,     0,     0,    56,    57,     0,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     3,    51,    36,     0,     0,     0,    37,
      38,    41,    39,    42,    40,     0,     0,     0,     0,     0,
      31,     0,    12,    21,    43,    44,    46,    47,     2,     9,
      10,    11,     0,     0,    32,    33,    35,     0,     0,     0,
      27,     0,    29,     7,     0,    23,    25,    24,     0,    30,
       8,     0,     0,    22,     0,     0,     0,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     9,    10,    92,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    79,    46,    47,    75,    33,
      34,    35,    36,    37
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int8 yypact[] =
{
     -42,    19,    14,    57,   -49,   -22,    -1,     9,    36,    63,
      23,    21,   -16,    10,    10,    -1,    41,    88,   -49,    92,
     -49,   -49,   -49,   -49,   -49,    96,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,     2,    72,   -49,   -49,   -49,    64,   -22,
      80,    -1,    69,   -49,   -49,    10,   -15,   -49,    93,    28,
      89,    77,    21,    67,    -1,    70,    21,    21,    21,    21,
     111,   -49,    52,   -49,   -49,   -49,    -1,    10,    10,   -49,
     -49,   -49,   -49,   -49,   -49,    21,    -1,    10,    21,   110,
     112,   114,   -49,   -49,    72,    72,   -49,   -49,   -49,   -49,
     -49,   -49,   115,    39,   -49,   -49,    76,    85,    30,    -2,
     -49,    21,   -49,   -22,    -1,   -49,   -49,   -49,    21,   -49,
     -49,    90,    -5,   -49,    21,    62,    -1,    91,   -49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   -49,    86,    24,   -49,   -14,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,    25,    -9,   -23,   -49,   -11,
      42,   -48,   -49,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      42,    50,    48,    48,    80,    49,     1,    11,    66,    55,
      86,    87,    56,    57,     4,    56,    57,    12,    11,    56,
      57,    13,    65,     3,    14,    15,     8,    63,    12,    11,
      38,    67,    68,    43,    48,    44,   114,    16,   108,    12,
      82,    17,    18,    19,    94,    95,    39,    20,    21,    22,
      23,    41,    93,    80,    76,    45,    48,    48,    20,    21,
      22,    23,    97,   104,    96,   107,    48,    99,    98,    20,
      21,    22,    23,   105,    67,    68,    67,    68,    64,    56,
      57,    89,    90,    91,     5,     6,    56,    57,   116,    51,
     111,    58,    59,    56,    57,    40,    52,   112,    84,    85,
      53,    54,   117,   115,    69,    70,    71,    72,    73,    74,
      56,    57,    60,    62,    77,    81,    78,    88,    83,   100,
     103,   106,   101,   102,   113,    61,   109,   110,   118
};

static const yytype_uint8 yycheck[] =
{
      11,    15,    13,    14,    52,    14,    48,     8,    23,     7,
      58,    59,    17,    18,     0,    17,    18,    18,     8,    17,
      18,    22,    45,     4,    25,    26,    48,    41,    18,     8,
      21,    46,    47,    49,    45,    51,    41,    38,    40,    18,
      54,    42,    43,    44,    67,    68,    10,    48,    49,    50,
      51,    28,    66,   101,    26,    45,    67,    68,    48,    49,
      50,    51,    76,    24,    75,    35,    77,    78,    77,    48,
      49,    50,    51,    34,    46,    47,    46,    47,     9,    17,
      18,    29,    30,    31,    27,    28,    17,    18,    26,    48,
     104,    19,    20,    17,    18,    32,     8,   108,    56,    57,
       8,     5,   116,   114,    11,    12,    13,    14,    15,    16,
      17,    18,    48,    33,    25,    48,    39,     6,    48,     9,
       5,    36,    10,     9,    34,    39,   101,   103,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    53,     4,     0,    27,    28,    54,    48,    55,
      56,     8,    18,    22,    25,    26,    38,    42,    43,    44,
      48,    49,    50,    51,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    71,    72,    73,    74,    75,    21,    10,
      32,    28,    71,    49,    51,    45,    68,    69,    71,    68,
      58,    48,     8,     8,     5,     7,    17,    18,    19,    20,
      48,    55,    33,    58,     9,    69,    23,    46,    47,    11,
      12,    13,    14,    15,    16,    70,    26,    25,    39,    67,
      73,    48,    58,    48,    72,    72,    73,    73,     6,    29,
      30,    31,    57,    58,    69,    69,    71,    58,    68,    71,
       9,    10,     9,     5,    24,    34,    36,    35,    40,    67,
      56,    58,    71,    34,    41,    71,    26,    58,    37
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 115 "spl.y"
    { TERNARY_TREE ParseTree;
                  ParseTree = create_node((yyvsp[(1) - (6)].iVal), PROGRAM, (yyvsp[(3) - (6)].tVal), NULL, NULL, NULL);
				  #ifdef DEBUG
					PrintTree(ParseTree, 0);
				  #else 
					WriteCode(ParseTree);
			      #endif
            ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 126 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[(2) - (4)].tVal), (yyvsp[(4) - (4)].tVal), NULL, NULL);
				;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 130 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, BLOCK, (yyvsp[(2) - (2)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 136 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), DECLARATION, NULL, NULL, NULL, NULL);
					;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 140 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(1) - (3)].iVal), DECLARATION_LIST, (yyvsp[(3) - (3)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 147 "spl.y"
    { 
							(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[(1) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
						;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 151 "spl.y"
    { 
							(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK, (yyvsp[(1) - (6)].tVal), (yyvsp[(4) - (6)].tVal), (yyvsp[(6) - (6)].tVal), NULL);
						;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 158 "spl.y"
    { 
				(yyval.tVal) = create_node(SPL_CHARACTER, TYPE, NULL, NULL, NULL, NULL);
			;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 162 "spl.y"
    { 
				(yyval.tVal) = create_node(SPL_INTEGER, TYPE, NULL, NULL, NULL, NULL);
			;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 166 "spl.y"
    { 
				(yyval.tVal) = create_node(SPL_REAL, TYPE, NULL, NULL, NULL, NULL);
			;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 172 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
        		 ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 176 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
        		  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 182 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_ASSIGNMENT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 186 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_IF, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 190 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_DO, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 194 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_WHILE, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 198 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_FOR, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 202 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_WRITE, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 206 "spl.y"
    { 
					(yyval.tVal) = create_node(NOTHING, STATEMENT_READ, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
				;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 212 "spl.y"
    { 
	                  (yyval.tVal) = create_node((yyvsp[(3) - (3)].iVal), ASSIGNMENT_STATEMENT, (yyvsp[(1) - (3)].tVal), NULL, NULL, NULL);
	            	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 218 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[(2) - (7)].tVal), (yyvsp[(4) - (7)].tVal), (yyvsp[(6) - (7)].tVal), NULL);
					;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 222 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, IF_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
					;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 228 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
					;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 234 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
					;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 241 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(2) - (11)].iVal), FOR_STATEMENT, (yyvsp[(4) - (11)].tVal), (yyvsp[(6) - (11)].tVal), (yyvsp[(8) - (11)].tVal), (yyvsp[(10) - (11)].tVal));
					;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 247 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT, (yyvsp[(3) - (4)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 251 "spl.y"
    { 
						(yyval.tVal) = create_node(SPL_NEWLINE, NEWLINE_STATEMENT, NULL, NULL, NULL, NULL);
					;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 257 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(3) - (4)].iVal), READ_STATEMENT, NULL, NULL, NULL, NULL);
					;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 263 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
					;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 268 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_ALT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 274 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, CONDITIONAL_AND, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
					;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 278 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, CONDITIONAL_OR, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
					;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 282 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, CONDITIONAL, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 288 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, CONDITION, (yyvsp[(1) - (3)].tVal), (yyvsp[(2) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 293 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, NOT_CONDITION, (yyvsp[(2) - (2)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 299 "spl.y"
    { 
						(yyval.tVal) = create_node(EQUALS, COMPARATOR_EQUALS, NULL, NULL, NULL, NULL);
					;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 303 "spl.y"
    { 
						(yyval.tVal) = create_node(NOT_EQUALS, COMPARATOR_NOT_EQUALS, NULL, NULL, NULL, NULL);
					;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 307 "spl.y"
    { 
						(yyval.tVal) = create_node(LESS_THAN, COMPARATOR_LESS_THAN, NULL, NULL, NULL, NULL);
					;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 311 "spl.y"
    { 
						(yyval.tVal) = create_node(GREATER_THAN, COMPARATOR_GREATER_THAN, NULL, NULL, NULL, NULL);
					;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 315 "spl.y"
    { 
						(yyval.tVal) = create_node(LESS_THAN_OR_EQUAL, COMPARATOR_LESS_THAN_OR_EQUAL, NULL, NULL, NULL, NULL);
					;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 319 "spl.y"
    { 
						(yyval.tVal) = create_node(GREATER_THAN_OR_EQUAL, COMPARATOR_GREATER_THAN_OR_EQUAL, NULL, NULL, NULL, NULL);
					;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 325 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, EXPRESSION_PLUS, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
					;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 329 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, EXPRESSION_MINUS, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
					;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 333 "spl.y"
    { 
						(yyval.tVal) = create_node(NOTHING, EXPRESSION, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
					;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 338 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, TERM_TIMES, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
			;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 342 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, TERM_DIVIDE, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
			;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 346 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, TERM, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
			;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 352 "spl.y"
    { 
				(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), IDENTIFIER_VALUE, NULL, NULL, NULL, NULL);
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 356 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, CONSTANT_VALUE, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
			;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 360 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, EXPRESSION_VALUE, (yyvsp[(2) - (3)].tVal), NULL, NULL, NULL);
			;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 366 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
			;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 370 "spl.y"
    { 
				(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), CHAR_CONSTANT, NULL, NULL, NULL, NULL);
			;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 376 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), NUMBER_INT, NULL, NULL, NULL, NULL);
					;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 380 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), NUMBER_REAL, NULL, NULL, NULL, NULL);
					;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 384 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(2) - (2)].iVal), MINUS_NUMBER_INT, NULL, NULL, NULL, NULL);
					;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 388 "spl.y"
    { 
						(yyval.tVal) = create_node((yyvsp[(2) - (2)].iVal), MINUS_NUMBER_REAL, NULL, NULL, NULL, NULL);
					;}
    break;



/* Line 1455 of yacc.c  */
#line 2074 "spl.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 393 "spl.y"


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
			if (t->second != NULL) 
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
	
	
   
