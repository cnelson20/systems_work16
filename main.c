#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main() {
  printf("Before Fork: pid: %d\n",getpid());

  if (fork()) {
    if (fork()) {
      int childstatus;
      if (WIFEXITED(childstatus)) {
	printf("Child status: %d\n",WEXITSTATUS(childstatus));
      } else {
	printf("Child did not exit correctly. Exit code %d\n",WEXITSTATUS(childstatus));
      }
      return(0);
    }
  }
  unsigned int seconds;
  int fd = open("/dev/urandom", O_RDONLY);
  read(fd,&seconds,4);
  close(fd);
  seconds = 2 + (seconds % 4); 
  sleep(seconds);
  printf("Child %d has finished.\n",getpid());

  //return(23);
  return(seconds);
}
