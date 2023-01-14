

void swap(unsigned char *a, unsigned char *b){
    unsigned char letter_1 = *a, letter_2 = *b;
    /*
    *a = c
    *b = a
    */
   unsigned char number_1 = a + added_elems;


//     a[0][0] = b[0][0];
//     a[0][1] = b[0][1];

//     b[0][0] = temp_1;
//     b[0][1] = temp_2;
}

unsigned char quickSort_partition(unsigned char **array, unsigned char low, unsigned char high){
    unsigned char pivot = array[1][high];
    unsigned char i = low > 0 ? (low - 1) : 0 ;
    for (unsigned char j = low; j < high; j++) {
        if (pivot >= array[1][j]) {
            i++;
            swap(&array[0][i], &array[0][j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort_2D(unsigned char **array, unsigned char low, unsigned char high){
    if (high > low) {
        unsigned char pi = quickSort_partition(array, low, high);

        quickSort_2D(array, low, pi - 1);
        quickSort_2D(array, pi + 1, high);
    }

}
