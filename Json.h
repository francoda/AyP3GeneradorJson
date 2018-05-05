#include "nJson.h"

#ifndef JSON_H_
#define JSON_H_

typedef struct _Json {
	Njson** nodos;
} Json;

Json* json_init(Json* this, Njson** nodos, unsigned tam);
void json_release(Json* this) ;
void json_imprimir(void* this) ;
Njson* json_get_by_prop(Json* this, char* prop);

#endif /* JSON_H_ */
