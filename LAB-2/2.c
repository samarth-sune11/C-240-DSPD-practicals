#include <stdio.h>
#include <string.h>
#define MAX 10

int s[MAX], top = -1;

void push() {
	int e;
    if (top == MAX - 1)
        printf("Stack Overflow!\n");
    else {
    	printf("enter element to push: ");
    	scanf("%d",&e);
        top++;
        s[top] = e;
        printf("%d pushed into stack\n", e);
    }
}

void pop() {
    if (top == -1)
        printf("Stack Underflow!\n");
    else {
        printf("%d popped from stack\n", s[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
    	int i;
        printf("Stack elements:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", s[i]);
    }
}

void palindrome() {
    char str[50], rev[50];
    int i, j, l;

    printf("Enter a word: ");
    scanf("%s", str);
    l = strlen(str);
    top = -1;
    for (i = 0; i < l; i++)
        s[++top] = str[i];

    for (i = 0; i < l; i++)
        rev[i] = s[top--];
    rev[l] = '\0';

    if (strcmp(str, rev) == 0)
        printf("Palindrome!\n");
    else
        printf("Not Palindrome!\n");
}

int main() {
    int ch;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Check Palindrome\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
              
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

