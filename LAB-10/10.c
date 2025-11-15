#include <stdio.h>
int main(){
    FILE *fs;
    FILE *fd;
    char ch;
    fs = fopen("input.txt", "r");
    fd = fopen("output.txt", "w");
 
    
    while(1) {
        ch = fgetc(fs);
        if (ch == EOF) {
            break;
        }
        fputc(ch, fd);
    }
    
    fclose(fs);
    fclose(fd);
    printf("Copied successfully!");
    
    return 0;
}

