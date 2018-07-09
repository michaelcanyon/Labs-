#include<iostream>
using namespace std;
int main()
{
 int a = 1, b = -3, c = 12, d = 4, x = -3, r;
	

	_asm
	{
		//(d2 + x)·b·c
		mov ax, x
		mov dx,0	
		mov cx,0
		L3:
		cmp ax, dx
		JL L1
		L1 :
		inc ax
		inc cx
		jmp L3
		mov bx, x
		L2:
		mov ax, d
			mul ax
			add ax, bx
			push bx
			mov bx, b
			mul bx
			mov bx, c
			mul bx
			pop bx
			inc bx
			mov r, ax
			Loop L2

		



		
	
	}
	cout << "r equals" + r;
	system("pause");
	return 0;
}