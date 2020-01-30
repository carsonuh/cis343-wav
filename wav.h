#ifndef   __H_WAV_FILE__
#define   __H_WAV_FILE__

typedef struct wav_file{
	char beg[4];
        int chunk_size;
	char wave[4];
 	char fmt[4];
	int fmt_length;
	short fmt_type;
	short num_channels;
	int sample_rate;
	int bits_per_sample;
	short block_alignment;
	short bits_per_samp;
	char beg_data[4];
	int size_data;
	char* act_data;	
} wav_file;

wav_file* parse(char* contents);

#endif
