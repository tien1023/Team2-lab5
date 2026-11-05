#include "myheaders.h"

// Bubble sort

void bubbleSort(long data[], int sz){

	//This loop will help us keep track which position we have correctly switch from the top down
	//the amount of fixed position we have sorted
	for(int i=0; i<sz-1;i++){

		//This loop will go through the array from the bottom to all the unsorted element in the array
		for(int j=sz-1; j>i; j--){

			//compare the data from the bottom up to sort the array from minimum to maximum
			if(data[j]<data[j-1]){
				long val = data[j];
				data[j]=data[j-1];
				data[j-1]=val;
			}
		}
	}
}