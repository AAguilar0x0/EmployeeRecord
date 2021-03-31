#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "employeeRecord.h"
#include "myTools.h"

// Helper function for restricted inputting of the number
int getDigit(char **ptr, int lim, char echo){
	CONSOLE_SCREEN_BUFFER_INFO info;
    int count = 0, size = 1;
    char inpt;

    if(*ptr == NULL)
        *ptr = malloc(1 * sizeof(char));
    
    do{
        fflush(stdin);
        inpt = getch();
        if(inpt == 8 && count > 0){
            printf("%c %c",inpt,inpt);
            *(*ptr + (--count)) = '\0';
            *ptr = realloc(*ptr, (size = count + 1) * sizeof(char));
        }else if(isdigit(inpt) && inpt != 8 && count < lim){
            printf("%c",(!echo) ? inpt : echo);
            *ptr = realloc(*ptr, (size = ++count + 1) * sizeof(char));
            *(*ptr + (count - 1)) = inpt;
            *(*ptr + count) = '\0';
        }
    }while(inpt != '\r' || count == 0);
    
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

    return info.dwCursorPosition.X;
}

// Helper Function for taking the number of employees
int getNumOfEmp(void) {
	char *buffer = NULL;
    int numOfEmp = 0;
	drawCSBox(40,2,5);
	centerOutString(3,"Input the total number of employees");
	gotoxy(centerOutString(4,">   ") + 2,4);
	getDigit(&buffer,2,'\0');
    numOfEmp = atoi(buffer);
    free(buffer);
    gotoxy(0,2);
    delline(4);
	
    return numOfEmp;
}

int main(void) {
	int numOfEmp = 0;
	double totalTax = 0, totalGross;
    centerOutString(0,"Employee Record");
    numOfEmp = getNumOfEmp();
    payrecord *payroll = calloc(numOfEmp,sizeof(payrecord));
	readRecords(payroll,numOfEmp);
	totalGross = calcRecords(payroll,numOfEmp,&totalTax);
	printRecords(payroll,numOfEmp);
	printSummary(totalGross,totalTax);
	free(payroll);
	
	return 0; 
}