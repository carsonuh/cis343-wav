//Carson Uecker-Herman

#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "wav_file.h"

int main(int argc, char** argv) {
	char *buffer;
	char *reverse;
	wav_file wav;
	
	//read file
	read_file(argv[1], *buffer);
	
	//parse
	wav = parse(buffer);
	
	//reverse
	int samp = wav.bits_sample / 8;
	int content_size = sizeof(wav.actual_data);
	char* c;
	for(int i = content_size; i >= 0; i-=samp) {
		//c[i-2] = 
		//c[i-1] = 
	}



}
