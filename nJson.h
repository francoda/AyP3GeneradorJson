#ifndef NJSON_H_
#define NJSON_H_

typedef enum { false, true } bool;

typedef struct _Njson {
	char* key;
	void* value;
	void (*print_nj)(void* this, FILE* out);
	unsigned size_type;
	unsigned count_elem;
	bool is_array; // Se utiliza para imprimir
} Njson;

Njson* njson_init(Njson* this, char* key, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), unsigned is_array);
void njson_release(Njson* this);
void njson_print(Njson* this, FILE* out);
void njson_print_string(void* value, FILE* out);
void njson_print_int(void* value, FILE* out);
void njson_print_double(void* value, FILE* out);
void njson_print_boolean(void* value, FILE* out);
void njson_print_json(void* value, FILE* out);
Njson* njson_set_value(Njson* this, void* value, unsigned size_type, unsigned count_elem, void (*print_nj)(void* this, FILE* out), unsigned is_array);

#endif /* NJSON_H_ */
