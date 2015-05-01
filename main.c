#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char** argv){
	FILE* input;
	FILE* output;
	char mode;
	NES emulator;

	input = fopen(argv[1], "rb");
	mode = argv[2][0];

	int a;
	int i = 0;
	while(!feof(input)){
		fread(&a, sizeof(int), 1, input);
		emulator.mem[i] = a;
		++i;
	}

	Initiate(&emulator);

	if(mode == 's'){
		while(1){
			short operator = 0;
			short opcode = 0;
			Decode(emulator.mem[emulator.PC], &opcode, &operator);
			Execute(&emulator, opcode, operator);
			if(opcode == 39 || opcode > 39 || opcode < 1) return 0;
		}
	}else if(mode == 'v'){
		while(1){
			short int operator = 0;
			short int opcode = 0;
			Decode(emulator.mem[emulator.PC], &opcode, &operator);
			Verbose(&emulator, opcode, operator);
			printf("\n");
			if(opcode == 39 || opcode > 39 || opcode < 1) return 0;
		}
	}else{
		printf("Invalid Mode\n");
		return 0;
	}
}