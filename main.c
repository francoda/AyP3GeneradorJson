#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "nJson.h"
#include "Json.h"

int main(int argc, char** argv) {
	for (int i=0;i<argc;i++) {
		if (!strcmp(argv[i],"-f") && i+1<argc) {
			FILE* out = fopen(argv[i+1], "w");
			test(out);
			fclose(out);
		} else if (!strcmp(argv[i],"-c")) {
			test(stdout);
		}
	}
	return 0;
}

void test(FILE* out) {
	Json js;
	Json js2;
	Json js3;

	char* size1 = "0 bytes";
	Njson nodo1;
	njson_init(&nodo1, "size", size1, sizeof(char), strlen(size1)+1, &njson_imprimir_string, false);

	Njson* nodos1[1] = {&nodo1};
	json_init(&js, nodos1, 1);

	char* hash = "37eb1ba1849d4b0fb0b28caf7ef3af52";
	Njson nodo2;
	njson_init(&nodo2, "hash", hash, sizeof(char), strlen(hash)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo2);

	int bytes1 = 0;
	Njson nodo3;
	njson_init(&nodo3, "bytes", &bytes1, sizeof(int), 1, &njson_imprimir_int, false);
	json_add(&js, &nodo3);

	bool thumb_exists1 = false;
	Njson nodo4;
	njson_init(&nodo4, "thumb_exists", &thumb_exists1, sizeof(bool), 1, &njson_imprimir_boolean, false);
	json_add(&js, &nodo4);

	char* rev1 = "714f029684fe";
	Njson nodo5;
	njson_init(&nodo5, "rev", rev1, sizeof(char), strlen(rev1)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo5);

	char* modified1 = "Wed, 27 Apr 2011 22:18:51 +0000";
	Njson nodo6;
	njson_init(&nodo6, "modified", modified1, sizeof(char), strlen(modified1)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo6);

	char* path1 = "/Photos";
	Njson nodo7;
	njson_init(&nodo7, "path", path1, sizeof(char), strlen(path1)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo7);

	bool is_dir1 = true;
	Njson nodo8;
	njson_init(&nodo8, "is_dir", &is_dir1, sizeof(bool), 1, &njson_imprimir_boolean, false);
	json_add(&js, &nodo8);

	char* icon1 = "folder";
	Njson nodo9;
	njson_init(&nodo9, "icon", icon1, sizeof(char), strlen(icon1)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo9);

	char* root1 = "dropbox";
	Njson nodo10;
	njson_init(&nodo10, "root", root1, sizeof(char), strlen(root1)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo10);

	char* size2 = "2.3 MB";
	Njson nodo11;
	njson_init(&nodo11, "size", size2, sizeof(char), strlen(size2)+1, &njson_imprimir_string, false);

	char* rev2 = "38af1b183490";
	Njson nodo12;
	njson_init(&nodo12, "rev", rev2, sizeof(char), strlen(rev2)+1, &njson_imprimir_string, false);

	Njson* nodos2[2] = {&nodo11, &nodo12};
	json_init(&js2, nodos2, 2);

	bool thumb_exists2 = true;
	Njson nodo13;
	njson_init(&nodo13, "thumb_exists", &thumb_exists2, sizeof(bool), 1, &njson_imprimir_boolean, false);
	json_add(&js2, &nodo13);

	int bytes2 = 2453963;
	Njson nodo14;
	njson_init(&nodo14, "bytes", &bytes2, sizeof(int), 1, &njson_imprimir_int, false);
	json_add(&js2, &nodo14);

	char* modified2 = "Mon, 07 Apr 2014 23:13:16 +0000";
	Njson nodo15;
	njson_init(&nodo15, "modified", modified2, sizeof(char), strlen(modified2)+1, &njson_imprimir_string, false);
	json_add(&js2, &nodo15);

	char* client_mtime = "Thu, 29 Aug 2013 01:12:02 +0000";
	Njson nodo16;
	njson_init(&nodo16, "client_mtime", client_mtime, sizeof(char), strlen(client_mtime)+1, &njson_imprimir_string, false);
	json_add(&js2, &nodo16);

	char* path2 = "/Photos/flower.jpg";
	Njson nodo17;
	njson_init(&nodo17, "path", path2, sizeof(char), strlen(path2)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo17);

	double lat_long[2] = {37.77256666666666, -122.45934166666667};
	Njson nodo18;
	njson_init(&nodo18, "lat_long", &lat_long, sizeof(double), 2, &njson_imprimir_double, true);

	char* time_taken = "Wed, 28 Aug 2013 18:12:02 +0000";
	Njson nodo19;
	njson_init(&nodo19, "time_taken", time_taken, sizeof(char), strlen(time_taken)+1, &njson_imprimir_string, false);

	Njson* nodos3[2] = {&nodo18, &nodo19};
	json_init(&js3, nodos3, 2);

	Njson nodo26;
	njson_init(&nodo26, "photo_info", &js3, sizeof(Json), 1, &njson_imprimir_json, false);
	json_add(&js2, &nodo26);

	bool is_dir2 = false;
	Njson nodo20;
	njson_init(&nodo20, "is_dir", &is_dir2, sizeof(bool), 1, &njson_imprimir_boolean, false);
	json_add(&js, &nodo20);

	char* icon2 = "page_white_picture";
	Njson nodo21;
	njson_init(&nodo21, "icon", icon2, sizeof(char), strlen(icon2)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo21);

	char* root2 = "dropbox";
	Njson nodo22;
	njson_init(&nodo22, "root", root2, sizeof(char), strlen(root2)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo22);

	char* mime_type = "image/jpeg";
	Njson nodo23;
	njson_init(&nodo23, "mime_type", mime_type, sizeof(char), strlen(mime_type)+1, &njson_imprimir_string, false);
	json_add(&js, &nodo23);

	int revision1 = 14511;
	Njson nodo24;
	njson_init(&nodo24, "revision", &revision1, sizeof(int), 1, &njson_imprimir_int, false);
	json_add(&js2, &nodo24);

	Json jss[1] = {js2};
	Njson nodo27;
	njson_init(&nodo27, "contents", jss, sizeof(Json), 1, &njson_imprimir_json, true);
	json_add(&js, &nodo27);

	int revision2 = 29007;
	Njson nodo25;
	njson_init(&nodo25, "revision", &revision2, sizeof(int), 1, &njson_imprimir_int, false);
	json_add(&js, &nodo25);

	json_imprimir(&js, out);
	json_release(&js);
}
