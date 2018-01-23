// Sort an Array of Lines 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  my_getline(char *line);
//void printarray(char *str[]);
void printarray(char **str);
void sortarray(char *str[]);

int main()
{
  char *strarray[4];
  
  char str0[80], str1[80], str2[80], str3[80];

  int i;


//   my_getline(str0);
//   my_getline(str1);
//   my_getline(str2);
//   my_getline(str3);

//   strarray[0] = str0;
//   strarray[1] = str1;
//   strarray[2] = str2;
//   strarray[3] = str3;

//   *strarray = str0;
//   *(strarray+1) = str1;
//   *(strarray+2) = str2;
//   *(strarray+3) = str3;

  for(i=0;i<4;i++)
  {
    strarray[i] = malloc(80);
    my_getline(strarray[i]);
  }  

  printf("Unsorted\n");
  printarray(strarray);

  printf("Sorted\n");
  sortarray(strarray);
  printarray(strarray);

  for(i=0;i<4;i++)
     free(strarray[i]);

}

//void printarray(char *str[])
void printarray(char **str)
{
  int i;
  for(i=0;i<4;i++)
  {
//    printf("Index %d: %s\n",i,str[i]);
    printf("Index %d: %s\n",i,*(str+i));
  }
}


void sortarray(char *str[])
{
  int swapped;
  int i;
  char *temp;

  do {
       swapped = 0;

       for(i=0;i<4-1;i++)
       {
         if (strcmp(str[i],str[i+1]) > 0) 
         {
            temp = str[i];
            str[i] = str[i+1];
            str[i+1] = temp;
            swapped = 1;
          }
        }
      } while (swapped == 1);
}



void  my_getline(char *line)
{
  printf("Enter Line: ");
  fgets(line,80,stdin);
}

