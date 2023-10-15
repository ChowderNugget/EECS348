#include <stdio.h>
#include <stdlib.h>

int main() { 
	
	FILE *pfile;  // pointer variable
	char arr_of_str[12][100];  // array of strings
	char arr_of_months[12][25] = {"Jan", 
                     "Feb", "Mar", "Apr", 
					 "May", "Jun", "Jul", 
					 "Aug", "Sep", "Oct", 
					 "Nov", "Dec"};
	float sales_floats[12]; // convert str of sales amt to float and put here
	pfile = fopen("sample_sales.txt", "r");

	printf("\nMonthly sales report for 2022:\n");
	printf("%-10s %-5s\n", "Month", "Sales");
	for (int i = 0; i < 12; i++) {
		fgets(arr_of_str[i], 50, pfile);
		
	}  
	// get a string from each line and put it into an array
	
	for (int i = 0; i < 12; i++) {
		printf("%-10s %-5s", arr_of_months[i], arr_of_str[i]);
		
	}
	// print monthly sales report
	printf("\n");
	
	for (int i = 0; i < 12; i++) {
		sales_floats[i] = strtof(arr_of_str[i], NULL);

	} // create array of floats for each month's sales number
	
	float min = sales_floats[0];
	float max = sales_floats[0];
	for (int i = 0; i < 12; i++) {
		if (sales_floats[i] < min) {
			min = sales_floats[i];
			
		}
		
		if (sales_floats[i] > max) {
			max = sales_floats[i];
			
		}
	} // assign lowest monthly sales to min and highest to max
	
	float sum = 0.0;
	for (int i = 0; i < 12; i++) {
		sum = sum + sales_floats[i];
		
	}
	float average = sum / 12;
	// find average
	
	printf("\nSales summary:");
	printf("\n%-15s %.2f", "Minimum sales:", min);
	printf("\n%-15s %.2f", "Maximum sales:", max);
	printf("\n%-15s %.2f", "Average:", average);

	float temp;
	float avg;
	printf("\nDidn't finish six month average fully\n");
	for (int i = 0; i < 7; i++) {
		temp = 0.0;
		for (int a = i; a < i+6; a++) {
			temp = temp + sales_floats[a];
		}
		
		
		avg = temp / 6;
		printf("\n%.2f", avg);
		
	}
	
	printf("\n");
	
	fclose(pfile);
	return 0; 
	
}
