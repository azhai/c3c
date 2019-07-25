#pragma once

// Copyright (c) 2019 Christoffer Lerno. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.


typedef enum _TokenType
{
	// Single-character tokens.
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_LBRACE,
	TOKEN_RBRACE,
	TOKEN_LBRACKET,
	TOKEN_RBRACKET,
	TOKEN_COMMA,
	TOKEN_DOT,
	TOKEN_EOS,
	TOKEN_AT,

	// One or two character tokens.
	TOKEN_PLUS,
	TOKEN_PLUSPLUS,
	TOKEN_PLUS_ASSIGN,
	TOKEN_BIT_NOT,
	TOKEN_NOT,
	TOKEN_MINUS,
	TOKEN_MINUSMINUS,
	TOKEN_MINUS_ASSIGN,
	TOKEN_STAR,
	TOKEN_MULT_ASSIGN,
	TOKEN_DIV,
	TOKEN_DIV_ASSIGN,
	TOKEN_MOD,
	TOKEN_MOD_ASSIGN,
	TOKEN_NOT_EQUAL,
	TOKEN_EQ,
	TOKEN_EQEQ,
	TOKEN_COLON,
	TOKEN_COLCOLON, // Not used but reserved
	TOKEN_DOTDOT,
	TOKEN_QUESTION,

	// Three or more
	TOKEN_ELIPSIS,
	TOKEN_GREATER,
	TOKEN_GREATER_EQ,
	TOKEN_RIGHT_SHIFT,
	TOKEN_RIGHT_SHIFT_ASSIGN,
	TOKEN_LESS,
	TOKEN_LESS_EQ,
	TOKEN_LEFT_SHIFT,
	TOKEN_LEFT_SHIFT_ASSIGN,
	TOKEN_ARROW, // Not used but reserved
	TOKEN_AND,
	TOKEN_AND_ASSIGN,
	TOKEN_AMP,
	TOKEN_BIT_AND_ASSIGN,
	TOKEN_OR,
	TOKEN_OR_ASSIGN,
	TOKEN_BIT_OR,
	TOKEN_BIT_OR_ASSIGN,
	TOKEN_BIT_XOR,
	TOKEN_BIT_XOR_ASSIGN,
	TOKEN_ELVIS,

	TOKEN_F256,
	TOKEN_I256,
	TOKEN_U256,
	TOKEN_F128,
	TOKEN_I128,
	TOKEN_U128,
	TOKEN_F64,
	TOKEN_I64,
	TOKEN_U64,
	TOKEN_F32,
	TOKEN_I32,
	TOKEN_U32,
	TOKEN_F16,
	TOKEN_I16,
	TOKEN_U16,
	TOKEN_I8,
	TOKEN_U8,
	TOKEN_QUAD,
	TOKEN_DOUBLE,
	TOKEN_FLOAT,
	TOKEN_HALF,
	TOKEN_LONG,
	TOKEN_ULONG,
	TOKEN_INT,
	TOKEN_UINT,
	TOKEN_SHORT,
	TOKEN_USHORT,
	TOKEN_BYTE,
	TOKEN_CHAR,
	TOKEN_BOOL,
	TOKEN_ISIZE,
	TOKEN_USIZE,

	// Literals.

	// In order to make the grammar
	// non ambiguous, we split tokens at the
	// lexer level
	TOKEN_TYPE_IDENT,
	TOKEN_CAPS_IDENT,
	TOKEN_VAR_IDENT,

	// We want to parse @foo / #foo / $foo separately.
	// Otherwise we allow things like "@ foo" which would be pretty bad.
	TOKEN_AT_IDENT,
	TOKEN_HASH_IDENT,
	TOKEN_DOLLAR_IDENT,

	TOKEN_STRING,
	TOKEN_INTEGER,
	TOKEN_REAL,

	// Keywords.
	TOKEN_ALIAS, // Reserved
	TOKEN_AS,
	TOKEN_ASM,
	TOKEN_BREAK,
	TOKEN_CASE,
	TOKEN_CAST,
	TOKEN_CATCH,
	TOKEN_CONST,
	TOKEN_CONTINUE,
	TOKEN_DEFAULT,
	TOKEN_DEFER,
	TOKEN_DO,
	TOKEN_ELSE,
	TOKEN_ENUM,
	TOKEN_ERROR,
	TOKEN_FALSE,
	TOKEN_FOR,
	TOKEN_FUNC,
	TOKEN_GENERIC,
	TOKEN_GOTO,
	TOKEN_IF,
	TOKEN_IMPORT,
	TOKEN_LOCAL,
	TOKEN_MACRO,
	TOKEN_MODULE,
	TOKEN_NIL,
	TOKEN_PUBLIC,
	TOKEN_RETURN,
	TOKEN_STRUCT,
	TOKEN_SWITCH,
	TOKEN_THROW,
	TOKEN_THROWS,
	TOKEN_TRUE,
	TOKEN_TRY,
	TOKEN_TYPE, // Reserved
	TOKEN_TYPEDEF,
	TOKEN_UNION,
	TOKEN_UNTIL,
	TOKEN_VAR, // Reserved
	TOKEN_VOID,
	TOKEN_VOLATILE,
	TOKEN_WHILE,


	TOKEN_C_USHORT,
	TOKEN_C_SHORT,
	TOKEN_C_INT,
	TOKEN_C_UINT,
	TOKEN_C_LONG,
	TOKEN_C_ULONG,
	TOKEN_C_LONGLONG,
	TOKEN_C_ULONGLONG,
	TOKEN_C_LONGDOUBLE,

	INVALID_TOKEN,
	TOKEN_EOF,

} TokenType;

const char *token_type_to_string(TokenType type);
TokenType identifier_type(const char* restrict start, int len);
TokenType ident_type_fnv1(const char *restrict start, int len);
