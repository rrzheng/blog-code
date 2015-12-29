#define MAXSIZE 10

struct Stack
{
    int data[MAXSIZE];
    int top;
};
typedef struct Stack Stack;

Stack *initStack();
int isEmpty (Stack *s);
void push(int e, Stack *s);
int  pop(Stack *s);
void display(Stack *s);