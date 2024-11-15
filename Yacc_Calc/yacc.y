%{
#include<stdio.h>
int flag =0;
%}

%token num

%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

ArithmeticExpression : E {
    printf("\n Result:= %d\n",$$);
    // return 0;
};

E:E '+' E   {$$=$1+$3;}  |
E '-' E {$$=$1-$3;}  |
E '*' E {$$=$1*$3;}  |
E '/' E {$$=$1/$3;}  |
E '%' E {$$=$1%$3;}  |
'('E')' {$$=$2;} |
num {$$=$1;}
;
%%

void main(){
    printf("Enter the Arithemetic Expression\n");
    yyparse();
    if(flag==0)
        printf("\nThe expression is valid \n");
}

int yyerror(){
    printf("\nerror\n");
    flag=1;
}