#include <iostream>

void polynomActions(int* array1, int n1, int* array2, int n2){
    int* sumOfPolynoms = new int[std::max(n1, n2)];
    for(int i = 0; i< std::max(n1, n2); i++)
        sumOfPolynoms[i] = 0;
    int* multiplicationOfPolynoms = new int[n1+n2-1];
    for(int i = 0; i< n1+n2-1; i++)
        multiplicationOfPolynoms[i] = 0;
    _asm{
        mov ebx, array1
        mov eax, 4
        mul n1
        sub eax, 4
        add ebx, eax

        mov esi, sumOfPolynoms
        mov eax, n1
        cmp eax, n2
        jl ChangeEax
        jmp MoveSumPointer
        ChangeEax:
        mov eax, n2
        MoveSumPointer:
        mov ecx, eax
        mov eax, 4
        mul ecx
        sub eax, 4
        add esi, eax

        mov eax, 4
        mul n2
        sub eax, 4
        mov edx, array2
        add edx, eax

        mov ecx, n1
        mov edi, n2
    CountSumm:
        dec ecx
        dec edi
        cmp ecx, 0
        jl CheckArray2
        mov eax, [ebx]
        add [esi], eax
        sub ebx, 4
    CheckArray2:
        cmp edi, 0
        jl FinalCheck
        mov eax,[edx]
        add[esi], eax
        sub edx, 4
    FinalCheck:
        sub esi, 4
        cmp ecx, 0
        jl CheckTheEndOfArray2
        jmp CountSumm
    CheckTheEndOfArray2:
        cmp edi, 0
        jl Continue
        jmp CountSumm
    Continue:
    }
    for(int i = 0; i<std::max(n1, n2); i++)
        std::cout<<sumOfPolynoms[i]<<" ";
    std::cout<<std::endl;
    _asm{
        mov edx, 0
        mov esi, 0
        mov ebx, array1
        sub ebx, 4
    CountMultiplication:
        mov eax, 4
        push edx
        imul edx
        pop edx

        inc edx
        cmp edx, n1
        jg End

        mov edi, multiplicationOfPolynoms
        add edi, eax
        add ebx, 4


        mov esi, 0
        mov ecx, array2
    MultiplyXAndPolynom2:
        inc esi
        cmp esi, n2
        jg CountMultiplication

        mov eax, 1
        push edx
        imul eax, [ecx]
        imul eax, [ebx]
        add [edi], eax
        pop edx
        add edi, 4
        add ecx, 4
        jmp MultiplyXAndPolynom2
    End:
    }
    for(int i = 0; i<n1+n2-1; i++)
        std::cout<<multiplicationOfPolynoms[i]<<" ";
    delete [] array1;
    delete [] array2;
    delete [] sumOfPolynoms;
    delete [] multiplicationOfPolynoms;
}

int main() {
    int n1, n2;
    std::cout << "Enter the amount of elements of the first array:";
    std::cin >> n1;
    std::cout << "Enter the amount of elements of the second array:";
    std::cin >> n2;
    int *array1 = new int[n1];
    int *array2 = new int[n2];
    int number = 0;
    std::cout << "Enter all elements of array1:";
    for (int i = 0; i < n1; i++) {
        std::cin >> number;
        array1[i] = number;
    }
    std::cout << "Enter all elements of array2:";
    for (int i = 0; i < n2; i++) {
        std::cin >> number;
        array2[i] = number;
    }
    polynomActions(array1, n1, array2, n2);
    return 0;
}
