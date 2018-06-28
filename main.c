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
		if (!strcmp(argv[i],"-c")) {
			//Crear otro JSON y mostrarlo en la salida utlizando el parámetro (Provicional)
		}
	}
	/* Test Modo de impresion */
	if (path == 0x0)
		printf("Modo impresión: \n");
	else
		printf("Modo archivo: %s \n", path);

	/* Test */

	Njson nodo1;
	Njson nodo2;
	Json js;

	int id = 45;
	njson_init(&nodo1, "id", &id, sizeof(int), 1, &njson_imprimir_int, false);
	char names[3][20] = { "Franco" , "Maxi", "Andy" };
	njson_init(&nodo2, "names", names, 20, 3, &njson_imprimir_string, true);

	Njson* no2[2] = {&nodo1, &nodo2};
	json_init(&js, no2, 2);
	json_imprimir(&js);
	printf("\n");

	int numeros[4] = { 34 , 14, 79, 101 };
	njson_set_value(&nodo2, numeros, sizeof(int), 4, &njson_imprimir_int, true);
	json_imprimir(&js);
	printf("\n");

	njson_set_value(&nodo2, "Maxi", sizeof(char*), 1, &njson_imprimir_string, false);
	json_imprimir(&js);
	printf("\n");

	//Njson* prop = json_get_by_prop(&js, "name");
	//printf("%p\n", prop);
	//njson_imprimir(prop);

	double decimal = 10.8;
	njson_set_value(&nodo2, &decimal, sizeof(double), 1, &njson_imprimir_double, false);
	json_imprimir(&js);
	printf("\n");

	bool boolean = true;
	njson_set_value(&nodo2, &boolean, sizeof(bool), 1, &njson_imprimir_boolean, false);
	json_imprimir(&js);
	printf("\n");

	int otroNumero = 14;
	Njson nodo3;
	njson_init(&nodo3, "other_number", &otroNumero, sizeof(int), 1, &njson_imprimir_int, false);
	json_add(&js, &nodo3);
	json_imprimir(&js);
	printf("\n");

	char* surname = "Andreoli";
	Njson nodo4;
	njson_init(&nodo4, "surname", surname, sizeof(char*), 1, &njson_imprimir_string, false);
	json_add(&js, &nodo4);
	json_imprimir(&js);
	printf("\n");

	Njson nodo5;
	njson_init(&nodo5, "numbers_again", numeros, sizeof(int), 4, &njson_imprimir_int, true);
	json_add(&js, &nodo5);
	json_imprimir(&js);
	printf("\n");

	njson_set_value(&nodo5, &decimal, sizeof(double), 1, &njson_imprimir_double, false);
	json_imprimir(&js);
	printf("\n");

	Njson nodo7;
	char* genero = "Rock";
	njson_init(&nodo7, "genre", genero, sizeof(char*), 1, &njson_imprimir_string, false);

	Njson* no3[2] = { &nodo7, &nodo3 };
	Json js2;
	json_init(&js2, no3, 2);
	Njson nodo6;
	njson_init(&nodo6, "music", &js2, sizeof(Json), 1, &njson_imprimir_json, false);
	json_add(&js, &nodo6);
	json_imprimir(&js);
	printf("\n");

	Njson nodo8;
	int numeros_again[1] = { 22 };
	njson_init(&nodo8, "prueba_array", numeros_again, sizeof(int), 1, &njson_imprimir_int, true);
	json_add(&js, &nodo8);
	json_imprimir(&js);
	printf("\n");

    return 0;
}
