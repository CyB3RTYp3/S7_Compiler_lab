%{
int COMMENT =0;
%}

identifier  [a-zA-Z][a-zA-Z0-9]*;


%%
#.*  {printf("%s This is a preprocessor \n",yytext);}
int |
float   |
typedef |
while   |
double  |
char    |
if  |
else    |
do  |
void    |
break   |
return  |
printf  |
goto    {printf("%s is a keyword \n",yytext);}
"/*"    {COMMENT=1;}{printf("Comment starts \n");}
"*/"    {COMMENT=0;}{printf("Comment ends \n");}
{identifier}\( {if(!COMMENT) printf("\n FUNCTION \n \t %s",yytext);}
\{  {if(!COMMENT)printf("Block Begins \n");}
\}  {if(!COMMENT)printf("Block ends \n");}
{identifier}(\[[0-9]*\])?    {if(!COMMENT)printf("%s is a identifier \n",yytext);}
\".*\"  {if(!COMMENT)printf("%s is a string \n",yytext);}
[0-9]+  {if(!COMMENT)printf("%s is a Number \n",yytext);}
\)(\:)? {if(!COMMENT)printf("\n");}
=   {if(!COMMENT)printf("\n%s is a Assignment operator \n",yytext);}
\<= |
\>= |
\< |
== |
\> {if(!COMMENT) printf("\n\t%s is a RELATIONAL OPERATOR\n",yytext);}
\+ |
\- |
\* |
\/ |
\% {if(!COMMENT) printf("\n\t%s is a Logical OPERATOR\n",yytext);}
%%

int main(){
    FILE *f=fopen("var.c","r");
    if(!f){
        printf("Could not print");
        return 0;
    }
    yyin=f;
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}