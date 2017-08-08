#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define at(a, i) ((char *)a + i*elsize)
#define inc(a) (a = (char *)a + elsize)

static void msort_helper (void *orig, void *buffer, int n, size_t elsize, 
                        int(*cmp)(const void*,const void*) )
{
   if(n <= 1)
      return;

   int mid = n / 2;

   // Sort two halfs
   msort_helper(orig, buffer, mid, elsize, cmp);
   msort_helper(at(orig, mid), at(buffer, mid), n - mid, elsize, cmp);

   int a = 0;
   int b = mid;
   int i;

   for(i = 0; i < n; i++)
   {
      int take;
      if(a >= mid || b >= n)
         break;

      if(cmp(at(orig, a), at(orig, b)) > 0)
         take = b++;
      else
         take = a++;

      memcpy(at(buffer, i), at(orig, take), elsize);
   }
   

   if(a < mid)
      memcpy(at(buffer, i), at(orig, a), (mid - a)*elsize);
   if(b < n)
      memcpy(at(buffer, i), at(orig, b), (n-b)*elsize);

   memcpy(orig, buffer, n *elsize);
}

static void msort (void *a, size_t n, size_t elsize, int(*cmp)(const void*,const void*) )
{
   void *buffer = malloc(n * elsize);
   msort_helper(a, buffer, n, elsize, cmp);
   memcmp(buffer, a, n*elsize);
   free(buffer);
}


static int compare_str(const void *a, const void *b)
{
   const char **ca = (const char **) a;
   const char **cb = (const char **) b;
   return strcmp(*ca, *cb);
}

static int compare_int (const void *a, const void *b)
{
   const int *ca = (int *) a;
   const int *cb = (int *) b;
   return (*ca == *cb ? 0 : (*ca < *cb? -1 : 1));
}

static int compare_char (const void *a, const void *b)
{
   const char *ca = (char *) a;
   const char *cb = (char *) b;
   return (*ca == *cb ? 0 : (*ca < *cb? -1 : 1));
}

void sort_str(char *a[], int len)
{
   msort(a, len, sizeof(char *), compare_str);
}

void sort_int(int a[], int len)
{
   msort(a, len, sizeof(int), compare_int);
}

void sort_char(int a[], int len)
{
   msort(a, len, sizeof(char), compare_char);
}
