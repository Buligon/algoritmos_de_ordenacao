#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataS {
    int *data;
    int dataLength;
    char type[4];
} dataS;

char* fileName(struct dataS result) {
    char *fileName, *numToStr;

    int strLength = snprintf(NULL, 0, "%d", result.dataLength);
    numToStr = (char *)malloc(strLength + 1); 

    if (numToStr == NULL)
        return NULL;
    
    sprintf(numToStr, "%d", result.dataLength);

    fileName = (char *) malloc(sizeof(char) * result.dataLength + 4);

    if (fileName == NULL) {
        free(numToStr);
        return NULL;
    }
    
    strcpy(fileName, result.type);

    strcat(fileName, numToStr);
    strcat(fileName, ".txt");

    free(numToStr);
    
    return fileName;
}

struct dataS readFile(struct dataS result) {
    FILE *file;

    file = fopen(fileName(result), "r");
    if (file == NULL) {
        printf("\nErro ao abrir arquivo!\n");
        struct dataS errorValue = { NULL, 0 }; // Define an error struct dataS
        return errorValue;
    }

    char *buffer = (char *)malloc(result.dataLength + 1);
    if (buffer == NULL) {
        printf("\nErro ao alocar memoria para o buffer de leitura do arquivo!\n");
        fclose(file);
        struct dataS errorValue = { NULL, 0 }; // Define an error struct dataS
        return errorValue;
    }

    int *data = (int *)malloc(result.dataLength * sizeof(int));
    if (data == NULL) {
        printf("\nErro ao alocar memoria para o array de numeros!\n");
        free(buffer);
        fclose(file);
        struct dataS errorValue = { NULL, 0 };
        return errorValue;
    }

    int index = 0, aux = 0;

    while (fgets(buffer, result.dataLength + 1, file) != NULL) {
        aux = atoi(buffer); // atoi == ASCII to Integer.

        data[index++] = aux;
    }

    free(buffer);
    fclose(file);

    result.data = data;

    return result;
}