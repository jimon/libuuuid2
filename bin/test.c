#include <stdlib.h>
#include <strings.h>
#include "uuuid2.h"
#include <stdio.h>


/* 	util_bin2hex 
		cd - line prefix,
		label - line label,  
		string 
		string length	
*/

void util_bin2hex (char *cd, char* label, unsigned char * x, int len ){
	int i;
	int z=0;
    int l = (len/4) + len*2;
    if (len % 4 > 0) { ++l; }

    char *_utilbuffer = (char *)malloc( (l+1) * sizeof(char) );
    bzero(_utilbuffer, l+1);
    
	for (i=0; i<len; i++) {
		sprintf(_utilbuffer+z, "%02x", x[i]);
		z+=2;

		if ( (i>0) && ( (i+1)%4 == 0 ) ) {
			sprintf (_utilbuffer+z, " " );
			z++;
		}

	}
	printf ( "%2s %24s: %42s\n", cd, label, _utilbuffer);
    free(_utilbuffer);

}
int main()
{
	int i;
	uuuid2_t id1;
	uuuid2_t id2;
	char s[37];

	for (i=0; i<10; i++) {	
		uuuid2_gen(&id1);
		
		uuuid2_to_str(s, sizeof(s), &id1);
		printf ( "%2s %24s: %42s\n\n", " ", "UUID", s);
		
		util_bin2hex( " ", "HEX Dump UUID 1", (unsigned char*)&id1, 16);		
		uuuid2_from_str(&id2, s);		
		util_bin2hex( " ", "HEX Dump UUID 2", (unsigned char*)&id2, 16);		
		if ( uuuid2_eq(&id1, &id2) ) {
			printf ( "%2s %24s: %42s\n\n", " ", "UUID Are", "equal");
		} else {
			printf ( "%2s %24s: %42s\n\n", "E!", "UUID Are", "NOT equal - ERROR !");		
		}
		
	}


	for (i=0; i<10; i++) {	
		uuuid2_gen(&id1);
		uuuid2_gen(&id2);
		
		uuuid2_to_str(s, sizeof(s), &id1);
		printf ( "%2s %24s: %42s\n\n", " ", "UUID", s);
		uuuid2_to_str(s, sizeof(s), &id2);
		printf ( "%2s %24s: %42s\n\n", " ", "UUID", s);
		
		util_bin2hex( " ", "HEX Dump UUID 1", (unsigned char*)&id1, 16);
		util_bin2hex( " ", "HEX Dump UUID 2", (unsigned char*)&id2, 16);

		if ( uuuid2_eq(&id1, &id2) ) {
			printf ( "%2s %24s: %42s\n\n", " ", "UUID Are", "equal");
		} else {
			printf ( "%2s %24s: %42s\n\n", "E!", "UUID Are", "NOT equal - ERROR !");		
		}
		
	}


	return 0;
}
