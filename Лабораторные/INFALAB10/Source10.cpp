#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
void ProcessingString(char *&Pstring, char *&buffstr);
int SymbolsQ(char *&Pstring);
int main()
{
	int empt = 0;
	setlocale(LC_ALL, "Russian");
	FILE *fin;
	fin = fopen("emptyFile.txt", "r");
	if (fin == NULL)
	{
		printf("Error! File can't be opened!");
		system("pause");
		return 0;
	}
		char* buffer=(char*)malloc(256);
		char* buffstr = (char*)malloc(256);
		int k =0;
		while (fgets(buffer, 256, fin))
		{
			empt++;
			k = SymbolsQ(buffer);
			k += strlen(buffer);
			if (k > strlen(buffstr))
				buffstr = (char*)realloc(buffstr, k);
			ProcessingString(buffer, buffstr);
			printf(buffstr);
			printf("\n");
		}
		if (!feof(fin))
		{
			printf("error of reading\n");
			fclose(fin);
			system("PAUSE");
			return -1;
		}
		if (empt == 0)
		{
			printf("file is empty\n");
			fclose(fin);
			system("PAUSE");
			return 0;
		}
		/*rewind(fin);*/
	fclose(fin);
	system("pause");
	return 0;
}


void ProcessingString(char *&Pstring, char *&buffstr)
{
	buffstr[0] = '\0';
	bool literalCatch = false;
	bool punctCatch = false;
	int length = strlen(Pstring);
	int g = 0;
	for (int i = 0; i < length; i++)
	{
		if (!(isalpha((unsigned char)Pstring[i]) || isdigit((unsigned char)Pstring[i])||isspace((unsigned char)Pstring[i])))
		{
			if (i == length - 1)
				continue;
			if (Pstring[i] == '.')
				literalCatch = true;
			buffstr[g] = Pstring[i];
			g++;
			buffstr[g] = ' ';
			g++;
			punctCatch = true;
			//чтобы лишний раз не выполнять проверки, идущие ниже
			continue;
		}
		if (isspace((unsigned char)Pstring[i]) && !punctCatch)
		{
			buffstr[g] = Pstring[i];
			g++;
			continue;
		}
		if (isspace((unsigned char)Pstring[i]) && punctCatch)
		{
			punctCatch = false;
			continue;
		}
		if (literalCatch&&isalpha((unsigned char)Pstring[i]))
		{

			buffstr[g] = (unsigned char)Pstring[i];
			buffstr[g] = toupper(buffstr[g]);
			g++;
			literalCatch = 0;
			continue;
		}
		buffstr[g] = Pstring[i];
		g++;
	}
	buffstr[g-1] = '\0';
}
int SymbolsQ(char *&Pstring)
{
	int Q=0;
	int length = strlen(Pstring);
	for (int i = 0; i < length; i++)
	{
		if (!(isalpha((unsigned char)Pstring[i]) || isdigit((unsigned char)Pstring[i])))
			Q++;
	}
	return Q;
}