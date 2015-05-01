#include "header.h"
#include <stdio.h>

void Initiate(NES* emulator){
	
	emulator->PC  = 0;
	emulator->SP  = 1983;
	emulator->A   = 0;
	emulator->X   = 0;
	emulator->Y   = 0;
	emulator->SRz = 0;
	emulator->SRn = 0;

}

void Decode(int instruction, short* opcode, short* operator){
	int aux = 1;
	int i;
	for(i=0; i<15; ++i){
		*operator += (instruction & aux);
		aux <<= 1;
	}
	int negativeFlag = (instruction & aux);
	if(negativeFlag > 0){
		*operator = -*operator;
	}
	for(i=16; i<32; ++i){
		*opcode += ((instruction & aux) / 65536);
		aux <<= 1;
	}
}

void READ(NES* emulator){
	int input;
	printf("Enter an integer:");
	scanf("%d", &input);
	emulator->A = input;
}

void WRITE(NES* emulator){
	printf("%d\n", emulator->A);
}

void LDA(NES* emulator, int M){
	emulator->A = emulator->mem[emulator->PC + M - 1];
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void LDX(NES* emulator, int M){
	emulator->X = emulator->mem[emulator->PC + M - 1];
	if(emulator->X == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->X < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void LDY(NES* emulator, int M){
	emulator->Y = emulator->mem[emulator->PC + M - 1];
	if(emulator->Y == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->Y < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void STA(NES* emulator, int M){
	emulator->mem[emulator->PC + M - 1] = emulator->A;
}

void STX(NES* emulator, int M){
	emulator->mem[emulator->PC + M - 1] = emulator->X;
}

void STY(NES* emulator, int M){
	emulator->mem[emulator->PC + M - 1] = emulator->Y;
}

void TAX(NES* emulator){
	emulator->X = emulator->A;
	if(emulator->X == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->X < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void TAY(NES* emulator){
	emulator->Y = emulator->A;
	if(emulator->Y == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->Y < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void TXA(NES* emulator){
	emulator->A = emulator->X;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void TYA(NES* emulator){
	emulator->A = emulator->Y;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void ADDX(NES* emulator){
	emulator->A += emulator->X;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void ADDY(NES* emulator){
	emulator->A += emulator->Y;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void SUBX(NES* emulator){
	emulator->A -= emulator->X;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void SUBY(NES* emulator){
	emulator->A -= emulator->Y;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void DEC(NES* emulator, int M){
	--emulator->mem[emulator->PC + M - 1];
	if(emulator->mem[emulator->PC +  - 1] == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->mem[emulator->PC + M - 1] < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void DECX(NES* emulator){
	--emulator->X;
	if(emulator->X == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->X < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

}

void DECY(NES* emulator){
	--emulator->Y;
	if(emulator->Y == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->Y < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

}

void INC(NES* emulator, int M){
	++emulator->mem[emulator->PC + M - 1];
	if(emulator->mem[emulator->PC + M - 1] == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->mem[emulator->PC + M - 1] < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void INCX(NES* emulator){
	++emulator->X;
	if(emulator->X == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->X < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

}

void INCY(NES* emulator){
	++emulator->Y;
	if(emulator->Y == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->Y < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

}

void AND(NES* emulator, int M){
	emulator->A = emulator->A & emulator->mem[emulator->PC + M - 1];
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void OR(NES* emulator, int M){
	emulator->A = emulator->A | emulator->mem[emulator->PC + M - 1];
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void XOR(NES* emulator, int M){
	emulator->A = emulator->A ^ emulator->mem[emulator->PC + M - 1];
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}


void CMP(NES* emulator, int M){
	int aux = emulator->A - emulator->mem[emulator->PC + M - 1];
	if(aux < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

	if(aux == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}

}

void CPX(NES* emulator, int M){
	int aux = emulator->X - emulator->mem[emulator->PC + M - 1];
	if(aux < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

	if(aux == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}

}

void CPY(NES* emulator, int M){
	int aux = emulator->Y - emulator->mem[emulator->PC + M - 1];
	if(aux < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}

	if(aux == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}

}

void JMP(NES* emulator, int M){
	emulator->PC += M;
}

void BEZ(NES* emulator, int M){
	if(emulator->SRz == 1){
		emulator->PC +=M;
	}else{
		++emulator->PC;
	}
}

void BNZ(NES* emulator, int M){
	if(emulator->SRz == 0){
		emulator->PC +=M;
	}else{
		++emulator->PC;
	}
}

void BEN(NES* emulator, int M){
	if(emulator->SRn == 1){
		emulator->PC +=M;
	}else{
		++emulator->PC;
	}
}

void BNN(NES* emulator, int M){
	if(emulator->SRn == 0){
		emulator->PC += M;
	}else{
		++emulator->PC;
	}
}

void PUSH(NES* emulator){
	++emulator->SP;
	emulator->mem[emulator->SP] = emulator->A;
}

void POP(NES* emulator){
	emulator->A = emulator->mem[emulator->SP];
	--emulator->SP;
	if(emulator->A == 0){
		emulator->SRz = 1;
	}else{
		emulator->SRz = 0;
	}
	if(emulator->A < 0){
		emulator->SRn = 1;
	}else{
		emulator->SRn = 0;
	}
}

void CALL(NES* emulator, int M){
	++emulator->SP;
	emulator->mem[emulator->SP] = emulator->PC;
	emulator->PC += M;
}

void RET(NES* emulator){
	emulator->PC = emulator->mem[emulator->SP];
	--emulator->SP;
}

void DUMP(NES* emulator){
	printf("  A = %d PC = %d SP = %d X = %d Y = %d SRz = %d SRn = %d\n", emulator->A, emulator->PC, emulator->SP, emulator->X, emulator->Y, emulator->SRz, emulator->SRn);
}

void HALT(NES* emulator){
	return;
}

void Verbose(NES* emulator, short opcode, short operator){
	switch(opcode){
		case 1:
			printf("READ ");
			DUMP(emulator);
			++emulator->PC;
			READ(emulator);
			break;

		case 2:
			printf("WRITE  ");
			DUMP(emulator);
			++emulator->PC;
			WRITE(emulator);
			break;
		
		case 3:
			printf("LDA  ");
			DUMP(emulator);
			++emulator->PC;
			LDA(emulator, operator);
			break;
		
		case 4:
			printf("LDX  ");
			DUMP(emulator);
			++emulator->PC;
			LDX(emulator, operator);
			break;
		
		case 5:
			printf("LDY  ");
			DUMP(emulator);
			++emulator->PC;
			LDY(emulator, operator);
			break;
		
		case 6:
			printf("STA  ");
			DUMP(emulator);
			++emulator->PC;
			STA(emulator, operator);
			break;
		
		case 7:
			printf("STX  ");
			DUMP(emulator);
			++emulator->PC;
			STX(emulator, operator);
			break;		

		case 8: 
			printf("STY  ");
			DUMP(emulator);
			++emulator->PC;
			STY(emulator, operator);
			break;		

		case 9:
			printf("TAX  ");
			DUMP(emulator);
			++emulator->PC;
			TAX(emulator);
			break;
					
		case 10:
			printf("TAY  ");
			DUMP(emulator);
			++emulator->PC;
			TAY(emulator);
			break;
					
		case 11:
			printf("TXA  ");
			DUMP(emulator);
			++emulator->PC;
			TXA(emulator);
			break;
					
		case 12:
			printf("TYA  ");
			DUMP(emulator);
			++emulator->PC;
			TYA(emulator);
			break;
					
		case 13:
			printf("ADDX ");
			DUMP(emulator);
			++emulator->PC;
			ADDX(emulator);
			break;
		
		case 14:
			printf("ADDY ");
			DUMP(emulator);
			++emulator->PC;
			ADDY(emulator);
			break;
		
		case 15:
			printf("SUBX ");
			DUMP(emulator);
			++emulator->PC;
			SUBX(emulator);
			break;

		case 16:
			printf("SUBY ");
			DUMP(emulator);
			++emulator->PC;
			SUBY(emulator);
			break;

		case 17:
			printf("DEC  ");
			DUMP(emulator);
			++emulator->PC;
			DEC(emulator, operator);
			break;
		
		case 18:
			printf("DECX ");
			DUMP(emulator);
			++emulator->PC;
			DECX(emulator);
			break;
		
		case 19:
			printf("DECY ");
			DUMP(emulator);
			++emulator->PC;
			DECY(emulator);
			break;
		
		case 20:
			printf("INC  ");
			DUMP(emulator);
			++emulator->PC;
			INC(emulator, operator);
			break;
		
		case 21:
			printf("INCX ");
			DUMP(emulator);
			++emulator->PC;
			INCX(emulator);
			break;
		
		case 22:
			printf("INCY ");
			DUMP(emulator);
			++emulator->PC;
			INCY(emulator);
			break;			

		case 23:
			printf("AND  ");
			DUMP(emulator);
			++emulator->PC;
			AND(emulator, operator);
			break;
					
		case 24:
			printf("OR   ");
			DUMP(emulator);
			++emulator->PC;
			OR(emulator, operator);
			break;
					
		case 25:
			printf("XOR  ");
			DUMP(emulator);
			++emulator->PC;
			XOR(emulator, operator);
			break;
					
		case 26:
			printf("CMP  ");
			DUMP(emulator);
			++emulator->PC;
			CMP(emulator, operator);
			break;
					
		case 27:
			printf("CPX  ");
			DUMP(emulator);
			++emulator->PC;
			CPX(emulator, operator);
			break;
		
		case 28:
			printf("CPY  ");
			DUMP(emulator);
			++emulator->PC;
			CPY(emulator, operator);
			break;
		
		case 29:
			printf("JMP  ");
			DUMP(emulator);
			JMP(emulator, operator);
			break;

		case 30:
			printf("BEZ  ");
			DUMP(emulator);
			BEZ(emulator, operator);
			break;
		
		case 31:
			printf("BNZ  ");
			DUMP(emulator);
			BNZ(emulator, operator);
			break;		

		case 32:
			printf("BEN  ");
			DUMP(emulator);
			BEN(emulator, operator);
			break;		

		case 33:
			printf("BNN  ");
			DUMP(emulator);
			BNN(emulator, operator);
			break;
					
		case 34:
			printf("PUSH ");
			DUMP(emulator);
			++emulator->PC;
			PUSH(emulator);
			break;
					
		case 35:
			printf("POP  ");
			DUMP(emulator);
			++emulator->PC;
			POP(emulator);
			break;
					
		case 36:
			printf("CALL ");
			DUMP(emulator);
			++emulator->PC;
			CALL(emulator, operator);
			break;
					
		case 37:
			printf("RET  ");
			DUMP(emulator);
			++emulator->PC;
			RET(emulator);
			break;

		case 38:
			printf("DUMP ");
			++emulator->PC;
			DUMP(emulator);
			break;
					
		case 39:
			printf("HALT ");
			DUMP(emulator);
			++emulator->PC;
			HALT(emulator);
			break;

		default:
			printf("Invalid opcode\n");
			break;
	}
}

void Execute(NES* emulator, short opcode, short operator){
	switch(opcode){
		case 1:
			++emulator->PC;
			READ(emulator);
			break;

		case 2:
			++emulator->PC;
			WRITE(emulator);
			break;
		
		case 3:
			++emulator->PC;
			LDA(emulator, operator);
			break;
		
		case 4:
			++emulator->PC;
			LDX(emulator, operator);
			break;
		
		case 5:
			++emulator->PC;
			LDY(emulator, operator);
			break;
		
		case 6:
			++emulator->PC;
			STA(emulator, operator);
			break;
		
		case 7:
			++emulator->PC;
			STX(emulator, operator);
			break;		

		case 8:
			++emulator->PC;
			STY(emulator, operator);
			break;		

		case 9:
			++emulator->PC;
			TAX(emulator);
			break;
					
		case 10:
			++emulator->PC;
			TAY(emulator);
			break;
					
		case 11:
			++emulator->PC;
			TXA(emulator);
			break;
					
		case 12:
			++emulator->PC;
			TYA(emulator);
			break;
					
		case 13:
			++emulator->PC;
			ADDX(emulator);
			break;
		
		case 14:
			++emulator->PC;
			ADDY(emulator);
			break;
		
		case 15:
			++emulator->PC;
			SUBX(emulator);
			break;

		case 16:
			++emulator->PC;
			SUBY(emulator);
			break;

		case 17:
			++emulator->PC;
			DEC(emulator, operator);
			break;
		
		case 18:
			++emulator->PC;
			DECX(emulator);
			break;
		
		case 19:
			++emulator->PC;
			DECY(emulator);
			break;
		
		case 20:
			++emulator->PC;
			INC(emulator, operator);
			break;
		
		case 21:
			++emulator->PC;
			INCX(emulator);
			break;
		
		case 22:
			++emulator->PC;
			INCY(emulator);
			break;			

		case 23:
			++emulator->PC;
			AND(emulator, operator);
			break;
					
		case 24:
			++emulator->PC;
			OR(emulator, operator);
			break;
					
		case 25:
			++emulator->PC;
			XOR(emulator, operator);
			break;
					
		case 26:
			++emulator->PC;
			CMP(emulator, operator);
			break;
					
		case 27:
			++emulator->PC;
			CPX(emulator, operator);
			break;
		
		case 28:
			++emulator->PC;
			CPY(emulator, operator);
			break;
		
		case 29:
			JMP(emulator, operator);
			break;

		case 30:
			BEZ(emulator, operator);
			break;
		
		case 31:
			BNZ(emulator, operator);
			break;		

		case 32:
			BEN(emulator, operator);
			break;		

		case 33:
			BNN(emulator, operator);
			break;
					
		case 34:
			++emulator->PC;
			PUSH(emulator);
			break;
					
		case 35:
			++emulator->PC;
			POP(emulator);
			break;
					
		case 36:
			++emulator->PC;
			CALL(emulator, operator);
			break;
					
		case 37:
			++emulator->PC;
			RET(emulator);
			break;

		case 38:
			++emulator->PC;
			DUMP(emulator);
			break;
					
		case 39:
			++emulator->PC;
			HALT(emulator);
			break;

		default:
			printf("Invalid opcode\n");
			break;
	}

}

