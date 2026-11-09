using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<size_t> indexSort(position.size());
        iota(indexSort.begin(), indexSort.end(), 0);
        sort(indexSort.begin(), indexSort.end(), [&](size_t i, size_t j) {
            return position[i] > position[j];
            });
        vector<float> time;
        time.reserve(position.size());
        for (size_t i : indexSort) {
            time.push_back((static_cast<float>(target - position[i])) / speed[i]);
        }
        vector<float> stack;
        stack.push_back(time[0]);
        for (float item : time) {
            if (item > stack.back()) {
                stack.push_back(item);
            }
        }
        return stack.size();
    }
};
