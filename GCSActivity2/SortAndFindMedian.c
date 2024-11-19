#include <stdio.h>

int swap(int* a, int i, int j){ //helper function, swaps two ints in an array with each other
    int b;
    b = a[i]; 
    a[i] = a[j];
    a[j] = b;
}

int part(int* a, int l, int h) { //partition helper function for quicksort, splits array into high and low arrays

    int p = a[l];
    int i = l;
    int j = h;

    while (i < j) {
        while (a[i] <= p && i <= h - 1) {
            i++;
        }

        while (a[j] > p && j >= l + 1) {
            j--;
        }
        if (i < j) {
            swap(a, i, j);
        }
    }
    swap(a, l, j);
    return j;
}

void quickSort(int a[], int l, int h) { //quicksort function with recursion, sorts an array of ints in place
    if (l < h) {
        int pi = part(a, l, h);
        quickSort(a, l, pi - 1);
        quickSort(a, pi + 1, h);
    }
}

int main(){ //main routine, implements sort and find median algorithm using quicksort
    int r; //return value
    int a[] = {5, 2, 4, 3, 1, 7, 6};
    int s = sizeof(a) / sizeof(int); 
    quickSort(a, 0, s - 1);

    if (s % 2 == 0){
        r = (a[(s / 2) - 1] + a[s / 2]) / 2;
    } else {
        r = a[s / 2];
    }

    printf("%d", r);
    return r;

}