#include <stdlib.h>
#include <stdio.h>

//function prototypes
void transformMatrix(int matrix[10][10]);
int bimod(int value);


int main()
{
  int i, j;
  int matrix[10][10];

  //load values into matrix
  for (i = 0; i < 10; i++)
  {
   for (j = 0; j < 10; j++)
    {
      matrix[i][j] = (i+1) * (j+1);
    }
  }

  //display initial contents of matrix
  printf("Initial matrix contents:\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 10; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  transformMatrix(matrix);

  //display transformed contents of matrix
  printf("\nTransformed matrix contents:\n");
  for (i = 0; i < 10; i++)
  {
    for (j = 0; j < 10; j++)
    {
      printf("%4i", matrix[i][j]);
    }
    printf("\n");
  }

  exit(0);
}


void transformMatrix(int matrix[10][10])
{
  int i, j;

  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
      matrix[i][j] = bimod(matrix[i][j]);
}


int bimod(int value)
{
  if (value % 2 == 0)
    return(1);
  else
    return(0);
}

