#include <stdio.h>
#include <string.h>
#include "Json.h"
#include "nJson.h"

int main(int argc, char** argv) {
	char* path = 0x0;
	Njson* nodo;

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
	/* Test njson */
	njson_init(&nodo, "String", "string", strlen("string") + 1, (void*)&njson_imprimir_string);
	njson_imprimir(&nodo);
	njson_set_value(&nodo, "String", strlen("String") + 1, &njson_imprimir_string);
	njson_imprimir(&nodo);
    return 0;
}
