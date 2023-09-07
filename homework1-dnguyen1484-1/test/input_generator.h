#ifndef INPUT_GENERATOR_H
#define INPUT_GENERATOR_H

#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

// ==================== CONSTANTS ====================
const pair<int,int> POSITIVE_VALUES_RANGE   = {1, INT_MAX/5};
const pair<int,int> NEGATIVE_VALUES_RANGE   = {INT_MIN/5, -1};
const pair<int,int> VALUES_RANGE            = {INT_MIN/5, INT_MAX/5};
const pair<int,int> SMALL_VALUES_RANGE      = {-100, 100};
const pair<int,int> SMALL_POSITIVE_VALUES_RANGE = {1, 100};
const pair<int,int> SMALL_NEGATIVE_VALUES_RANGE = {-100, -1};
// ===================================================

int                 get_random_value(pair<int,int> val_range=VALUES_RANGE);

vector<int>         get_random_values(int total, pair<int,int> val_range=VALUES_RANGE);
vector<int>         get_partially_sorted_values(int total, pair<int,int> val_range=VALUES_RANGE);

vector<vector<int>> get_random_set(int total, pair<int,int> n_range, pair<int,int> val_range);
vector<vector<int>> get_partially_sorted_set(int total, pair<int,int> n_range, pair<int,int> val_range);

vector<vector<int>> get_copy(vector<vector<int>>& set);

#endif