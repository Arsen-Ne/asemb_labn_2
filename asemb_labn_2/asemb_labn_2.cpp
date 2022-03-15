#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int n;
    cout << "size off array = ";
    cin >> n;
    int* b = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        b[i] = rand() % 100;
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;

    int sum;
    int max = 0;
    int min = 0;
    int n1 = n - 1;
    _asm{
        mov ecx,n1
        mov ebx,b //занесение адреса массива b
        add ebx,4    
        mov esi,b // min address
        mov eax,[esi] // min value
        mov edi,b // max address
        mov edx,eax // max value
    l1 :
        cmp eax, [ebx] // сравниваем минимум с текущим
        jle e1 // если (eax < [ebx] == true) меньше 1й, то jmp to e1
        mov esi,ebx
        mov eax,[ebx]
        jmp e2
    e1:
        cmp edx, [ebx]
            jge e2
            mov edi, ebx
            mov edx, [ebx]
            e2 :
            add ebx, 4
            loop l1

            mov max, edx
            mov min, eax

            xor eax, eax

            cmp esi, edi
            jl e3

            mov ebx, edi            
            mov ecx, esi
            jmp l2
    e3 : 
        mov ebx, esi
        mov ecx, edi    

    l2:
        add eax,[ebx]
        add ebx,4
        cmp ebx,ecx
        jle l2

        mov sum,eax
    }
    cout << "min=" << min << endl;
    cout << "max=" << max << endl;
    cout << "sum=" << sum << endl;
}
