//Carson Uecker-Herman

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "wav.h"


int main(int argc, char** argv) {
	char *buffer;
	wav_file *wav;
	size_t rval, wval;


	//read file
	rval = read_file(argv[1], &buffer);

	printf("SIZE read_file [MAIN]: %lu\n", rval);

	//parse
	wav = parse(buffer);
	
	//reverse
	
	char* reverse = buffer;
	
	int samp = wav->bits_per_samp / 8;
	//int size = wav->chunk_size;
	//printf("Size of WAV: %d\n",size);
	//char* c;
	int size = rval;
	
	for(int i = 0; i <= rval-44; i+=2) {
		reverse[44 + i] = buffer[rval-2-i];
		reverse[45 + i] = buffer[rval-1-i];
	}
	
	/*
	for (int i=size; i >= 44; i-=2){
		for(int j=0; j<=1; j++){
			reverse[size-(i-j)] = buffer[i-2*j];
			//reverse[size-(i-j)] = buffer[i-(2*j)];
		}
	}
	
	*/
	/*
	for (int i=44; i < rval; i++){
		buffer[i] = reverse[i];
	}
	*/
	
	
	wval = write_file(argv[2], reverse, rval);
	
	printf("SIZE write_file [MAIN]: %lu\n", wval);
	
	//DumpHex(buffer, rval);

		
	printf("=============================================\n");
	printf("beg: %s\n", wav->beg);
	printf("chunk_size: %d\n", wav->chunk_size);
	printf("wave: %s\n", wav->wave);
	printf("fmt: %s\n", wav->fmt);
	printf("fmt_length: %d\n", wav->fmt_length);
	printf("fmt_type: %d\n", wav->fmt_type);
	printf("num_channels: %d\n", wav->num_channels);
	printf("sample_rate: %d\n", wav->sample_rate);
	printf("bits_per_sample: %d\n",wav->bits_per_sample);
	printf("block_alignment: %d\n", wav->block_alignment);
	printf("bits_per_sample: %d\n", wav->bits_per_samp);
	printf("beg_data: %s\n", wav->beg_data);
	printf("size_data: %d\n", wav->size_data);
	//printf("act_data: %s\n", wav->act_data);
	printf("=============================================\n\n");





	printf("File: %s\n", argv[1]);
	printf("===============================================\n");
	printf("File size is %d. Read %zu btyes.\n", wav->chunk_size, wval);
	printf("Format is %s with format data length %d.\n", wav->fmt, wav->fmt_length);
	printf("Format type is %s.\n", wav->wave);
	printf("%d channels with sample rate of %d.\n", wav->num_channels, wav->sample_rate);
	printf("%d byte rate, %d alignment, %d bits per sample\n", wav->bits_per_samp, wav->block_alignment, wav->bits_per_sample);
	printf("Data is %s and data size is %d\n", wav->beg_data, wav->size_data); 


	free(buffer);
	//free(reverse);
	return 0;
}


