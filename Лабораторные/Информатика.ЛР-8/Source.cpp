#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
void ProcessingText(char *buffer)
{
	int i = 0;
	while (buffer[i] != '.'&&i < strlen(buffer))
		i++;
	if (i < strlen(buffer))
		buffer[i + 1] = '\0';
	printf(buffer);
	printf("\n");
}
int main()
{
	FILE *fin;
	fin = fopen("edsf.txt", "r");
	char buffer[256];
	int k = 0;
	setlocale(LC_ALL, "Russian");
	if (fin != NULL)
	{
		rewind(fin);
		FILE *fout;
		fout = fopen("OutFile.txt", "w");
		while (fgets(buffer, 256, fin))
		{
			ProcessingText(buffer);
			fputs(buffer, fout);
			fputs("\n", fout);
			k++;
		}
		if (!feof(fin))
		{
			printf("error of reading\n");
			fclose(fin);
			fclose(fout);
			system("PAUSE");
			return -1;
		}

		fclose(fin);
		if (k == 0)
		{
			printf("file is empty\n");
			fclose(fin);
			fclose(fout);
			system("PAUSE");
			return 0;
		}
		fclose(fin);
		fclose(fout);
	}
	else
	{
		printf("file can't be opened or doesn't exist\n");
	}
	system("PAUSE");
	return 0;
}