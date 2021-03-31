#include <stdio.h>
#include "employeeRecord.h"
#include "myTools.h"

void readName(payrecord payroll[], int i){
	if(payroll == NULL || i < 0) return;
	fflush(stdin);
	gotoxy(40 + 2 + outString(40 + 2,5,"Last Name: "),5);
	gets(payroll[i].name.last);
	gotoxy(40 + 2 + outString(40 + 2,6,"First Name: "),6);
	gets(payroll[i].name.first);
	gotoxy(40 + 2 + outString(40 + 2,7,"Middle Name: "),7);
	gets(payroll[i].name.middle);
}

void printName(payrecord payroll[], int i){
	if(payroll == NULL || i < 0) return;
	printf("%s, %s %s", payroll[i].name.last, payroll[i].name.first, payroll[i].name.middle);
}

void readRecords(payrecord payroll[], int n){
	if(payroll == NULL || n == 0) return;
	int i;
	for(i = 0; i < n; i++){
		drawCSBox(40,2,10);
		centerOutString(3,"Employee #%d",i+1);
		gotoxy(40 + 2 + outString(40 + 2,4,"ID: "),4);
		scanf("%d", &payroll[i].id);
		readName(payroll, i);
		gotoxy(40 + 2 + outString(40 + 2,8,"Hours: "),8);
		scanf("%f", &payroll[i].hours);
		gotoxy(40 + 2 + outString(40 + 2,9,"Rate: "),9);
		scanf("%f", &payroll[i].rate);
		gotoxy(0,2);
		delline(9);
	}
	gotoxy(0,2);
}

void printSummary(double gross, double tax){
	printf("\tTotal Gross Pay: %.2lf", gross);
	printf("\n\tTotal Tax Withheld: %.2lf", tax);
}

void printRecords(payrecord payroll[], int n){
	if(payroll == NULL || n == 0) return;
	int i;
	for(i = 0; i < n; i++){
		printf("\tID: %d", payroll[i].id);
		printf("\n\tName: ");
		printName(payroll, i);
		printf("\n\tRate per Hour: %.2f", payroll[i].rate);
		printf("\n\tHours: %.2f", payroll[i].hours);
		printf("\n\tRegular Pay: %.2f", payroll[i].regular);
		printf("\n\tOvertime Pay: %.2f", payroll[i].overtime);
		printf("\n\tGross Income: %.2f", payroll[i].gross);
		printf("\n\tTax Withheld: %.2f", payroll[i].tax_withheld);
		printf("\n\tNet Income: %.2f", payroll[i].net);
		printf("\n\n");
	}
}

double calcRecords(payrecord payroll[], int n, double *taxptr){
	if(payroll == NULL || taxptr == NULL || n == 0) return 0;
	int i;
	double totalGrossPay = 0;
	for(i = 0; i < n; i++){
		
		if(payroll[i].hours > 40){
			payroll[i].overtime = (payroll[i].hours - 40) * (payroll[i].rate * 1.5f);
			payroll[i].regular = payroll[i].rate * 40;
		}else{
			payroll[i].overtime = 0;
			payroll[i].regular = payroll[i].rate * payroll[i].hours;
		}			
		
		payroll[i].gross = payroll[i].regular + payroll[i].overtime;
		totalGrossPay += payroll[i].gross;
		
		if(payroll[i].gross < 500) payroll[i].tax_withheld = payroll[i].gross * 0.15f;
		else if(payroll[i].gross < 1000) payroll[i].tax_withheld = payroll[i].gross * 0.28f;
		else payroll[i].tax_withheld = payroll[i].gross * 0.33f;
		payroll[i].net = payroll[i].gross - payroll[i].tax_withheld;
		*taxptr += payroll[i].tax_withheld;
	}
	
	return totalGrossPay;
}
