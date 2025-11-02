#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char q[MAX];
int f = -1, r = -1;

void enq(char x) {
    if (r == MAX - 1) {
        printf("Queue Overflow!\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        q[r] = x;
        printf("%c entered the queue\n", q[r]);
    } else {
        r++;
        q[r] = x;
        printf("%c entered the queue\n", q[r]);
    }
}

void deq() {
    if (f == -1 && r == -1) {
        printf("Queue Underflow!\n");
    } else if (f == r) {
        printf("%c left the queue\n", q[f]);
        f = r = -1;
    } else {
        printf("%c left the queue\n", q[f]);
        f++;
    }
}

void display() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else {
    	int i;
        printf("Queue elements: ");
        for ( i = f; i <= r; i++)
            printf("%c ", q[i]);
        printf("\n");
    }
}

int main() {
    int c;
    char x;
    while (1) {
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                printf("Enter character: ");
                scanf(" %c", &x); 
                enq(x);
                break;

            case 2:
                deq();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}

