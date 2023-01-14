void swap(uint8_t **a, uint8_t **b){
    uint8_t temp_1 = a[0][0], temp_2 = a[0][1];

    a[0][0] = b[0][0];
    a[0][1] = b[0][1];

    b[0][0] = temp_1;
    b[0][1] = temp_2;
}

uint8_t quickSort_partition(uint8_t **array, uint8_t low, uint8_t high){
    uint8_t pivot = array[high][1];
    uint8_t i = (low - 1);
    for (uint8_t j = low; j < high; j++) {
        if (array[j][1] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort_2D(uint8_t **array, uint8_t low, uint8_t high){
    if (low < high) {
        uint8_t pi = quickSort_partition(array, low, high);

        quickSort_2D(array, low, pi - 1);
        quickSort_2D(array, pi + 1, high);
    }

    printf("a");
}
