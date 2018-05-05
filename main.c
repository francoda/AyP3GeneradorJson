#include <stdio.h>
#include <string.h>

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

	if (path == 0x0) {
		printf("Modo impresión \n");
	} else {
		printf("Modo archivo: %s \n", path);
	}
    return 1;

// Posible uso de primitivas
//	Json j;
//	njson_set_data(json_get_by_prop(j, "size"));
//	njson_set_data(json_get_by_prop((Json*)(json_get_by_prop(j, "contents")->data), "size"));

}
