#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float gettemp() {
  FILE *fp;
  int c=0, i=0;
  char x[5];

  fp = fopen ("/sys/class/thermal/thermal_zone0/temp","r");
  if( fp == NULL ) {
    puts("Cannot access /sys/class/thermal/thermal_zone0/temp. You may need to update your firmware.");
    return 1;
  }

  while((c = fgetc(fp)) != EOF) {
    x[i] = c; 
    i++;
  }

  fclose(fp);
  float temp = atof(x) / 1000;
  return temp;
}

double primetime() {
  clock_t start, end;
  double runtime;
  start = clock();   
  int num,primes = 0, limit = 100000;
  for (num = 1; num <= limit; num++) { 
    int i = 2; 
    while(i <= num) { 
      if(num % i == 0)
        break;
      i++; 
    }
    if(i == num)
      primes++;
  }
  end = clock();
  runtime = (end - start) / (double) CLOCKS_PER_SEC;
  return runtime;
}

int main(int argc, char *argv[]) {
  double totaltime=0, time=0;
  float totaltemp=0, temp=0;
  int y;
  for (y = 1; y < 5; y++) {
    printf("Test %i\n",y);
    double time = primetime();
    float temp = gettemp();
    printf("  CPU temp: %.2f\260C\n",temp);
    printf("  Time taken: %gs\n",time);
    printf("\n");
    totaltemp = totaltemp+temp;
    totaltime = totaltime+time;
  }
  temp = totaltemp / (y-1);
  time = totaltime / (y-1);
  printf("Testing complete.\n  Average CPU temp: %.2f\260C\n  Average time taken: %gs\n",temp,time);
  return 0;
}

