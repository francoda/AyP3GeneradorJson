#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nJson.h"
#include "Json.h"

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam_type, unsigned count_elem, void (*print_nj)(void* this)) {
	this->key = (char*)malloc(strlen(key) + 1);
	strcpy(this->key, key);
	this->value = malloc(tam_type * count_elem);
	memcpy(this->value, value, tam_type * count_elem);
	this->print_nj = print_nj;
	this->size_type = tam_type;
	this->count_elem = count_elem;
	return this;
}

void njson_release(Njson* this)  {
	if(this->key)
		free(this->key);
	this->key = 0x0;
	if(this->value)
		free(this->value);
	this->value = 0x0;
	this->print_nj = 0x0;
}

void njson_imprimir(Njson* this) {
	printf("\"%s\": ", this->key);
	if (this->count_elem == 1) {
		(*(this->print_nj))(this->value);
	} else {
		printf("[ ");
		unsigned tamArray = this->size_type * this->count_elem;
		for (unsigned i = 0; i < tamArray; i += this->size_type) {
			if (i != 0) printf(" , ");
			(*(this->print_nj))(this->value + i);
		}
		printf(" ]");
	}
}

void njson_imprimir_string(void* value) {
	printf("\"%s\"", (char*)value);
}

void njson_imprimir_int(void* value) {
	printf("%d", *(int*)value);
}

void njson_imprimir_double(void* value) {
	printf("%f", *(double*)value);
}

void njson_imprimir_boolean(void* value) {
	printf("%s", *(bool*)value ? "true" : "false");
}

void njson_imprimir_json(void* value) {
	json_imprimir((Json*)value);
}

Njson* njson_set_value(Njson* this, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this)) {
	this->size_type = size_type;
	this->count_elem = count_elem;
	this->print_nj = print_nj;
	this->value = realloc(this->value, size_type * count_elem);
	memcpy(this->value, value, size_type * count_elem);
	return this;
}
