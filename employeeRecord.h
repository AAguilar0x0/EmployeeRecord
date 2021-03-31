struct namerec{
	char last[15];
	char first[15];
	char middle[15];
};

struct payrecord{
	int id;
	struct namerec name;
	float hours, rate;
	float regular, overtime;
	float gross, tax_withheld, net;
};

typedef struct payrecord payrecord;

void readName(payrecord payroll[], int i);
void printName(payrecord payroll[], int i);
void printSummary(double gross, double tax);
void readRecords(payrecord payroll[], int n);
void printRecords(payrecord payroll[], int n);
double calcRecords(payrecord payroll[], int n, double *taxptr);





