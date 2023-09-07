#include <algorithm>
#include "sorting_algorithms.h"

/*
inbuilt sort function sorts the array in-place using the inbuilt library
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void inbuilt_sort(vector<int>& nums){
    sort(nums.begin(), nums.end());
}