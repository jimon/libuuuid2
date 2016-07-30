#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#pragma pack(push, 1)
typedef struct
{
	uint8_t bytes[16];
} uuuid2_t;
#pragma pack(pop)

uuuid2_t uuuid2_gen();
bool uuuid2_eq(uuuid2_t a, uuuid2_t b);
bool uuuid2_to_str(char * buf, size_t size, uuuid2_t id);
bool uuuid2_from_str(uuuid2_t * id, const char * buf);
