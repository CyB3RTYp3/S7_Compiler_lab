#include<stdio.h>
#include<string.h>
#include<ctype.h>

char keyword[10][10]= {"do","while","int","for","printf","main","if","else"};
int line=0,token=0;
char ch,str[20];
int i,flag;

int main(){
    FILE *fp1=fopen("input.txt","r");
    FILE *fp2=fopen("Output.txt","w");
    fprintf(fp2,"Line No \t token \t lexeme \n");

    while(!feof(fp1)){
        i=0;flag=0;
        ch=fgetc(fp1);

        if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='%'){
            fprintf(fp2,"%d \t %d \t Logical Operator \t %c\n",line,token,ch);
            token++;
        }

        if(ch ==';'||ch=='&'||ch=='('||ch==')'||ch=='#'||ch=='{'||ch=='}'){
            fprintf(fp2,"%d \t %d \t special Symbol \t %c\n",line,token,ch);
            token++;
        }
        if(isdigit(ch)){
            fprintf(fp2,"%d \t %d \t Digit \t %c\n",line,token,ch);
            token++;
        }
        if(ch=='\n'){
            line++;
        }
        if(isalpha(ch)){
            str[i]=ch;
            i++;

            ch=fgetc(fp1);

            while (isalnum(ch)&& ch!=' ')
            {
                str[i]=ch;
                i++;
                ch=fgetc(fp1);
            }

            str[i]='\0';

            for(int j=0;j<10;j++){
                if(strcmp(str,keyword[i])==0){
                    flag==1;
                    break;
                }
            }

            if(flag==1){
                fprintf(fp2,"%d \t %d \t Keyword\t %s\n",line,token,str);
                 token++;
            }
            else{
                fprintf(fp2,"%d \t %d \t Identifier \t %s\n",line,token,str);
                token++;
            }
            
        }

    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
