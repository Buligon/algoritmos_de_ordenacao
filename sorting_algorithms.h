#include <stdlib.h>
#include <stdio.h>

// Geeks for geeks video: https://www.youtube.com/watch?v=nmhjrI-aW5o
int bubbleSort(int *data, int dataLength) {
    int i, j;

    for (i = 0; i < dataLength - 1; i++) 
        for (j = 0; j < dataLength - i - 1; j++)
            if (data[j] > data[j + 1]) {
                int aux = data[j];
                data[j] = data[j + 1];
                data[j + 1] = aux;
            }

    return 0;
}

// Geeks for geeks video: https://www.youtube.com/watch?v=OGzPmgsI-pQ&t=41s
int insertionSort(int *data, int dataLength) {
    int i, element, j;
   
    for (i = 1; i < dataLength; i++) {
        element = data[i];
        j = i - 1;
 
        while (j >= 0 && data[j] > element) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = element;
    }

    return 0;
}

// Geeks for geeks video: https://www.youtube.com/watch?v=xWBP4lzkoyM
int selectionSort(int *data, int dataLength) {
    int i, j, start;
    
    for (i = 0; i < dataLength-1; i++) {
        start = i;

        for (j = i+1; j < dataLength; j++)
            if (data[j] < data[start])
                start = j;
 
            if(start != i) {
                int aux = data[start];
                data[start] = data[i];
                data[i] = aux;
            }
    }

    return 0;
}

// Geeks for geeks video: https://www.youtube.com/watch?v=SHcPqUe2GZM
int shellSort(int *data, int dataLength) {
    int gap, i;

    for (gap = dataLength/2; gap > 0; gap /= 2) 
        for (i = gap; i < dataLength; i += 1) {
            int aux = data[i], j;

            for (j = i; j >= gap && data[j - gap] > aux; j -= gap)
                data[j] = data[j - gap];
              
            data[j] = aux;
        }

    return 0;
}

// Geeks for geeks video: https://www.youtube.com/watch?v=PgBzjlCcFvc
int quicksort(int *data, int start, int end) {
    if (start < end) {
        int pivot = data[end], i, j, aux;
    
        for (j = start, i = (start - 1); j <= end - 1; j++) {
            if (data[j] < pivot) {
                i++;
                aux = data[i];
                data[i] = data[j];
                data[j] = aux;
            }
        }

        aux = data[i + 1];
        data[i + 1] = data[end];
        data[end] = aux;

        int pi = (i + 1);
        if (pi - 1 > 0 || pi + 1 > end)
            return 1;
        quicksort(data, start, pi - 1);
        quicksort(data, pi + 1, end);
    }

    return 0;
}

// Geeks for geeks video: https://www.youtube.com/watch?v=JSceec-wEyw
void mergesort(int *data, int start, int end) {
    if (start < end) {
        int middle = start + (end - start) / 2;
 
        mergesort(data, start, middle);
        mergesort(data, middle + 1, end);
 
        int i, j, k, n1 = middle - start + 1, n2 = end - middle;
    
        int *left = (int *)malloc(n1 * sizeof(int));
        int *right = (int *)malloc(n2 * sizeof(int));
    
        for (i = 0; i < n1; i++)
            left[i] = data[start + i];

        for (j = 0; j < n2; j++)
            right[j] = data[middle + 1 + j];
    
        i = 0;
        j = 0;
        k = start;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                data[k] = left[i];
                i++;
            }
            else {
                data[k] = right[j];
                j++;
            }
            k++;
        }
    
        while (i < n1) {
            data[k] = left[i];
            i++;
            k++;
        }
    
        while (j < n2) {
            data[k] = right[j];
            j++;
            k++;
        }
        free(left);
        free(right);
    }

}

// Geeks for geeks video: https://www.youtube.com/watch?v=nu4gDuFabIM
void radixsort(int *data, int dataLength) {
    int i, higher = data[0], exp = 1;

    int *b;
    b = (int *)calloc(dataLength, sizeof(int));

    for (i = 0; i < dataLength; i++) {
        if (data[i] > higher)
    	    higher = data[i];
    }

    while (higher/exp > 0) {
        int bucket[10] = { 0 };

    	for (i = 0; i < dataLength; i++)
    	    bucket[(data[i] / exp) % 10]++;

    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

    	for (i = dataLength - 1; i >= 0; i--)
    	    b[--bucket[(data[i] / exp) % 10]] = data[i];

    	for (i = 0; i < dataLength; i++)
    	    data[i] = b[i];

    	exp *= 10;
    }

    free(b);
}

void heapify(int *data, int dataLength, int i) {
    int largest = i;
    int left = 2 * i + 1, right = 2 * i + 2;
 
    if (left < dataLength && data[left] > data[largest])
        largest = left;
 
    if (right < dataLength && data[right] > data[largest])
        largest = right;
   
    if (largest != i) {
        int aux = data[i];
        data[i] = data[largest];
        data[largest] = aux;
 
        heapify(data, dataLength, largest);
    }
}

// Geeks for geeks video: https://www.youtube.com/watch?v=MtQL_ll5KhQ
void heapsort(int *data, int dataLength) {
    int i;
    for (i = dataLength / 2 - 1; i >= 0; i--)
        heapify(data, dataLength, i);
 
    for (i = dataLength - 1; i >= 0; i--) {
        int aux = data[0];
        data[0] = data[i];
        data[i] = aux;

        heapify(data, i, 0);
    }
}