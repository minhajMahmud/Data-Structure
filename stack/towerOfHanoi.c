#include <stdio.h>
void TOH(int n, char rodA, char rodC, char rodB)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", rodA, rodC);
		return;
	}
	TOH(n - 1, rodA, rodB, rodC);
	printf("\n Move disk %d from rod %c to rod %c", n, rodA, rodC);
	TOH(n - 1, rodB, rodC, rodA);
}

int main()
{
	int no_of_disks;
	printf("Enter number of disks: ");
	scanf("%d", &no_of_disks);
	TOH(no_of_disks, 'A', 'C', 'B');
	return 0;
}