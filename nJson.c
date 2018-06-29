#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nJson.h"
#include "Json.h"

Njson* njson_init(Njson* this, char* key, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), bool is_array) {
	this->key = (char*)malloc(strlen(key) + 1);
	strcpy(this->key, key);
	this->value = malloc(size_type * count_elem);
	memcpy(this->value, value, size_type * count_elem);
	this->print_nj = print_nj;
	this->size_type = size_type;
	this->count_elem = count_elem;
	this->is_array = is_array;
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

void njson_imprimir(Njson* this, FILE* out) {
	fprintf(out, "\"%s\": ", this->key);
	if (!this->is_array) {
		(*(this->print_nj))(this->value, out);
	} else {
		fprintf(out, "[ ");
		unsigned tamArray = this->size_type * this->count_elem;
		for (unsigned i = 0; i < tamArray; i += this->size_type) {
			if (i != 0) fprintf(out, " , ");
			(*(this->print_nj))(this->value + i, out);
		}
		fprintf(out, " ]");
	}
}

void njson_imprimir_string(void* value, FILE* out) {
	fprintf(out, "\"%s\"", (char*)value);
}

void njson_imprimir_int(void* value, FILE* out) {
	fprintf(out, "%d", *(int*)value);
}

void njson_imprimir_double(void* value, FILE* out) {
	fprintf(out, "%f", *(double*)value);
}

void njson_imprimir_boolean(void* value, FILE* out) {
	fprintf(out, "%s", *(bool*)value ? "true" : "false");
}

void njson_imprimir_json(void* value, FILE* out) {
	json_imprimir((Json*)value, out);
}

Njson* njson_set_value(Njson* this, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), bool is_array) {
	this->size_type = size_type;
	this->count_elem = count_elem;
	this->print_nj = print_nj;
	this->is_array = is_array;
	this->value = realloc(this->value, size_type * count_elem);
	memcpy(this->value, value, size_type * count_elem);
	return this;
}
