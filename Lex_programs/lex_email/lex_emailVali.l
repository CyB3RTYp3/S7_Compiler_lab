%{
#include<stdio.h>
#include<string.h>
#include<ctype.h>
%}

%%
[a-zA-Z0-9_]+@[a-zA-Z0-9_]+[.](com|in|edu)  {printf("Valid Email\n");}
[0-9]{10}   {printf("Valid Number\n");}
.+   {printf("Invalid\n");}
%%

int main(){
    // freopen("input.txt","r",stdin);
    printf("Enter the words \n");
    yylex();
    return 0;

    /*
    FILE *f1=fopen("input.txt","r");
    if(!f1){
     printf("Cannot access file");
     return 0;
    }
    yyin=f1;
    yylex();
    return 0;
    */
}

int yywrap(){
    return 1;
}