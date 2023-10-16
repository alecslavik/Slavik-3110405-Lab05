#include <stdio.h>

int main(){

//Here I initiate both lists with what they need, either the value of the month or the name of the month
	const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

	//This will be used for the Sales summary part, but we initiate it with the first value in the sales list
	float min_sales = sales[0];
	float max_sales = sales[0];
	float total_sales = sales[0];

	//Our first header for our first 'function'
	printf("Monthly sales report for 2022:\n");
	printf("Month     Sales\n");
	
	//Here we are saying the for every month, print the month and sale
	for (int month = 0; month<12; month++){
		printf("%-9s $%.2f\n", months[month], sales[month]);
	}
	
	//For the min and max sales, finding the lowest and highest int in the sales list, then change accordingly, we also find our total sales here and average sales with a simple equation
	for (int i = 1; i < 12; i++){
		if (sales[i] < min_sales){
			min_sales = sales[i];
		}
		if (sales[i] > max_sales){
			max_sales = sales[i];
		}
		total_sales += sales[i];
	}
	float average_sales = total_sales / 12;

	//Another header and the correct output formatted
	printf("\nSales summary:\n");
	printf("Minimum sales: $%.2f (%s)\n", min_sales, months[0]);
	printf("Maximum sales: $%.2f (%s)\n", max_sales, months[11]);
	printf("Average sales: $%.2f\n", average_sales);
		
	//Header for six month
	printf("\nSix-Month Moving Average Report:\n");
	//Here we find the moving average between a month and a month six away from it
	for (int start_month = 0; start_month < 7; start_month++){
		float moving_average = 0;
		for (int i = start_month; i < start_month + 6 ; i++){
			moving_average += sales[i];
		}
		//Again another cimple equation and printed output
		moving_average /= 6;
		printf("%s - %s $%.2f\n", months[start_month], months[start_month + 5], moving_average);
	}

	printf("\nSales Report (Highest to Lowest)\n");
	printf("Month      Sales\n");

	//Here we find the highest float, and immediately print it at the top, followed by the next biggest and so on
	for (int i = 0; i < 11; i++){
		for (int j = 0; j < 11 - i; j++){
			if (sales[j] < sales[j + 1]){
				float temp_sales = sales[j];
				sales[j] = sales[j + 1];
				sales[j + 1] = temp_sales;
				const char *temp_month = months[j];
				months[j] = months[j + 1];
				months[j + 1] = temp_month;
			}
		}
	}
	//Here our output needs a another for loop for each entry
	for (int month = 0; month < 12; month++){
		printf("%-9s $%.2f\n", months[month], sales[month]);
	}

	return 0;
}

