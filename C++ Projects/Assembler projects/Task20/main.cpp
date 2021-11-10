#include <iostream>
#include <string>

void reverseAllWords(char* words){
    char* result = new char[1000];
    int lengt;
    _asm{
        mov lengt, 0
        mov edx, 0
        cld
        mov edi, words
        mov esi, edi
        mov ecx, 0ffffffffh
        xor al, al
        repne scasb
        sub edi, esi
        dec edi
        mov lengt, edi

        mov ecx, edi
        mov esi, result
        mov edi, words
        mov eax, ' '

    NextWord:
        cmp ecx, 0
        je End

        mov ebx, edi  //Beginning of the word
        repne scasb
        mov edx, edi //End of the word
        jz IfSpace
        sub edi, 1
        jmp EndChecking
    IfSpace:
        sub edi, 2
    EndChecking:
        xchg edi, esi
        std
    Invert:
        cmp esi, ebx
        jl Continue
        movsb
        add edi, 2
        jmp Invert
    Continue:
        cld
        stosb
        xchg edi, esi
        mov edi, edx
        jmp NextWord
    End:
    }
    for(int i = 0; i<lengt; i++){
        std::cout<<result[i];
    }
}

int strLength(char * s)
{
    int res = 0;
    __asm
    {
    CLD; //задаем направление сканирования (сбрасываем флаг DF-флаг направления).
    //данный флаг учитывается в строковых операциях.Если флаг равен 1, то в строковых операциях
    //адрес автоматически уменьшается.Мы сбрасываем этот флаг,чтобы адрес автоматически увеличивался
    MOV EDI,s; // помещаем адрес начала строки в регистр EDI
    MOV ESI,EDI; //сохраняем адрес строки в регистре ESI
    MOV ECX, 0ffffffffh; //помещаем в регистр-счетчик цикла максимальное 32-битное целое число
    XOR AL,AL; //запускаем бесконечный цикл-операция XOR от двух одинаковых элементов возвращает 0
    //таким образом,эта команда представляет с собой "пока 0 ..."
    REPNE SCASB; //сканируем строку байтов, пока не встретится 0
    SUB EDI,ESI; //вычитаем из текущего адреса, который хранится в EDI, адрес начала строки(хранится в ESI ),
    //таким образом находим длину строки вместе с терминальным символом
    DEC EDI; //вычитаем из полученной длины строки 1- исключаем терминальный символ
    MOV res,EDI; //помещаем в переменную l на длину строки
    }
    return res; //возвращаем длину строки
    }

int countSumOfUpperTriangle(int** matrix, int n, int m){
    int result;
    _asm{
        mov eax, 0
        mov ebx, matrix
        mov ecx, -1
    CountSumOfUpperTriangle:
        inc ecx
        cmp ecx, n
        je End
        mov esi, [ebx+4*ecx]
        mov edx, ecx
        dec edx
    CountARow:
        inc edx
        cmp edx, m
        jge CountSumOfUpperTriangle
        add eax, [esi+4*edx];
        jmp CountARow
        End:
        mov result, eax
    }
    return result;
}
int main() {
    /*char* words = "a b c d";
    //std::cout<<strLength(words);
    reverseAllWords(words);*/
    int n, m;
    std::cin>>n>>m;
    int** matrix = new int*[n];
    for(int i = 0; i<n; i++){
        matrix[i] = new int[m];
        for(int j = 0; j<m; j++){
            std::cin>>matrix[i][j];
        }
    }
    for(int i = 0; i<n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout<<countSumOfUpperTriangle(matrix, n, m);
    return 0;
}
