#include <stdio.h>
#include <stdlib.h>


#define MAX_LEN 256


void proc(char *str);


int main(int argc, char **argv){

    char buff[MAX_LEN] = {'\0'};
    fgets(buff, MAX_LEN, stdin);


    proc(buff);

    return 0;
}


void proc(char *str){

    if(*str == '\0'){
        return;
    }

    if(*str == '+'){
        printf("%c", *(str + 1));
        printf("+");
        proc(str + 2);
    }else if(*str == '-'){
        printf("%c", *(str+1));
        printf("-");
        proc(str + 2);
    }else{
        printf("%c", *str);
        proc(str+1);
    }

}