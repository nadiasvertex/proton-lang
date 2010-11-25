/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CODE_BLOCK = 259,
     K_PTR = 260,
     K_REG = 261,
     K_LREG = 262,
     K_FREG = 263,
     K_IMM = 264,
     K_IMMZERO = 265,
     K_IMMS8 = 266,
     K_IMMU8 = 267,
     K_IMMS16 = 268,
     K_IMMU16 = 269,
     K_LOCAL = 270,
     K_SPILL_BEFORE = 271,
     K_BINARY = 272,
     K_UNARY = 273,
     K_UNARY_BRANCH = 274,
     K_BINARY_BRANCH = 275,
     K_UNARY_NOTE = 276,
     K_BINARY_NOTE = 277,
     K_TERNARY = 278,
     K_STACK = 279,
     K_ONLY = 280,
     K_MORE_SPACE = 281,
     K_MANUAL = 282,
     K_INST_TYPE = 283
   };
#endif
#define IDENTIFIER 258
#define CODE_BLOCK 259
#define K_PTR 260
#define K_REG 261
#define K_LREG 262
#define K_FREG 263
#define K_IMM 264
#define K_IMMZERO 265
#define K_IMMS8 266
#define K_IMMU8 267
#define K_IMMS16 268
#define K_IMMU16 269
#define K_LOCAL 270
#define K_SPILL_BEFORE 271
#define K_BINARY 272
#define K_UNARY 273
#define K_UNARY_BRANCH 274
#define K_BINARY_BRANCH 275
#define K_UNARY_NOTE 276
#define K_BINARY_NOTE 277
#define K_TERNARY 278
#define K_STACK 279
#define K_ONLY 280
#define K_MORE_SPACE 281
#define K_MANUAL 282
#define K_INST_TYPE 283




/* Copy the first part of user declarations.  */
#line 1 "gen-sel-parser.y"

/*
 * gen-sel-parser.y - Bison grammar for the "gen-sel" program.
 *
 * Copyright (C) 2004  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <config.h>
#include <stdio.h>
#ifdef HAVE_STRING_H
	#include <string.h>
#elif defined(HAVE_STRINGS_H)
	#include <strings.h>
#endif
#ifdef HAVE_STDLIB_H
	#include <stdlib.h>
#endif

/*
 * Imports from the lexical analyser.
 */
extern int yylex(void);
extern void yyrestart(FILE *file);
#ifdef YYTEXT_POINTER
extern char *yytext;
#else
extern char yytext[];
#endif

/*
 * Report error messages from the parser.
 */
static void yyerror(char *msg)
{
	puts(msg);
}

/*
 * Current file and line number.
 */
extern char *gensel_filename;
extern long gensel_linenum;

/*
 * Instruction type for the "inst" variable.
 */
static char *gensel_inst_type = "unsigned char *";
static int gensel_new_inst_type = 0;

/*
 * Amount of space to reserve for the primary instruction output.
 */
static int gensel_reserve_space = 32;
static int gensel_reserve_more_space = 128;

/*
 * First register in a stack arrangement.
 */
static int gensel_first_stack_reg = 8;	/* st0 under x86 */

/*
 * Option values.
 */
#define	GENSEL_OPT_SPILL_BEFORE			0x0001
#define	GENSEL_OPT_BINARY				0x0002
#define	GENSEL_OPT_UNARY				0x0004
#define	GENSEL_OPT_TERNARY				0x0008
#define	GENSEL_OPT_STACK				0x0010
#define	GENSEL_OPT_UNARY_BRANCH			0x0020
#define	GENSEL_OPT_BINARY_BRANCH		0x0040
#define	GENSEL_OPT_ONLY					0x0080
#define	GENSEL_OPT_MANUAL				0x0100
#define	GENSEL_OPT_UNARY_NOTE			0x0200
#define	GENSEL_OPT_BINARY_NOTE			0x0400
#define	GENSEL_OPT_MORE_SPACE			0x0800

/*
 * Pattern values.
 */
#define	GENSEL_PATT_END					0
#define	GENSEL_PATT_REG					1
#define	GENSEL_PATT_LREG				2
#define	GENSEL_PATT_FREG				3
#define	GENSEL_PATT_IMM					4
#define	GENSEL_PATT_IMMZERO				5
#define	GENSEL_PATT_IMMS8				6
#define	GENSEL_PATT_IMMU8				7
#define	GENSEL_PATT_IMMS16				8
#define	GENSEL_PATT_IMMU16				9
#define	GENSEL_PATT_LOCAL				10

/*
 * Information about clauses.
 */
typedef struct gensel_clause *gensel_clause_t;
struct gensel_clause
{
	int				pattern[8];
	char		   *filename;
	long			linenum;
	char		   *code;
	gensel_clause_t	next;
};

/*
 * Free a list of clauses.
 */
static void gensel_free_clauses(gensel_clause_t clauses)
{
	gensel_clause_t next;
	while(clauses != 0)
	{
		next = clauses->next;
		free(clauses->code);
		free(clauses);
		clauses = next;
	}
}

/*
 * Declare the register variables that are needed for a set of clauses.
 */
static void gensel_declare_regs(gensel_clause_t clauses, int options)
{
	int have_reg1 = 0;
	int have_reg2 = 0;
	int have_reg3 = 0;
	int have_imm = 0;
	int have_local = 0;
	int index;
	while(clauses != 0)
	{
		for(index = 0; clauses->pattern[index] != GENSEL_PATT_END; ++index)
		{
			switch(clauses->pattern[index])
			{
				case GENSEL_PATT_REG:
				case GENSEL_PATT_LREG:
				case GENSEL_PATT_FREG:
				{
					if(index == 0)
						have_reg1 = 1;
					else if(index == 1)
						have_reg2 = 1;
					else
						have_reg3 = 1;
				}
				break;

				case GENSEL_PATT_IMMZERO: break;

				case GENSEL_PATT_IMM:
				case GENSEL_PATT_IMMS8:
				case GENSEL_PATT_IMMU8:
				case GENSEL_PATT_IMMS16:
				case GENSEL_PATT_IMMU16:
				{
					have_imm = 1;
				}
				break;

				case GENSEL_PATT_LOCAL:
				{
					have_local = 1;
				}
				break;
			}
		}
		clauses = clauses->next;
	}
	if(have_reg1)
	{
		printf("\tint reg;\n");
	}
	if(have_reg2 && (options & GENSEL_OPT_STACK) == 0)
	{
		printf("\tint reg2;\n");
	}
	if(have_reg3 && (options & GENSEL_OPT_STACK) == 0)
	{
		printf("\tint reg3;\n");
	}
	if(have_imm)
	{
		printf("\tjit_nint imm_value;\n");
	}
	if(have_local)
	{
		printf("\tjit_nint local_offset;\n");
	}
}

/*
 * Output the code within a clause.
 */
static void gensel_output_clause_code(gensel_clause_t clause)
{
	char *code;
	int index;

	/* Output the line number information from the original file */
	printf("#line %ld \"%s\"\n", clause->linenum, clause->filename);

	/* Output the clause code */
	printf("\t\t");
	code = clause->code;
	while(*code != '\0')
	{
		if(*code == '$' && code[1] >= '1' && code[1] <= '9')
		{
			index = code[1] - '1';
			switch(clause->pattern[index])
			{
				case GENSEL_PATT_REG:
				case GENSEL_PATT_LREG:
				case GENSEL_PATT_FREG:
				{
					if(index == 0)
						printf("_jit_reg_info[reg].cpu_reg");
					else if(index == 1)
						printf("_jit_reg_info[reg2].cpu_reg");
					else
						printf("_jit_reg_info[reg3].cpu_reg");
				}
				break;

				case GENSEL_PATT_IMM:
				case GENSEL_PATT_IMMZERO:
				case GENSEL_PATT_IMMS8:
				case GENSEL_PATT_IMMU8:
				case GENSEL_PATT_IMMS16:
				case GENSEL_PATT_IMMU16:
				{
					printf("imm_value");
				}
				break;

				case GENSEL_PATT_LOCAL:
				{
					printf("local_offset");
				}
				break;
			}
			code += 2;
		}
		else if(*code == '%' && code[1] >= '1' && code[1] <= '9')
		{
			index = code[1] - '1';
			switch(clause->pattern[index])
			{
				case GENSEL_PATT_REG:
				case GENSEL_PATT_LREG:
				case GENSEL_PATT_FREG:
				{
					if(index == 0)
						printf("_jit_reg_info[_jit_reg_info[reg].other_reg].cpu_reg");
					else if(index == 1)
						printf("_jit_reg_info[_jit_reg_info[reg2].other_reg].cpu_reg");
					else
						printf("_jit_reg_info[_jit_reg_info[reg3].other_reg].cpu_reg");
				}
				break;
			}
			code += 2;
		}
		else if(*code == '\n')
		{
			putc(*code, stdout);
			putc('\t', stdout);
			++code;
		}
		else
		{
			putc(*code, stdout);
			++code;
		}
	}
	printf("\n");
}

/*
 * Output a single clause for a rule.
 */
static void gensel_output_clause(gensel_clause_t clause, int options)
{
	/* Cache the instruction pointer into "inst" */
	if(gensel_new_inst_type)
	{
		printf("\t\tjit_gen_load_inst_ptr(gen, inst);\n");
	}
	else
	{
		printf("\t\tinst = (%s)(gen->posn.ptr);\n", gensel_inst_type);
		printf("\t\tif(!jit_cache_check_for_n(&(gen->posn), %d))\n",
			   (((options & GENSEL_OPT_MORE_SPACE) == 0)
			   		? gensel_reserve_space : gensel_reserve_more_space));
		printf("\t\t{\n");
		printf("\t\t\tjit_cache_mark_full(&(gen->posn));\n");
		printf("\t\t\treturn;\n");
		printf("\t\t}\n");
	}

	/* Output the clause code */
	gensel_output_clause_code(clause);

	/* Copy "inst" back into the generation context */
	if(gensel_new_inst_type)
	{
		printf("\t\tjit_gen_save_inst_ptr(gen, inst);\n");
	}
	else
	{
		printf("\t\tgen->posn.ptr = (unsigned char *)inst;\n");
	}
}

/*
 * Output the clauses for a rule.
 */
static void gensel_output_clauses(gensel_clause_t clauses, int options)
{
	const char *arg1;
	const char *arg2;
	const char *arg3;
	const char *arg;
	const char *reg;
	const char *flag1;
	const char *flag2;
	const char *flag3;
	const char *flag;
	int destroy1;
	int destroy2;
	int destroy3;
	int destroy;
	gensel_clause_t clause;
	int first, index;
	int check_index;

	/* If the clause is manual, then output it as-is */
	if((options & GENSEL_OPT_MANUAL) != 0)
	{
		gensel_output_clause_code(clauses);
		return;
	}

	/* Determine the location of this instruction's arguments */
	if((options & GENSEL_OPT_TERNARY) != 0)
	{
		arg1 = "insn->dest";
		arg2 = "insn->value1";
		arg3 = "insn->value2";
		flag1 = "DEST";
		flag2 = "VALUE1";
		flag3 = "VALUE2";
		destroy1 = 0;
		destroy2 = 0;
		destroy3 = 0;
	}
	else
	{
		arg1 = "insn->value1";
		arg2 = "insn->value2";
		arg3 = "??";
		flag1 = "VALUE1";
		flag2 = "VALUE2";
		flag3 = "??";
		if((options & (GENSEL_OPT_BINARY_BRANCH |
					   GENSEL_OPT_UNARY_BRANCH |
					   GENSEL_OPT_BINARY_NOTE |
					   GENSEL_OPT_UNARY_NOTE)) != 0)
		{
			destroy1 = 0;
		}
		else
		{
			destroy1 = 1;
		}
		destroy2 = 0;
		destroy3 = 0;
	}

	/* If all of the clauses start with a register, then load the first
	   value into a register before we start checking cases */
	check_index = 0;
	if((options & (GENSEL_OPT_BINARY | GENSEL_OPT_UNARY |
				   GENSEL_OPT_BINARY_BRANCH | GENSEL_OPT_UNARY_BRANCH |
				   GENSEL_OPT_BINARY_NOTE | GENSEL_OPT_UNARY_NOTE)) != 0 &&
	   (options & GENSEL_OPT_STACK) == 0)
	{
		clause = clauses;
		while(clause != 0)
		{
			if(clause->pattern[0] != GENSEL_PATT_REG &&
			   clause->pattern[0] != GENSEL_PATT_LREG &&
			   clause->pattern[0] != GENSEL_PATT_FREG)
			{
				break;
			}
			clause = clause->next;
		}
		if(!clause)
		{
			printf("\treg = _jit_regs_load_value(gen, %s, %d, ",
				   arg1, destroy1);
			printf("(insn->flags & (JIT_INSN_%s_NEXT_USE | "
								   "JIT_INSN_%s_LIVE)));\n", flag1, flag1);
			check_index = 1;
		}
	}

	/* Output the clause checking and dispatching code */
	clause = clauses;
	first = 1;
	while(clause != 0)
	{
		if(clause->next)
		{
			if(first)
				printf("\tif(");
			else
				printf("\telse if(");
			for(index = check_index; clause->pattern[index]; ++index)
			{
				if(index == 0)
					arg = arg1;
				else if(index == 1)
					arg = arg2;
				else
					arg = arg3;
				switch(clause->pattern[index])
				{
					case GENSEL_PATT_REG:
					case GENSEL_PATT_LREG:
					case GENSEL_PATT_FREG:
					{
						printf("%s->in_register", arg);
					}
					break;

					case GENSEL_PATT_IMM:
					{
						printf("%s->is_constant", arg);
					}
					break;

					case GENSEL_PATT_IMMZERO:
					{
						printf("%s->is_nint_constant && ", arg);
						printf("%s->address == 0", arg);
					}
					break;

					case GENSEL_PATT_IMMS8:
					{
						printf("%s->is_nint_constant && ", arg);
						printf("%s->address >= -128 && ", arg);
						printf("%s->address <= 127", arg);
					}
					break;

					case GENSEL_PATT_IMMU8:
					{
						printf("%s->is_nint_constant && ", arg);
						printf("%s->address >= 0 && ", arg);
						printf("%s->address <= 255", arg);
					}
					break;

					case GENSEL_PATT_IMMS16:
					{
						printf("%s->is_nint_constant && ", arg);
						printf("%s->address >= -32768 && ", arg);
						printf("%s->address <= 32767", arg);
					}
					break;

					case GENSEL_PATT_IMMU16:
					{
						printf("%s->is_nint_constant && ", arg);
						printf("%s->address >= 0 && ", arg);
						printf("%s->address <= 65535", arg);
					}
					break;

					case GENSEL_PATT_LOCAL:
					{
						printf("%s->in_frame && !(%s->in_register)", arg, arg);
					}
					break;
				}
				if(clause->pattern[index + 1])
				{
					printf(" && ");
				}
			}
			printf(")\n\t{\n");
		}
		else if(first)
		{
			printf("\t{\n");
		}
		else
		{
			printf("\telse\n\t{\n");
		}
		if((options & GENSEL_OPT_STACK) == 0 || clause->next)
		{
			for(index = check_index; clause->pattern[index]; ++index)
			{
				if(index == 0)
				{
					arg = arg1;
					reg = "reg";
					flag = flag1;
					destroy = destroy1;
				}
				else if(index == 1)
				{
					arg = arg2;
					reg = "reg2";
					flag = flag2;
					destroy = destroy2;
				}
				else
				{
					arg = arg3;
					reg = "reg3";
					flag = flag3;
					destroy = destroy3;
				}
				switch(clause->pattern[index])
				{
					case GENSEL_PATT_REG:
					case GENSEL_PATT_LREG:
					case GENSEL_PATT_FREG:
					{
						printf("\t\t%s = _jit_regs_load_value(gen, %s, %d, ",
							   reg, arg, destroy);
						printf("(insn->flags & (JIT_INSN_%s_NEXT_USE | "
											   "JIT_INSN_%s_LIVE)));\n",
							   flag, flag);
					}
					break;
	
					case GENSEL_PATT_IMMZERO: break;

					case GENSEL_PATT_IMM:
					case GENSEL_PATT_IMMS8:
					case GENSEL_PATT_IMMU8:
					case GENSEL_PATT_IMMS16:
					case GENSEL_PATT_IMMU16:
					{
						printf("\t\timm_value = %s->address;\n", arg);
					}
					break;
	
					case GENSEL_PATT_LOCAL:
					{
						printf("\t\tlocal_offset = %s->frame_offset;\n", arg);
					}
					break;
				}
			}
		}
		else
		{
			if((options & GENSEL_OPT_ONLY) != 0)
			{
				printf("\t\tif(!_jit_regs_is_top(gen, insn->value1) ||\n");
				printf("\t\t   _jit_regs_num_used(gen, %d) != 1)\n",
					   gensel_first_stack_reg);
				printf("\t\t{\n");
				printf("\t\t\t_jit_regs_spill_all(gen);\n");
				printf("\t\t}\n");
			}
			if((options & GENSEL_OPT_TERNARY) != 0)
			{
				printf("\t\treg = _jit_regs_load_to_top_three\n");
				printf("\t\t\t(gen, insn->dest, insn->value1, insn->value2,\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_DEST_NEXT_USE | "
											   "JIT_INSN_DEST_LIVE)),\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_VALUE1_NEXT_USE | "
											   "JIT_INSN_VALUE1_LIVE)),\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_VALUE2_NEXT_USE | "
											   "JIT_INSN_VALUE2_LIVE)), "
											   "%d);\n",
					   gensel_first_stack_reg);
			}
			else if((options & (GENSEL_OPT_BINARY |
								GENSEL_OPT_BINARY_BRANCH)) != 0)
			{
				printf("\t\treg = _jit_regs_load_to_top_two\n");
				printf("\t\t\t(gen, insn->value1, insn->value2,\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_VALUE1_NEXT_USE | "
											   "JIT_INSN_VALUE1_LIVE)),\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_VALUE2_NEXT_USE | "
											   "JIT_INSN_VALUE2_LIVE)), "
											   "%d);\n",
					   gensel_first_stack_reg);
			}
			else if((options & (GENSEL_OPT_UNARY |
								GENSEL_OPT_UNARY_BRANCH |
								GENSEL_OPT_UNARY_NOTE)) != 0)
			{
				printf("\t\treg = _jit_regs_load_to_top\n");
				printf("\t\t\t(gen, insn->value1,\n");
				printf("\t\t\t\t(insn->flags & (JIT_INSN_VALUE1_NEXT_USE | "
											   "JIT_INSN_VALUE1_LIVE)), "
											   "%d);\n",
					   gensel_first_stack_reg);
			}
		}
		if((options & (GENSEL_OPT_BINARY_BRANCH |
					   GENSEL_OPT_UNARY_BRANCH)) != 0)
		{
			/* Spill all other registers back to their original positions */
			printf("\t\t_jit_regs_spill_all(gen);\n");
		}
		gensel_output_clause(clause, options);
		printf("\t}\n");
		first = 0;
		clause = clause->next;
	}
}

/*
 * List of opcodes that are supported by the input rules.
 */
static char **supported = 0;
static char **supported_options = 0;
static int num_supported = 0;

/*
 * Add an opcode to the supported list.
 */
static void gensel_add_supported(char *name, char *option)
{
	supported = (char **)realloc
		(supported, (num_supported + 1) * sizeof(char *));
	if(!supported)
	{
		exit(1);
	}
	supported[num_supported] = name;
	supported_options = (char **)realloc
		(supported_options, (num_supported + 1) * sizeof(char *));
	if(!supported_options)
	{
		exit(1);
	}
	supported_options[num_supported++] = option;
}

/*
 * Output the list of supported opcodes.
 */
static void gensel_output_supported(void)
{
	int index;
	for(index = 0; index < num_supported; ++index)
	{
		if(supported_options[index])
		{
			if(supported_options[index][0] == '!')
			{
				printf("#ifndef %s\n", supported_options[index] + 1);
			}
			else
			{
				printf("#ifdef %s\n", supported_options[index]);
			}
			printf("case %s:\n", supported[index]);
			printf("#endif\n");
		}
		else
		{
			printf("case %s:\n", supported[index]);
		}
	}
	printf("\treturn 1;\n\n");
}



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 702 "gen-sel-parser.y"
typedef union YYSTYPE {
	char		   *name;
	struct
	{
		char	   *filename;
		long		linenum;
		char	   *block;
	}				code;
	int				options;
	struct
	{
		int			elem[8];
		int			size;

	}				pattern;
	struct
	{
		struct gensel_clause *head;
		struct gensel_clause *tail;

	}				clauses;
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 852 "gen-sel-parser.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 864 "gen-sel-parser.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if YYSTACK_USE_ALLOCA
#  define YYSTACK_ALLOC alloca
# else
#  ifndef YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC malloc
#  define YYSTACK_FREE free
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   41

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  14
/* YYNRULES -- Number of rules. */
#define YYNRULES  44
/* YYNRULES -- Number of states. */
#define YYNSTATES  56

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    29,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned char yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    17,    20,    22,
      26,    27,    31,    32,    34,    36,    40,    42,    44,    46,
      48,    50,    52,    54,    56,    58,    60,    62,    64,    66,
      69,    75,    76,    78,    80,    84,    86,    88,    90,    92,
      94,    96,    98,   100,   102
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      36,     0,    -1,    -1,    37,    -1,    38,    -1,    37,    38,
      -1,    39,    40,    29,    41,    44,    -1,    28,     3,    -1,
       3,    -1,    39,    30,     3,    -1,    -1,    31,     3,    32,
      -1,    -1,    42,    -1,    43,    -1,    42,    30,    43,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    27,    -1,    45,    -1,    44,    45,    -1,    33,
      46,    34,     5,     4,    -1,    -1,    47,    -1,    48,    -1,
      47,    30,    48,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   769,   769,   771,   775,   776,   780,   836,   843,   844,
     860,   861,   865,   866,   870,   871,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   890,   891,
     899,   921,   925,   929,   934,   942,   943,   944,   945,   946,
     947,   948,   949,   950,   951
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"an identifier\"", "\"a code block\"", 
  "\"`->'\"", "\"word register\"", "\"long register\"", 
  "\"float register\"", "\"immediate value\"", "\"immediate zero value\"", 
  "\"immediate signed 8-bit value\"", 
  "\"immediate unsigned 8-bit value\"", 
  "\"immediate signed 16-bit value\"", 
  "\"immediate unsigned 16-bit value\"", "\"local variable\"", 
  "\"`spill_before'\"", "\"`binary'\"", "\"`unary'\"", 
  "\"`unary_branch'\"", "\"`binary_branch'\"", "\"`unary_note'\"", 
  "\"`binary_note'\"", "\"`ternary'\"", "\"`stack'\"", "\"`only'\"", 
  "\"`more_space'\"", "\"`manual'\"", "\"`%inst_type'\"", "':'", "','", 
  "'('", "')'", "'['", "']'", "$accept", "Start", "Rules", "Rule", 
  "IdentifierList", "IfClause", "Options", "OptionList", "Option", 
  "Clauses", "Clause", "Pattern", "Pattern2", "PatternElement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    58,
      44,    40,    41,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    40,    41,    41,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     1,     1,     2,     5,     2,     1,     3,
       0,     3,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       2,     8,     0,     0,     3,     4,    10,     7,     1,     5,
       0,     0,     0,     9,     0,    12,    11,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      13,    14,    31,     6,    28,     0,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    32,    33,    29,
      15,     0,     0,     0,    34,    30
};

/* YYDEFGOTO[NTERM-NUM]. */
static const yysigned_char yydefgoto[] =
{
      -1,     3,     4,     5,     6,    12,    29,    30,    31,    33,
      34,    46,    47,    48
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -16
static const yysigned_char yypact[] =
{
      -3,   -16,    23,    27,    -3,   -16,    -7,   -16,   -16,   -16,
      25,    26,     1,   -16,    -1,   -15,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,     0,
       2,   -16,     7,     0,   -16,   -15,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,     3,     4,   -16,   -16,
     -16,    30,     7,    32,   -16,   -16
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -16,   -16,   -16,    34,   -16,   -16,   -16,   -16,     5,   -16,
       6,   -16,   -16,   -11
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
       1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    10,    11,     2,     7,     8,    13,    14,
      15,    16,    35,    32,    52,    53,    55,    51,     9,    49,
      50,    54
};

static const unsigned char yycheck[] =
{
       3,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    30,    31,    28,     3,     0,     3,     3,
      29,    32,    30,    33,    30,     5,     4,    34,     4,    33,
      35,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,     3,    28,    36,    37,    38,    39,     3,     0,    38,
      30,    31,    40,     3,     3,    29,    32,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    41,
      42,    43,    33,    44,    45,    30,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    46,    47,    48,    45,
      43,    34,    30,     5,    48,     4
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrlab1

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylineno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 6:
#line 780 "gen-sel-parser.y"
    {
				if(yyvsp[-3].name)
				{
					if((yyvsp[-3].name)[0] == '!')
					{
						printf("#ifndef %s\n\n", yyvsp[-3].name + 1);
					}
					else
					{
						printf("#ifdef %s\n\n", yyvsp[-3].name);
					}
				}
				printf("case %s:\n{\n", yyvsp[-4].name);
				if((yyvsp[-1].options & GENSEL_OPT_MANUAL) == 0)
				{
					printf("\t%s inst;\n", gensel_inst_type);
				}
				gensel_declare_regs(yyvsp[0].clauses.head, yyvsp[-1].options);
				if((yyvsp[-1].options & GENSEL_OPT_SPILL_BEFORE) != 0)
				{
					printf("\t_jit_regs_spill_all(gen);\n");
				}
				gensel_output_clauses(yyvsp[0].clauses.head, yyvsp[-1].options);
				if((yyvsp[-1].options & (GENSEL_OPT_BINARY | GENSEL_OPT_UNARY)) != 0)
				{
					printf("\tif((insn->flags & JIT_INSN_DEST_NEXT_USE) != 0)\n");
					printf("\t{\n");
					printf("\t\t_jit_regs_set_value(gen, reg, insn->dest, 0);\n");
					printf("\t}\n");
					printf("\telse\n");
					printf("\t{\n");
					printf("\t\tint other_reg;\n");
					printf("\t\tif(gen->contents[reg].is_long_start)\n");
					printf("\t\t{\n");
					printf("\t\t\tother_reg = _jit_reg_info[reg].other_reg;\n");
					printf("\t\t}\n");
					printf("\t\telse\n");
					printf("\t\t{\n");
					printf("\t\t\tother_reg = -1;\n");
					printf("\t\t}\n");
					printf("\t\t_jit_gen_spill_reg(gen, reg, other_reg, insn->dest);\n");
					printf("\t\tif(insn->dest->has_global_register)\n");
					printf("\t\t\tinsn->dest->in_global_register = 1;\n");
					printf("\t\telse\n");
					printf("\t\t\tinsn->dest->in_frame = 1;\n");
					printf("\t\t_jit_regs_free_reg(gen, reg, 1);\n");
					printf("\t}\n");
				}
				printf("}\nbreak;\n\n");
				if(yyvsp[-3].name)
				{
					printf("#endif /* %s */\n\n", yyvsp[-3].name);
				}
				gensel_free_clauses(yyvsp[0].clauses.head);
				gensel_add_supported(yyvsp[-4].name, yyvsp[-3].name);
			}
    break;

  case 7:
#line 836 "gen-sel-parser.y"
    {
				gensel_inst_type = yyvsp[0].name;
				gensel_new_inst_type = 1;
			}
    break;

  case 8:
#line 843 "gen-sel-parser.y"
    { yyval.name = yyvsp[0].name; }
    break;

  case 9:
#line 844 "gen-sel-parser.y"
    {
				char *result = (char *)malloc(strlen(yyvsp[-2].name) + strlen(yyvsp[0].name) + 16);
				if(!result)
				{
					exit(1);
				}
				strcpy(result, yyvsp[-2].name);
				strcat(result, ":\ncase ");
				strcat(result, yyvsp[0].name);
				free(yyvsp[-2].name);
				free(yyvsp[0].name);
				yyval.name = result;
			}
    break;

  case 10:
#line 860 "gen-sel-parser.y"
    { yyval.name = 0; }
    break;

  case 11:
#line 861 "gen-sel-parser.y"
    { yyval.name = yyvsp[-1].name; }
    break;

  case 12:
#line 865 "gen-sel-parser.y"
    { yyval.options = 0; }
    break;

  case 13:
#line 866 "gen-sel-parser.y"
    { yyval.options = yyvsp[0].options; }
    break;

  case 14:
#line 870 "gen-sel-parser.y"
    { yyval.options = yyvsp[0].options; }
    break;

  case 15:
#line 871 "gen-sel-parser.y"
    { yyval.options = yyvsp[-2].options | yyvsp[0].options; }
    break;

  case 16:
#line 875 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_SPILL_BEFORE; }
    break;

  case 17:
#line 876 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_BINARY; }
    break;

  case 18:
#line 877 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_UNARY; }
    break;

  case 19:
#line 878 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_UNARY_BRANCH; }
    break;

  case 20:
#line 879 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_BINARY_BRANCH; }
    break;

  case 21:
#line 880 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_UNARY_NOTE; }
    break;

  case 22:
#line 881 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_BINARY_NOTE; }
    break;

  case 23:
#line 882 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_TERNARY; }
    break;

  case 24:
#line 883 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_STACK; }
    break;

  case 25:
#line 884 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_ONLY; }
    break;

  case 26:
#line 885 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_MORE_SPACE; }
    break;

  case 27:
#line 886 "gen-sel-parser.y"
    { yyval.options = GENSEL_OPT_MANUAL; }
    break;

  case 28:
#line 890 "gen-sel-parser.y"
    { yyval.clauses = yyvsp[0].clauses; }
    break;

  case 29:
#line 891 "gen-sel-parser.y"
    {
				yyvsp[-1].clauses.tail->next = yyvsp[0].clauses.head;
				yyval.clauses.head = yyvsp[-1].clauses.head;
				yyval.clauses.tail = yyvsp[0].clauses.tail;
			}
    break;

  case 30:
#line 899 "gen-sel-parser.y"
    {
				gensel_clause_t clause;
				int index;
				clause = (gensel_clause_t)malloc(sizeof(struct gensel_clause));
				if(!clause)
				{
					exit(1);
				}
				for(index = 0; index < 8; ++index)
				{
					clause->pattern[index] = yyvsp[-3].pattern.elem[index];
				}
				clause->filename = yyvsp[0].code.filename;
				clause->linenum = yyvsp[0].code.linenum;
				clause->code = yyvsp[0].code.block;
				clause->next = 0;
				yyval.clauses.head = clause;
				yyval.clauses.tail = clause;
			}
    break;

  case 31:
#line 921 "gen-sel-parser.y"
    {
				yyval.pattern.elem[0] = GENSEL_PATT_END;
				yyval.pattern.size = 0;
			}
    break;

  case 32:
#line 925 "gen-sel-parser.y"
    { yyval.pattern = yyvsp[0].pattern; }
    break;

  case 33:
#line 929 "gen-sel-parser.y"
    {
				yyval.pattern.elem[0] = yyvsp[0].options;
				yyval.pattern.elem[1] = GENSEL_PATT_END;
				yyval.pattern.size = 1;
			}
    break;

  case 34:
#line 934 "gen-sel-parser.y"
    {
				yyval.pattern.elem[yyvsp[-2].pattern.size] = yyvsp[0].options;
				yyval.pattern.elem[yyvsp[-2].pattern.size + 1] = GENSEL_PATT_END;
				yyval.pattern.size = yyvsp[-2].pattern.size + 1;
			}
    break;

  case 35:
#line 942 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_REG; }
    break;

  case 36:
#line 943 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_LREG; }
    break;

  case 37:
#line 944 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_FREG; }
    break;

  case 38:
#line 945 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMM; }
    break;

  case 39:
#line 946 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMMZERO; }
    break;

  case 40:
#line 947 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMMS8; }
    break;

  case 41:
#line 948 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMMU8; }
    break;

  case 42:
#line 949 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMMS16; }
    break;

  case 43:
#line 950 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_IMMU16; }
    break;

  case 44:
#line 951 "gen-sel-parser.y"
    { yyval.options = GENSEL_PATT_LOCAL; }
    break;


    }

/* Line 991 of yacc.c.  */
#line 2091 "gen-sel-parser.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  char *yymsg;
	  int yyx, yycount;

	  yycount = 0;
	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  for (yyx = yyn < 0 ? -yyn : 0;
	       yyx < (int) (sizeof (yytname) / sizeof (char *)); yyx++)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      yysize += yystrlen (yytname[yyx]) + 15, yycount++;
	  yysize += yystrlen ("syntax error, unexpected ") + 1;
	  yysize += yystrlen (yytname[yytype]);
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yycount = 0;
		  for (yyx = yyn < 0 ? -yyn : 0;
		       yyx < (int) (sizeof (yytname) / sizeof (char *));
		       yyx++)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			const char *yyq = ! yycount ? ", expecting " : " or ";
			yyp = yystpcpy (yyp, yyq);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yycount++;
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (yychar == YYEOF)
        {
	  /* Pop the error token.  */
          YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (yyss < yyssp)
	    {
	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
	      yydestruct (yystos[*yyssp], yyvsp);
	      YYPOPSTACK;
	    }
	  YYABORT;
        }

      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
      yydestruct (yytoken, &yylval);
      yychar = YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab2;


/*----------------------------------------------------.
| yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
yyerrlab1:

  /* Suppress GCC warning that yyerrlab1 is unused when no action
     invokes YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__) \
    && !defined __cplusplus
  __attribute__ ((__unused__))
#endif


  goto yyerrlab2;


/*---------------------------------------------------------------.
| yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
yyerrlab2:
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      yyvsp--;
      yystate = *--yyssp;

      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 954 "gen-sel-parser.y"


#define	COPYRIGHT_MSG	\
" * Copyright (C) 2004  Southern Storm Software, Pty Ltd.\n" \
" *\n" \
" * This program is free software; you can redistribute it and/or modify\n" \
" * it under the terms of the GNU General Public License as published by\n" \
" * the Free Software Foundation; either version 2 of the License, or\n" \
" * (at your option) any later version.\n" \
" *\n" \
" * This program is distributed in the hope that it will be useful,\n" \
" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
" * GNU General Public License for more details.\n" \
" *\n" \
" * You should have received a copy of the GNU General Public License\n" \
" * along with this program; if not, write to the Free Software\n" \
" * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA\n"
 
int main(int argc, char *argv[])
{
	FILE *file;
	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s input.sel >output.slc\n", argv[0]);
		return 1;
	}
	file = fopen(argv[1], "r");
	if(!file)
	{
		perror(argv[1]);
		return 1;
	}
	printf("/%c Automatically generated from %s - DO NOT EDIT %c/\n",
		   '*', argv[1], '*');
	printf("/%c\n%s%c/\n\n", '*', COPYRIGHT_MSG, '*');
	printf("#if defined(JIT_INCLUDE_RULES)\n\n");
	gensel_filename = argv[1];
	gensel_linenum = 1;
	yyrestart(file);
	if(yyparse())
	{
		fclose(file);
		return 1;
	}
	fclose(file);
	printf("#elif defined(JIT_INCLUDE_SUPPORTED)\n\n");
	gensel_output_supported();
	printf("#endif\n");
	return 0;
}

