#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdint.h>
#include "../quicksort.c"

extern unsigned char added_elems;

void swap(uint8_t *a, uint8_t *b);

uint8_t quickSort_partition(uint8_t **array, uint8_t low, uint8_t high);

void quickSort_2D(uint8_t **array, uint8_t low, uint8_t high);



#endif