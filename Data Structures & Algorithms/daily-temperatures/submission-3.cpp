using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> indiceStack;
        vector<int> out(temperatures.size());
        for (int i{ 0 }; i < static_cast<int>(temperatures.size()); ++i) {
            while (!indiceStack.empty() && temperatures[i] > temperatures[indiceStack.back()]) {
                out[indiceStack.back()] = i - indiceStack.back();
                indiceStack.pop_back();
            }
            indiceStack.push_back(i);
        }
        return out;
    }
};