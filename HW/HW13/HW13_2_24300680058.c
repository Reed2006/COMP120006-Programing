#include "HW13_2_24300680058.h"

int main()
{
	printf("/*shuffling cards program*/\n\n");
	printf("The initial cards are:\n");
	struct card *cardlist = initcards();
	outputcards(cardlist);
	shuffle(cardlist);
	printf("\n\n");
	printf("The shuffled cards are:\n");
	outputcards(cardlist);
	return 0;
 } 
