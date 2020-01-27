#include <stdio.h>
#include <stdlib.h>
#include "wav.h"

wav_file* parse(char* contents) {

	wav_file wf;
	memcpy(&wf, contents, sizeof(wav_file));
	return &wf;
}
