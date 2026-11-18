class Solution {
public:
    unsigned int workDurationInHours(vector<int>& piles, int expectedWork) {
        unsigned int out{ 0 };
        for (int item : piles) {
            out += (item - 1) / expectedWork + 1;
        }
        return out;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max{ *max_element(piles.begin(), piles.end()) };
        int arrLength{ static_cast<int>(piles.size()) };
        if (h == arrLength) return max;
        int l{ 0 };
        int r{ max };
        int expectedWork{ l };
        while ((r - l) / 2 + l != expectedWork) {
            expectedWork = (r - l) / 2 + l;
            unsigned int dur = workDurationInHours(piles, expectedWork);
            if (dur > h)
                l = expectedWork;
            else {
                r = expectedWork + 1;
            }

        }


        return expectedWork;
    }
};