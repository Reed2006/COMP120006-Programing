#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define max1 10
#define max2 6
char *suits[] = {"Spades", "Hearts", "Diammonds", "Clubs"};

char *faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

struct card
{
	char suits[10];
	char faces[6];
};

struct card* initcards() {
    struct card* cards = malloc(52 * sizeof(struct card)); 
    struct card* p = cards;
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 13; j++) {
            strcpy(p -> suits, suits[i]);
            strcpy(p -> faces, faces[j]);
            p++;
        }
    }
    return cards;
}
void outputcards(struct card* cards)
{
	struct card* pca = cards;
	int i, j, k, count = 0;
	for(i = 0; i < 52; i++)
	{
			printf("%s", (pca + i) -> suits);
			for(k = 0; k < max1 - strlen((pca + i) -> suits); k++)
				printf(" ");
			printf("%s", (pca + i) -> faces);
			for(k = 0; k < max2 - strlen((pca + i) -> faces); k++)
				printf(" ");
			printf("|");
		count++;
		if(count % 6 == 0)
		printf("\n");
	}
}
void shuffle(struct card cards[])
{
	int i, n;
	struct card temp;
	srand((unsigned int)time(NULL));
	for(i = 0; i < 52; i++)
	{
		n = rand()%52;
		temp = cards[i]; 
        cards[i] = cards[n];
        cards[n] = temp;
	}
}


