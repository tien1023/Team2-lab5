#include <iostream>
#include <fstream>
#include "myheaders.h"

using namespace std;


// Print menu of choices to screen

void	printmenu() {

			cout << endl;
			cout << "Please choose from the following menu:" << endl;
			cout << "  1: Read input file" << endl;
			cout << "  2: Sort using Asort" << endl;
			cout << "  3: Sort using Bsort" << endl;
			cout << "  4: Sort using Csort" << endl;
			cout << "  5: Sort using Dsort" << endl;			
			cout << "  6: Sort using Esort" << endl;
			cout << "  7: Sort using Fsort" << endl;			
			cout << "  0: Exit program" << endl;
			cout << endl << "Enter your choice: ";

		return;

}


// Print array to screen .. only for use with small test files

void	printarray(long data[], long size) {

			cout << endl << "Array contents:" << endl;
			for (int i = 0; i < size; ++i)	  cout << data[i] << " ";
			cout << endl;

		return;

}


// Read input file and store numbers in arrays d1 and d2
// Function returns no. of data items, if file is read successfully. Else,
// function returns -1.

int		readfile(string infilename, long d[]) {

			long		i, size;
			ifstream	infile;

			// IMP NOTE: In the C++ std before C++11, the constructor for an
			//           ifstream or ofstream object takes a const char*, not
			//           a string. In compilers that follow the C++11 std or
			//			 later, we may write instead: infile.open(infilename);
	
			infile.open(infilename.c_str());

			if (!infile.is_open()) { size = -1;}
			else {
				for (i = 0; (!infile.eof()) && (i < MAXSIZE); ++i) {
					infile >> d[i];
				} // for
				
				size = i-1; // eof() causes an extra (invalid) number to be read
				infile.close();
			} // else
	
			return size;
}


// Write output file to disk from array data[]
// If file is successfully written to disk, function returns 0. Else,
// function returns -1.

int		writefile(long data[], long size, string outfilename) {

			long		i, errcode;
			ofstream	outfile;

			// IMP NOTE: In the C++ std before C++11, the constructor for an
			//           ifstream or ofstream object takes a const char*, not
			//           a string. In compilers that follow the C++11 std or
			//			 later, we may write instead: outfile.open(outfilename);
			outfile.open(outfilename.c_str());

			if (!outfile.is_open()) { errcode = -1;}
			else {
				for (i = 0; i < size; ++i)	  outfile << data[i] << " ";
				
				errcode = 0;
				outfile.close();
			} // else
	
			return errcode;
}


// Swaps two numbers. Numbers *must* be passed by reference, else we end up
// swapping only copies of data, not the originals.

void	swap(long& x, long& y) {

			long	tmp;

			tmp = x;
			x = y;
			y = tmp;

			return;
}


