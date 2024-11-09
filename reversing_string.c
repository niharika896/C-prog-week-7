#include <stdio.h>
#include <string.h>

void Reverse(char *str, char *rev){
    int n=strlen(str);
    for(int i=0;str[i]!='\0';i++){
        rev[i]=str[n-i-1];
    }
}
int main(){
    char str[100],rev[100]={'\0'};
    printf("Enter a string:");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")]='\0';
    Reverse(str,rev);
    printf("%s",rev);
}
