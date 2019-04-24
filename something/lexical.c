#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct lexical_analyser{
    char tokens[50];
    char type[50];
}lex;
lex lex_table[20];
void main(){
    char str[100];
    int i=0;
    FILE *ptr;
    ptr=fopen("lexical_input.txt","r");
    if(ptr==NULL){
        printf("Error");
        exit(1);
    }
    while(fscanf(ptr,"%s",str)==1) {
        if (strcmp(str,"while")==0 || strcmp(str,"do")==0 || strcmp(str,"for")==0 || strcmp(str,"if")==0
        || strcmp(str,"else")==0 || strcmp(str,"break")==0 || strcmp(str,"int")==0 || strcmp(str,"void")==0
        || strcmp(str,"char")==0 || strcmp(str,"continue")==0 || strcmp(str,"switch")==0 || strcmp(str,"long")==0
        || strcmp(str,"float")==0 || strcmp(str,"goto")==0 || strcmp(str,"struct")==0 || strcmp(str,"typedef")==0){
            //printf("%s-> is a keyword\n", str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is a keyword");
            i++;
        } else if ((str[0]>='A' && str[0]<='Z') || (str[0]>='a' && str[0]<='z')) {
            //printf("%s -> is an identifier\n", str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is an identifier");
            i++;
        } else if (strcmp(str,">")==0 || strcmp(str,"<")==0 || strcmp(str,">=")==0 || strcmp(str,"<=")==0
                    || strcmp(str,"==")==0 || strcmp(str,"!=")==0) {
            //printf("%s -> is a relational operator\n", str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is a relational operator");
            i++;
        } else if (strcmp(str,":=")==0 || strcmp(str,"=")==0 || strcmp(str,"+=")==0 || strcmp(str,"-=")==0
                    || strcmp(str,"*=")==0 || strcmp(str,"/=")==0 || strcmp(str,"%=")==0 || strcmp(str,"<<=")==0
                    || strcmp(str,">>=")==0 || strcmp(str,"|=")==0 || strcmp(str,"&=")==0 || strcmp(str,"^=")==0) {
            //printf("%s -> is an assignment operator\n", str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is an assignment operator");
            i++;
        } else if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
                    str[0] == '3' || str[0] == '4' || str[0] == '5' ||
                    str[0] == '6' || str[0] == '7' || str[0] == '8' ||
                    str[0] == '9'){
            //printf("%s -> is a constant\n");
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is a constant");
            i++;
        } else if (strcmp(str,"+")==0|| strcmp(str,"*")==0 || strcmp(str,"-")==0 || strcmp(str,"/")==0
                    || strcmp(str,"%")==0) {
            //printf("%s -> is an arithmetic operator\n",str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is an arithmetic operator");
            i++;
        } else if(strcmp(str,"&")==0 || strcmp(str,"|")==0 || strcmp(str,"^")==0 || strcmp(str,">>")==0
                    || strcmp(str,"<<")==0 || strcmp(str,"~")==0){
            //printf("%s -> is a bitwise operator\n",str);
            strcpy(lex_table[i].tokens,str);
            strcpy(lex_table[i].type,"is a bitwise operator");
            i++;
        }
    }
    for (int j = 0; j < i; j++) {
        printf("%s -> %s\n",lex_table[j].tokens,lex_table[j].type);
    }
    fclose(ptr);
}
