# Employee Record

This program reads data, computes payroll and prints it. Each data record is a structure, and the payroll is an array of structures. Overtime hours are 150% of the rate. (Note: Maximum regular hours for the week is 40.) Tax is withheld 15% if weekly pay is below 500, 28% if pay is below 1000, and 33% otherwise. A summary report prints the total gross pay and tax withheld.

The following are the function prototypes:
```c
// reads a single name.
void readName(payrecord payroll[], int i);

// prints a single name.
void printName(payrecord payroll[], int i);

// prints total tax gross pay and total tax withheld.
void printSummary(double gross, double tax);

// reads payroll input data records until n records have been read.
void readRecords(payrecord payroll[], int n);

// prints n payroll records.
void printRecords(payrecord payroll[], int n);

/*
 * computes regular and overtime pay, and the tax to be withheld.
 * also cumulatively sums total gross pay and total tax withheld.
 * passes the address of tax initialized to 0 and returns the gross.
 */
double calcRecords(payrecord payroll[], int n, double *taxptr);
```