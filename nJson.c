#include <stdlib.h>
#include <string.h>
#include "nJson.h"

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam) {
	this->key = malloc(strlen(key));
	strcpy(this->key, key);
	this->value = malloc(tam);
	memcpy(this->value, value, tam);
	return this;
}

void njson_release(Njson* this)  {
	if(this->key){
		free(this->key);
	}
	this->key = 0x0;
	if(this->value){
		free(this->value);
	}
	this->value = 0x0;
}

void njson_imprimir_string(Njson* this) {
	printf("%s:%s\n", this->key, (char*)this->value);
}

void njson_imprimir_int(Njson* this) {
	printf("%s:%d\n", this->key, (int*)this->value);
}

void njson_imprimir_double(Njson* this) {
	printf("%s:%f\n", this->key, (double*)this->value);
}

Njson* njson_set_value(Njson* this, void* value, unsigned tam) {
	njson_release(this);
	this->tam = tam;
	this->value = realloc(tam);
	memcpy(this->value, value, tam);
	return this;
}
