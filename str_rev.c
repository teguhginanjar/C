#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char * rev_str (char * str)
{
	char * tmp = (char * ) malloc (sizeof (char ));
	int len = strlen (str) -1;
	tmp[len] = '\0';
	do {
		tmp[len--] = *str;
	} while (*str++ != '\0');
	return tmp;
}


int main (int argc, char ** argv)
{
	if (argc < 2) return 1;
	char * revstr = rev_str (argv[1]);
	puts (revstr);
	free (revstr);
  return 0;
}
