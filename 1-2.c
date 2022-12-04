#include <stdio.h>

void main() {
	FILE* list = fopen("1.txt", "r");
	char c = ' ';
	char oldc = ' ';
	int sum = 0;
	int least = 0;
	int oldsums[3];
	for(int i = 0; i < 3; i++)
		oldsums[i] = 0;
	while(c != EOF) {
		c = getc(list);
		if(c == '\n' & oldc == '\n') { 
			if(sum > oldsums[least]) {
				oldsums[least] = sum;
				for(int i = 0; i < 3; i++)
					if(oldsums[least] > oldsums[i]) least = i;
			}
			sum = 0;
		}
		int num = 0;
		while(c >= 47 & c <= 57) {
			int digit = c-48;
			num=num*10+digit;
			c = getc(list);
		}
		sum+=num;
		oldc=c;
	}
	fclose(list);
	for(int i = 0; i < 3; i++)
		printf("%d ", oldsums[i]);
	printf("\n");
	int final = 0;
	for(int i = 0; i < 3; i++)
		final+=oldsums[i];
	printf("%d\n", final);
}
