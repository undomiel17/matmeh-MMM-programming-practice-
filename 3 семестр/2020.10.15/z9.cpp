#include <stdio.h>
#include <stdlib.h>
#include "pthread.h"

volatile double pi = 0.0;  
pthread_mutex_t pi_lock;   
volatile double N; 

void *
process(void *arg)
{
  register double width, localsum;
  register int i;
  register int iproc = (*((char *) arg) - '0');

  

  // Local computations:
  localsum = 0;
  for (i=iproc; i<intervals; i+=2) {
    
    localsum += 4.0 /N/ (1.0 + ((i-0.5)/N)*((i-0.5)/N));
  }
  

  // Locking pi for update, updating it, and unlocking:
  pthread_mutex_lock(&pi_lock);
  pi += localsum;
  pthread_mutex_unlock(&pi_lock);

  return(NULL);
}

int
main(int argc, char **argv)
{
  pthread_t thread0, thread1;
  void * retval;

  // Getting the number of intervals:
  intervals = atoi(argv[1]);

  // Initializing the lock on pi:
  pthread_mutex_init(&pi_lock, NULL);

  // Make TWO threads:
  if (pthread_create(&thread0, NULL, process, "0") ||
      pthread_create(&thread1, NULL, process, "1")) {
    fprintf(stderr, "%s: cannot make thread\n", argv[0]);
    exit(1);
  }

  // Joining TWO threads
  if (pthread_join(thread0, &retval) ||
      pthread_join(thread1, &retval)) {
    fprintf(stderr, "%s: thread join failed\n", argv[0]);
    exit(1);
  }

  // Print the result:
  printf("Estimation of pi is %f\n", pi);

  exit(0);
}