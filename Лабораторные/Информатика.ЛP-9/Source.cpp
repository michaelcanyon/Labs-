#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	FILE *fin;
	fin = fopen("filelab9.txt", "r");
	if (fin != NULL)
	{
		int stringCounter = 1;
		char buffer[256];
		fgets(buffer, 256, fin);
		int sizeOfMaxString = 0;
		int sizeOfCurrentString = 0;
		int eofi;
		eofi = fgetc(fin);
		if (eofi == EOF)
		{
			perror("File is empty");
			fclose(fin);
			system("PAUSE");
			return 0;
		}
		else
		{
			fseek(fin, -1, SEEK_CUR);
		}
		FILE *fout;
		fout = fopen("OUTFILE.bin", "wb");
		while (fgets(buffer, 256, fin))
		{

			for (int i = 0; buffer[i] != '\n'; sizeOfCurrentString++, i++)
			{
			}
			if (sizeOfCurrentString > sizeOfMaxString)
			{
				sizeOfMaxString = sizeOfCurrentString;
			}
			stringCounter++;
			sizeOfCurrentString = 0;
			
		}
		fwrite(&stringCounter, sizeof(int), 1, fout);
		rewind(fin);
		char *array = new char[sizeOfMaxString];
		while (fgets(array, 256, fin))
		{
			int i = 0;
			/*if (array[0] == '\n')
			{
				char *end=new char;
				*end = '\n';
				fwrite(end, 1, 1, fout);
				continue;
			}*/
			for (; array[i] != '\n'; i++)
			{}
			while (i < sizeOfMaxString)
			{
				array[i] = ' ';
				i++;
			}
			fwrite(array, 1, sizeof(array),fout);
		}
		fclose(fout);
		fclose(fin);
			fout = fopen("outfile.bin", "rb");
		int n;
		fread(&n, sizeof(int), 1, fout);
		printf("%d",n);
		int strCtr = 1;
		while (strCtr<=stringCounter)
		{
			fread(array, 1, sizeOfMaxString, fout);
			printf(array);
			strCtr++;
		}
		fclose(fout);
		system("PAUSE");
		return 0;
	}
}
