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
     INTEGER_CONSTANT = 259,
     STRING_CONSTANT = 260,
     REAL_CONSTANT = 261,
     K_AND = 262,
     K_ARRAY = 263,
     K_BEGIN = 264,
     K_CASE = 265,
     K_CATCH = 266,
     K_CONST = 267,
     K_DIV = 268,
     K_DO = 269,
     K_DOWNTO = 270,
     K_ELSE = 271,
     K_END = 272,
     K_EXIT = 273,
     K_FASTCALL = 274,
     K_FINALLY = 275,
     K_FOR = 276,
     K_FORWARD = 277,
     K_FUNCTION = 278,
     K_GOTO = 279,
     K_IF = 280,
     K_IN = 281,
     K_LABEL = 282,
     K_IMPORT = 283,
     K_MOD = 284,
     K_MODULE = 285,
     K_NIL = 286,
     K_NOT = 287,
     K_OF = 288,
     K_OR = 289,
     K_PACKED = 290,
     K_POW = 291,
     K_PROCEDURE = 292,
     K_PROGRAM = 293,
     K_RECORD = 294,
     K_REPEAT = 295,
     K_SET = 296,
     K_SHL = 297,
     K_SHR = 298,
     K_SIZEOF = 299,
     K_STDCALL = 300,
     K_THEN = 301,
     K_THROW = 302,
     K_TO = 303,
     K_TRY = 304,
     K_TYPE = 305,
     K_UNTIL = 306,
     K_VAR = 307,
     K_VA_ARG = 308,
     K_WITH = 309,
     K_WHILE = 310,
     K_XOR = 311,
     K_NE = 312,
     K_LE = 313,
     K_GE = 314,
     K_ASSIGN = 315,
     K_DOT_DOT = 316
   };
#endif
#define IDENTIFIER 258
#define INTEGER_CONSTANT 259
#define STRING_CONSTANT 260
#define REAL_CONSTANT 261
#define K_AND 262
#define K_ARRAY 263
#define K_BEGIN 264
#define K_CASE 265
#define K_CATCH 266
#define K_CONST 267
#define K_DIV 268
#define K_DO 269
#define K_DOWNTO 270
#define K_ELSE 271
#define K_END 272
#define K_EXIT 273
#define K_FASTCALL 274
#define K_FINALLY 275
#define K_FOR 276
#define K_FORWARD 277
#define K_FUNCTION 278
#define K_GOTO 279
#define K_IF 280
#define K_IN 281
#define K_LABEL 282
#define K_IMPORT 283
#define K_MOD 284
#define K_MODULE 285
#define K_NIL 286
#define K_NOT 287
#define K_OF 288
#define K_OR 289
#define K_PACKED 290
#define K_POW 291
#define K_PROCEDURE 292
#define K_PROGRAM 293
#define K_RECORD 294
#define K_REPEAT 295
#define K_SET 296
#define K_SHL 297
#define K_SHR 298
#define K_SIZEOF 299
#define K_STDCALL 300
#define K_THEN 301
#define K_THROW 302
#define K_TO 303
#define K_TRY 304
#define K_TYPE 305
#define K_UNTIL 306
#define K_VAR 307
#define K_VA_ARG 308
#define K_WITH 309
#define K_WHILE 310
#define K_XOR 311
#define K_NE 312
#define K_LE 313
#define K_GE 314
#define K_ASSIGN 315
#define K_DOT_DOT 316




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 775 "dpas-parser.y"
typedef union YYSTYPE {
	char		   *name;
	struct
	{
		jit_ulong	value;
		jit_type_t	type;
	}				int_const;
	jit_nfloat		real_const;
	jit_constant_t	const_value;
	jit_type_t		type;
	struct
	{
		char	  **list;
		int			len;
	}				id_list;
	struct
	{
		jit_type_t *list;
		int			len;
	}				type_list;
	dpas_params		parameters;
	struct
	{
		char	   *name;
		jit_type_t	type;
	}				procedure;
	struct
	{
		jit_type_t	type;
		dpas_params	bounds;
	}				param_type;
	dpas_semvalue	semvalue;
	struct
	{
		dpas_semvalue *exprs;
		int			len;
	}				expr_list;
	int				direction;
	jit_abi_t		abi;
} YYSTYPE;
/* Line 1249 of yacc.c.  */
#line 199 "dpas-parser.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



