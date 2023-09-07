#include <iostream>

#include <vector>
#include <unordered_map>

#include <functional>
#include <chrono>
#include <fstream>
#include <cassert>

#include "../src/sorting_algorithms.h"
#include "input_generator.h"

using namespace std;
using namespace std::chrono;

#define CORRECT_SYMBOL "✅"
#define WRONG_SYMBOL   "❌"
#define testfn_type function<void(vector<int>&)>

// ====================== Helper ======================
void print(vector<int>& nums){
    for(int num: nums)
    cout<<num<<" ";
    cout<<"\n";
}

bool isSorted(vector<int>& nums){
    for(int i=1; i<nums.size(); i++){
        if(nums[i] < nums[i-1])
        return false;
    }
    return true;
}

bool runTestSet(string testSetName, vector<vector<int>> testSet, bool saveOutput=true){
    cout<<"Running Test Set: "<<testSetName<<"\n";

    // setup file for printing output
    ofstream outputFile;
    if(saveOutput){
        string output_path = "./out/" + testSetName + ".csv";
        outputFile.open(output_path);
        outputFile << "Algorithm,N,TimeTaken\n";
    }

    int total_tests = testSet.size();
    bool allPassed = true;

    // adding testing functions
    unordered_map<string, testfn_type> sortingFns;
    sortingFns["Selection Sort"] = selection_sort;
    sortingFns["Insertion Sort"] = insertion_sort;
    sortingFns["Merge Sort"]     = merge_sort;
    sortingFns["Quick Sort"]     = quick_sort;
    sortingFns["Inbuilt Sort"]   = inbuilt_sort;

    for(pair<string, testfn_type> entry: sortingFns){
        string func_name = entry.first;
        testfn_type test_fn = entry.second;

        cout<<"\tTesting: "<<func_name<<" ";
        int total_passed = 0;

        for(vector<int> testInput: get_copy(testSet)){
            // start timer
            auto start = high_resolution_clock::now();
            // run the function
            test_fn(testInput);
            // stop the timer
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            // writing output to file
            if(saveOutput){
                outputFile << func_name << "," << testInput.size() << "," << duration.count() << "\n";
            }
            // validate the function's output
            bool passed = isSorted(testInput);
            total_passed += (passed ? 1 : 0);
        }

        if(total_passed == total_tests){
            cout<<CORRECT_SYMBOL<<"\n";
        }else{
            allPassed = false;
            cout<<WRONG_SYMBOL<<" ("<<total_passed<<"/"<<total_tests<<" tests passed)\n";
        }
    }

    // closing the output file
    if(saveOutput)
    outputFile.close();

    return allPassed;
}
// =====================================================

int main(int argc, char* argv[]){
    // initialization
    srand((unsigned) time(NULL));
    int total_tests;
    string testSetName;
    vector<vector<int>> testSet;


    // ========================== Github Autograder ==========================
    // for github autograder
    if(argc > 1){
        total_tests = 1000;
        testSetName = "Github Autograder";
        testSet = get_random_set(total_tests, {1, 1000}, SMALL_VALUES_RANGE);

        assert(runTestSet(testSetName, testSet, false));
        return 0;
    }
    // =======================================================================
    
    // ========================== Test Locally ==========================
    // 1.) Testing on Small Inputs
    total_tests = 100;
    testSetName = "Small Values";
    testSet = get_random_set(total_tests, {1, 100}, SMALL_VALUES_RANGE);

    runTestSet(testSetName, testSet);

    // 2.) Testing on Big Inputs
    total_tests = 100;
    testSetName = "Big Values";
    testSet = get_random_set(total_tests, {1, 100}, VALUES_RANGE);

    runTestSet(testSetName, testSet);

    // 3.) Testing on Big Length Inputs
    total_tests = 10;
    testSetName = "Big Length";
    testSet = get_random_set(total_tests, {1000, 10000}, VALUES_RANGE);

    runTestSet(testSetName, testSet);

    // 4.) Testing on Partially Sorted Inputs
    total_tests = 100;
    testSetName = "Partially Sorted";
    testSet = get_partially_sorted_set(total_tests, {1, 1000}, SMALL_VALUES_RANGE);

    runTestSet(testSetName, testSet);
    // ==================================================================
    
    return 0;
}