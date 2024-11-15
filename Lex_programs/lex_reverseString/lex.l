%{
#include<stdio.h>
#include<string.h>

void reverse(char *str){
    int len=strlen(str);
    for(int i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
%}

%%
[a-zA-Z]+ {
        char *temp= yytext;
        reverse(yytext);
        printf("\nThe reverse is %s ",yytext);
        if(strcmp(temp,yytext)==0)
            printf("\nPalindrome \n");
    }
\n  {}
.   {}
%%

int main(){
    printf("Enter the String \n");
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}