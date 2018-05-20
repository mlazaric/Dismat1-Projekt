#include <stdio.h>

int main(void) 
{
	int n, k, br[10], i, fakt = 1, j;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		scanf("%d", br + i);
	}
	
	scanf("%d", &k);
	
	/* Izračunaj (n - 1)! */
	for (i = 1; i < n; ++i)
	{
		fakt = fakt * i;
	}
	
	/* U zadatku nam je prva permutacija 1, ali nam je smislenije početi od 0 */
	k--;
	
	for (i = n - 1; i > 0; --i)
	{
		/* Biramo znamenku jednu po jednu */
		printf("%d ", br[k / fakt]);
		
		/* Pomičemo preostale brojeve */
		for (j = k / fakt; j < n - 1; ++j)
		{
			br[j] = br[j + 1];
		}
		
		/* Gledamo sljedeću manju faktorijelu */
		k = k % fakt;
		fakt = fakt / i;
	}
	
	/* Zadnja znamenka je jednoznačno određena jer je samo jedna ostala u polju */
	printf("%d\n", br[0]);
	
	return 0;
}