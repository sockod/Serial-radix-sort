#include <stdio.h>
#include <stdlib.h>

#define MAX 30000

int *arr;
int *bucket;
int *sumbucket;
int *listedArray;

void *generateRandom()
{
	srand(time(NULL));
	int i;
	for (i=0; i<MAX; i++)
	{
	  arr[i] = rand() % 10001;
	}
}

int findMax()
{
	int i, m=-1;
	for (i=0; i<MAX; i++)
	{
	  if(arr[i] > m)
	  {
	    m = arr[i];
	  }
	}
	return m;

}

int lengthOfMax(int m)
{
  int i, j=0;
  
  for (i = 1; i<100; i=i*10)
  {
    if (m>i)
    {
      j++;
    }
  }
  return j;
}

void *createHistogram(int b)
{
  int i, j;
  
  
    for (i = 0; i < MAX; i++)
    {
      for (j = 0; j < MAX; j++)
      {
	if (i == ((arr[j] / b)%10))
	{
	  bucket[i]++;
	}
      }
    }
  /*for (i = 0; i < MAX; i++)
  {
    printf("To bucket[%d] exei %d arithmous \n", i, bucket[i]);
  }*/
  return bucket;
}

void *createSumbucket(int b[])
{
  int i, sum = 0;
  
  for (i = 0; i < MAX; i++)
  {
    sum = sum + b[i];
    sumbucket[i] = sum;
    //printf("To sumbucket[%d] einai iso me %d\n", i, sumbucket[i]);
  }
  //printf("Einai swsto mono an 10 = %d \n", sum);
  return sumbucket;
}

void *makeSort(int d[], int e)
{
  int i, j;
  int new;
  
  for (i = MAX-1; i >= 0; i--)
  {
    for (j = 0; j < 10; j++)
    {
      if (j == ((arr[i]/e)%10))
      {
	while (!d[j])
	{
	  --d[j];
	}
	d[j]= d[j] - 1;
	new = d[j];
	listedArray[new] = arr[i];
      }
    }
  }
  //printf("O neos pinakas pros taksinomisi einai o eksis: \n");
  for (i = 0; i < MAX; i++)
  {
    //printf("%d\n", listedArray[i]);
    arr[i] = listedArray[i];
    bucket[i] = 0;
    sumbucket[i] = 0;
  }
}

int main()
{
  arr = (int *) malloc(MAX * sizeof(int *));
  bucket = (int *) malloc(MAX * sizeof(int *));
  sumbucket = (int *) malloc(MAX * sizeof(int *));
  listedArray = (int *) malloc(MAX * sizeof(int *));
  int i, *p, *q, *r;
  int exp = 1;
  
  generateRandom();
  int maximum = findMax();
  
  
  printf("\n");
  for (i = 0; i < MAX; i++)
  {
    printf(" %d ", arr[i]);
  }
  /*printf("\n\n");
  printf("O megistos arithmos einai o %d: ", maximum);
  printf("\n\n");*/
  
  while (exp < 101)
  {
    p = createHistogram(exp);
    q = createSumbucket(p);
    r = makeSort(q, exp);
    exp = exp*10;
  }
  
  printf("Sorted:\n");
  for (i = 0; i < MAX; i++)
  {
    printf("%d\n", arr[i]);
  }
}
