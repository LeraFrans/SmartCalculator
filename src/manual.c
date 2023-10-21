#include "SmartCalc_v1.0.h"

int main() {
    char value[256] = {'\0'};
    //char *tmp = "2^3+3/(1+3)*2";
    char *tmp = "2^3+sin(3/(1+3)*2)";

    for (int i = 0; i<strlen(tmp); i++) value[i] = tmp[i];

    struct lexeme root;
                root.next = NULL;
                root.priority = 0;
                root.value = 0;
                root.type = 0;

    make_lexeme_array(value, &root);
    printf("INFIX:\n");
    print_node_array(&root);



    lexeme *postfix = (lexeme*)calloc(1, sizeof(lexeme));
        // postfix->next = NULL;
        // postfix->priority = 0;
        // postfix->value = 0;
        // postfix->type = 0;

    from_infix_to_postfix (&root, postfix);
    //printf("HHHHH\n");
    printf("\n\n\nPOSTFIX:\n");
    print_node_array(postfix);

    double calc_result = 0;
    calc_result = from_postfix_to_result (postfix);
    printf("\n\nCALC_RESULT = %lf\n", calc_result);

}