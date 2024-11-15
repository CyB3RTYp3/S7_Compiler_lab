#include<stdio.h>
#include<string.h>

int i=0,j=0,k=0;
char stack[5],arr[15],shift[10],reduce[10];

void check(int len){
    strcpy(reduce,"Reduce->E");
    for(k=0;k<len;k++){
        if(stack[k]=='i' && stack[k+1]=='d'){
            stack[k]='E';
            stack[k+1]='\0';
            printf("\n$%s\t%s$\t%s",stack,arr,reduce);
            j++;
        }
    }
    for(k=0;k<len;k++){
        if(stack[k]=='E' && stack[k+1]=='+'&& stack[k+2]=='E'){
            stack[k]='E';
            stack[k+1]='\0';
            stack[i+2]='\0';
            printf("\n$%s\t%s$\t%s",stack,arr,reduce);
            i=i-2;
        }
    }
     for(k=0;k<len;k++){
        if(stack[k]=='E' && stack[k+1]=='*'&& stack[k+2]=='E'){
            stack[k]='E';
            stack[k+1]='\0';
            stack[i+2]='\0';
            printf("\n$%s\t%s$\t%s",stack,arr,reduce);
            i=i-2;
        }
    }
     for(k=0;k<len;k++){
        if(stack[k]=='(' && stack[k+1]=='E'&& stack[k+2]==')'){
            stack[k]='E';
            stack[k+1]='\0';
            stack[i+2]='\0';
            printf("\n$%s\t%s$\t%s",stack,arr,reduce);
            i=i-2;
        }
    }
}

int main(){
    printf("GRAMMAR is E->E+E \n E->E*E \n E->(E) \n E->id\n");
    printf("Enter the Expression to Evaluate\n");
    scanf("%s",arr);
    int len=strlen(arr);

    strcpy(shift,"SHIFT-->");
    printf("Stack\tinput\tAction\n");

    for(i=0;j<len;j++,i++){

        if(arr[j]=='i' && arr[j+1]=='d'){
            stack[i]=arr[j];
            stack[i+1]=arr[j+1];
            stack[i+2]='\0';
            printf("\n$%s\t%s$\t%sid",stack,arr,shift);
            arr[j]=' ';
            arr[j+1]=' ';
            check(len);
        }
        else{
            stack[i]=arr[j];
            stack[i+1]='\0';
            printf("\n$%s\t%s$\t%ssymbols",stack,arr,shift);
            arr[j]=' ';
            check(len);
        }
    }
    printf("\n");
}

