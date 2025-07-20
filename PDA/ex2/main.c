#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LNULL NULL
#define MAX_SIZE 256



struct node{
    char obj;
    struct node * next;
};

typedef struct node * stack;

static stack temp;


//a fast and simple implementation of a stack
void createEmptyStack();
bool push(char el);
void pop();
char peek();
bool isEmptyStack();
void nextCon(char **);

int main(int argc, char **argv){


    char buff[MAX_SIZE] = {'\0'};
    char *con = buff;

    fgets(buff, MAX_SIZE, stdin);

    while(*con){
        if(*con == '0'){
            push('0');
        }else if(*con == '1'){
            while(*con){
                if(*con == '0'){
                    fprintf(stderr, "The string is not well formed");
                    return -1;
                }else if(*con == '1'){
                    if(isEmptyStack()){
                        fprintf(stderr,"The string is not well formed");
                        return -1;
                    }
                    pop();
                }

                nextCon(&con);
            }
        }
        nextCon(&con);
    }

    if(isEmptyStack()){
        fprintf(stdout, "The string is well formed");
    }else{
        fprintf(stdout, "The string is not well formed");
    }

    return 0;
}


void nextCon(char **var){
    (*var)++;
}

void createEmptyStack(){
    temp = LNULL;
}
bool isEmptyStack(){
    return temp == LNULL;
}

bool push(char el){
    struct node *elemento = malloc(sizeof(struct node));
    if(!elemento) {
        fprintf(stderr, "Malloc error");
        exit(EXIT_FAILURE);
    }
    elemento -> obj = el;
    elemento -> next = LNULL;
    if(isEmptyStack()){
        temp = elemento;
    }else{
        elemento -> next = temp;
        temp = elemento;
    }
    return true;
}

void pop(){
    if(isEmptyStack()){
        return;
    }else{
        struct node * t = temp;
        temp = temp -> next;
        free(t);
    };
}


char peek(){
    if(isEmptyStack()){
        fprintf(stderr, "EmptyStack");
    }else{
        return temp -> obj;
    }
}
