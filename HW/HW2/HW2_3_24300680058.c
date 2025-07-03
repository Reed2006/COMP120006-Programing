#include <stdio.h>

int main()
{
	int amount;
	float payment, remains, interest_rate;
	
	printf("Enter amount of loan:");
	scanf("%d", &amount);
	
	printf("Enter interest rate:");
	scanf("%f", &interest_rate);
	
	printf("Enter monthly payment:");
	scanf("%f", &payment);
	
	remains = amount * (1.0 + interest_rate / 12.0 / 100.0) - payment;
	printf("Balance remaining after 1 month:%.2f:\n", remains);
	
	remains = remains * (1.0 + interest_rate / 12.0 / 100.0) - payment;
	printf("Balance remaining after 2 months:%.2f:\n", remains);
	
	remains = remains * (1.0 + interest_rate / 12.0 / 100.0) - payment;
	printf("Balance remaining after 3 months:%.2f:\n", remains);
	
	return 0;
}
