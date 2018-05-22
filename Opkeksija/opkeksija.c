#include <stdio.h>

typedef struct red {
	int parnost;
	int max;
	int min;
} red;

int ntiClan(red r, int n)
{
	/* Ako želi samo parne, onda su sve neparne potencije = 0 */
	if (r.parnost == 1 && n & 1) return 0;

	/* Ako želi samo neparne, onda su sve parne potencije = 0 */
	if (r.parnost == 0 && !(n & 1)) return 0;

	/* Ako želi max r.max keksi, a n je veći od toga, onda je potencija = 0 */
	if (r.max != -1 && r.max < n) return 0;

	/* Ako želi min r.min keksi, a n je manji od toga, onda je potencija = 0 */
	if (r.min != -1 && r.min > n) return 0;

	return 1;
}

int main (void)
{
	int k, p, i, currred[100] = {0}, j, n, sum;
	red r;
	char parnost[10];

	scanf("%d %d", &k, &p);

	for (i = 0; i < p; ++i)
	{
		/* Format: (PARAN|NEPARAN|OBOJE) MIN min MAX max radi jednostavnosti*/
		scanf("%s %*s %d %*s %d", parnost, &(r.min), &(r.max));

		/* Ako je paran, onda je 1, ako je neparan, onda je 0, inače je -1 */
		if (parnost[0] == 'P') r.parnost = 1;
		else if (parnost[0] == 'N') r.parnost = 0;
		else r.parnost = -1;

		/* Ako je tek prvi red, onda njega samo upišemo ---- do k-tog člana jer nam ne trebaju oni iznad njega */
		if (i == 0)
		{
			for (j = 0; j <= k; ++j)
			{
				currred[j] = ntiClan(r, j);
			}
		}
		else 
		{
			/* Inače Cauchyjev produkt */
			for (n = k; n >= 0; --n)
			{
				sum = 0;

				for (j = 0; j <= n; ++j)
				{
					sum += currred[j] * ntiClan(r, n - j);
				}

				currred[n] = sum;
			}
		}
	}

	printf("%d\n", currred[k]);

	return 0;
}