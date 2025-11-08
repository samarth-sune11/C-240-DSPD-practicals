#include<stdio.h>
#define SIZE 7
int main(){
    int hash[SIZE];
    int i,n,key,index;
    for( i=0;i<SIZE;i++){
hash[i] = -1;
}
printf("Enter no. of keys to insert: ");
scanf("%d", &n);
printf("Enter %d keys: ", n);
for (i = 0; i < n; i++) {
    scanf("%d", &key);
    index = key % SIZE;
    while (hash[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hash[index] = key;
}
printf("\n Final Hash Table: \n");
for (int i = 0; i < SIZE; i++) {
    printf("%d\t", hash[i]);
}
return 0;
}