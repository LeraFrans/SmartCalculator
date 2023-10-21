#include "SmartCalc_v1.0.h"

//добавить недостающие проверки валидности

double simple_calculation (char *string) {
    double result = 0;

    int error = 0;
    error =  check_string_validity(string);

    //if error ... return ...

    struct lexeme root;
                root.next = NULL;
                root.priority = 0;
                root.value = 0;
                root.type = 0;
    make_lexeme_array(string, &root);

    lexeme *postfix = (lexeme*)calloc(1, sizeof(lexeme));
    from_infix_to_postfix (&root, postfix);
    result = from_postfix_to_result (postfix);

    return result;
}

/** @brief Check thr validity of braces
 *
 *
 *  @param value the string containing a mathematical expression entered by the user
 *  @return OK - expression is correct
 *          ERROR_* - expression is wrong
 */
int check_string_validity(char *value) {
    int braces_balans = 0;
    for (int i = 0; i < 256; i++) {

        //check braces (to close not opened brace)
        if (value[i] = '(') braces_balans++;
        else if (value[i] = ')') braces_balans--;
        if (braces_balans < 0) return ERROR_BRACES;

        //check point without digit (char befor point and char after point must be a digit)
        if (value[i] == '.' && i != 0 && i != 255) {
            if (value[i+1] < '0' || value[i+1] > '9' || value[i-1] < '0' || value[i-1] > '9') return ERROR_POINT;
        }
        else return ERROR_POINT;

        //check double x
        if (value[i] == 'x' && i != 255) {
            if (value[i+1] == 'x') return ERROR_X;
        }
    }

    //again check braces (brace is opened, but not close)
    if (braces_balans != 0) return ERROR_BRACES;

    return OK;
}


/** @brief Set priority in value lexeme
 *
 *
 *  @param value lexeme
 */
void set_priority (lexeme *value) {
    int type = value->type;
    if (type > 5) value->priority = 0;
    else if (type == PLUS || type == MINUS) value->priority = 1;
    else if (type == MULT || type == DIV || type == MOD) value->priority = 2;
    else if (type == POW) value->priority = 3;
    else value->priority = 4;
}


int make_lexeme_array (char *string, lexeme *root) {
    
    lexeme *last_node = root;
    //printf("OK\n");

    char previous_char = '\0';
    for (int i = 0; i < strlen(string); i++) {
        printf("i = %d\n", i);

        //if digit
        if (string[i] >= '0' && string[i] <= '9') {
            char string_number[256] = {'\0'};
            int count_string_number_index = 0;
            int flag_point = 0;
    
            while (((string[i] >= '0' && string[i] <= '9') || string[i] == '.') && i<256) {
                //printf("OK\n");
                if (string[i] == '.') {
                    if (flag_point == 1) return ERROR_POINT;
                    flag_point = 1;
                }

                string_number[count_string_number_index] = string[i];
                count_string_number_index++;
                i++;
            }
            i--;
            double result_double = 0;
            sscanf(string_number, "%lf", &result_double);
            last_node->value = result_double;
            last_node->type = NUMBER;
        }

        //if x or braces
            else if (string[i] == 'x') last_node->type = X;
            else if (string[i] == '(') last_node->type = OPEN_BRACE;
            else if (string[i] == ')') last_node->type = CLOSE_BRACE;

        //if + or -
        else if (string[i] == '+' || string[i] == '-' || string[i] == 'x') {

            //if unary write 0.0 befor it
            if (i == 0 || previous_char == '(') {

                //set 0
                last_node->priority = 0;
                last_node->type = NUMBER;
                last_node->value = 0;

                //create next node
                lexeme *tmp = (lexeme*)calloc(1, sizeof(lexeme));
                tmp->next = NULL;
                tmp->priority = 0;
                tmp->value = 0;
                tmp->type = 0;
                //make connection
                last_node->next = tmp;
                //swith the last_node pointer
                last_node = last_node->next;
            }

            if (string[i] == '+') last_node->type = PLUS;
            else if (string[i] == '-') last_node->type = MINUS;
            last_node->priority = 1;

        }

        //if mult or div
        else if (string[i] == '*' || string[i] == '/') {
            if (string[i] == '*') last_node->type = MULT;
            else last_node->type = DIV;
            last_node->priority = 2;
        }

        //if mod
        else if (string[i] == 'm' && i<253) {
            if (string[i+1] == 'o' && string[i+2] == 'd' && ((string[i+3] >= '0' && string[i+3] <= '9') ||string[i+3] == 'x')) {
                last_node->type = MOD;
                last_node->priority = 2;
                i+=2;
            }
            else return ERROR_OPERATOR;
        }

        //if pow
        else if (string[i] == '^') {
            last_node->type = POW;
            last_node->priority = 3;
        }

        //if functions 
        else if (i < 252) {
            if (string[i] == 'l' && string[i+1] == 'n' && string[i+2] == '(' ) last_node->type = LN;
            else if (i < 251) {
                if (string[i] == 'l' && string[i+1] == 'o' && string[i+2] == 'g' && string[i+3] == '(' ) last_node->type = LOG;
                else if (string[i] == 'c' && string[i+1] == 'o' && string[i+2] == 's' && string[i+3] == '(' ) last_node->type = COS;
                else if (string[i] == 's' && string[i+1] == 'i' && string[i+2] == 'n' && string[i+3] == '(' ) last_node->type = SIN;
                else if (string[i] == 't' && string[i+1] == 'a' && string[i+2] == 'n' && string[i+3] == '(' ) last_node->type = COS;
                else if (i < 250) {
                    if (string[i] == 'a' && string[i+1] == 'c' && string[i+2] == 'o' && string[i+3] == 's' && string[i+4] == '(' ) last_node->type = ACOS;
                    else if (string[i] == 'a' && string[i+1] == 's' && string[i+2] == 'i' && string[i+3] == 'n' && string[i+4] == '(' ) last_node->type = ASIN;
                    else if (string[i] == 'a' && string[i+1] == 't' && string[i+2] == 'a' && string[i+3] == 'n' && string[i+4] == '(' ) last_node->type = ATAN;
                    else if (string[i] == 's' && string[i+1] == 'q' && string[i+2] == 'r' && string[i+3] == 't' && string[i+4] == '(' ) last_node->type = SQRT;
                    else return ERROR_OPERATOR;
                    i++;
                }
                else return ERROR_OPERATOR;
                i++;
            }
            else return ERROR_OPERATOR;
            i++;
            last_node->priority = 4;
        }

        previous_char = string[i];

        //create next node
        lexeme *tmp = (lexeme*)calloc(1, sizeof(lexeme));
        tmp->next = NULL;
        tmp->priority = 0;
        tmp->value = 0;
        tmp->type = 0;
        //make connection
        last_node->next = tmp;
        //swith the last_node pointer
        last_node = last_node->next;

    }
}

void print_node_array(const lexeme *root) {
    while (root) {
        printf(" type = %d , priority = %d , value = %lf\n", root->type, root->priority, root->value);
        root = root->next;
    }
}

// Принцип работы алгоритма Дейкстра:
// Проходим исходную строку;
// При нахождении числа, заносим его в выходную строку;
// При нахождении оператора, заносим его в стек;
// Выталкиваем в выходную строку из стека все операторы, имеющие приоритет выше или равный рассматриваемого;
// При нахождении открывающейся скобки, заносим её в стек;
// При нахождении закрывающей скобки, выталкиваем из стека все операторы до открывающейся скобки, а открывающуюся скобку удаляем из стека.


int from_infix_to_postfix (lexeme *root_infix, lexeme *root_postfix) {

    //create stack
    lexeme *stack = (lexeme*)calloc(1, sizeof(lexeme));

    lexeme *curent_postfix = root_postfix; 

int count = 0;
    //теперь смотрим ее и думаем, куда ее засунуть (в стек или в результат)
do {

count++;
printf("\n\ncount = %d\n", count);

    lexeme *curent_infix = copy_one_node(root_infix);
    printf("Curent_infix\n type = %d , priority = %d , value = %lf, next = %p\n", curent_infix->type, curent_infix->priority, curent_infix->value, curent_infix->next);

    //если число или x, то кладем в результат 
    if (curent_infix->type == NUMBER || curent_infix->type == X) {
        printf("NOMBER OR X\n");
        push_in_postfix(&curent_postfix, &curent_infix);
    }
    //если оператор, то заносим его в вершину стека 
    else if (curent_infix->type > 4 ) {
        printf("OPERATOR OR OPEN\n");
        //выталкиваем из стека в результат все опереторы, имеющие приоритет выше или равный нашему
        while (stack != NULL && stack->type > 4 && stack->priority >= curent_infix->priority) {
            printf("выталкиваем\n");
            lexeme *tmp = pop_from_stack(&stack);
            push_in_postfix(&curent_postfix, &tmp);
        }
        //кладем оператор в стек
        push_in_stack(&stack, &curent_infix);

        printf("Stack next = %p\n", stack->next);
    }

    //если открывающая скобка?, просто кладем в стек ее
    if  (curent_infix->type == OPEN_BRACE) {
        push_in_stack(&stack, &curent_infix);
    }

    //если закрывающая скобка, то выталкиваем из стека в результат все до открывающей скобки
    //саму открывающую скобку просто удаляем из стека
    else if (curent_infix->type == CLOSE_BRACE) {
        while(stack != NULL && stack->type != OPEN_BRACE) {
            lexeme *tmp = pop_from_stack(&stack);
            push_in_postfix(&curent_postfix, &tmp);
        }
        pop_from_stack(&stack);
        //мб тут нужно будет зафришить удаленную ноду
    }
    //двигаем инфикс на следующую лексему
    root_infix = root_infix->next;

    printf("stack in count %d\n", count);
    print_node_array(stack);
    printf("result in count %d\n", count);
    print_node_array(root_postfix);

} while (root_infix->next != NULL);


// //все оставшееся в стеке выталкиваем в результат

 while (stack) {
     lexeme *tmp = pop_from_stack(&stack);
//printf("tmp from stack\n type = %d , priority = %d , value = %lf\n", tmp->type, tmp->priority, tmp->value);
     push_in_postfix(&curent_postfix, &tmp);
}



    return 0;
}

// Создаёт новый узел типа lexeme, копирует туда данные из стaрого узла, возвращает указатель на новый узел
lexeme *copy_one_node(lexeme *old_node) {
    lexeme *new_node = (lexeme*)calloc(1, sizeof(lexeme));
    new_node->next = NULL;
    new_node->priority = old_node->priority;
    new_node->value = old_node->value;
    new_node->type = old_node->type;

    return new_node;
}

void push_in_stack (lexeme **stack, lexeme **new_node) {
    (*new_node)->next = *stack;
    *stack = *new_node;
}

lexeme *pop_from_stack (lexeme **stack) {
    lexeme *out;
    out = copy_one_node(*stack);
    *stack = (*stack)->next;

    return out;
}

void push_in_postfix (lexeme **postfix, lexeme** node) {
    (*postfix)->next = *node;
    *postfix = (*postfix)->next;
}


// Проходим постфиксную запись;
// При нахождении числа, парсим его и заносим в стек;
// При нахождении бинарного оператора, берём два последних значения из стека в обратном порядке;
// При нахождении унарного оператора, в данном случае - унарного минуса, берём последнее значение из стека и вычитаем его из нуля, так как унарный минус является правосторонним оператором;
// Последнее значение, после отработки алгоритма, является решением выражения.

double from_postfix_to_result (lexeme *postfix) {
    postfix = postfix->next;
    double result = 0;

    //create stack
    lexeme *stack = (lexeme*)calloc(1, sizeof(lexeme));

    while (postfix) {
        lexeme *node = copy_one_node(postfix);

        //если число, то заносим его в стек
        if (node->type == NUMBER) {
            push_in_stack(&stack, &node);
        }

        //если бинарный оперетор, то берем из стека два верхних числа в обратном порядке и применяем над ними операцию, результат заносим в стек
        else if (node->type >= 5 && node->type <= 12) {
            lexeme* b = pop_from_stack(&stack);
            lexeme* a = pop_from_stack(&stack);

            lexeme* res = (lexeme*)calloc(1, sizeof(lexeme));
            res->next = NULL;
            res->priority = 0;
            res->type = 0;
            res->value = make_operation_for_binary(a, b, node);

            push_in_stack(&stack, &res);

            result = res->value;
            printf("tmp result = %lf\n", result);

        }

        //если унарный оператор, то берем из стека верхнее число и применям к нему операцию, результат заносим в стек
        else if (node->type >= 13) {
            lexeme* a = pop_from_stack(&stack);

            lexeme* res = (lexeme*)calloc(1, sizeof(lexeme));
            res->next = NULL;
            res->priority = 0;
            res->type = 0;
            res->value = make_operation_for_unary(a, node);

            push_in_stack(&stack, &res);

            result = res->value;
            printf("tmp result = %lf\n", result);
        }
    
        postfix = postfix->next;
    }


    return result;
}

double make_operation_for_binary(lexeme *a, lexeme *b, lexeme *operation) {
    double result = 0;

    if (operation->type == PLUS || operation->type == UNARY_PLUS) result = a->value + b->value;
    else if (operation->type == MINUS || operation->type == UNARY_MINUS) result = a->value - b->value;
    else if (operation->type == MULT) result = a->value * b->value;
    else if (operation->type == DIV) result = a->value / b->value;
    else if (operation->type == MOD) result = fmod(a->value, b->value);
    else if (operation->type == POW) {
        printf("\na = %lf b = %lf\n", a->value, b->value);
        result = pow(a->value, b->value);
    }

    return result;
}

double make_operation_for_unary(lexeme *a, lexeme *operation) {
    double result = 0;

    if (operation->type == SIN) result = sin(a->value);
    else if (operation->type == COS) result = cos(a->value);
    else if (operation->type == TAN) result = tan(a->value);
    else if (operation->type == ASIN) result = asin(a->value);
    else if (operation->type == ACOS) result = acos(a->value);
    else if (operation->type == ATAN) result = atan(a->value);
    else if (operation->type == SQRT) result = sqrt(a->value);
    else if (operation->type == LN) result = log(a->value);
    else if (operation->type == LOG) result = log10(a->value);

    return result;
}
