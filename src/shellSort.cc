#include "myheaders.h"
//shell sort


void shellSort(long data[], int sz){

	int gaps[20];
	int i,j,h,hcount,k;

	// the gaps array store the gaps that we will go through.
	//this loop helps us generate the gaps that we can divide the data array into
	for(h=1, i=0; h<sz; i++){
		gaps[i]=h;
		h=3*h+1;
	}

	//We use the gap in order of largest to smallest
	//this loop will go through the gap array from bottom up
	for (i--; i>=0; i--){
		h=gaps[i];

		//this do through each subarray formed by gap h
		//hcount start at second element of each group
		for(hcount = h; hcount<2*h; hcount++){

			//go through the elements in the current group of gap h
			//moving by h position each time
			for(j=hcount; j<sz; ){
				long temp=data[j];
				k=j;

				//compare temp with elements that is h position away
				//compare and switch these 2 data position if the data we compare is larger than value in temp
				while (k-h >=0 && temp < data[k-h]){
					data[k] = data[k-h];
					k-=h;
				}

				//put temp in it correct position
				data[k] = temp;
				j= j+h;
			}
		}
	}
}
