/***********************************************
@author Carson Uecker-Herman
************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

/** wav struct */
wav_file wf;

/***********************************************
Parses a file into a wav file. The contents of
the file get saved into a wav struct.
@param contents the contents of the file
@return a pointer to the wav file
************************************************/
wav_file* parse(char* contents) {
	
	// copy the contents of the file into a wav struct
	memcpy(&wf, contents, sizeof(struct wav_file));
	
	return &wf;
}
