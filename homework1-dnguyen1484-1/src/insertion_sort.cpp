#include "sorting_algorithms.h"

/*
insertion_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void insertion_sort(vector<int>& nums){
    int n = static_cast<int>(nums.size());
    //i will keep first position of the unsorted section
    for (int i = 1; i < n; i++)
    {
        //j will help with the swaping
        //j will be the last position of the sorted section
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
            else
            {
                break;
            }
        }
    }
}