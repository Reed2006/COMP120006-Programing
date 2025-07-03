#include <stdio.h>

int  main()
{
	int item_number = 0;
	float unit_price = .0;
	int mm, dd, yyyy;
	
	printf("Enter item number:");
	scanf("%d", &item_number);
	
	printf("Enter unit price:");
	scanf("%f", &unit_price);
	
	printf("Enter purchase date (mm/dd/yyyy):");
	scanf("%d/%d/%d", &mm, &dd, &yyyy);
	
	printf("Item\tUnit\t\tPurchase\n\tPrice\t\tDate\n");
	printf("%-d\t$%7.2f\t%-d%02d%02d", item_number, unit_price, yyyy, mm, dd);//不要忘记小数点也算一位 
	
	return 0;
}
