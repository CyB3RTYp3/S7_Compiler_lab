#include<stdio.h>
#include<string.h>

int E(),Edash(),T(),Tdash(),F();

char string[64];
const char *cursor;

int main(){
    printf("Enter the string\n");
    scanf("%s",string);

    cursor = string;
    printf("\n");
    printf("Input		 Action\n");
	printf("--------------------------------\n");

    if(E() && *cursor == '\0'){
        printf("\n Successfully parsed\n");
        return 0;
    }
    printf("\n cannot parsde the string \n");
    return 0;
}

int E(){
    printf("%-16s E-->TE' \n",cursor);
    if(T()){
        if(Edash())
            return 1;
        return 0;
    }
    return 0;
}

int Edash(){
    if(*cursor == '+'){
        printf("%-16s E-->+TE'\n",cursor);
        cursor++;
        if(T()){
            if(Edash())
                return 1;
            return 0;
        }
        return 0;
    }
    printf("%-16s E-->$\n",cursor);
    return 1;
}

int T(){
    printf("%-16s T-->FT'\n",cursor);
    if(F()){
        if(Tdash())
            return 1;
        return 0;
    }
    return 0;
}

int Tdash(){
    if(*cursor == '*'){
        printf("%-16s T-->*FT'\n",cursor);
        cursor++;
        if(F()){
            if(Tdash())
                return 1;
            return 0;
        }
        return 0;
    }
    printf("%-16s T-->$\n",cursor);
    return 1;
}

int F(){
    if(*cursor == '('){
        printf("%-16s F-->(E)\n",cursor);
        cursor++;
        if(E())
            if(*cursor == ')'){
                cursor++;
                return 1;
            }
            return 0;
        return 0;
    }
    else if(*cursor == 'i'){
        printf("%-16s F-->id \n",cursor);
        cursor++;
        return 1;
    }
    return 0;
}