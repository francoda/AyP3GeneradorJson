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

Json* json_imprimir(Json* this) {
	printf("{ ");
	for(unsigned i = 0; i < this->elems; i++){
		if (i != 0) printf(" , ");
		njson_imprimir(this->nodos[i]);
	}
	printf(" }");
	return this;
}

Njson* json_get_by_prop(Json* this, char* prop){
	for(unsigned i = 0; i < this->elems; i++){
		if (strcmp(this->nodos[i]->key,prop))
			return this->nodos[i];
	}
	return 0x0;
}

Json* json_add(Json* this, Njson* new){
	if (new != 0x0){
		this->elems += 1;
		this->nodos = (Njson**)realloc(this->nodos, this->elems * sizeof(Njson));
		this->nodos[this->elems - 1] = new;
	}
	return this;
}
