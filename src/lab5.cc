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

            case 2: // Selection sort.
                if (sz <= 0) {
                    cout << "Choose option 1 to load data first."
                         << endl;
                    break;
                }

                // Give the sort a fresh copy of the original data.
                for (long i = 0; i < sz; i++) {
                    wData[i] = data[i];
                }

                // Measure only the sorting function.
                begin_time = clock();

                selectionSort(wData, sz);

                end_time = clock();

                cpu_time_used =
                    (end_time - begin_time) / CLOCKS_PER_SEC;

                cout << "Selection Sort ran for "
                     << cpu_time_used << " secs." << endl;

                // Save the sorted array to its output file.
                ofilename = "lab5_A_out.txt";

                if (writefile(wData, sz, ofilename) < 0) {
                    cerr << "ERROR: Output file could not be opened."
                         << endl;
                    return 1;
                }

                cout << "Output written to "
                     << ofilename << endl;
                break;

            // Placeholders until the remaining sorts are connected.
            case 3:
            case 4:
            case 5: // Selection sort - Gilbert =)
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

   	 		// Menu option 5 corresponds to algorithm D.
    		ofilename = "lab5_D_out.txt";

    		if (writefile(wData, sz, ofilename) < 0) {
        		cerr << "ERROR: Output file could not be opened." << endl;
        		return 1;
    		}

    		cout << "Output written to " << ofilename << endl;
    		break;

            case 6: // Counting sort - Gilbert =)
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

                // Menu option 6 corresponds to algorithm E.
                ofilename = "lab5_E_out.txt";

                if (writefile(wData, sz, ofilename) < 0) {
                    cerr << "ERROR: Output file could not be opened." << endl;
                return 1;
                }

                cout << "Output written to " << ofilename << endl;
                break;



            case 7:
                cout << "This sorting option is not implemented yet."
                     << endl;
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

