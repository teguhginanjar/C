#include <stdio.h>

#define print(x)	_Generic((x), 	\
		char: "%c",					\
		signed char: "%hhd",		\
		unsigned char : "%hhu",		\
		unsigned int : "%u",		\
		long int	: "%ld",		\
		int	: "%i",					\
		float :	"%f",				\
		double: "%f",				\
		char *: "%s",				\
		void *: "%p"				)

#define println(x) printf(print(x),x),printf("\n");


#define typename(x)	_Generic((x), \
	_Bool: "_Bool", \
	char :"char", 	\
	short int : "short int",	\
	int: "int",					\
	long int: "long int",		\
	long long int : "long long int", \
	float: "float",					\
	long double: "long double",		\
	unsigned char :"unsigned char",	\
	signed char:  "signed char",		\
	unsigned short int: "unsigned short int", \
	unsigned int :"unsigned int",	\
	unsigned long int: "unsigned long int",	\
	unsigned long long int : "unsigned long long int",	\
	double : "double", 	\
	char * : "char *",	\
	int * : "int *",	\
	void * :"void *",	\
	default: "other"	\
	)

typedef struct abc {
	int x;
}
bca;

bca b;

int main (int argc, char ** argv)
{

	println ((char *) "string");
	println (100);
	println (90.12);
	println ((char) 'a');

	float x;
	println ((char *) typename ("string"));
	println ((char *) typename (x));		
	return 0;
}
