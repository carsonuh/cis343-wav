#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

wav_file wf;
wav_file* parse(char* contents) {

	memcpy(&wf, contents, sizeof(struct wav_file));
	return &wf;
}
