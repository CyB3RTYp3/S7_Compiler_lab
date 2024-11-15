%{
#include<stdio.h>
#include<string.h>
int vowelCount,constCount =0,spCount=0;    
%}

%%
[aeiouAEIOU]    {vowelCount++;}
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]    {constCount++;} 
%%

int main(){
    freopen("input.txt","r",stdin);
    yylex();
    printf("Vowel Count := %d Consonants count := %d",vowelCount,constCount);
    return 0;
}

int yywrap(){
    return 1;
}

