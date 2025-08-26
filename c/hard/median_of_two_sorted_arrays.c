double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int fullSize = nums1Size + nums2Size;
    int *mergedArray = malloc(sizeof(int) * fullSize);
    int nums1Indexer = 0;
    int nums2Indexer = 0;
    double median; //extra var so we can free the merged array

    //merging both arrays while keeping it sorted
    for (int i = 0; i < fullSize; i++)
    {
        if (nums1Indexer >= nums1Size)
        {
            //only nums2 left, so add it to the array and increment it's indexer
            mergedArray[i] = nums2[nums2Indexer];
            nums2Indexer++;
        }else if (nums2Indexer >= nums2Size)
        {
            // only nums1 left, so add it to the array and increment it's indexer
            mergedArray[i] = nums1[nums1Indexer];
            nums1Indexer++;
        }else if (nums1[nums1Indexer] < nums2[nums2Indexer])
        {
            //insert from nums1
            mergedArray[i] = nums1[nums1Indexer];
            nums1Indexer++;
        }else{
            //insert from nums2
            mergedArray[i] = nums2[nums2Indexer];
            nums2Indexer++;
        }
    }

    //now with the merged array we must get the median, there are two cases, array size odd or even
    int index = fullSize/2; //assume result is truncated
    
    if ((fullSize % 2) != 0)
    {
        //odd
        median = (double) mergedArray[index];
    }else{
        //even, we have to divide by two the sum of the two middle indexes
        median = (double) ((mergedArray[index] + mergedArray[index - 1]) / 2.0);
    }

    free(mergedArray); //freeing the memory
    return median;

}