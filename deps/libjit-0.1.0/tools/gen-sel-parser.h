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
/* Line 1249 of yacc.c.  */
#line 115 "gen-sel-parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



