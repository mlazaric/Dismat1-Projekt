#include <stdio.h>

int main(void) 
{
	int n, k, br[10], i, fakt = 1, j;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		scanf("%d", br + i);
		fakt = fakt * (i + 1);
	}
	
	scanf("%d", &k);
	fakt = fakt / n;
	k--;
	
	for (i = n - 1; i > 0; --i)
	{
		printf("%d ", br[k / fakt]);
		
		for (j = k / fakt; j < n - 1; ++j)
		{
			br[j] = br[j + 1];
		}
		
		k = k % fakt;
		fakt = fakt / i;
	}
	
	printf("%d\n", br[0]);
	
	return 0;
}