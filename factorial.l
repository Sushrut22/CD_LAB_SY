%{
#include <stdio.h>
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}
%}

%%
[0-9]+ {
    int n = atoi(yytext);
    printf("Factorial of %d is %d\n", n, factorial(n));
}
%%

int yywrap(){}

int main() {
    yylex();
    return 0;
}
