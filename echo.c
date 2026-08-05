//This program mimics echo command used in linux
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char extFlag(char* arg[]);                    //extract flag function declaration
char *usg="USAGE : echox [flag] STRING \n";   //Display error message

//Definig extFlag function
char extFlag(char* arg[]){
    if (strcmp(arg[1], "-A") == 0 || (strcmp(arg[1], "-s") == 0)){
        return arg[1][1];
    }
    return ' ';
}


int main(int argc, char *argv[]){
    if (argc==1){
        printf("%s",usg);
        return -1;
    }
    if(argc<2 || argc>3){
        printf("Invalid arguments or Use \" \" to pass a sentance\n");
        printf("%s",usg);
        return -1;
    }
    char flag=extFlag(argv);       //store the extracted flag
    int argSize=strlen(argv[2]);   //calculate the size of the string

    //Split outputs based on the flag given
    if(flag=='A'){
        for (int i=0;i<argSize;i++){
            putchar(toupper(argv[2][i]));
        }
        printf("\n");
    }
    else if(flag=='s'){
        for (int i=0;i<argSize;i++){
            putchar(tolower(argv[2][i]));
        }
        printf("\n");
    }
    else if(flag==' '){
        for (int i=0;i<argSize;i++){
            putchar((argv[1][i]));
        }
        printf("\n");
    }
    return 0;
}


