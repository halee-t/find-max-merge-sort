#include <stdio.h>
#include <stdlib.h>


void populateArray(int numData[]) {				//populate the array with random numbers 1-100

    for (int i = 0; i < 250; i++) {
        numData[i] = rand() % 100;
    }

    printf("Contents of numData: \n");				//print the array to output

    for (int i = 0; i < 250; i++) {
        printf("%d ", numData[i]);
    }

    printf("\n");
    printf("\n");

}

void Merge(int array[], int start, int mid, int end) {
    int i, j, k;
    int aSize = mid - start + 1;                                //arrayA is the first half
    int bSize = end - mid;                                      //arrayB is the second half
    int arrayA[aSize];
    int arrayB[bSize];

    for (i = 0; i < aSize; i++) {                              //populate arrayA with the first half of array
        arrayA[i] = array[start + i];
    }

    for (j = 0; j < bSize; j++) {                              //populate arrayB with the second half of array
        arrayB[j] = array[mid + 1 + j];
    }

    //reset from for loops
    i = 0;
    j = 0;
    k = start;
 


    while ((i < aSize) && (j < bSize)) {                      //populate sorted array while i and j are less than the size of their respective arrays      
        
        if (arrayA[i] <= arrayB[j]) {
            array[k] = arrayA[i];
            i++;                                              //INCREASE THE COUNT
        }

        else {
            array[k] = arrayB[j];
            j++;                                              //INCREASE THE COUNT
        }

        k++;                                                  //INCREASE THE COUNT

    }
   
    while (i < aSize) {                                       //In case anything is left over, fill it in
        array[k] = arrayA[i];
        i++;
        k++;
    }

    while (j < bSize) {                                       //In case anything is left over, fill it in
        array[k] = arrayB[j];
        j++;
        k++;
    }

}

void MergeSort(int a, int b, int array[]) {

    if (a < b) {

        int distance = b - a;                                   //calculate the distance between start and end of array
        int halfDistance = a + ((distance) / 2);                //find the midpoint

        MergeSort(a, halfDistance, array);                      //first half recurrsion
        MergeSort(halfDistance + 1, b, array);                 //second half recurrsion

        Merge(array, a, halfDistance, b);                      //when recurrsion is done, call merge
    }
}

void findMax(int numData[]) {

    int i = 0;
    int j = 250;

    MergeSort(i, j-1, numData);					//use merge sort to sort the array

    printf("Greatest Integer: %d", numData[249]);		//to find the greatest integer, use the last element of the sorted array (249)
    
}