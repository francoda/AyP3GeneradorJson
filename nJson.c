#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nJson.h"

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam, void (*njson_imp_gen)(void* this)) {
	this->key = malloc(strlen(key) + 1);
	strcpy(this->key, key);
	this->value = malloc(tam);
	memcpy(this->value, value, tam);
	this->imp = njson_imp_gen;
	return this;
}

void njson_release(Njson* this)  {
	if(this->key)
		free(this->key);
	this->key = 0x0;
	if(this->value)
		free(this->value);
	this->value = 0x0;
	this->imp = 0x0;
}

void njson_imprimir(void* this) {
	(*(((Njson*)this)->imp))((Njson*)this);
}

void njson_imprimir_string(void* this) {
	printf("\"%s\": \"%s\"", ((Njson*)this)->key, (char*)((Njson*)this)->value);
}

void njson_imprimir_int(void* this) {
	printf("\"%s\": %d", ((Njson*)this)->key, *(int*)((Njson*)this)->value);
}

void njson_imprimir_double(void* this) {
	printf("\"%s\": %f", ((Njson*)this)->key, *(double*)((Njson*)this)->value);
}

void njson_imprimir_boolean(void* this) {
	printf("\"%s\": %s", ((Njson*)this)->key, ((Njson*)this)->value ? "true" : "false");
}

Njson* njson_set_value(Njson* this, void* value, unsigned tam, void (*njson_imp_gen)(void* this)) {
	this->tam = tam;
	this->value = realloc(this->value, tam);
	memcpy(this->value, value, tam);
	return this;
}
