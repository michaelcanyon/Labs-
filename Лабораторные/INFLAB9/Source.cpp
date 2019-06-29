#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <io.h>

void SizeofMaxStringAndCounter(char *buffer, int *sizeOfMaxString, int *stringCounter);
void ProcessStr(int sizeOfMaxString, char *array);
int BinRead(FILE *fout, int stringCounter, int sizeOfMaxString, int errorCheck, char *array);
int main()
{
	int errorCheck = 0;
	setlocale(LC_ALL, "Russian");
	FILE *fin;
	char *filename = "FILEREAD.txt";
	char *outfilename = "OUTF.bin";
	fin = fopen(filename, "r");
	if (fin != NULL)
	{
		int stringCounter = 0;
		char buffer[256];
		int sizeOfMaxString = 0;
		int sizeOfCurrentString = 0;
		if (fgets(buffer, 256, fin) == nullptr)
			printf("File is empty\n");
		rewind(fin);
		FILE *fout;
		fout = fopen(outfilename, "wb");
		if (fout != NULL)
		{
			while (fgets(buffer, 256, fin))
			{
				SizeofMaxStringAndCounter(buffer, &sizeOfMaxString, &stringCounter);
			}
			if ((errorCheck = fwrite(&stringCounter, sizeof(int), 1, fout)) < 0)
			{
				printf("%s", "Cant't write strings quantity");
				fclose(fout);
				fclose(fin);
				return -1;
			}
			rewind(fin);
			char *array = new char[sizeOfMaxString];

			while (fgets(array, 256, fin))
			{
				ProcessStr(sizeOfMaxString, array);
				if ((errorCheck = fwrite(array, 1, sizeOfMaxString, fout)) < 0)
				{
					printf("%s", "Cant't write string");
					fclose(fout);
					fclose(fin);
					return -1;
				}
			}
			fclose(fout);
			fclose(fin);
			fout = fopen(outfilename, "rb");
			BinRead(fout, stringCounter, sizeOfMaxString, errorCheck, array);
		}
		else
		{
			fclose(fout);
			printf("%s", "binary out file opening failure");
			return -1;
		}
		fclose(fout);
	}
	else
	{
		printf("%s", "Reading file opening failure");
	}
	system("PAUSE");
	return 0;
}

int BinRead(FILE *fout, int stringCounter, int sizeOfMaxString, int errorCheck, char *array)
{
	int n;
	if ((errorCheck = fread(&n, sizeof(int), 1, fout)) < 0)
	{
		fclose(fout);
		printf("%s", "Cant't read strings quantity");
		return -1;
	}
	printf("%d", n);
	printf("%c", '\n');
	int strCtr = 0;
	while (strCtr < stringCounter)
	{
		if ((errorCheck = fread(array, 1, sizeOfMaxString, fout)) < 0)
		{
			fclose(fout);
			printf("%s", "Cant't read string");
			return -1;
		}
		printf(array);
		printf("%c", '\n');
		strCtr++;
	}
	long size = 0;
	rewind(fout);
	char c;
	while (fread(&c, 1, 1, fout))
	{
		size++;
	}
	printf("File size equals %d", size);
	printf("%c", '\n');
	return 0;
}
void SizeofMaxStringAndCounter(char *buffer, int *sizeOfMaxString, int *stringCounter)
{
	int sizeOfCurrentString = 0;
	sizeOfCurrentString = strlen(buffer);
	if (sizeOfCurrentString > *sizeOfMaxString)
	{
		*sizeOfMaxString = sizeOfCurrentString;
	}
	*stringCounter = *stringCounter + 1;
}
void ProcessStr(int sizeOfMaxString, char *array)
{
	int errorCheck = 0;
	int i = 0;
	for (; array[i] != '\n'&&i < sizeOfMaxString; i++)
	{
	}
	while (i < sizeOfMaxString)
	{
		array[i] = ' ';
		i++;
	}
}