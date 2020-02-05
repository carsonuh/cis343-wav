/***********************************************
@author Carson Uecker-Herman
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "wav.h"


int main(int argc, char** argv) {
	
	/** buffer to hold the contents of a file */
	char* buffer;
	
	/** buffer to hold the reverse contents of file */
	char* reverse;

	/** wav struct */
	wav_file *wav;

	/** size of read_file and write_file */
	size_t rval, wval;

	// read file that passed from the command line 
	rval = read_file(argv[1], &buffer);

	// parse the contents of the file into a wav struct
	wav = parse(buffer);
	
	// malloc reverse buffer
	reverse = malloc(rval);
	
	// copy header of buffer to reverse
	for(int i=0; i<44; i++) {
		reverse[i] = buffer[i];
	}

	int samp = wav->bits_per_samp / 8;
	int size = rval;

	// reverse contents
	for (int i=size; i >= 44; i-=samp){
		for(int j=0; j<=1; j++){
			if((i-j)>43){
			reverse[size-(i-j)+44] = buffer[i-j];
			}
		}
	}	
	
	// write the reversed contents to second filename from the command line
	wval = write_file(argv[2], reverse, rval);
		
	// output 
	printf("File: %s\n", argv[1]);
	printf("===============================================\n");
	printf("File size is %zu. Read %d bytes.\n", rval, wav->chunk_size);
	printf("Format is '%.*s' with format data length %d.\n", 4, wav->fmt, wav->fmt_length);
	printf("Format type is '%.*s'.\n", 4, wav->wave);
	printf("%d channels with sample rate of %d.\n", wav->num_channels, wav->sample_rate);
	printf("%d byte rate, %d alignment, %d bits per sample\n", wav->bits_per_samp, wav->block_alignment, wav->bits_per_sample);
	printf("Data is '%.*s' and data size is %d\n", 4, wav->beg_data, wav->size_data); 

	// free buffers
	free(buffer);
	free(reverse);

	return 0;
}


