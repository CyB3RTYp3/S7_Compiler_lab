#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct expr {
    char op[2],arg1[5],arg2[5],res[5];
    int flag;
}arr[10];
int len;

void change(int p, char *res){
    for(int i=p+1;i<len;i++){
        if(strcmp(arr[i].arg1,arr[p].res)==0){
            strcpy(arr[i].arg1,res);
        }
         if(strcmp(arr[i].arg2,arr[p].res)==0){
            strcpy(arr[i].arg2,res);
        }
    }
}

void check(){
    char res1[5],op;
    int arg1,arg2,res;
    for(int i=0;i<len;i++){
        if(isdigit(arr[i].arg1[0]) && isdigit(arr[i].arg2[0]) || strcmp(arr[i].op,"=") == 0){
            arg1 = atoi(arr[i].arg1);
            arg2 = atoi(arr[i].arg2);
            op=arr[i].op[0];

            switch(op){
                case '+':
                    res=arg1+arg2;
                    break;
                case '-':
                     res = arg1 - arg2;
                    break;
                case '*':
                    res = arg1 * arg2;
                    break;
                case '/':
                    res = arg1 / arg2;
                    break;
                case '=':
                    res = arg1;
                    break;
            }
            sprintf(res1,"%d",res);
            arr[i].flag=1;
            change(i,res1);
        }
    }
}

int main(){ 
    printf("Enter the no . of expr \n");
    scanf("%d",&len);

    printf("Enter the code Segment \n");
    for(int i=0;i<len;i++){
        scanf("%s %s %s %s",arr[i].op,arr[i].arg1,arr[i].arg2,arr[i].res);
        arr[i].flag=0;
    }

    check();

    printf("The Optimised code Segment is\n");
    for(int i=0;i<len;i++){
        if(!arr[i].flag)
            printf("%s %s %s %s\n",arr[i].op,arr[i].arg1,arr[i].arg2,arr[i].res);
    }

}