#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


char * 
tgstrdup (const char * fmt, ...)
{
	int n;
	int size = 100;
	char * p, *np;
	va_list ap;
	
	if ((p=malloc (size)) == NULL) return NULL;
	
	while (1)	{
		va_start (ap, fmt);
		n = vsnprintf (p, size, fmt, ap);
		va_end(ap);
		if (n>-1 && n < size) return p;
		/* else is try again with more space */
		if (n > -1) size = n+1;
		else size *= 2;
		if ((np = realloc (p, size)) == NULL)	{
			free (p);
			return NULL;
		} else p = np;
	}
}


int main ()
{
	char * msg = tgstrdup ("%s %i %02.2f ", "abcd", 10, 0.05);
	printf ("%s", msg);
	free (msg);
	
	char sentence [] = "abcdef 7686  years is my age ";
	char str [20];
	int i = 0;

	sscanf (sentence, "%s  %d", str, &i);
	printf ("%s %i\n", str, i);

	return 0;
}
