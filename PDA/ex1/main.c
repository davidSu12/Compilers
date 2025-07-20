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

int main(int argc, char **argv){

    char buff[256] = {'\0'};

    fgets(buff, MAX_SIZE, stdin);

    char *com = buff;

    while(*com){
        if(*com == '('){
            push('(');
        }else if(*com == ')'){
            if(isEmptyStack()){
                printf("String on bad format\n");
                return 0;
            }
            pop();
        }
        com++;
    }

    if(isEmptyStack()){
        printf("String on right format\n");
    }else{
        printf("String on bad format\n");
    }

    return 0;
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
        fprintf(stderr, "Empty stack");
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

