#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static unsigned char 
tohex (char h)
{
	char hex [] = {
		'a', 'b', 'c', 'd', 'e', 'f', 
		'A', 'B', 'C', 'D', 'E', 'F'
	};

	unsigned char ret [] = {
		0xa, 0xb, 0xc, 0xd, 0xe, 0xf
	};
	for (int i=0; i<12; i++)	
		if (h == hex[i]) return ret[i];
	
	return (unsigned char ) h - 48;
}


static void 
plainStrtoPlainByte (unsigned char res[], char * str)
{
	unsigned char bytes[strlen (str)];
	unsigned char ret[(strlen (str) ) / 2];
	
	memset (bytes, 0, sizeof (bytes));
	memset (ret, 0, sizeof (ret));
	
	for (int i=0; i<sizeof (bytes); i++) bytes[i] = tohex (str[i]);

	for (int i=0,j=0; i<sizeof (bytes) ; j+=2, i++)	
        ret[i] = (((bytes[j] * 16) | bytes[j+1]) & 0xFF);
    memcpy (res, ret, sizeof (res));    
}

int 
main (int argc, char ** argv)
{
	char * str = "0abbccddeeff0102";
	unsigned char bytes [(strlen (str))/2];
	memset (bytes, 0, sizeof (bytes));
	
	plainStrtoPlainByte  (bytes, str);
	
	for (int i=0; i<sizeof (bytes); i++) printf ("%.02X ", bytes[i]);
	puts ("");

    return 0;
}
