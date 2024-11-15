%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int isArmstrong(int num){

    int temp=num,sum=0,len=0;
    while(temp!=0){
        temp/=10;
        len++;
    }
    temp=num;

    while(temp!=0){
        int dig = temp %10;
        sum+=pow(dig,len);
        temp/=10;
    }
    return (sum==num);
}

%}

%%
[0-9]+  {
    int num=atoi(yytext);
    if(isArmstrong(num))
        printf("\nArmstrong Number\n");
    else
        printf("\nNot Armstrong Number\n");
    }
\n  {}
.   {}
%%

int main(){
    printf("Enter the Number\n");
    yylex();
    return 1;
}

int yywrap(){
    return 1;
}