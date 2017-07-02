#ifndef ROMEN_AST_H
#define ROMEN_AST_H

typedef enum {
	AST_NUMBER,
	AST_BLOCK,
	AST_LIST,
	AST_LET,
	AST_OP,
	AST_IDENT,
	AST_NULL,
} ast_type;

typedef struct ast_inner_string {
	ast_type type;
	unsigned int len;
	char buffer[0];
} *ast_inner_string;

typedef struct ast {
	ast_type type;
} ast;

typedef struct {
	ast_type type;
	long long value;
} ast_number;

typedef struct {
	ast_type type;
	ast_inner_string name;
} ast_ident;

typedef struct {
	ast_type type;
	unsigned int size;
	ast** stmts;
} ast_list;

typedef struct {
	ast_type type;
	ast* body;
} ast_block;

typedef struct {
	ast_type type;
	ast_inner_string lhs;
	ast* rhs;
} ast_let;

typedef struct {
	ast_type type;
	ast_inner_string op;
	ast* lhs;
	ast* rhs;
} ast_op;

extern ast_inner_string new_ast_inner_string(const char*, unsigned int);
extern ast* new_ast_number(long long);
extern ast* new_ast_ident(ast_inner_string);
extern ast* new_ast_list(void);
extern void add_ast_list(ast*, ast*);
extern ast* new_ast_let(ast_inner_string, ast*);
extern ast* new_ast_block(ast*);
extern ast* new_ast_op(const char*, ast*, ast*);
extern void ast_free(ast*);

#endif //ROMEN_AST_H
