#include "nJson.h"

#ifndef JSON_H_
#define JSON_H_

typedef struct _Json {
	Njson** nodos;
	unsigned elems;
} Json;

Json* json_init(Json* this, Njson** nodos, unsigned elems);
void json_release(Json* this);
Json* json_print(Json* this, FILE* out);
Njson* json_get_njson_by_key(Json* this, char* key);
Njson* json_set_value_by_key(Json* this, char* key, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), bool is_array);
Json* json_add(Json* this, Njson* new);

#endif /* JSON_H_ */
