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