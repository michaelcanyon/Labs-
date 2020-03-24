#include <fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
char* RmDpDirName(char* fulldir, char* trash_dir,char* strtmp);
void Getinfo(char *dir, int depth, char* filepath, char* trash_dir, int flag, char* strtmp, char* outdir, int *fileDeskDir, int *fileDescFile);
void Write_info(char* dirPath, char* WritableFilePath, int *fileDesk, int closeflag, int fileOrDirFlag);
void Read_info(char* dirPath, char *ReadableFilePath, int *fileDesk, int closeflag, int fileOrDirFlag, long long *readableFileSize);


//void pack(char* filepath,)
int main(int argc, char* argv[])
{
  int *fileDescriptorDirectory;
  int *fileDescriptorFile;
  char* trash_dir=(char*)malloc(256);
  char *dirname=(char*)malloc(1024);
  char* topdir;
  char* outdir;
  char* strtmp=(char*)malloc(1024);
  //if(argc>=2)
  topdir=argv[1];
  outdir=argv[2];
  printf("Directory scan of %s\n", topdir);
  if(outdir==NULL)
    Getinfo(topdir, 0, dirname, trash_dir, 0, strtmp,"none",fileDescriptorDirectory, fileDescriptorFile);
  else
    Getinfo(topdir, 0, dirname, trash_dir, 0, strtmp,outdir,fileDescriptorDirectory,fileDescriptorFile);
  printf("done.\n");
  exit(0);

}

char* RmDpDirName(char* fulldir, char* trash_dir,char* strtmp)
{
  int b=strlen(trash_dir);
  int c=strlen(fulldir);
  int k=0;
  for(int i=b;i<c;i++,k++)
     strtmp[k]=fulldir[i];
   strtmp[k]='\0';
   fulldir=strcpy(fulldir,strtmp);
   return fulldir;
}

void Getinfo(char *dir, int depth, char* filepath, char* trash_dir, int flag, char* strtmp, char* outdir, int *fileDeskDir, int *fileDescFile)
{
  strtmp=strcpy(strtmp,"");
  if(!flag)
  {
    trash_dir=strcpy(trash_dir, dir);
    flag=1;
  }
  DIR *dp;
  struct dirent *entry;
  struct stat statbuf;
  if ((dp = opendir(dir)) == NULL)
  {
      fprintf(stderr, "cannot open directory: %s\n", dir);
      return;
  }
  chdir(dir);
  //Читается содержимое текущей и вложенных в неё дирректорий
  while((entry = readdir(dp)) != NULL)
  {
      lstat(entry->d_name, &statbuf);
      if (S_ISDIR(statbuf.st_mode))
      {
          if (strcmp(".", entry->d_name) == 0 || strcmp("..",entry->d_name) == 0)
            continue;
          realpath(entry->d_name, filepath);
          //Отрезать лишнюю дирректорию
          filepath=RmDpDirName(filepath, trash_dir, strtmp);

          //Записать в файл информации дирректорию или путь к файлу
          if(outdir=="none")
              strtmp=strcat(trash_dir,"/infoDir.txt");
          else
              strtmp=strcat(outdir,"/infoDir.txt");
          Write_info(strtmp,filepath,fileDeskDir,0, 0);
          GetInfo(entry->d_name, depth+1, filepath, trash_dir, flag, strtmp, outdir, *fileDeskDir, *fileDescFile);
        }
        else
        {
          realpath(entry->d_name, filepath);
          //Отрезать лишнюю дирректорию
          filepath=RmDpDirName(filepath, trash_dir, strtmp);

          //Записать в файл информации дирректорию или путь к файлу
          if(outdir=="none")
              strtmp=strcat(trash_dir,"/infoFile.txt");
          else
              strtmp=strcat(outdir,"/infoFile.txt");
          Write_info(strtmp,filepath,fileDeskDir,0,1);
        }
    }
  chdir("..");
  closedir(dp);
}

void Write_info(char* dirPath, char* WritableFilePath, int *fileDesk, int closeflag, int fileOrDirFlag)
{
  int title_size=sizeof(WritableFilePath);
  if(*fileDesk==NULL)
      *fileDesk=open(dirPath, O_WRONLY || O_CREAT, S_IWUSR);
  if(*fileDesk<0)
    {
      printf("%s", "Error: Unable to open file ");
      printf("%s\n", WritableFilePath);
      return;
    }

    //Флаг закрытия файла информации
    if(closeflag)
      {
        if(close(*fileDesk)!=0)
          printf("%n\n", "Unable to close infofile. Аборт, когда допишешь остальное");
      }
  write(*fileDesk, title_size, sizeof(int));
  write(*fileDesk,WritableFilePath, title_size);

  //Вычислить и записать размер файла в инфо
  if(fileOrDirFlag)
  {
    void *buffer=NULL;
    long long file_size;
    int local_descriptor=open(WritableFilePath, O_RDONLY);
    if(local_descriptor<0)
    {
      printf("%s\n", "Error, opening directory file");
      return;
    }
    struct stat statistics;
    if(fstat(local_descriptor,&statistics)!=-1)
    {
      buffer=(char*)malloc(statistics.st_size);
      file_size=(long long)buffer;
      close(local_descriptor);
      write(*fileDesk,file_size, sizeof(long long));
    }


    }

}
void Read_info(char* dirPath, char *ReadableFilePath, int *fileDesk, int closeflag, int fileOrDirFlag, long long *readableFileSize)
{
  int title_size;
  if(*fileDesk==NULL)
    *fileDesk=open(dirPath, O_RDONLY);
  if(*fileDesk<0)
    {
      printf("%s", "Error: Unable to open file ");
      printf("%s\n", ReadableFilePath);
      return;
    }

    //Флаг закрытия файла информации
    if(closeflag)
      {
        if(close(*fileDesk)!=0)
          printf("%n\n", "Unable to close infofile. Аборт, когда допишешь остальное");
      }
  read(*fileDesk, title_size, sizeof(int));
  read(*fileDesk,ReadableFilePath, title_size);
  if(fileOrDirFlag)
    read(*fileDesk, readableFileSize, sizeof(long long));

}
//1.Тебе нужно добавить в метод записи информации также запись размера файла. Наверное, сразу открывать файл, выполнять сик и запихивать результат в файл.
//Получается, в рид инфо и райт инфо будет ещё один параметр для размера самого файла
// Соответственно, читать размер тоже будет необходимо. Поменяются оба метода.
//2.Вынеси селектор пути инфо в отдельный метод. Ниже прототип прототипа.
// 3.Дальше пишешь метод зипера, который сначала закидывает содержимое файлов инфо в файл архива, а затем возвращается в начало инфо о ФАЙЛАХ и последовательно открывает и записывает содержимое каждого файла в
// Файл архива.
//4.Дальше пишешь метод распаковки. Сначала читаешь дирректории и попутно их создаешь(без вывода первых в отдельный файл, наверное). Далее читаешь дирректории с именами файлов и переписываешь прочитанное в
//отдельный файл. Далее открываешь этот созданный файл и начинаешь читать информацию о пути файла и его размере. После прочтения информации о файле, считываешь количество байт по его размеру
//из файла архива(или же по одному байту. Погугли, не будет ли переполнения стека.), создавай файл по дирректории распаковки и переписывай считанное туда. Проделать со всеми файлами,  о которых есть упоминание
//файле архива.
//5.Далее освободи все занятые ресурсы
//6.ПРопиши параметры работы с архивом
//void Select_path_write_info(...)
