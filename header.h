#ifndef HEADER_H
#define HEADER_H

typedef struct NES{
	//memory
	int mem[2048];
	//acumulator
	int A;
	//program counter
	int PC;
	//stack pointer
	int SP;
	//general purpose register
	int X;
	//general purpose register
	int Y;
	//state register for zero
	unsigned int SRz : 1;
	//state register for negative
	unsigned int SRn : 1;


}NES;

void Initiate(NES* emulator);

void Decode(int instruction, short* opcode, short* operator);

void Execute(NES* emulator, short opcode, short operator);

void Verbose(NES* emulator, short opcode, short operator);




#endif