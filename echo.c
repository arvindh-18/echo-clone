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
        fputs(usg,stderr);
        return -1;
    }
    if(argc<2 || argc>3){
        fputs("Invalid arguments or Use \" \" to pass a sentance\n", stderr);
        fputs(usg,stderr);
        return -1;
    }
    char flag=extFlag(argv);       //store the extracted flag
    size_t argSize;
    if(argc>2) argSize=strlen(argv[2]);   //calculate the size of the string
    else argSize=strlen(argv[1]);           //calculate the size of the string

    //Split outputs based on the flag given
    if(flag=='A'){
        for (int i=0;i<argSize;i++){
            putchar(toupper(argv[2][i]));
        }
        putchar('\n');
    }
    else if(flag=='s'){
        for (int i=0;i<argSize;i++){
            putchar(tolower(argv[2][i]));
        }
        putchar('\n');
    }
    else if(flag==' '){
        for (int i=0;i<argSize;i++){
            putchar((argv[1][i]));
        }
        putchar('\n');
    }
    return 0;
}


