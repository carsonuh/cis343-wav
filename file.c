#include <stdio.h>
#include <stdlib.h>
#include "file.h"

FILE* fp;
//char* buffer;

size_t read_file(char* filename, char** buffer) {
 fp = fopen(filename, "r");
 fseek(fp, 0, SEEK_END);
 size_t size = ftell(fp);
 fseek(fp, 0, SEEK_SET);

 *buffer = malloc(size);
 printf("Buffer allocated: %lu\n", sizeof(char)*size);
 fread(*buffer, sizeof(char), size, fp);
 fclose(fp);
 printf("SIZE read_file [FILE]: %lu\n",size);
 return size;
}

size_t write_file(char* filename, char* buffer, size_t size) {

fp = fopen(filename, "wb");
fseek(fp, 0, SEEK_END);
fseek(fp, 0, SEEK_SET);
size_t s = fwrite(buffer, sizeof(char), size, fp);
fclose(fp);
printf("SIZE write_file [FILE]: %lu\n", s);
return s;
}	
