#include <stdio.h>
#include <string.h>
#include "Json.h"

Json* json_init(Json* this, Njson** nodos, unsigned elems) {
	this->elems = elems;
	this->nodos = malloc(elems * sizeof(Njson));
	memcpy(this->nodos, nodos, elems * sizeof(Njson));
	return this;
}

void json_release(Json* this) {
	if (this->nodos){
		for(unsigned i = 0; i < this->elems; i++){
			njson_release(this->nodos[i]);
		}
		free(this->nodos);
	}
	this->nodos = 0x0;
}

Json* json_print(Json* this, FILE* out) {
	fprintf(out, "{ ");
	for(unsigned i = 0; i < this->elems; i++){
		if (i != 0) fprintf(out, ", ");
		njson_print(this->nodos[i], out);
	}
	fprintf(out, " }");
	return this;
}

Njson* json_get_njson_by_key(Json* this, char* key){
	for(unsigned i = 0; i < this->elems; i++){
		if (strcmp(this->nodos[i]->key, key) == 0)
			return this->nodos[i];
	}
	return 0x0;
}

Njson* json_set_value_by_key(Json* this, char* key, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), bool is_array){
	Njson* node = json_get_njson_by_key(this, key);
	if (node == 0x0) return 0x0;
	return njson_set_value(node, value, size_type, count_elem, print_nj, is_array);
}

Json* json_add(Json* this, Njson* new){
	if (new != 0x0){
		this->elems += 1;
		this->nodos = (Njson**)realloc(this->nodos, this->elems * sizeof(Njson));
		this->nodos[this->elems - 1] = new;
	}
	return this;
}
