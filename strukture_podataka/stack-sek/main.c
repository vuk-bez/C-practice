// sekvencijalna reprezentacija stacka
#include <stdio.h>
#include <stdlib.h>

int top; //vrh stacka
int size;

int* initStack() {
    int* niz = malloc(sizeof(int) * size);
    top = -1;
    return niz;
}

void push(int* niz, int x) {
    if (top == size - 1) {
        printf("stack overflow\n");
        return;
    } else {
        top = top + 1;
        niz[top] = x;
    }
}

int pop(int* niz) {
    if (top == -1) {
        printf("stack underflow\n");
        return -1;
    } else {
        int h = niz[top];
        top = top - 1;
        return h;
    }
}

int stackEmpty(int* niz) {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int stackTop(int* niz) {
    if (top == -1) {
        return -1;
    } else {
        return niz[top];
    }
}

int main() {

    scanf("%d", &size);
    int* stack1 = initStack();

    push(stack1, 1);
    push(stack1, 2);
    push(stack1, 3);
    printf("%d", pop(stack1));

    return 0;
}
