// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!


#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long data[]);
int		writefile(long data[], long size, string outfilename);
void	swap(long& x, long& y);

//Gilbert Added =)
void selectionSort(long data[], long size);
void radixSort(long data[], long size); //Recently Added replaced for counting sort

//Tien Add
void bubbleSort(long data[], int sz);
void shellSort(long data[], int sz);

//Vivianna Add
void insertionsort(long data[], long n);
void heapsort(long data[], long n);