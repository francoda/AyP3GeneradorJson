#include <stdio.h>

int main(int argc, char** argv) {
	char* path = 0x0;

	for (int i=0;i<argc;i++) {
		if (!strcmp(argv[i],"-f")) {
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
}
