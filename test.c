
#include "uuuid2.h"
#include <stdio.h>

int main()
{
	uuuid2_t id1 = uuuid2_gen();

	char buf[64];
	if(!uuuid2_to_str(buf, sizeof(buf), id1))
		return 1;

	uuuid2_t id2;
	if(!uuuid2_from_str(&id2, buf))
		return 1;

	if(!uuuid2_eq(id1, id2))
		return 1;

	printf("everything seems to be fine\n");
	return 0;
}
