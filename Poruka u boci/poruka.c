#include <stdio.h>

int main(void) 
{
	char a, arr[3];
	int i = 0, in;
	
	while (i < 0x7A)
	{
		a = getchar();
		
		printf("%c", a);
		++i;
	}
	
	while (!feof(stdin)) 
	{
		in = getchar();
		in = (in << 8) | getchar();
		in = (in << 8) | getchar();
		
		if (in == 0xFFF4F4) in = 0; /* Boja pronađena hex editorom, ima i drugih boja, npr. 0xFFF7F7 */
		
		printf("%c", (in >> 16) & 0xFF);
		printf("%c", (in >> 8) & 0xFF);
		printf("%c", in & 0xFF);
	}
	
	
	return 0;
}