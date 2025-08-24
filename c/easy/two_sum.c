#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *result = malloc(2 * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        for(int j = i+1; j < numsSize; j++){
            //if(i == j){continue;} //checking if the numbers aren't the same
            if ((nums[i] + nums[j]) == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result; //this should never happen
}