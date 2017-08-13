#include "mpc.h"
#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

/* declare a buffer for user input of size 2048 */
// the static keyword makes this variable local to this file
//static char input[2048];


/* Use operator string to see which operation to perform */
long eval_op(long x, char* op, long y) {
    if (strcmp(op, "+") == 0 || strcmp(op, "add") == 0) { return x + y; }
    if (strcmp(op, "-") == 0) { return x - y; }
    if (strcmp(op, "*") == 0) { return x * y; }
    if (strcmp(op, "/") == 0) { return x / y; }
    if (strcmp(op, "%") == 0) { return x % y; }
    return 0;
}

long eval(mpc_ast_t* t) {
    if (strstr(t->tag, "number")) {
        return atoi(t->contents);
    }
    
    /* The operator is always the second child */
    char* op = t->children[1]->contents;

    /* We store the third child in `x` */
    long x = eval(t->children[2]);

    /* Iterate the remaining children and combining */
    int i = 3;
    while (strstr(t->children[i]->tag, "expr")) {
        x = eval_op(x, op, eval(t->children[i]));
        i++;
    }

    return x;
}



int main(int argc, char** argv) {

    /* Create some parsers */
    mpc_parser_t* Number = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    mpc_parser_t* Expr = mpc_new("expr");
    mpc_parser_t*  Lispy = mpc_new("lispy");

    /* Define them with the following Language */

    /* Added optional operators and made the grammar recognize decimal numbers */
    mpca_lang(MPCA_LANG_DEFAULT,
            "                                                        \
                number : /-?[0-9?.[0-9]+/ ;                          \
                operator : /add/ | /sub/ | /mul/ | /div/             \
                |'+' | '-' | '*' | '/' | '%' | '^';                  \
                expr : <number> | '(' <operator> <expr>+ ')' ;       \
                lispy : /^/ <operator> <expr>+ /$/ ;                 \
            ",
            Number, Operator, Expr, Lispy);

    
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to exit.\n");

    while(1){
        char* input = readline("lispy> ");
        add_history(input);

        /* Attempt to parse the user input */
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            /* On success print result and delete the AST */

            long result = eval(r.output);
            printf("%li\n", result);

            mpc_ast_delete(r.output);
        } else {
            /* Otherwise print and delete the error */
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);

    }

    /* Undefine and Delete our Parsers */
    mpc_cleanup(4, Number, Operator, Expr, Lispy);





   return 0;
}

