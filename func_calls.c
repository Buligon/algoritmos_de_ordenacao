#include "sorting_algorithms.h"
#include "open_file.h"
#include <windows.h>

struct results {
    double bubble;
    double insertion;
    double selection;
    double shell;
    double quick;
    double merge;
    double radix;
    double heap;
};


const int LENGTH[5] = {100000, 200000, 300000, 500000, 1000000};
const char TYPES[3][4] = {{"ord\0"},
                        {"inv\0"},
                        {"rdm\0"}};

int main(void) {
    int len_idx, type_idx;
    LARGE_INTEGER frequency, start, end;

    QueryPerformanceFrequency(&frequency);
    
    for (len_idx = 0; len_idx < 5; len_idx++)
        for (type_idx = 0; type_idx < 3; type_idx++) {
            struct dataS data;
            struct results results;

            data.dataLength = LENGTH[len_idx];
            strncpy(data.type, TYPES[type_idx], sizeof(data.type));
            data = readFile(data);

            if (data.data == NULL) {
                printf("Erro ao ler arquivo.\n");
                return 1;
            }

            QueryPerformanceCounter(&start);
            bubbleSort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.bubble = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            selectionSort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.selection = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;
            
            QueryPerformanceCounter(&start);
            insertionSort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.insertion = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            shellSort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.shell = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            quicksort(data.data, 0, data.dataLength-1);
            QueryPerformanceCounter(&end);
            results.quick = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            mergesort(data.data, 0, data.dataLength-1);
            QueryPerformanceCounter(&end);
            results.merge = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            radixsort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.radix = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;

            QueryPerformanceCounter(&start);
            heapsort(data.data, data.dataLength);
            QueryPerformanceCounter(&end);
            results.heap = ((double)(end.QuadPart - start.QuadPart)) / frequency.QuadPart * 1000.0;
 
            FILE *file;

            file = fopen("resultados.txt", "a");

            if (file == NULL) {
                printf("\nErro ao gravar dados!\n");
                return 1;
            }

            fprintf(file, "%i;%s;%.6f;%.6f;%.6f;%.6f;%.6f;%.6f;%.6f;%.6f\n", len_idx, TYPES[type_idx], results.bubble, results.insertion, results.selection, results.shell, results.quick, results.merge, results.radix, results.heap);

            fclose(file);
        }

    return 0;
}