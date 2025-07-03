#include <stdio.h>

int main()
{
	int number = 0;
	int thousands, hundreds, tens, singles, sum;
	
	printf("Enter a 4_digit number:");
	scanf("%d", &number);
	
	thousands = (number - number % 1000) / 1000;
	hundreds = (number - thousands * 1000 - number % 100) / 100;
	tens = (number - thousands * 1000 - hundreds * 100 - number %10 ) / 10;
	singles = number % 10;
	sum = thousands + hundreds + tens + singles;
	
	printf("%d+%d+%d+%d=%d", thousands, hundreds, tens, singles, sum);
	
	return 0;
	
 } 
