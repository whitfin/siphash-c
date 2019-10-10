#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "src/siphash.h"

int main(int argc, char *argv[]){
		FILE* fileptr;
		long filelen;
		char* key = NULL;
		char* input = NULL;

		int c = 0, d = 0, option = 0, input_len = 0;

		if (argc < 2) {
				printf("Usage: siphash -k <key> [-i <input> | -f <filepath>] [-c=2] [-d=4] [-l=0]\n");
				return 1;
		}

		while ((option = getopt(argc, argv, "f:k:i:c:d:l:")) != -1) {
				switch (option) {
						case 'c':
								c = atoi(optarg);
								break;
						case 'd':
								d = atoi(optarg);
								break;
						case 'f':
								if (access(optarg, F_OK) == -1) {
										break;
								}
								fileptr = fopen(optarg, "rb");
								fseek(fileptr, 0, SEEK_END);
								filelen = ftell(fileptr);
								rewind(fileptr);
								input = (char*) malloc((filelen + 1) * sizeof(char));
								fread(input, (size_t) filelen, 1, fileptr);
								fclose(fileptr);
								break;
						case 'i':
								input = optarg;
								break;
						case 'k':
								key = optarg;
								break;
						case 'l':
								input_len = atoi(optarg);
								break;

				}
		}

		if (key == NULL || input == NULL) {
				printf("Usage: siphash -k <key> [-i <input> | -f <filepath>] [-c=2] [-d=4] [-l=0]\n");
				return 1;
		}

		if (strlen(key) != 16) {
				printf("Key must consist of exactly 16 bytes!\n");
				return 1;
		}

		if (c <= 0) {
				c = 2;
		}

		if (d <= 0) {
				d = 4;
		}

		printf("%" PRIu64 "\n", siphash(key, input, c, d, input_len));

    return 0;
}
