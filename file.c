#include <stdio.h>
#include <stdlib.h>
#include "file.h"

FILE* fp;
char* buffer;

size_t read_file(char* filename, char** buffer) {
 fp = fopen(filename, "rb");
 fseek(fp, 0, SEEK_END);
 size_t size = ftell(fp);
 
 *buffer = malloc(size * sizeof(char));

 size = fread(*buffer, sizeof(char), size, fp);

 fclose(fp);

 return size;
}

size_t write_file(char* filename, char* buffer, size_t size) {

fp = fopen(filename, "wb");
size_t res;
res = fwrite(buffer, sizeof(char), size, fp);
fclose(fp);
return res;
}	
