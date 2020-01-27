#ifndef   __H_WAV_FILE__
#define   __H_WAV_FILE__

typedef struct wav_struct{
	beg char[4];
        chunk_size int;
	wave char[4];
 	fmt char[4];
	fmt_length int;
	fmt_type short;
	num_channels short;
	sample_rate int;
	block_alignment short;
	bits_per_sample short;
	beg_data char[4];
	size_data int;
	act_data char*;	
} wav_file

wav_file* parse(char* contents);

#endif
