#include "sorting_algorithms.h"

/*
selection_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void selection_sort(vector<int>& nums){
    int n = static_cast<int>(nums.size());
    int i = 0;
    while (i < n)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[min] > nums[j])
            {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
        ++i;
    }
}