#include "nJson.h"

#ifndef JSON_H_
#define JSON_H_

typedef struct _Json {
	Njson** nodos;
	unsigned elems;
} Json;

Json* json_init(Json* this, Njson** nodos, unsigned elems);
void json_release(Json* this);
Json* json_imprimir(Json* this, FILE* out);
Njson* json_get_by_key(Json* this, char* prop);
Json* json_add(Json* this, Njson* new);

#endif /* JSON_H_ */
