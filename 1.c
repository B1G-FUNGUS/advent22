#include <stdio.h>

void main() {
	FILE* list = fopen("1.txt", "r");
	char c = ' ';
	char oldc = ' ';
	int sum = 0;
	int oldsum = 0;
	while(c != EOF) {
		c = getc(list);
		if(c == '\n' & oldc == '\n') { 
			if(sum > oldsum) oldsum = sum;
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
	printf("%d\n", oldsum);
}
