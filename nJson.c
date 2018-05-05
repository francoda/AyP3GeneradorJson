#include <stdlib.h>
#include <string.h>
#include "nJson.h"

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam) {
	this->key = key;
	return njson_set_value(this, value, tam);
}

void njson_release(Njson* this)  {
	if(this->value){
		free(this->value);
	}
	this->value = 0x0;
}

void njson_imprimir(void* this) {

}

Njson* njson_set_value(Njson* this, void* value, unsigned tam) {
	njson_release(this);
	this->tam = tam;
	this->value = malloc(tam);
	memcpy(this->value, value, tam);
	return this;
}
