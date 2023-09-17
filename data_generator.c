#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

int genDataOrd(char *fileName, int dataLength) {
    FILE *file;
    int i;

    file = fopen(fileName, "a");

    if (file == NULL) {
        printf("\nErro ao abrir arquivo para gerar dados.\n");
        return 1;
    }

    for (i = 0; i < dataLength; i++) {
        fprintf(file, "%i\n", i);
    }

    fclose(file);

    return 0;
}

int genDataInv(char *fileName, int dataLength) {
    FILE *file;
    int i;

    file = fopen(fileName, "a");

    if (file == NULL) {
        printf("\nErro ao abrir arquivo para gerar dados.\n");
        return 1;
    }

    for (i = dataLength - 1; i >=0; i--) {
        fprintf(file, "%i\n", i);
    }

    fclose(file);

    return 0;
}

int genDataRdm(char *fileName, int dataLength) {
    FILE *file;
    int i;

    file = fopen(fileName, "a");

    if (file == NULL) {
        printf("\nErro ao abrir arquivo para gerar dados.\n");
        return 1;
    }

    for (i = 0; i < dataLength; i++) {
        fprintf(file, "%i\n", rand());
    }

    fclose(file);

    return 0;
}

char* nameFile(int dataLength, int dataType) {
    char *fileName, *numToStr;

    int strLength = snprintf(NULL, 0, "%d", dataLength); // Calcula o tamanho do número
    numToStr = (char *)malloc(strLength + 1); 

    if (numToStr == NULL)
        return NULL;
    
    sprintf(numToStr, "%d", dataLength); // Converte o inteiro para string

    fileName = (char *) malloc(sizeof(char) * dataLength + 4);

    if (fileName == NULL) {
        free(numToStr);
        return NULL;
    }
    
    switch (dataType) {
        case 1:
            strcpy(fileName, "ord");
            break;
        case 2:
            strcpy(fileName, "inv");
            break;
        case 3:
            strcpy(fileName, "rdm");
            break;
        default:
            free(numToStr);
            free(fileName);
            return NULL;
    }

    strcat(fileName, numToStr);
    strcat(fileName, ".txt");

    free(numToStr);
    
    return fileName;
}

int createFile(int dataLength, int dataType) {
    FILE *file;
    char *fileName;

    fileName = nameFile(dataLength, dataType);

    if (fileName == NULL) {
        printf("Erro ao criar nome do arquivo.\n");
        return 1;
    }

    file = fopen(fileName, "w");

    if (file == NULL) {
        perror("\nErro ao criar arquivo.\n");
        return 1;
    }

    fclose(file);

    switch (dataType) {
        case 1:
            genDataOrd(fileName, dataLength);
            break;
        case 2:
            genDataInv(fileName, dataLength);
            break;
        case 3:
            genDataRdm(fileName, dataLength);
            break;
        default:
            break;
    }

    printf("\nArquivo %s criado com sucesso!\n", fileName);

    free(fileName);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <data_type> <data_length>\n", argv[0]);
        return 1;
    }

    int dataType = atoi(argv[1]);
    int dataLength = atoi(argv[2]);

    /* do {
        printf("Informe o tipo do arquivo:\n1\t-\tOrdenado\n2\t-\tInvertido\n3\t-\tRandomico\n");
        scanf("%i", &dataType);
    } while (dataType != 1 && dataType != 2 && dataType != 3);
    
    do {
        printf("Informe o tamanho do arquivo:");
        scanf("%i", &dataLength);
    } while (dataLength <= 0); */
    
    createFile(dataLength, dataType);

    return 0;
}