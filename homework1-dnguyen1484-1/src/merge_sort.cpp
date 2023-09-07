#include "sorting_algorithms.h"

vector<int> aux;
/*  
merge function will merge two sorted sub-arrays, 
one starts from `low` and goes until `mid`
second starts from `mid+1` and goes until `high`
e.g.
    1   4 6  8     3 5 7
    ^        ^         ^
    low      mid       high

@Parameters:
    nums: a reference to the vector of numbers
    low: start point of first sub-array
    mid: end of left-sub-array
    high: end of right-sub-array

@Returns:
    the function does NOT return anything
    it merges the sub-arrays in-place.
*/
void merge(vector<int>& nums, int low, int mid, int high){
    for(int i=low; i<=high; i++){
       aux[i] = nums[i];
   }

   // this variables will refer to where we are in sub-array
   // initially, both point to the first element in respective sub-arrays
   int left_ind = low;
   int right_ind = mid+1;
  
   // iterate through all position and pick the correct element
   for(int ptr=low; ptr<=high; ptr++){
       // if left subarray exhausted then use right one
       if(left_ind > mid){
           nums[ptr] = aux[right_ind];
           right_ind += 1;
       }
       // if right subarray exhausted then use left one
       else if(right_ind > high){
           nums[ptr] = aux[left_ind];
           left_ind += 1;
       }
       // if we have elements on both subarrays 
       //choose the left if its smaller
       else if(aux[left_ind] < aux[right_ind]){
           nums[ptr] = aux[left_ind];
           left_ind += 1;
       }
       // choose right if its smaller
       else{
           nums[ptr] = aux[right_ind];
           right_ind += 1;
       }
   }
}

/*
merge_sort function will sort the array in-place in the given bounds
@Parameters:
    nums: a reference to the vector of integers to be sorted
    low: start index of the array to be sorted
    high: end index of the array to be sorted
@Returns:
    void. 
    the algorithm sorts the vector in-place. so, it does not return anything.
*/
void _merge_sort(vector<int>& nums, int low, int high){
    // check if the bounds are correct
   if (low >= high) return;

   // finding the split index
   int mid = (low + high)/2;

   // recursively sorting two sub-arrays
   _merge_sort(nums, low,   mid);
   _merge_sort(nums, mid+1, high);

   // merge the two sorted arrays
   merge(nums, low, mid, high);
}

/*
merge_sort function sorts the array in-place
@Parameters:
    nums: a reference to the vector of integers to be sorted
@Returns:
    void.
    the algorithm sorts the vector in-place. so, it does not return anything. 
*/
void merge_sort(vector<int>& nums){
    aux.resize(nums.size(), 0);
    _merge_sort(nums, 0, nums.size()-1);
}