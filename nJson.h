#ifndef NJSON_H_
#define NJSON_H_

typedef struct _Njson {
	char* key;
	void* value;
	void (*imp)(void* this);
	unsigned tam;
} Njson;

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam, void (*njson_imp_gen)(void* this));
void njson_release(Njson* this);
void njson_imprimir(void* this);
void njson_imprimir_string(void* this);
void njson_imprimir_int(void* this);
void njson_imprimir_double(void* this);
void njson_imprimir_boolean(void* this);
Njson* njson_set_value(Njson* this, void* value, unsigned tam, void (*njson_imp_gen)(void* this));

#endif /* NJSON_H_ */
