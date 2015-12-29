#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

struct Stack
{
    int data[MAXSIZE];
    int top;
};
typedef struct Stack Stack;

Stack *initStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

int isEmpty (Stack *s) {
    return s->top == -1;
}

/*  Function to add an element to the Stack */
void push (int e, Stack *s) {
    if (s->top < MAXSIZE) {
        s->data[++s->top] = e;
    }
    else
        fprintf(stderr, "Error: Stack is full.\n");
}

/*  Function to delete an element from the Stack */
int pop (Stack *s) {
    if (s->top == -1) {
        fprintf(stderr, "Error: Stack is empty.\n");
        return -1;
    }
    return s->data[s->top--];
}

/*  Function to display the status of the Stack */
void display (Stack *s) {
    int i;
    if (s->top == -1) {
        fprintf (stderr, "Stack is empty\n");
        return;
    }
    else {
        printf ("\n The status of the stack is \n");
        for (i = s->top; i >= 0; i--) {
            printf ("%d\n", s->data[i]);
        }
    }
    printf ("\n");
}