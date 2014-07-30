#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void * 
thr_func_a (void * args)
{
  int x;
  for (x=0; x<10; x++) 
    fprintf (stderr, "%s %i\n", __func__, x);
  fprintf (stderr, "%s is done\n", __func__);
  return NULL;
}

void * 
thr_func_b (void * args)
{ 
  int x;
  for (x=0; x<50; x++) 
    fprintf (stderr, "%s %i\n", __func__, x);
  fprintf (stderr, "%s is done\n", __func__);
  return NULL;
}

int 
main (int argc, char ** argv)
{

  pthread_t thr_a, thr_b;
  pthread_create (&thr_a, NULL, thr_func_a, NULL);
  pthread_create (&thr_b, NULL, thr_func_b, NULL);
  
  pthread_join (thr_a, NULL);
  pthread_join (thr_b, NULL);
  
  return 0;
}
