#define _CRT_SECURE_NO_WARNINGS
#define ERRCODE -99999
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>
//#include <GL/freeglut.h>
struct Task1Point
{
public:
	double X;
	double Y;
};
void Task1GettingData(double &X1, double &X2, double &X3, double &P1, double &P2, double &A, double &B);
double FirstFunc(double &X1, double &X2, double &X3, double &P1, double &P2, double &A, double &B);
double ThirdFunc(double &X1, double &X2, double &X3, double &P1, double &P2, double &A, double &B);
int Fact(int num);
/*void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//очищаем буфер
	glColor3f(1.0f, 0.0f, 0.0f);//задаем цвет рисования
	glLineWidth(3);//задаем толщину линии
	glBegin(GL_LINES);//говорим что будем рисовать линию
	glVertex2d(-1, 0);//координата начала отрезка в формате (x,y)
	glVertex2d(1, 0);//координата конца отрезка
	glEnd();//говорим что закончили рисовать линию
	glutSwapBuffers();//прорисовываем буфер на экран
}
*/
int main(int argc, char **argv)
{
	int C;
	printf("Press: 0 to calculate task function; 1 to 'still unknown task', 2 to 'still unknown task', 3 to 'still unknown task', 4 to exit:");
	scanf("%d", &C);	
	switch (C)
	{
	case 0:
		double X1, X2, X3, P1, P2, A, B;
		Task1GettingData(X1, X2, X3, P1, P2, A, B);
		struct Task1Point *salvations = (struct Task1Point*)malloc(((X2 - X1) / X3) * sizeof(Task1Point));
		int i;
		for (i = 0; X1 < P1; i++, X1 += X3)
		{
			salvations[i].X = X1;
			salvations[i].Y = FirstFunc(X1, X2, X3, P1, P2, A, B);
		}
		for (; X1 < P2; i++, X1 += X3)
		{
			salvations[i].X = X1;
			salvations[i].Y = cos(A * X1);
		}
		for (; X1 < X2; i++, X1 += X3)
		{
			salvations[i].X = X1;
			salvations[i].Y = ThirdFunc(X1, X2, X3, P1, P2, A, B);
		}
	/*	glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_DOUBLE);
		glutInitWindowSize(200, 200);
		glutInitWindowPosition(200, 200);
		glutCreateWindow("Window");
		glClearColor(1, 1, 1, 0);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-10, 10, -10, 10, 0, 0);
		glutDisplayFunc(display);
		glutMainLoop();
		break;
		*/

	}
}

void Task1GettingData(double &X1, double &X2, double &X3, double &P1,double &P2, double &A, double &B)
{
	int preferableMode=0;
	printf("Press 0 if you want to declare data on your own or else number to read data from file");
	scanf("%d", &preferableMode);
	printf("\n");
	if (preferableMode == 0)
	{
		printf("X1=");
		scanf("%f", X1);
		printf("\nX2=");
		scanf("%f", X2);
		printf("\nX3=");
		scanf("%f", X3);
		printf("\nP1=");
		scanf("%f", P1);
		printf("\nP2=");
		scanf("%f", P2);
		printf("\nA=");
		scanf("%f", A);
		printf("\nB=");
		scanf("%f", B);
		printf("\n");
	}
	else
	{
		char filePath[256];
		printf("Enter the filepath:");
		scanf("%s", filePath);
		char *filepath1 = filePath;
		char hy[15];
		//filePath = "C:\\Users\\hrani\\Desktop\\exp.txt";

		FILE *f = fopen("exp.txt","r");
			
		fscanf(f, "%f", hy);
		fscanf(f, "%f", X2);
		fscanf(f, "%f", X3);
		fscanf(f, "%f", P1);
		fscanf(f, "%f", P2);
		fscanf(f, "%f", A);
		fscanf(f, "%f", B);
		/*{
			printf("File Error! Shutting down the program!");
			X1 = ERRCODE;
			fclose(f);
			return;
		}
		else
			fclose(f);
			*/
	}
}

double FirstFunc(double &X1, double &X2, double &X3, double &P1, double &P2, double &A, double &B)
{
	return ((1 + X1 +pow(X1, 2) / Fact(2) + pow(X1, 3) / Fact(3) + pow(X1, 4) / Fact(4) + pow(X1, 5) / Fact(5) + pow(X1, 6) / Fact(6) +
		pow(X1, 7) / Fact(7) + pow(X1, 8) / Fact(8) + pow(X1, 9) / Fact(9) + pow(X1, 10) / Fact(10)) * sin(B* X1));
}
double ThirdFunc(double &X1, double &X2, double &X3, double &P1, double &P2, double &A, double &B)
{
	return ((1 + X1 + pow(X1, 2) / Fact(2) + pow(X1, 3) / Fact(3) + pow(X1, 4) / Fact(4) + pow(X1, 5) / Fact(5) + pow(X1, 6) / Fact(6) +
		pow(X1, 7) / Fact(7) + pow(X1, 8) / Fact(8) + pow(X1, 9) / Fact(9) + pow(X1, 10) / Fact(10)) * cos(B * X1));
}
int Fact(int num)
{
	if (num <= 1)
		return 1;
	else
		return num * Fact(num - 1);
}
