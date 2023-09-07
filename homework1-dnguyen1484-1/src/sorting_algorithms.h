#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
using namespace std;

// ================== QUICK SORT ==================
int partition(vector<int>& nums, int low, int high);
void _quick_sort(vector<int>& nums, int low, int high);
void quick_sort(vector<int>& nums);
// ================================================

// ================== MERGE SORT ==================
extern vector<int> aux;
void merge(vector<int>& nums, int low, int mid, int high);
void _merge_sort(vector<int>& nums, int low, int high);
void merge_sort(vector<int>& nums);
// ================================================

// ================== INSERTION SORT ==================
void insertion_sort(vector<int>& nums);
// ====================================================

// ================== SELECTION SORT ==================
void selection_sort(vector<int>& nums);
// ====================================================


// ================== INBUILT SORT ==================
void inbuilt_sort(vector<int>& nums);
// ==================================================
#endif