#include <vector>
#include <iostream>
#include <unordered_map>


using namespace std;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mapRepeat;
        for (int item : nums) {
            if (++mapRepeat[item] > 1) {
                return true;
            }
        }
        return false;
    }
};
