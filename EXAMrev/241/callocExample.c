// PROGRAM 3
#include <stdio.h>
int main(void)
{
    float *nums;
    int a_size = 5;
    int idx;
    printf("Read how many numbers:");
    scanf("%d",&a_size);
    nums = (float *) calloc(a_size,sizeof(float));
    
    // for(idx = 0; idx < a_size;idx++){
    //     printf("please enter number %d: ",idx+1);
    //     scanf("%f",&(nums[idx]));
        
    // }
    // free(nums);
    for(a_size = 0; a_size <5){
        nums[a_size] = 2.0* a_size;
    }
    nums =(float *) realloc(nums,10 * sizeof(float));
    /* An array of 10 floating point values is allocated,
  the first 5 floats from the old nums are copied as
  the first 5 floats of the new nums, then the old nums
  is released */
	return 0;
}
