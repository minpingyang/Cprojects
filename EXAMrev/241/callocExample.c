// PROGRAM 3
#include <stdio.h>
int main(void)
{
    float *nums;
    int a_size;
    int idx;
    printf("Read how many numbers:");
    scanf("%d",&a_size);
    nums = (float *) calloc(a_size,sizeof(float));
    
    for(idx = 0; idx < a_size;idx++){
        printf("please enter number %d: ",idx+1);
        scanf("%f",&(nums[idx]));
        
    }
    free(nums);
	return 0;
}
