#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <io.h>
#include<ctype.h>
int getWordOrSynonim(char *array, FILE *stream);
void ReplaceWords(char *&string, char *OldWord, char *NewWord, char *newBuffer);
int getmaxwords(char *string, char *oldword);
int main()
{
	setlocale(LC_ALL, "Russian");
	char *filename = "FileLab11.txt";
	char *sin = "ReplaceFile.txt";
	char *outfilename = "OutFile11.txt";
	char *word = (char*)malloc(20);
	char *synonim = (char*)malloc(20);
	FILE *fin = fopen(filename, "r");
	if (fin == NULL)
	{
		printf("Opening file error");
		return 0;
	}
	FILE *fout = fopen(outfilename, "w");
	if (fout == NULL)
	{
		printf("Opening file error");
		return 0;
	}
	char *buffer = (char*)malloc(256);
	char *newBuffer = (char*)malloc(256);
	int size;//эта переменная нужна для того, чтобы у нас была максимально возможная длина строки до считывания в неё чего-либо. см.строка ...
	int maximalquantity = 0;
	int compare;
	int ch = 0;
	int nk = 0;
	//файл на чтение слов и заменяемых слов
	FILE *win = fopen(sin, "r");
	if (win == NULL)
	{
		printf("Opening file error");
		system("PAUSE");
		return 0;
	}
	//замена слов и запись текста в выходной файл
	while (fgets(buffer, 256, fin) != NULL)
	{
		nk = 1;
		//приведение всех букв к нижнему регистру
		int strsize = strlen(buffer);
		for (int t = 0; t < strsize; t++)
		{
			if (isupper((unsigned char)buffer[t]))
				buffer[t] = tolower((unsigned char)buffer[t]);
		}
		while (ch != 1)
		{
			//читает слово и заменяемое слово и проверяет, корректно ли они считаны
			ch = getWordOrSynonim(word, win);
			if (ch < 0)
				return -1;
			else if (ch == 1)
			{
				rewind(win);
				continue;
			}
			ch = getWordOrSynonim(synonim, win);
			if (ch < 0)
				return -1;
			else if (ch == 1)
			{
				rewind(win);
				continue;
			}
			//приведение заменяемого слова к регистру исходного слова
			int wordlength = 0;
			if (strlen(word) < strlen(synonim))
				wordlength = strlen(word);
			else
				wordlength = strlen(synonim);
			for (int i = 0; i < wordlength; i++)
			{
				if (isupper((unsigned char)word[i]) == 1)
					synonim[i] = toupper((unsigned char)synonim[i]);
				else if (islower((unsigned char)word[i]))
					synonim[i] = tolower((unsigned char)synonim[i]);
			}
			wordlength = strlen(word);
			for (int j = 0; j < wordlength; j++)
			{
				if (isupper((unsigned char)word[j]))
					word[j] = tolower((unsigned char)word[j]);
			}
			//считает количество повторений слова в строке
			int k = 0;
			k = getmaxwords(buffer, word);
			if (maximalquantity < k)
				maximalquantity = k;
			//вычисляем размер необходимого места в памяти, если изначально заданного размера не хватило
			size = strlen(buffer);
			compare = size - strlen(word)*maximalquantity + maximalquantity * strlen(word);
			if (strlen(buffer) < size)
			{
				newBuffer = (char*)realloc(newBuffer, compare);
				buffer = (char*)realloc(buffer, compare);
			}
			ReplaceWords(buffer, word, synonim, newBuffer);
		}
		ch = 0;
		fputs(newBuffer, fout);
	}
	if (nk == 0)
	{
		printf("Text file is empty!");
		system("PAUSE");
		return 0;
	}
	if (!feof(fin))
	{
		printf("reading error!\n");
		fclose(fin);
		fclose(fout);
		fclose(win);
		system("PAUSE");
		return -1;
	}
	fclose(fout);
	fclose(fin);
	fclose(win);
	remove(filename);
	rename(outfilename, filename);
	system("PAUSE");
	return 0;
}
void ReplaceWords(char *&string, char *OldWord, char *NewWord, char *newBuffer)
{
	char *pieceOfstring;
	//Избавимся от данных из предыдущей итерации
	newBuffer[0] = '\0';
	char *i = string;
	int diff;
	char *mem;
	char *mem1;
	char *wordcheck;
	int k = 0;
	//проверка на наличие вхожжений
	if (strstr(i, OldWord) != NULL)
		k = 1;
	//если вхождений нет, переходим в конец подпрограммы
	if (k == 0)
	{
		strcpy(newBuffer, string);
		mem = string;
		mem1 = newBuffer;
		goto processing;
	}
	i = string;
	k = 0;
	//запоминаем указатель старой строки
	mem = i;
	//запоминаем указатель начала результирующей строки
	mem1 = newBuffer;
	int check = 0;
	while ((i = strstr(i, OldWord)) != NULL)
	{
		//если в предыдущей итерации цикла встретилось ложное вхождение, нам нужно добавить этот кусок строки в результат до следующего вхождения 
		if (check == 1)
		{
			strncpy(newBuffer, mem, i - mem);
			newBuffer += (i - mem);
			mem = i;
			check = 0;
		}
		wordcheck = i;
		//проверка на наличие букв до вхождения слова. Если слово является частью другого слова, то это будет ложное вхождение
		if (*wordcheck != string[0])
		{
			wordcheck -= 1;
			if (!(isspace((unsigned char)*wordcheck)||ispunct((unsigned char)*wordcheck)))
			{
				i += strlen(OldWord);
				check = 1;
				continue;
			}
		}
		//поиск букв после вхождения слова. Если буквы есть, то это ложное вхождение
		wordcheck = i + strlen(OldWord);
		if (!(isspace((unsigned char)*wordcheck) || ispunct((unsigned char)*wordcheck)))
		{
			i += strlen(OldWord);
			check = 1;
			continue;
		}
		//последовательность, записывающая строку до вхождения и новое слово
		strncpy(newBuffer, mem, i - mem);
		//Перевод заглавных букв к верхнему регистру
		pieceOfstring = newBuffer + (i - mem);
		if (newBuffer == mem1)
		{
			if (isalpha((unsigned char)*newBuffer))
				*newBuffer = toupper((unsigned char)*newBuffer);
		}
		for (; newBuffer != pieceOfstring; newBuffer++)
		{
			if (*newBuffer == '.' || *newBuffer == '!' || *newBuffer == '?' || *newBuffer == ';')
			{
				while (newBuffer != pieceOfstring && isalpha((unsigned char)*newBuffer) == 0)//!
					newBuffer++;
				if ((pieceOfstring - newBuffer) <= 0)
					break;
				else
					*newBuffer = toupper((unsigned char)*newBuffer);
			}
		}
		strcpy(newBuffer, NewWord);
		newBuffer += strlen(NewWord);
		//необходимо запомнить адрес начала строки после вхождения
		//старого слова, чтобы добавить кусок строки между концом старого вхождения и следующим вхождением в результирующую строку
		i += strlen(OldWord);
		mem = i;
	}
	//если вхождений больше нет, необходимо добавить остаток строки к результирующей
	strcpy(newBuffer, mem);
processing:
	pieceOfstring = newBuffer + strlen(mem);
	if (newBuffer == mem1)
	{
		if (isalpha((unsigned char)*newBuffer))
			*newBuffer = toupper((unsigned char)*newBuffer);
	}
	for (; newBuffer != pieceOfstring; newBuffer++)
	{
		if (*newBuffer == '.' || *newBuffer == '!' || *newBuffer == '?' || *newBuffer == ';')
		{
			while (newBuffer != pieceOfstring && isalpha((unsigned char)*newBuffer) == 0)//!
				newBuffer++;
			if ((pieceOfstring - newBuffer) <= 0)
				break;
			else
				*newBuffer = toupper((unsigned char)*newBuffer);
		}
	}
	newBuffer = mem1;
	strcpy(string, newBuffer);
	return;
}
//Считает максимальное количество вхождений слова в тексте
int getmaxwords(char *string, char *oldword)
{
	char *buffstring = (char*)malloc(strlen(string));
	strcpy(buffstring, string);
	char *i = buffstring;
	int strsize = strlen(buffstring);
	for (int t = 0; t < strsize; t++)
	{
		if (isupper((unsigned char)buffstring[t]))
			buffstring[t] = tolower(buffstring[t]);
	}
	int k = 0;
	while ((i = strstr(i, oldword)) != NULL)
	{
		i = i + strlen(oldword);
		k++;
	}
	return k;
}
//Считывает заменяемое слово или слово-заменитель из файла
int getWordOrSynonim(char *array, FILE *stream)
{
	array[0] = '\0';
	char *control = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghigklmnopqrsruvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧЫЪШЩЬЭЮЯабвгдеёжзийклмнопрстуфхцчыъшщьэюя";
	int wordlength;
	int c;
	char k;
	c = fgetc(stream);
	for (int i = 0; c != NULL; i++, c = fgetc(stream))
	{
		if (ispunct(c) || isspace(c))
			continue;
		int j = 0;
		while (c != NULL && isalpha(c))
		{
			array[j] = c;
			j++;
			c = fgetc(stream);
		}
		array[j] = '\0';
		break;
	}
	//предыдущее слово было последним
	if (strlen(array) == 0)
		return 1;
	//В слове есть посторонние символы
	if (strcspn(array, control) != 0)
		return -1;
	return 0;
}