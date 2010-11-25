
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
#line 1 "gen-rules-parser.y"

/*
 * gen-rules-parser.y - Bison grammar for the "gen-rules" program.
 *
 * Copyright (C) 2006  Southern Storm Software, Pty Ltd.
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
 * Current file and line number.
 */
extern char *gensel_filename;
extern long gensel_linenum;

/*
 * Report error message.
 */
static void
gensel_error_message(char *filename, long linenum, char *msg)
{
	fprintf(stderr, "%s(%ld): %s\n", filename, linenum, msg);
}

/*
 * Report error message and exit.
 */
static void
gensel_error(char *filename, long linenum, char *msg)
{
	gensel_error_message(filename, linenum, msg);
	exit(1);
}

/*
 * Report error messages from the parser.
 */
static void
yyerror(char *msg)
{
	gensel_error_message(gensel_filename, gensel_linenum, msg);
}

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
 * Maximal number of input values in a pattern.
 */
#define MAX_INPUT				3

/*
 * Maximal number of scratch registers in a pattern.
 */
#define MAX_SCRATCH				6

/*
 * Maximal number of pattern elements.
 */
#define MAX_PATTERN				(MAX_INPUT + MAX_SCRATCH)

/*
 * Rule Options.
 */
#define	GENSEL_OPT_TERNARY			1
#define GENSEL_OPT_BRANCH			2
#define GENSEL_OPT_NOTE				3
#define	GENSEL_OPT_COPY				4
#define GENSEL_OPT_COMMUTATIVE			5
#define	GENSEL_OPT_STACK			6
#define GENSEL_OPT_X87_ARITH			7
#define GENSEL_OPT_X87_ARITH_REVERSIBLE		8

#define	GENSEL_OPT_MANUAL			9
#define	GENSEL_OPT_MORE_SPACE			10

/*
 * Pattern values.
 */
#define GENSEL_PATT_ANY				1
#define	GENSEL_PATT_REG				2
#define	GENSEL_PATT_LREG			3
#define	GENSEL_PATT_IMM				4
#define	GENSEL_PATT_IMMZERO			5
#define	GENSEL_PATT_IMMS8			6
#define	GENSEL_PATT_IMMU8			7
#define	GENSEL_PATT_IMMS16			8
#define	GENSEL_PATT_IMMU16			9
#define	GENSEL_PATT_LOCAL			10
#define	GENSEL_PATT_FRAME			11
#define	GENSEL_PATT_SCRATCH			12
#define	GENSEL_PATT_CLOBBER			13
#define	GENSEL_PATT_IF				14
#define	GENSEL_PATT_SPACE			15

/*
 * Value types.
 */
#define GENSEL_VALUE_STRING			1
#define GENSEL_VALUE_REGCLASS			2
#define	GENSEL_VALUE_ALL			3
#define GENSEL_VALUE_CLOBBER			4
#define GENSEL_VALUE_EARLY_CLOBBER		5

/*
 * Register class.
 */
typedef struct gensel_regclass *gensel_regclass_t;
struct gensel_regclass
{
	char			*id;
	char			*def;
	int			is_long;
	gensel_regclass_t	next;
};

/*
 * Option value.
 */
typedef struct gensel_value *gensel_value_t;
struct gensel_value
{
	int			type;
	void			*value;
	gensel_value_t		next;
};

/*
 * Option information.
 */
typedef struct gensel_option *gensel_option_t;
struct gensel_option
{
	int			option;
	gensel_value_t		values;
	gensel_option_t		next;
};

/*
 * Information about clauses.
 */
typedef struct gensel_clause *gensel_clause_t;
struct gensel_clause
{
	int			dest;
	gensel_option_t		pattern;
	char			*filename;
	long			linenum;
	char			*code;
	gensel_clause_t		next;
};

static char *gensel_args[] = {
	"dest", "value1", "value2"
};
static char *gensel_imm_args[] = {
	"insn->dest->address", "insn->value1->address", "insn->value2->address"
};
static char *gensel_reg_names[] = {
	"reg", "reg2", "reg3", "reg4", "reg5", "reg6", "reg7", "reg8", "reg9"
};
static char *gensel_other_reg_names[] = {
	"other_reg", "other_reg2", "other_reg3"
};
static char *gensel_imm_names[] = {
	"imm_value", "imm_value2", "imm_value3"
};
static char *gensel_local_names[] = {
	"local_offset", "local_offset2", "local_offset3"
};

/*
 * Register classes.
 */
static gensel_regclass_t gensel_regclass_list;

/*
 * Create a register class.
 */
static void
gensel_create_regclass(char *id, char *def, int is_long)
{
	gensel_regclass_t rp;

	rp = (gensel_regclass_t) malloc(sizeof(struct gensel_regclass));
	if(!rp)
	{
		exit(1);
	}
	
	rp->id = id;
	rp->def = def;
	rp->is_long = is_long;
	rp->next = gensel_regclass_list;

	gensel_regclass_list = rp;
}

gensel_regclass_t
gensel_lookup_regclass(char *id)
{
	gensel_regclass_t rp;

	rp = gensel_regclass_list;
	for(;;)
	{
		if(!rp)
		{
			gensel_error(
				gensel_filename, gensel_linenum,
				"invalid register class");
		}
		if(strcmp(id, rp->id) == 0)
		{
			return rp;
		}
		rp = rp->next;
	}
}

/*
 * Create a value.
 */
static gensel_value_t
gensel_create_value(int type)
{
	gensel_value_t vp;

	vp = (gensel_value_t) malloc(sizeof(struct gensel_value));
	if(!vp)
	{
		exit(1);
	}

	vp->type = type;
	vp->value = 0;
	vp->next = 0;

	return vp;
}

/*
 * Create string value.
 */
static gensel_value_t
gensel_create_string_value(char *value)
{
	gensel_value_t vp;

	vp = gensel_create_value(GENSEL_VALUE_STRING);
	vp->value = value;

	return vp;
}

/*
 * Create string value.
 */
static gensel_value_t
gensel_create_regclass_value(char *value)
{
	gensel_value_t vp;

	vp = gensel_create_value(GENSEL_VALUE_REGCLASS);
	vp->value = gensel_lookup_regclass(value);

	return vp;
}

/*
 * Create an option.
 */
static gensel_option_t
gensel_create_option(int option, gensel_value_t values)
{
	gensel_option_t op;

	op = (gensel_option_t) malloc(sizeof(struct gensel_option));
	if(!op)
	{
		exit(1);
	}

	op->option = option;
	op->values = values;
	op->next = 0;
	return op;
}

/*
 * Create a register pattern element.
 */
static gensel_option_t
gensel_create_register(
	int flags,
	gensel_value_t value,
	gensel_value_t values)
{
	gensel_regclass_t regclass;

	if(flags)
	{
		value->next = gensel_create_value(flags);
		value->next->next = values;
	}
	else
	{
		value->next = values;
	}

	regclass = value->value;
	return gensel_create_option(
		regclass->is_long ? GENSEL_PATT_LREG : GENSEL_PATT_REG,
		value);
}

/*
 * Create a scratch register pattern element.
 */
static gensel_option_t
gensel_create_scratch(
	gensel_value_t regclass,
	gensel_value_t values)
{
	regclass->next = values;
	return gensel_create_option(GENSEL_PATT_SCRATCH, regclass);
}

/*
 * Free a list of values.
 */
static void
gensel_free_values(gensel_value_t values)
{
	gensel_value_t next;
	while(values)
	{
		next = values->next;
		if(values->type == GENSEL_VALUE_STRING)
		{
			free(values->value);
		}
		free(values);
		values = next;
	}
}

/*
 * Free a list of options.
 */
static void
gensel_free_options(gensel_option_t options)
{
	gensel_option_t next;
	while(options)
	{
		next = options->next;
		gensel_free_values(options->values);
		free(options);
		options = next;
	}
}

/*
 * Free a list of clauses.
 */
static void
gensel_free_clauses(gensel_clause_t clauses)
{
	gensel_clause_t next;
	while(clauses != 0)
	{
		next = clauses->next;
		gensel_free_options(clauses->pattern);
		free(clauses->code);
		free(clauses);
		clauses = next;
	}
}

/*
 * Look for the option.
 */
static gensel_option_t
gensel_search_option(gensel_option_t options, int tag)
{
	while(options && options->option != tag)
	{
		options = options->next;
	}
	return options;
}

/*
 * Declare the register variables that are needed for a set of clauses.
 */
static void
gensel_declare_regs(gensel_clause_t clauses, gensel_option_t options)
{
	gensel_option_t pattern;
	int regs, max_regs;
	int other_regs_mask;
	int imms, max_imms;
	int locals, max_locals;
	int scratch, others;

	max_regs = 0;
	other_regs_mask = 0;
	max_imms = 0;
	max_locals = 0;
	while(clauses != 0)
	{
		regs = 0;
		imms = 0;
		locals = 0;
		others = 0;
		scratch = 0;
		pattern = clauses->pattern;
		while(pattern)
		{
			switch(pattern->option)
			{
			case GENSEL_PATT_ANY:
				++others;
				break;

			case GENSEL_PATT_REG:
				++regs;
				break;

			case GENSEL_PATT_LREG:
				other_regs_mask |= (1 << regs);
				++regs;
				break;

			case GENSEL_PATT_IMMZERO:
				++others;
				break;

			case GENSEL_PATT_IMM:
			case GENSEL_PATT_IMMS8:
			case GENSEL_PATT_IMMU8:
			case GENSEL_PATT_IMMS16:
			case GENSEL_PATT_IMMU16:
				++imms;
				break;

			case GENSEL_PATT_LOCAL:
			case GENSEL_PATT_FRAME:
				++locals;
				break;

			case GENSEL_PATT_SCRATCH:
				++scratch;
			}
			pattern = pattern->next;
		}
		if((regs + imms + locals + others) > MAX_INPUT)
		{
			gensel_error(
				clauses->filename,
				clauses->linenum,
				"too many input args in the pattern");
		}
		if(scratch > MAX_SCRATCH)
		{
			gensel_error(
				clauses->filename,
				clauses->linenum,
				"too many scratch args in the pattern");
		}
		if(max_regs < (regs + scratch))
		{
			max_regs = regs + scratch;
		}
		if(max_imms < imms)
		{
			max_imms = imms;
		}
		if(max_locals < locals)
		{
			max_locals = locals;
		}
		clauses = clauses->next;
	}
	if(max_regs > 0)
	{
		printf("\tint reg");
		for(scratch = 1; scratch < max_regs; scratch++)
		{
			printf(", reg%d", scratch + 1);
		}
		printf(";\n");
	}
	if(other_regs_mask)
	{
		switch(other_regs_mask)
		{
		case 1:
			printf("\tint other_reg;\n");
			break;
		case 2:
			printf("\tint other_reg2;\n");
			break;
		case 3:
			printf("\tint other_reg, other_reg2;\n");
			break;
		case 4:
			printf("\tint other_reg3;\n");
			break;
		case 5:
			printf("\tint other_reg, other_reg3;\n");
			break;
		case 6:
			printf("\tint other_reg2, other_reg3;\n");
			break;
		case 7:
			printf("\tint other_reg, other_reg2, other_reg3;\n");
			break;
		}
	}
	switch(max_imms)
	{
	case 1:
		printf("\tjit_nint imm_value;\n");
		break;
	case 2:
		printf("\tjit_nint imm_value, imm_value2;\n");
		break;
	case 3:
		printf("\tjit_nint imm_value, imm_value2, imm_value3;\n");
		break;
	}
	switch(max_locals)
	{
	case 1:
		printf("\tjit_nint local_offset;\n");
		break;
	case 2:
		printf("\tjit_nint local_offset, local_offset2;\n");
		break;
	case 3:
		printf("\tjit_nint local_offset, local_offset2, local_offset3;\n");
		break;
	}
}

/*
 * Check if the pattern contains any registers.
 */
static int
gensel_contains_registers(gensel_option_t pattern)
{
	while(pattern)
	{
		switch(pattern->option)
		{
		case GENSEL_PATT_REG:
		case GENSEL_PATT_LREG:
		case GENSEL_PATT_SCRATCH:
		case GENSEL_PATT_CLOBBER:
			return 1;
		}
		pattern = pattern->next;
	}
	return 0;
}

/*
 * Returns first register in the pattern if any.
 */
static gensel_option_t
gensel_get_first_register(gensel_option_t pattern)
{
	while(pattern)
	{
		switch(pattern->option)
		{
		case GENSEL_PATT_REG:
		case GENSEL_PATT_LREG:
			return pattern;
		}
		pattern = pattern->next;
	}
	return 0;
}

static void
gensel_init_names(int count, char *names[], char *other_names[])
{
	int index;
	for(index = 0; index < count; index++)
	{
		if(names)
		{
			names[index] = "undefined";
		}
		if(other_names)
		{
			other_names[index] = "undefined";
		}
	}

}

static void
gensel_build_arg_index(
	gensel_option_t pattern,
	int count,
	char *names[],
	char *other_names[],
	int ternary,
	int free_dest)
{
	int index;

	gensel_init_names(count, names, other_names);

	index = 0;
	while(pattern)
	{
		switch(pattern->option)
		{
		case GENSEL_PATT_ANY:
			++index;
			break;

		case GENSEL_PATT_REG:
		case GENSEL_PATT_LREG:
		case GENSEL_PATT_LOCAL:
		case GENSEL_PATT_FRAME:
		case GENSEL_PATT_IMMZERO:
		case GENSEL_PATT_IMM:
		case GENSEL_PATT_IMMS8:
		case GENSEL_PATT_IMMU8:
		case GENSEL_PATT_IMMS16:
		case GENSEL_PATT_IMMU16:
			if(ternary || free_dest)
			{
				if(index < 3)
				{
					names[index] = gensel_args[index];
				}
			}
			else
			{
				if(index < 2)
				{
					names[index] = gensel_args[index + 1];
				}
			}
			++index;
			break;
		}
		pattern = pattern->next;
	}
}

static void
gensel_build_imm_arg_index(
	gensel_option_t pattern,
	int count,
	char *names[],
	char *other_names[],
	int ternary,
	int free_dest)
{
	int index;

	gensel_init_names(count, names, other_names);

	index = 0;
	while(pattern)
	{
		switch(pattern->option)
		{
		case GENSEL_PATT_ANY:
		case GENSEL_PATT_REG:
		case GENSEL_PATT_LREG:
		case GENSEL_PATT_LOCAL:
		case GENSEL_PATT_FRAME:
		case GENSEL_PATT_IMMZERO:
			++index;
			break;

		case GENSEL_PATT_IMM:
		case GENSEL_PATT_IMMS8:
		case GENSEL_PATT_IMMU8:
		case GENSEL_PATT_IMMS16:
		case GENSEL_PATT_IMMU16:
			if(ternary || free_dest)
			{
				if(index < 3)
				{
					names[index] = gensel_imm_args[index];
				}
			}
			else
			{
				if(index < 2)
				{
					names[index] = gensel_imm_args[index + 1];
				}
			}
			++index;
			break;
		}
		pattern = pattern->next;
	}
}

/*
 * Build index of input value names.
 */
static void
gensel_build_var_index(
	gensel_option_t pattern,
	char *names[MAX_PATTERN],
	char *other_names[MAX_PATTERN])
{
	int regs, imms, locals, index;

	gensel_init_names(MAX_PATTERN, names, other_names);

	regs = 0;
	imms = 0;
	locals = 0;
	index = 0;
	while(pattern)
	{
		switch(pattern->option)
		{
		case GENSEL_PATT_ANY:
			++index;
			break;

		case GENSEL_PATT_REG:
			names[index] = gensel_reg_names[regs];
			++regs;
			++index;
			break;

		case GENSEL_PATT_LREG:
			names[index] = gensel_reg_names[regs];
			other_names[index] = gensel_other_reg_names[regs];
			++regs;
			++index;
			break;

		case GENSEL_PATT_IMMZERO:
			++index;
			break;

		case GENSEL_PATT_IMM:
		case GENSEL_PATT_IMMS8:
		case GENSEL_PATT_IMMU8:
		case GENSEL_PATT_IMMS16:
		case GENSEL_PATT_IMMU16:
			names[index] = gensel_imm_names[imms];
			++imms;
			++index;
			break;

		case GENSEL_PATT_LOCAL:
		case GENSEL_PATT_FRAME:
			names[index] = gensel_local_names[locals];
			++locals;
			++index;
			break;

		case GENSEL_PATT_SCRATCH:
			names[index] = gensel_reg_names[regs];
			++regs;
			++index;
		}
		pattern = pattern->next;
	}
}

/*
 * Output the code.
 */
static void
gensel_output_code(
	gensel_option_t pattern,
	char *code,
	char *names[MAX_PATTERN],
	char *other_names[MAX_PATTERN],
	int free_dest,
	int in_line)
{
	char first;
	int index;
	
	/* Output the clause code */
	if(!in_line)
	{
		printf("\t\t");
	}
	while(*code != '\0')
	{
		first = '1';
		if(*code == '$' && code[1] >= first && code[1] < (first + MAX_PATTERN))
		{
			index = code[1] - first;
			printf(names[index]);
			code += 2;
		}
		else if(*code == '%' && code[1] >= first && code[1] < (first + MAX_PATTERN))
		{
			index = code[1] - first;
			printf(other_names[index]);
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
	if(!in_line)
	{
		printf("\n");
	}
}

/*
 * Output the code within a clause.
 */
static void
gensel_output_clause_code(
	gensel_clause_t clause,
	char *names[MAX_PATTERN],
	char *other_names[MAX_PATTERN],
	int free_dest)
{
	/* Output the line number information from the original file */
#if 0
	printf("#line %ld \"%s\"\n", clause->linenum, clause->filename);
#endif

	gensel_output_code(clause->pattern, clause->code, names, other_names, free_dest, 0);
}

static void
gensel_output_register(char *name, gensel_regclass_t regclass, gensel_value_t values)
{
	printf("\t\t_jit_regs_init_%s(&regs, insn, ", name);
	switch(values ? values->type : 0)
	{
	case GENSEL_VALUE_CLOBBER:
		printf("_JIT_REGS_CLOBBER");
		values = values->next;
		break;
	case GENSEL_VALUE_EARLY_CLOBBER:
		printf("_JIT_REGS_EARLY_CLOBBER");
		values = values->next;
		break;
	default:
		printf("0");
		break;
	}
	printf(", %s);\n", regclass->def);
	if(values && values->value)
	{
		char *reg;
		reg = values->value;
		if(values->next && values->next->value)
		{
			char *other_reg;
			other_reg = values->next->value;
			printf("\t\t_jit_regs_set_%s(gen, &regs, _jit_regs_lookup(\"%s\"), _jit_regs_lookup(\"%s\"));\n",
			       name, reg, other_reg);
		}
		else
		{
			printf("\t\t_jit_regs_set_%s(gen, &regs, _jit_regs_lookup(\"%s\"), -1);\n",
			       name, reg);
		}
	}
}

/*
 * Output value initialization code.
 */
static void
gensel_output_register_pattern(char *name, gensel_option_t pattern)
{
	gensel_output_register(name, pattern->values->value, pattern->values->next);
}

/*
 * Output the clauses for a rule.
 */
static void gensel_output_clauses(gensel_clause_t clauses, gensel_option_t options)
{
	char *name;
	char *args[MAX_INPUT];
	char *names[MAX_PATTERN];
	char *other_names[MAX_PATTERN];
	gensel_clause_t clause;
	gensel_option_t pattern;
	gensel_option_t space, more_space;
	gensel_value_t values;
	int regs, imms, locals, scratch, index;
	int first, seen_option;
	int ternary, free_dest;
	int contains_registers;
	gensel_regclass_t regclass;

	/* If the clause is manual, then output it as-is */
	if(gensel_search_option(options, GENSEL_OPT_MANUAL))
	{
		gensel_init_names(MAX_PATTERN, names, other_names);
		gensel_output_clause_code(clauses, names, other_names, 0);
		return;
	}

	clause = clauses;
	contains_registers = 0;
	while(clause)
	{
		contains_registers = gensel_contains_registers(clause->pattern);
		if(contains_registers)
		{
			break;
		}
		clause = clause->next;
	}

	printf("\t%s inst;\n", gensel_inst_type);
	if(contains_registers)
	{
		printf("\t_jit_regs_t regs;\n");
	}
	gensel_declare_regs(clauses, options);

	ternary = (0 != gensel_search_option(options, GENSEL_OPT_TERNARY));

	/* Output the clause checking and dispatching code */
	clause = clauses;
	first = 1;
	while(clause)
	{
		contains_registers = gensel_contains_registers(clause->pattern);
		free_dest = clause->dest;

		gensel_build_arg_index(clause->pattern, 3, args, 0, ternary, free_dest);

		if(clause->next)
		{
			if(first)
				printf("\tif(");
			else
				printf("\telse if(");

			index = 0;
			seen_option = 0;
			pattern = clause->pattern;
			while(pattern)
			{
				switch(pattern->option)
				{
				case GENSEL_PATT_ANY:
					++index;
					break;

				case GENSEL_PATT_REG:
				case GENSEL_PATT_LREG:
					/* Do not check if the value is in
					   a register as the allocator will
					   load them anyway as long as other
					   conditions are met. */
#if 0
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->in_register", args[index]);
#endif
					++index;
					break;

				case GENSEL_PATT_IMM:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_constant", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IMMZERO:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_nint_constant && ", args[index]);
					printf("insn->%s->address == 0", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IMMS8:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_nint_constant && ", args[index]);
					printf("insn->%s->address >= -128 && ", args[index]);
					printf("insn->%s->address <= 127", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IMMU8:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_nint_constant && ", args[index]);
					printf("insn->%s->address >= 0 && ", args[index]);
					printf("insn->%s->address <= 255", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IMMS16:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_nint_constant && ", args[index]);
					printf("insn->%s->address >= -32768 && ", args[index]);
					printf("insn->%s->address <= 32767", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IMMU16:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("insn->%s->is_nint_constant && ", args[index]);
					printf("insn->%s->address >= 0 && ", args[index]);
					printf("insn->%s->address <= 65535", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_LOCAL:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("!insn->%s->is_constant && ", args[index]);
					printf("!insn->%s->in_register && ", args[index]);
					printf("!insn->%s->has_global_register", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_FRAME:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("!insn->%s->is_constant && ", args[index]);
					printf("!insn->%s->has_global_register", args[index]);
					seen_option = 1;
					++index;
					break;

				case GENSEL_PATT_IF:
					if(seen_option)
					{
						printf(" && ");
					}
					printf("(");
					gensel_build_imm_arg_index(
						clause->pattern, MAX_PATTERN,
						names, other_names, ternary, free_dest);
					gensel_output_code(
						clause->pattern,
						pattern->values->value,
						names, other_names, free_dest, 1);
					printf(")");
					seen_option = 1;
					break;
				}
				pattern = pattern->next;
			}
			if(!seen_option)
			{
				printf("1");
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

		if(contains_registers)
		{
			seen_option = 0;
			printf("\t\t_jit_regs_init(gen, &regs, ");
			if(ternary)
			{
				seen_option = 1;
				printf("_JIT_REGS_TERNARY");
			}
			else if(free_dest)
			{
				seen_option = 1;
				printf("_JIT_REGS_FREE_DEST");
			}
			if(gensel_search_option(options, GENSEL_OPT_BRANCH))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_BRANCH");
			}
			if(gensel_search_option(options, GENSEL_OPT_COPY))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_COPY");
			}
			if(gensel_search_option(options, GENSEL_OPT_STACK))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_STACK");
			}
			if(gensel_search_option(options, GENSEL_OPT_COMMUTATIVE))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_COMMUTATIVE");
			}
			/* x87 options */
			if(gensel_search_option(options, GENSEL_OPT_X87_ARITH))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_X87_ARITH");
			}
			else if(gensel_search_option(options, GENSEL_OPT_X87_ARITH_REVERSIBLE))
			{
				if(seen_option)
				{
					printf(" | ");
				}
				else
				{
					seen_option = 1;
				}
				printf("_JIT_REGS_X87_ARITH | _JIT_REGS_REVERSIBLE");
			}
			if(!seen_option)
			{
				printf("0");
			}
			printf(");\n");

			if(!(ternary || free_dest
			     || gensel_search_option(options, GENSEL_OPT_NOTE)
			     || gensel_search_option(options, GENSEL_OPT_BRANCH)))
			{
				pattern = gensel_get_first_register(clause->pattern);
				gensel_output_register("dest", pattern ? pattern->values->value : 0, 0);
			}
		}

		regs = 0;
		index = 0;
		scratch = 0;
		pattern = clause->pattern;
		while(pattern)
		{
			switch(pattern->option)
			{
			case GENSEL_PATT_ANY:
				++index;
				break;

			case GENSEL_PATT_REG:
			case GENSEL_PATT_LREG:
				gensel_output_register_pattern(args[index], pattern);
				++regs;
				++index;
				break;

			case GENSEL_PATT_IMMZERO:
			case GENSEL_PATT_IMM:
			case GENSEL_PATT_IMMS8:
			case GENSEL_PATT_IMMU8:
			case GENSEL_PATT_IMMS16:
			case GENSEL_PATT_IMMU16:
				++index;
				break;

			case GENSEL_PATT_LOCAL:
				printf("\t\t_jit_gen_fix_value(insn->%s);\n", args[index]);
				++index;
				break;

			case GENSEL_PATT_FRAME:
				printf("\t\t_jit_regs_force_out(gen, insn->%s, %d);\n",
				       args[index], (free_dest && index == 0));
				printf("\t\t_jit_gen_fix_value(insn->%s);\n", args[index]);
				++index;
				break;

			case GENSEL_PATT_SCRATCH:
				regclass = pattern->values->value;
				printf("\t\t_jit_regs_add_scratch(&regs, %s);\n",
				       regclass->def);
				if(pattern->values->next && pattern->values->next->value)
				{
					name = pattern->values->next->value;
					printf("\t\t_jit_regs_set_scratch(gen, &regs, %d, _jit_regs_lookup(\"%s\"));\n",
					       scratch, name);
				}
				++regs;
				++scratch;
				++index;
				break;

			case GENSEL_PATT_CLOBBER:
				values = pattern->values;
				while(values)
				{
					if(!values->value)
					{
						continue;
					}
					switch(values->type)
					{
					case GENSEL_VALUE_STRING:
						name = values->value;
						printf("\t\t_jit_regs_clobber(&regs, _jit_regs_lookup(\"%s\"));\n",
						       name);
						break;

					case GENSEL_VALUE_REGCLASS:
						regclass = values->value;
						printf("\t\t_jit_regs_clobber_class(gen, &regs, %s);\n",
							regclass->def);
						break;

					case GENSEL_VALUE_ALL:
						printf("\t\t_jit_regs_clobber_all(gen, &regs);\n");
						break;
					}
					values = values->next;
				}
				break;
			}
			pattern = pattern->next;
		}

		if(gensel_search_option(options, GENSEL_OPT_BRANCH))
		{
			/* Spill all other registers back to their original positions */
			if(contains_registers)
			{
				printf("\t\t_jit_regs_clobber_all(gen, &regs);\n");
			}
			else
			{
				printf("\t\t_jit_regs_spill_all(gen);\n");
			}
		}

		if(gensel_new_inst_type)
		{
			if(contains_registers)
			{
				printf("\t\tif(!_jit_regs_assign(gen, &regs))\n");
				printf("\t\t{\n");
				printf("\t\t\treturn;\n");
				printf("\t\t}\n");
				printf("\t\tif(!_jit_regs_gen(gen, &regs))\n");
				printf("\t\t{\n");
				printf("\t\t\treturn;\n");
				printf("\t\t}\n");
			}
			printf("\t\tjit_gen_load_inst_ptr(gen, inst);\n");
		}
		else
		{
			space = gensel_search_option(clause->pattern, GENSEL_PATT_SPACE);
			more_space = gensel_search_option(options, GENSEL_OPT_MORE_SPACE);

			if(contains_registers)
			{
				printf("\t\tif(!(inst = (%s)_jit_regs_begin(gen, &regs, ", gensel_inst_type);
			}
			else
			{
				printf("\t\tinst = (%s)(gen->posn.ptr);\n", gensel_inst_type);
				printf("\t\tif(!jit_cache_check_for_n(&(gen->posn), ");
			}
			if(space && space->values && space->values->value)
			{
				printf("(");
				gensel_build_imm_arg_index(
					clause->pattern, MAX_PATTERN,
					names, other_names, ternary, free_dest);
				gensel_output_code(
					clause->pattern,
					space->values->value,
					names, other_names, free_dest, 1);
				printf(")");
			}
			else
			{
				printf("%d", ((more_space == 0)
					      ? gensel_reserve_space
					      : gensel_reserve_more_space));
			}
			if(contains_registers)
			{
				printf(")))\n");
				printf("\t\t{\n");
				printf("\t\t\treturn;\n");
				printf("\t\t}\n");
			}
			else
			{
				printf("))\n");
				printf("\t\t{\n");
				printf("\t\t\tjit_cache_mark_full(&(gen->posn));\n");
				printf("\t\t\treturn;\n");
				printf("\t\t}\n");
			}
		}

		regs = 0;
		imms = 0;
		locals = 0;
		index = 0;
		scratch = 0;
		pattern = clause->pattern;
		while(pattern)
		{
			switch(pattern->option)
			{
			case GENSEL_PATT_ANY:
				++index;
				break;

			case GENSEL_PATT_REG:
				printf("\t\t%s = _jit_reg_info[_jit_regs_get_%s(&regs)].cpu_reg;\n",
				       gensel_reg_names[regs], args[index]);
				++regs;
				++index;
				break;

			case GENSEL_PATT_LREG:
				printf("\t\t%s = _jit_reg_info[_jit_regs_get_%s(&regs)].cpu_reg;\n",
				       gensel_reg_names[regs], args[index]);
				printf("\t\t%s = _jit_reg_info[_jit_regs_get_%s_other(&regs)].cpu_reg;\n",
				       gensel_other_reg_names[regs], args[index]);
				++regs;
				++index;
				break;

			case GENSEL_PATT_IMMZERO:
				++index;
				break;

			case GENSEL_PATT_IMM:
			case GENSEL_PATT_IMMS8:
			case GENSEL_PATT_IMMU8:
			case GENSEL_PATT_IMMS16:
			case GENSEL_PATT_IMMU16:
				printf("\t\t%s = insn->%s->address;\n",
				       gensel_imm_names[imms], args[index]);
				++imms;
				++index;
				break;

			case GENSEL_PATT_LOCAL:
			case GENSEL_PATT_FRAME:
				printf("\t\t%s = insn->%s->frame_offset;\n",
				       gensel_local_names[locals], args[index]);
				++locals;
				++index;
				break;

			case GENSEL_PATT_SCRATCH:
				printf("\t\t%s = _jit_reg_info[_jit_regs_get_scratch(&regs, %d)].cpu_reg;\n",
				       gensel_reg_names[regs], scratch);
				++regs;
				++scratch;
				++index;
				break;

			}
			pattern = pattern->next;
		}

		gensel_build_var_index(clause->pattern, names, other_names);
		gensel_output_clause_code(clause, names, other_names, free_dest);

		/* Copy "inst" back into the generation context */
		if(gensel_new_inst_type)
		{
			printf("\t\tjit_gen_save_inst_ptr(gen, inst);\n");
			if(contains_registers)
			{
				printf("\t\t_jit_regs_commit(gen, &regs);\n");
			}
		}
		else if(contains_registers)
		{
			printf("\t\t_jit_regs_end(gen, &regs, (unsigned char *)inst);\n");
		}
		else
		{
			printf("\t\tgen->posn.ptr = (unsigned char *)inst;\n");
		}

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



/* Line 189 of yacc.c  */
#line 1650 "gen-rules-parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     IDENTIFIER = 258,
     CODE_BLOCK = 259,
     LITERAL = 260,
     K_PTR = 261,
     K_ANY = 262,
     K_ALL = 263,
     K_IMM = 264,
     K_IMMZERO = 265,
     K_IMMS8 = 266,
     K_IMMU8 = 267,
     K_IMMS16 = 268,
     K_IMMU16 = 269,
     K_LOCAL = 270,
     K_FRAME = 271,
     K_NOTE = 272,
     K_TERNARY = 273,
     K_BRANCH = 274,
     K_COPY = 275,
     K_COMMUTATIVE = 276,
     K_IF = 277,
     K_CLOBBER = 278,
     K_SCRATCH = 279,
     K_SPACE = 280,
     K_STACK = 281,
     K_X87_ARITH = 282,
     K_X87_ARITH_REVERSIBLE = 283,
     K_INST_TYPE = 284,
     K_REG_CLASS = 285,
     K_LREG_CLASS = 286,
     K_MANUAL = 287,
     K_MORE_SPACE = 288
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CODE_BLOCK 259
#define LITERAL 260
#define K_PTR 261
#define K_ANY 262
#define K_ALL 263
#define K_IMM 264
#define K_IMMZERO 265
#define K_IMMS8 266
#define K_IMMU8 267
#define K_IMMS16 268
#define K_IMMU16 269
#define K_LOCAL 270
#define K_FRAME 271
#define K_NOTE 272
#define K_TERNARY 273
#define K_BRANCH 274
#define K_COPY 275
#define K_COMMUTATIVE 276
#define K_IF 277
#define K_CLOBBER 278
#define K_SCRATCH 279
#define K_SPACE 280
#define K_STACK 281
#define K_X87_ARITH 282
#define K_X87_ARITH_REVERSIBLE 283
#define K_INST_TYPE 284
#define K_REG_CLASS 285
#define K_LREG_CLASS 286
#define K_MANUAL 287
#define K_MORE_SPACE 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 1580 "gen-rules-parser.y"

	int			tag;
	char			*name;
	struct gensel_value	*value;
	struct gensel_option	*option;
	struct
	{
		char	*filename;
		long	linenum;
		char	*block;

	}	code;
	struct
	{
		struct gensel_value	*head;
		struct gensel_value	*tail;

	}	values;
	struct
	{
		struct gensel_option	*head;
		struct gensel_option	*tail;

	}	options;
	struct
	{
		struct gensel_clause	*head;
		struct gensel_clause	*tail;

	}	clauses;



/* Line 214 of yacc.c  */
#line 1786 "gen-rules-parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 1798 "gen-rules-parser.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   97

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  100

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    41,    42,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,     2,
       2,    40,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    17,    20,    24,
      28,    30,    34,    35,    39,    40,    42,    46,    48,    50,
      53,    60,    61,    63,    67,    69,    72,    78,    84,    87,
      93,    98,   103,   108,   110,   112,   114,   118,   120,   122,
     124,   126,   130,   132,   134,   136,   138,   140,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   169,   171,   172,   174,   176,   178
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    -1,    45,    -1,    46,    -1,    45,    46,
      -1,    47,    48,    34,    49,    51,    -1,    29,     3,    -1,
      30,     3,     3,    -1,    31,     3,     3,    -1,     3,    -1,
      47,    35,     3,    -1,    -1,    36,     3,    37,    -1,    -1,
      50,    -1,    49,    35,    50,    -1,    61,    -1,    52,    -1,
      51,    52,    -1,    38,    63,    53,    39,     6,     4,    -1,
      -1,    54,    -1,    53,    35,    54,    -1,    62,    -1,    64,
      58,    -1,    64,    58,    36,    59,    37,    -1,    64,    58,
      36,    60,    37,    -1,    24,    58,    -1,    24,    58,    36,
      59,    37,    -1,    23,    36,    55,    37,    -1,    22,    36,
      59,    37,    -1,    25,    36,    59,    37,    -1,     8,    -1,
      56,    -1,    57,    -1,    56,    35,    57,    -1,    58,    -1,
      59,    -1,     3,    -1,    65,    -1,    59,    34,    59,    -1,
      18,    -1,    19,    -1,    17,    -1,    20,    -1,    21,    -1,
      26,    -1,    27,    -1,    28,    -1,    32,    -1,    33,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    15,    -1,    16,    -1,     7,    -1,    -1,    40,
      -1,    -1,    41,    -1,    42,    -1,     5,    -1,    65,     5,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,  1670,  1670,  1672,  1676,  1677,  1681,  1703,  1707,  1710,
    1716,  1717,  1733,  1734,  1738,  1742,  1746,  1754,  1760,  1761,
    1769,  1788,  1792,  1796,  1804,  1807,  1810,  1813,  1824,  1835,
    1846,  1849,  1852,  1858,  1861,  1867,  1871,  1879,  1880,  1884,
    1890,  1896,  1904,  1905,  1906,  1907,  1908,  1909,  1910,  1911,
    1914,  1915,  1919,  1920,  1921,  1922,  1923,  1924,  1925,  1926,
    1927,  1931,  1932,  1936,  1937,  1938,  1942,  1943
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"an identifier\"", "\"a code block\"",
  "\"literal string\"", "\"`->'\"", "\"any value\"", "\"all registers\"",
  "\"immediate value\"", "\"immediate zero value\"",
  "\"immediate signed 8-bit value\"", "\"immediate unsigned 8-bit value\"",
  "\"immediate signed 16-bit value\"",
  "\"immediate unsigned 16-bit value\"", "\"local variable\"",
  "\"local variable forced out into the stack frame\"", "\"`note'\"",
  "\"`ternary'\"", "\"`branch'\"", "\"`copy'\"", "\"`commutative'\"",
  "\"`if'\"", "\"`clobber'\"", "\"`scratch'\"", "\"`space'\"",
  "\"`stack'\"", "\"`x87_arith'\"", "\"`x87_arith_reversible'\"",
  "\"`%inst_type'\"", "\"`%reg_class'\"", "\"`%lreg_class'\"",
  "\"`manual'\"", "\"`more_space'\"", "':'", "','", "'('", "')'", "'['",
  "']'", "'='", "'*'", "'+'", "$accept", "Start", "Rules", "Rule",
  "IdentifierList", "IfClause", "Options", "Option", "Clauses", "Clause",
  "Pattern", "PatternElement", "ClobberSpec", "ClobberList",
  "ClobberEntry", "RegClass", "Value", "ValuePair", "OptionTag",
  "InputTag", "DestFlag", "RegFlag", "Literal", 0
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
     285,   286,   287,   288,    58,    44,    40,    41,    91,    93,
      61,    42,    43
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    50,    51,    51,
      52,    53,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      59,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    64,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     5,     2,     3,     3,
       1,     3,     0,     3,     0,     1,     3,     1,     1,     2,
       6,     0,     1,     3,     1,     2,     5,     5,     2,     5,
       4,     4,     4,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     0,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    10,     0,     0,     0,     0,     3,     4,    12,     7,
       0,     0,     1,     5,     0,     0,     0,     8,     9,    11,
       0,    14,    13,    44,    42,    43,    45,    46,    47,    48,
      49,    50,    51,     0,    15,    17,     0,    61,     6,    18,
      16,    62,    21,    19,    60,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,    64,    65,     0,
      22,    24,     0,     0,     0,    39,    28,     0,    63,     0,
      25,    66,     0,    40,    33,     0,    34,    35,    37,    38,
       0,     0,    23,     0,     0,    31,    67,    30,     0,     0,
      32,    20,     0,     0,    36,    29,     0,    26,    27,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    16,    33,    34,    38,    39,
      59,    60,    75,    76,    77,    78,    79,    93,    35,    61,
      42,    62,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int8 yypact[] =
{
      20,   -39,    23,    32,    33,    45,    20,   -39,   -33,   -39,
      34,    43,   -39,   -39,    44,    49,    24,   -39,   -39,   -39,
      29,    36,   -39,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,   -20,   -39,   -39,    36,    27,    35,   -39,
     -39,   -39,    -3,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,   -39,    40,    42,    76,    46,   -39,   -39,   -34,
     -39,   -39,    76,    75,    67,   -39,    47,    75,    18,    78,
      50,   -39,    48,    82,   -39,    51,    54,   -39,   -39,   -39,
      75,    53,   -39,    77,    75,   -39,   -39,   -39,    11,    55,
     -39,   -39,    37,    56,   -39,   -39,    75,   -39,   -39,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,    85,   -39,   -39,   -39,    58,   -39,    57,
     -39,    28,   -39,   -39,     9,   -38,   -19,   -39,   -39,   -39,
     -39,   -39,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int8 yytable[] =
{
     -63,    68,    14,    15,    44,    69,    45,    46,    47,    48,
      49,    50,    51,    52,    65,    36,    71,    66,    37,    53,
      54,    55,    56,     1,    70,    44,     9,    45,    46,    47,
      48,    49,    50,    51,    52,    10,    11,    17,    57,    58,
      53,    54,    55,    56,    72,    12,    18,    19,    81,     2,
       3,     4,    20,    23,    24,    25,    26,    27,    21,    57,
      58,    89,    28,    29,    30,    92,    22,    41,    31,    32,
      65,    96,    71,    37,    97,    74,    63,    99,    64,    65,
      71,    91,    67,    80,    83,    85,    84,    86,    87,    88,
      90,    13,    95,    98,    40,    43,    82,    94
};

static const yytype_uint8 yycheck[] =
{
       3,    35,    35,    36,     7,    39,     9,    10,    11,    12,
      13,    14,    15,    16,     3,    35,     5,    55,    38,    22,
      23,    24,    25,     3,    62,     7,     3,     9,    10,    11,
      12,    13,    14,    15,    16,     3,     3,     3,    41,    42,
      22,    23,    24,    25,    63,     0,     3,     3,    67,    29,
      30,    31,     3,    17,    18,    19,    20,    21,    34,    41,
      42,    80,    26,    27,    28,    84,    37,    40,    32,    33,
       3,    34,     5,    38,    37,     8,    36,    96,    36,     3,
       5,     4,    36,    36,     6,    37,    36,     5,    37,    35,
      37,     6,    37,    37,    36,    38,    68,    88
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    31,    44,    45,    46,    47,     3,
       3,     3,     0,    46,    35,    36,    48,     3,     3,     3,
       3,    34,    37,    17,    18,    19,    20,    21,    26,    27,
      28,    32,    33,    49,    50,    61,    35,    38,    51,    52,
      50,    40,    63,    52,     7,     9,    10,    11,    12,    13,
      14,    15,    16,    22,    23,    24,    25,    41,    42,    53,
      54,    62,    64,    36,    36,     3,    58,    36,    35,    39,
      58,     5,    59,    65,     8,    55,    56,    57,    58,    59,
      36,    59,    54,     6,    36,    37,     5,    37,    35,    59,
      37,     4,    59,    60,    57,    37,    34,    37,    37,    59
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
        case 6:

/* Line 1455 of yacc.c  */
#line 1681 "gen-rules-parser.y"
    {
			if((yyvsp[(2) - (5)].name))
			{
				if(((yyvsp[(2) - (5)].name))[0] == '!')
				{
					printf("#ifndef %s\n\n", (yyvsp[(2) - (5)].name) + 1);
				}
				else
				{
					printf("#ifdef %s\n\n", (yyvsp[(2) - (5)].name));
				}
			}
			printf("case %s:\n{\n", (yyvsp[(1) - (5)].name));
			gensel_output_clauses((yyvsp[(5) - (5)].clauses).head, (yyvsp[(4) - (5)].options).head);
			printf("}\nbreak;\n\n");
			if((yyvsp[(2) - (5)].name))
			{
				printf("#endif /* %s */\n\n", (yyvsp[(2) - (5)].name));
			}
			gensel_free_clauses((yyvsp[(5) - (5)].clauses).head);
			gensel_add_supported((yyvsp[(1) - (5)].name), (yyvsp[(2) - (5)].name));
		}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 1703 "gen-rules-parser.y"
    {
			gensel_inst_type = (yyvsp[(2) - (2)].name);
			gensel_new_inst_type = 1;
		}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 1707 "gen-rules-parser.y"
    {
			gensel_create_regclass((yyvsp[(2) - (3)].name), (yyvsp[(3) - (3)].name), 0);
		}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 1710 "gen-rules-parser.y"
    {
			gensel_create_regclass((yyvsp[(2) - (3)].name), (yyvsp[(3) - (3)].name), 1);
		}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 1716 "gen-rules-parser.y"
    { (yyval.name) = (yyvsp[(1) - (1)].name); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 1717 "gen-rules-parser.y"
    {
			char *result = (char *)malloc(strlen((yyvsp[(1) - (3)].name)) + strlen((yyvsp[(3) - (3)].name)) + 16);
			if(!result)
			{
				exit(1);
			}
			strcpy(result, (yyvsp[(1) - (3)].name));
			strcat(result, ":\ncase ");
			strcat(result, (yyvsp[(3) - (3)].name));
			free((yyvsp[(1) - (3)].name));
			free((yyvsp[(3) - (3)].name));
			(yyval.name) = result;
		}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 1733 "gen-rules-parser.y"
    { (yyval.name) = 0; }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 1734 "gen-rules-parser.y"
    { (yyval.name) = (yyvsp[(2) - (3)].name); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 1738 "gen-rules-parser.y"
    {
			(yyval.options).head = 0;
			(yyval.options).tail = 0;
		}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 1742 "gen-rules-parser.y"
    {
			(yyval.options).head = (yyvsp[(1) - (1)].option);
			(yyval.options).tail = (yyvsp[(1) - (1)].option);
		}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 1746 "gen-rules-parser.y"
    {
			(yyvsp[(1) - (3)].options).tail->next = (yyvsp[(3) - (3)].option);
			(yyval.options).head = (yyvsp[(1) - (3)].options).head;
			(yyval.options).tail = (yyvsp[(3) - (3)].option);
		}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 1754 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_option((yyvsp[(1) - (1)].tag), 0);
		}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 1760 "gen-rules-parser.y"
    { (yyval.clauses) = (yyvsp[(1) - (1)].clauses); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 1761 "gen-rules-parser.y"
    {
			(yyvsp[(1) - (2)].clauses).tail->next = (yyvsp[(2) - (2)].clauses).head;
			(yyval.clauses).head = (yyvsp[(1) - (2)].clauses).head;
			(yyval.clauses).tail = (yyvsp[(2) - (2)].clauses).tail;
		}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 1769 "gen-rules-parser.y"
    {
			gensel_clause_t clause;
			clause = (gensel_clause_t)malloc(sizeof(struct gensel_clause));
			if(!clause)
			{
				exit(1);
			}
			clause->dest = (yyvsp[(2) - (6)].tag);
			clause->pattern = (yyvsp[(3) - (6)].options).head;
			clause->filename = (yyvsp[(6) - (6)].code).filename;
			clause->linenum = (yyvsp[(6) - (6)].code).linenum;
			clause->code = (yyvsp[(6) - (6)].code).block;
			clause->next = 0;
			(yyval.clauses).head = clause;
			(yyval.clauses).tail = clause;
		}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 1788 "gen-rules-parser.y"
    {
			(yyval.options).head = 0;
			(yyval.options).tail = 0;
		}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 1792 "gen-rules-parser.y"
    {
			(yyval.options).head = (yyvsp[(1) - (1)].option);
			(yyval.options).tail = (yyvsp[(1) - (1)].option);
		}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 1796 "gen-rules-parser.y"
    {
			(yyvsp[(1) - (3)].options).tail->next = (yyvsp[(3) - (3)].option);
			(yyval.options).head = (yyvsp[(1) - (3)].options).head;
			(yyval.options).tail = (yyvsp[(3) - (3)].option);
		}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 1804 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_option((yyvsp[(1) - (1)].tag), 0);
		}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 1807 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_register((yyvsp[(1) - (2)].tag), (yyvsp[(2) - (2)].value), 0);
		}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 1810 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_register((yyvsp[(1) - (5)].tag), (yyvsp[(2) - (5)].value), (yyvsp[(4) - (5)].value));
		}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 1813 "gen-rules-parser.y"
    {
			gensel_regclass_t regclass;
			regclass = (yyvsp[(2) - (5)].value)->value;
			if(!regclass->is_long)
			{
				gensel_error(
					gensel_filename, gensel_linenum,
					"not a long pair register");
			}
			(yyval.option) = gensel_create_register((yyvsp[(1) - (5)].tag), (yyvsp[(2) - (5)].value), (yyvsp[(4) - (5)].values).head);
		}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 1824 "gen-rules-parser.y"
    {
			gensel_regclass_t regclass;
			regclass = (yyvsp[(2) - (2)].value)->value;
			if(regclass->is_long)
			{
				gensel_error(
					gensel_filename, gensel_linenum,
					"scratch register cannot be a long pair");
			}
			(yyval.option) = gensel_create_scratch((yyvsp[(2) - (2)].value), 0);
		}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 1835 "gen-rules-parser.y"
    {
			gensel_regclass_t regclass;
			regclass = (yyvsp[(2) - (5)].value)->value;
			if(regclass->is_long)
			{
				gensel_error(
					gensel_filename, gensel_linenum,
					"scratch register cannot be a long pair");
			}
			(yyval.option) = gensel_create_scratch((yyvsp[(2) - (5)].value), (yyvsp[(4) - (5)].value));
		}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 1846 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_option(GENSEL_PATT_CLOBBER, (yyvsp[(3) - (4)].values).head);
		}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 1849 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_option(GENSEL_PATT_IF, (yyvsp[(3) - (4)].value));
		}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 1852 "gen-rules-parser.y"
    {
			(yyval.option) = gensel_create_option(GENSEL_PATT_SPACE, (yyvsp[(3) - (4)].value));
		}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 1858 "gen-rules-parser.y"
    {
			(yyval.values).head = (yyval.values).tail = gensel_create_value(GENSEL_VALUE_ALL);
		}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 1861 "gen-rules-parser.y"
    {
			(yyval.values) = (yyvsp[(1) - (1)].values);
		}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 1867 "gen-rules-parser.y"
    {
			(yyval.values).head = (yyvsp[(1) - (1)].value);
			(yyval.values).tail = (yyvsp[(1) - (1)].value);
		}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 1871 "gen-rules-parser.y"
    {
			(yyvsp[(1) - (3)].values).tail->next = (yyvsp[(3) - (3)].value);
			(yyval.values).head = (yyvsp[(1) - (3)].values).head;
			(yyval.values).tail = (yyvsp[(3) - (3)].value);
		}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 1879 "gen-rules-parser.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 1880 "gen-rules-parser.y"
    { (yyval.value) = (yyvsp[(1) - (1)].value); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 1884 "gen-rules-parser.y"
    {
			(yyval.value) = gensel_create_regclass_value((yyvsp[(1) - (1)].name));
		}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 1890 "gen-rules-parser.y"
    {
			(yyval.value) = gensel_create_string_value((yyvsp[(1) - (1)].name));
		}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 1896 "gen-rules-parser.y"
    {
			(yyvsp[(1) - (3)].value)->next = (yyvsp[(3) - (3)].value);
			(yyval.values).head = (yyvsp[(1) - (3)].value);
			(yyval.values).tail = (yyvsp[(3) - (3)].value);
		}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 1904 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_TERNARY; }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 1905 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_BRANCH; }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 1906 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_NOTE; }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 1907 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_COPY; }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 1908 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_COMMUTATIVE; }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 1909 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_STACK; }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 1910 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_X87_ARITH; }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 1911 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_X87_ARITH_REVERSIBLE; }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 1914 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_MANUAL; }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 1915 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_OPT_MORE_SPACE; }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 1919 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMM; }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 1920 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMMZERO; }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 1921 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMMS8; }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 1922 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMMU8; }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 1923 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMMS16; }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 1924 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_IMMU16; }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 1925 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_LOCAL; }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 1926 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_FRAME; }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 1927 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_PATT_ANY; }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 1931 "gen-rules-parser.y"
    { (yyval.tag) = 0; }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 1932 "gen-rules-parser.y"
    { (yyval.tag) = 1; }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 1936 "gen-rules-parser.y"
    { (yyval.tag) = 0; }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 1937 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_VALUE_CLOBBER; }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 1938 "gen-rules-parser.y"
    { (yyval.tag) = GENSEL_VALUE_EARLY_CLOBBER; }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 1942 "gen-rules-parser.y"
    { (yyval.name) = (yyvsp[(1) - (1)].name); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 1943 "gen-rules-parser.y"
    {
			char *cp = malloc(strlen((yyvsp[(1) - (2)].name)) + strlen((yyvsp[(2) - (2)].name)) + 1);
			if(!cp)
			{
				exit(1);
			}
			strcpy(cp, (yyvsp[(1) - (2)].name));
			strcat(cp, (yyvsp[(2) - (2)].name));
			free((yyvsp[(1) - (2)].name));
			free((yyvsp[(2) - (2)].name));
			(yyval.name) = cp;
		}
    break;



/* Line 1455 of yacc.c  */
#line 3675 "gen-rules-parser.c"
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
#line 1957 "gen-rules-parser.y"


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

