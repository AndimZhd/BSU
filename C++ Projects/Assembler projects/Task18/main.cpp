#include <iostream>
double count(int n, double x, double y){
    double result;
    int divider;
    int factorialOf4;
    _asm{
        mov factorialOf4, 24

        fld x
        fadd y
        fst result
        fmul result
        fmul result//ST(4) = multiplicator
        fldz//ST(3) = result
        fst result

        fld1 //ST(2) = previousMultiplicator
        fldz //ST(1) = previousSum
        fld1 //ST(0) = previousMember
        fidiv factorialOf4
        mov ecx, 1
    MainLoop:
        cmp ecx, n
        jg End
        mov divider, ecx
        add divider, 4
        fidiv divider
        fmul st, st(4)

        fadd st(1), st

        fxch
        fmul st(2), st
        fxch

        fxch st(2)
        fadd st(3), st
        fxch st(2)

        inc ecx
        jmp MainLoop
    End:
        fxch st(3)
        fst result
        finit
    }
    return result;
}

int main() {
    int n;
    double x, y;
    std::cin>>n>>x>>y;
    std::cout<<count(n, x, y);
    return 0;
}