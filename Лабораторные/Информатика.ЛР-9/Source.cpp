#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fin;
	fin = fopen("filel9.txt", "r");
	if (fin != NULL)
	{
		int stringCounter=0;
		char buffer[256];
		int sizeOfMaxString = 0;
		int sizeOfCurrentString=0;
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
		/*FILE *fout;
		fout = fopen("outfile.bin", "wb");*/
		while (fgets(buffer,256, fin))
		{
			
			for (int i = 0;buffer[i] !='\n'; sizeOfCurrentString++, i++)
			{}
			if (sizeOfCurrentString > sizeOfMaxString)
			{
				sizeOfMaxString = sizeOfCurrentString;
			}
			stringCounter++;
			sizeOfCurrentString = 0;
			printf(buffer);
		}
		printf("%d" ,sizeOfMaxString);
		/*fwrite(&stringCounter, sizeof(int), 1, fout);*/
		rewind(fin);
		char *array = new char[sizeOfMaxString];
		while (fgets(array, 256, fin))
		{
			for (int i = 0; array[i] !='\n'; i++)
			{
				while (i < sizeof(array))
				{
					array[i] = ' ';
					i++;
				}
			}
			/*fwrite(array, 1, sizeOfMaxString,fout);*/
		}
		//fclose(fout);
	/*	fout = fopen("outfile.bin", "rb");*/
		int n;
		char *buffArray=new char[sizeOfMaxString];
		//fread(&n, sizeof(int), 1, fout);
		//while (feof(fout) == 0)
		//{
		//	fread(buffArray, sizeof(char), sizeOfMaxString, fout);
		//	printf(buffArray);
		//}
		system("PAUSE");
		return 0;
	}
}
