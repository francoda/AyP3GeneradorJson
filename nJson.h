#ifndef NJSON_H_
#define NJSON_H_

typedef enum { false, true } bool;

typedef struct _Njson {
	char* key;
	void* value;
	void (*print_nj)(void* this);
	unsigned size_type;
	unsigned count_elem;
} Njson;

Njson* njson_init(Njson* this, char* key, void* value, unsigned tam_type, unsigned count_elem, void (*print_nj)(void* this));
void njson_release(Njson* this);
void njson_imprimir(Njson* this);
void njson_imprimir_string(void* value);
void njson_imprimir_int(void* value);
void njson_imprimir_double(void* value);
void njson_imprimir_boolean(void* value);
Njson* njson_set_value(Njson* this, void* value, unsigned tam_type, unsigned count_elem, void (*print_nj)(void* this));

#endif /* NJSON_H_ */
