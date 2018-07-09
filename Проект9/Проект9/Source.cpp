#include<iostream>
#include<stdio.h>
using namespace std;
void main()
{
	short int a = 8, b = -6, c = 0, d = 0, m = 0 ;
	_asm {
		/*mov ax, a; ax присваиваем а
		imul b; b умножаем на ах
		mov bx, c; ax присваемваем с
		add bx, 13; добавляем к ax 13
		idiv bx
		mov ax, d
		imul ax, 2
		sub dx, ax
		mov m, dx*/
		mov ax,a
		mul a
		mul a
		mov c,ax
		mov ax, b
		imul b 
		imul b
		add c,ax
		mov ax,a
		mul a
		mov bx, ax
		mov ax, b
		mul b
		and bx, ax
		mov ax,c
		xor ax,bx
		mov m,ax






	}
	short int k = (((a*a*a)+(b*b*b))^((a*a)&(b*b)));
	cout << "result assembler " << m<<endl;
	cout << "result c " << k;
	
	system("pause");
}