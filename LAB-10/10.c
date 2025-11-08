#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sf, *df;
    char sourceName[100], destName[100];
    char ch;

    printf("Enter the name of the source file (e.g., input.txt): ");
    scanf("%s", sourceName);

    printf("Enter the name of the destination file (e.g., output.txt): ");
    scanf("%s", destName);

    
    sf = fopen(sourceName, "r");
    if (sf == NULL) {
        printf("Error: Cannot open source file '%s'\n", sourceName);
        exit(1);
    }

    
    df = fopen(destName, "w");
    if (df == NULL) {
        printf("Error: Cannot create destination file '%s'\n", destName);
        fclose(sf);
        exit(1);
    }

    
    while ((ch = fgetc(sf)) != EOF) {
        fputc(ch, df);
    }

    printf("File copied successfully from '%s' to '%s'\n", sourceName, destName);

    
    fclose(sf);
    fclose(df);

    return 0;
}
