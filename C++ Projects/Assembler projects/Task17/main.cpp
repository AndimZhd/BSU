#include <iostream>
/*int x;
int divider;
std::cin >> x;
_asm {
	mov ecx, 2
	mov eax, x
	mainLoop : cmp eax, 0
	jle L2
	div ecх
	mov divider, eax
	mul ecx
	cmp x, eax
	je ifZero
	jne ifNotZero
	ifZero : }
{std::cout << divider << " "; }
_asm {
smallLoop:

ifNotZero:


	mov eax
		jmp mainLoop



	L2:
}*/

bool isPrime(int number){
	_asm {
		mov eax, number
		mov ecx, 2
	mainLoop :
		cmp ecx, eax
		je End
		mov edx, 0
		div ecx
		mul ecx
		cmp eax, number
		je Break
		inc ecx
		mov eax, number
	    jmp mainLoop
	    Break :
	}
	return false;
	_asm {
		End:
	}
	return true;
}

void LCMAndGCD(int number1, int number2) {
	int GCD;
	int LCM;
	_asm {
		mov eax, number1
		mov ecx, number2
		mov edx, 0
		cmp eax, ecx
		jl Change
		jge CountGCD
	Change:
		xchg eax, ecx
	CountGCD:
		div ecx
		cmp edx, 0
		je CountLCM
		mov eax, ecx
		mov ecx, edx
		mov edx, 0
		jmp CountGCD
	CountLCM:
		mov GCD, ecx
		mov eax, number1
		mov ecx, number2
		mul ecx
		div GCD
		mov LCM, eax
	}
	std::cout << "LCM = " << LCM << ", GCD = " << GCD;
}

int sumOfCubesFrom0ToN(int n) {
	_asm {
		mov eax, n
		mov ecx, eax
		add ecx, 1
		mul ecx
		mov ecx, 2
		div ecx
		mov ecx, eax
		mul ecx
		mov n, eax
	}
	return n;
}

void writeAllDigitsOfTheNumber(int number){
	int allDigits[1000];
	int* pointer;
	int printer;
	_asm {
		lea ebx, allDigits
		mov pointer, ebx
		mov ecx, 10
		mov eax, number
		mov edx, 0
	WhileNotZero:
		cmp eax, 0
		je PreparingToPrint
		div ecx
		mov[ebx], edx
		mov edx, 0
		add ebx, type allDigits
		jmp WhileNotZero
	PreparingToPrint :
		mov pointer, ebx
	Print:
		sub pointer, type allDigits
		mov ecx, pointer
		mov edx, [ecx]
		mov printer, edx
	}
	std::cout << printer << " ";
	_asm{
		lea ebx, allDigits
		cmp ebx, pointer
		je End
		jmp Print
	End:
	}
}

int main() {
	int number;
	std::cin >> number;
	if (isPrime(number))
		std::cout << "The number is prime";
	else
		std::cout << "The number isn't prime";
	int number2;
	std::cin >> number2;
	LCMAndGCD(number, number2);
	//std::cout << sumOfCubesFrom0ToN(number);
	//writeAllDigitsOfTheNumber(number);
}