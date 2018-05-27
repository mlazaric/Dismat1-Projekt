#include <stdio.h>

int main(void) 
{
	long int n, fibo[100000] = {1, 1}, i;
	
	scanf("%d", &n);
	
	/* Računamo fibonacijeve brojeve dok ne dođemo do nekog koji je veći od n-a */
	for (i = 2; fibo[i - 1] < n; ++i)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	
	/* Ako je fibo[i - 1] n, onda umanjimo i za 1, inače ga umanjimo za 2 kako bismo došli do prvog fibonacijevog broja koji je manji od n */
	if (fibo[i - 1] == n) i = i - 1;
	else i = i - 2;
	
	/* Idemo za svaki fibonacijev broj i provjeravamo je li n veći ili jednak od trenutnog fibonacijevog broja */
	while (i >= 1)
	{
		/* Ako je, ispišemo 1 */
		if (fibo[i] <= n)
		{
			n = n - fibo[i];
			printf("1");
		}
		/* Inače ispišemo 0 */
		else printf("0");
		
		/* Prebacimo se na prethodni fibonacijev broj */
		--i;
	}
	
	printf("\n");
	
	return 0;
}