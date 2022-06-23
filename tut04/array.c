#include <stdio.h>
#define ARR_SIZE 5

void odd_only(void);
void copy_array(void);

int main(void) {
  odd_only();
  copy_array();
  return 0;
}

void odd_only() {
 int array[ARR_SIZE] = {1,2,3,4,5}; // create integer array
  int i = 0;
  while(i < ARR_SIZE){
    if (array[i] % 2 == 0) {
      array[i] += 1;
    }

    printf("%d")
     
    i++;
  }

  // print out array
  
}

void copy_array(){
    double array1[3] = {1.1, 2.2, 3.3};
    double array2[100] = {0};
    int i = 0;
    while(i < 3) {
        array2[i] = array1[i];
        i++;
    }
    int j = 0;
    while (j < 100) {
        printf("%lf\n", array2[j]);
        j++;
    }
}
