#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//for returns function check_string_validity()
#define OK 0
#define ERROR_BRACES 1
#define ERROR_POINT 2
#define ERROR_FUNCTION 3
#define ERROR_OPERATOR 4
#define ERROR_X 5

// //for type in lexeme
enum {
    X = 1,
    NUMBER = 2,
    OPEN_BRACE = 3,
    CLOSE_BRACE = 4,
    PLUS = 5,
    MINUS = 6,
    MULT = 7,
    DIV = 8,
    MOD = 9,
    POW = 10,
    UNARY_PLUS = 11,
    UNARY_MINUS = 12,
    SIN = 13,
    COS = 14,
    TAN = 15,
    ASIN = 16,
    ACOS = 17,
    ATAN = 18,
    SQRT = 19,
    LN = 20,
    LOG = 21
};


typedef struct lexeme {
    int type;
    double value;  // 0.0 for all excess numbers
    int priority;  //will be set by a special function
    struct lexeme *next;
} lexeme;


double simple_calculation (char *string);
int check_string_validity(char *value);
void set_priority (lexeme *value);
int make_lexeme_array (char *string, lexeme *root);
void print_node_array(const lexeme *root);
lexeme *copy_one_node(lexeme *old_node);
int from_infix_to_postfix (lexeme *root_infix, lexeme *root_postfix);
void push_in_stack (lexeme **stack, lexeme **new_node);
lexeme *pop_from_stack (lexeme **stack);
void push_in_postfix (lexeme **postfix, lexeme** node);
double from_postfix_to_result (lexeme *postfix);
double make_operation_for_binary(lexeme *a, lexeme *b, lexeme *operation);
double make_operation_for_unary(lexeme *a, lexeme *operation);
double calculate_y (char *string, double x);
