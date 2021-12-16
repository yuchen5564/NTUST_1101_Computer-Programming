#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <math.h>
int cc = 1, target = 0;
char oa, ob;
int on;
int hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		//printf("%d:Disk %d moved from %c to %c\n", cc, n, a, c);
		if (cc == target) {
			on = n;
			oa = a;
			ob = c;
		}
		cc++;
	}
	else {
		hanoi(n - 1, a, c, b);
		
		//printf("%d:Disk %d moved from %c to %c\n", cc, n, a, c);
		if (cc == target) {
			on = n;
			oa = a;
			ob = c;
		}
		cc++;
		hanoi(n - 1, b, a, c);
	}
}


int main()
{
	int disk = 0;
	scanf("%d", &disk);
	scanf(" %d", &target);
	
	int less_step = pow(2, disk) - 1;
	//printf("%d %d %d\n", disk, target, less_step);
	if (disk < 1) {
		printf("Invalid disk number\n");
	}
	else if (target > less_step) {
		printf("Step out of range\n");
	}
	else {
		hanoi(disk, 'A', 'B', 'C');
		printf("Disk %d moved from %c to %c\n", on, oa, ob);
	}

	
	return 0;
}