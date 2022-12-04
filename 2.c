#include <stdio.h>

void main() {
	FILE* list = fopen("2.txt", "r");
	char c = ' ';
	int score = 0;
	while(c != EOF) {
		c = getc(list);
		int mine = c - 65;
		score += c - 64;
		getc(list);
		c = getc(list);
		int theirs = c - 88;
		if(mine == theirs) score += 3;
		if(theirs == mine + 1) score += 6;
		getc(list);
	}
	printf("%d\n", score);
	fclose(list);
}
