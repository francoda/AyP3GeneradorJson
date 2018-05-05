#ifndef NJSON_H_
#define NJSON_H_

typedef struct _Njson {
	char* key;
	void* value;
	unsigned tam;
} Njson;

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam);
void njson_release(Njson* this) ;
void njson_imprimir(void* this) ;
Njson* njson_set_value(Njson* this, void* value, unsigned tam);

#endif /* NJSON_H_ */
