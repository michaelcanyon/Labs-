#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
int main()
{
	FILE *fin;
	fin = fopen("file.txt", "r");
	char buffer[256];
	setlocale(LC_ALL, "Russian");
	if (fin != NULL)
	{
		if (fgetc(fin) == '\n')
		{
			perror("File is empty");
			fclose(fin);
			return 0;
		}
		else
		{
			fseek(fin, -1, SEEK_CUR);
		}
		FILE *fout;
		fout = fopen("OutFile.txt", "w");
		while (fgets(buffer, 256, fin))
		{
			int i = 0;
			while (buffer[i] != '.'&&i < sizeof(buffer))
			{
				i++;
			}
			if (i < sizeof(buffer))
			{
				buffer[i + 1] = '\n';
				buffer[i + 2] = '\0';
			}
			fputs(buffer, fout);
			printf(buffer);
		}

		fclose(fin);
		fclose(fout);
	}
	else
	{
		printf("file can't be opened");
	}
	system("PAUSE");
	return 0;
}