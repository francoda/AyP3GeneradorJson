#include <stdio.h>
#include <string.h>
#include "nJson.h"
#include "Json.h"

int main(int argc, char** argv) {
	char* path = 0x0;

	for (int i=0;i<argc;i++) {
		if (!strcmp(argv[i],"-f") && i+1<argc) {
			//Se concatena la carpeta con el archivo (Provicional)
			argv[0] = strcat(argv[0], "/");
			//path={dir de ejecucion}+{nombre archivo}
			path = strcat(argv[0],argv[i+1]);
		}
	}
	/* Test Modo de impresion */
	if (path == 0x0)
		printf("Modo impresión \n");
	else
		printf("Modo archivo: %s \n", path);

	/* Test */

	Njson nodo1;
	Njson nodo2;
	Json js;

	int id = 45;
	njson_init(&nodo1, "id", &id, sizeof(int), 1, &njson_imprimir_int);
	char names[3][20] = { "Franco" , "Maxi", "Andy" };
	njson_init(&nodo2, "names", names, 20, 3, &njson_imprimir_string);

	Njson* no2[2] = {&nodo1, &nodo2};
	json_init(&js, no2, 2);

	json_imprimir(&js);

	int numeros[4] = { 34 , 14, 79, 101 };
	njson_set_value(&nodo2, numeros, sizeof(int), 4, &njson_imprimir_int);
	json_imprimir(&js);

	njson_set_value(&nodo2, "Maxi", sizeof(char*), 1, &njson_imprimir_string);
	json_imprimir(&js);

	Njson* prop = json_get_by_prop(&js, "name");
	printf("%p\n", prop);
	//njson_imprimir(prop);

	double decimal = 10.8;
	njson_set_value(&nodo2, &decimal, sizeof(double), 1, &njson_imprimir_double);
	json_imprimir(&js);

	bool boolean = true;
	njson_set_value(&nodo2, &boolean, sizeof(bool), 1, &njson_imprimir_boolean);
	json_imprimir(&js);

	int otroNumero = 14;
	Njson nodo3;
	njson_init(&nodo3, "other_number", &otroNumero, sizeof(int), 1, &njson_imprimir_int);
	json_add(&js, &nodo3);
	json_imprimir(&js);

	char* surname = "Andreoli";
	Njson nodo4;
	njson_init(&nodo4, "surname", surname, sizeof(char*), 1, &njson_imprimir_string);
	json_add(&js, &nodo4);
	json_imprimir(&js);

	Njson nodo5;
	njson_init(&nodo5, "numbers_again", numeros, sizeof(int), 4, &njson_imprimir_int);
	json_add(&js, &nodo5);
	json_imprimir(&js);

    return 0;
}
