// Copyright (C) 2025 Sarvesh Kulkarni <sarvesh.kulkarni@villanova.edu>
// If you are a student in the ECE 2161 lab, you may use this code.
// Permission is NOT granted to use this code for non-educational purposes.
// Write code for bubble sort and merge sort and call the functions in main.

// WARNING! WARNING! WARNING!
//  This program declares *very* large arrays. If you have not increased your
//  stack space, expect a segmentation fault. In order to increase your
//  stack space, run the following command from your terminal:
//  ulimit -s 819200

#include <iostream>
#include <ctime>
#include "myheaders.h"

using namespace std;


int main() {
    int choice = 0;
    int sz = 0;

    // Store large arrays outside the stack.
    static long data[MAXSIZE], wData[MAXSIZE];

    double begin_time, end_time, cpu_time_used;
    string ifilename, ofilename;

    while (true) {
        printmenu();

        if (!(cin >> choice)) {
            cerr << "ERROR: Please enter a number." << endl;
            return 1;
        }

        switch (choice) {

            case 1: // Load the original input data.
                ifilename = "lab5_input.txt";
                sz = readfile(ifilename, data);

                if (sz < 0) {
                    cerr << "ERROR: Input file could not be opened."
                         << endl;
                    return 1;
                }

                cout << "File size is: " << sz << endl;
                break;

            case 2: // Bubble sort

                    // First, copy the contents of the array 'data' to the working array 'wData'. Your program should sort 'wData' and not 'data'.
                    for(int i = 0; i<sz; i++){
                    	wData[i] = data[i];
                    }

					begin_time = clock();   // start cpu timer

					// Call your Sort function A here to sort the array 'wData''
			        //  Note that 'wData' is of size 'sz' (see case 1).
					bubbleSort(wData, sz);


					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "BubbleSort ran for " << cpu_time_used << " secs.";

                    // Menu option 2 goes to Bubble Sort
					ofilename = "bubbleSort_out.txt";
					writefile(wData, sz, ofilename);

					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;

					break;

			case 3: // Shell sort

			        // First, copy the contents of the array 'data' to the working array 'wData'. Your program should sort 'wData' and not 'data'.

				for(int i = 0; i<sz; i++){
                    	wData[i] = data[i];
                    }

					begin_time = clock();   // start cpu timer

					// Call your Sort function A here to sort the array 'wData''
			        //  Note that 'wData' is of size 'sz' (see case 1).
					shellSort(wData, sz);

					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "ShellSort ran for " << cpu_time_used << " secs.";


                    // Menu option 3 goes to Shell Sort
					ofilename = "shellSort_out.txt";
					writefile(wData, sz, ofilename);

					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;

					break;

            case 4: // Insertion sort.
                if (sz <= 0) {
                    cout << "Choose option 1 to load data first." << endl;
                break;
                }

                // Copy the original data into the working array.
                for (long i = 0; i < sz; i++) {
                    wData[i] = data[i];
                }

                // Measure only the sorting function.
                begin_time = clock();

                insertionsort(wData, sz);

                end_time = clock();

                cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;

                cout << "Insertion Sort ran for "
                    << cpu_time_used << " secs." << endl;

                // Menu option 4 goes to Insertion Sort
                ofilename = "insertionSort_out.txt";

                if (writefile(wData, sz, ofilename) < 0) {
                    cerr << "ERROR: Output file could not be opened." << endl;
                    return 1;
                }

                cout << "Output written to " << ofilename << endl;
                break;

            case 5: // Heap sort.
                if (sz <= 0) {
                    cout << "Choose option 1 to load data first." << endl;
                break;
                }

                // Copy the original data into the working array.
                for (long i = 0; i < sz; i++) {
                    wData[i] = data[i];
                }

                // Measure only the sorting function.
                begin_time = clock();

                heapsort(wData, sz);

                end_time = clock();

                cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;

                cout << "Heap Sort ran for "
                    << cpu_time_used << " secs." << endl;

                // // Menu option 5 goes to Heap Sort
                ofilename = "heapSort_out.txt";

                if (writefile(wData, sz, ofilename) < 0) {
                    cerr << "ERROR: Output file could not be opened." << endl;
                    return 1;
                }

                 cout << "Output written to " << ofilename << endl;
                break;

            case 6: // Selection sort - Gilbert =)
    		    if (sz <= 0) {
       			    cout << "Choose option 1 to load data first." << endl;
        	    break;
    		    }

    		    // Copy the original data into the working array.
    		    for (long i = 0; i < sz; i++) {
        		    wData[i] = data[i];
    		    }

    		    // Measure only the sorting function.
    		    begin_time = clock();

    		    selectionSort(wData, sz);

    		    end_time = clock();

    		    cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;

    		    cout << "Selection Sort ran for "
         		    << cpu_time_used << " secs." << endl;

   	 		    // Menu option 6 goes to Selection Sort
    		    ofilename = "selectionSort_out.txt";

    		    if (writefile(wData, sz, ofilename) < 0) {
        		    cerr << "ERROR: Output file could not be opened." << endl;
        		    return 1;
    		    }

    		    cout << "Output written to " << ofilename << endl;
    		    break;

            case 7: // Counting sort - Gilbert =)
                if (sz <= 0) {
                    cout << "Choose option 1 to load data first." << endl;
                    break;
                }

                 // Copy the data into the working array.
                for (long i = 0; i < sz; i++) {
                    wData[i] = data[i];
                }            

                // Measure  the sorting function.
                begin_time = clock();

                countingSort(wData, sz);

                end_time = clock();

                cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;

                cout << "Counting Sort ran for "
                    << cpu_time_used << " secs." << endl;

                // Menu option 7 goes to Counting Sort
                ofilename = "countingSort_out.txt";

                if (writefile(wData, sz, ofilename) < 0) {
                    cerr << "ERROR: Output file could not be opened." << endl;
                return 1;
                }

                cout << "Output written to " << ofilename << endl;
                break;



            case 0: // Exit the program.
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Incorrect selection. Please try again."
                     << endl;
                break;
        }
    }
}

