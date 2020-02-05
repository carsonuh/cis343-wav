/***********************************************
@author Carson Uecker-Herman
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "file.h"

/** file pointer */
FILE* fp;

/************************************************
Reads the file that is passed in and mallocs 
the buffer to the size of the file. The contents 
of the file is then read into the buffer.
@param filename the name of the file
@param buffer the address of the buffer
@return size the size of file 
************************************************/
size_t read_file(char* filename, char** buffer) {
 
 // open file
 fp = fopen(filename, "rb");
 fseek(fp, 0, SEEK_END);
 size_t size = ftell(fp);
 fseek(fp, 0, SEEK_SET);

 // malloc buffer to size of file
 *buffer = malloc(size);
 
 // read file into buffer
 fread(*buffer, sizeof(char), size, fp);

 // check if there is an error reading file 
 if(ferror(fp)){
	 printf("Error reading: %s/n", filename);
 }
 
 // check if end of the file has been reached
 if(feof(fp)) {
	 printf("End of file reached./n");
 }

 // close file
 fclose(fp);

 return size;
}

/************************************************
Writes a file to system 
@param filename the name of the file
@param buffer the contents of the file
@param size the size of the file
@return size of written file
************************************************/
size_t write_file(char* filename, char* buffer, size_t size) {

// open file
fp = fopen(filename, "wb");
fseek(fp, 0, SEEK_END);
fseek(fp, 0, SEEK_SET);

// write file to system
size_t s = fwrite(buffer, sizeof(char), size, fp);

// check if there was an error writing to file
if(ferror(fp)) {
	printf("Error writing to file: %s/n", filename);
}

// close file
fclose(fp);

return s;
}	
