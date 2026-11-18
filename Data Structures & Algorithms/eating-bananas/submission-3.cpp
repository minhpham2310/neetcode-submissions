class Solution {
public:
    unsigned int workDurationInHours(vector<int>& piles, int expectedWork) {
        unsigned int out{ 0 };
        for (int item : piles) {
            int buffer{ 0 };
            if (item % expectedWork) buffer = expectedWork - item % expectedWork;
            out += (buffer + item) / expectedWork;
        }
        return out;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max{ *max_element(piles.begin(), piles.end()) };
        int arrLength{ static_cast<int>(piles.size()) };
        if (h == arrLength) return max;
        int l{ 0 };
        int r{ max + 1 };
        int expectedWork{ l };
        int minWork{ max };
        int minDur{h};
        while ((r - l) / 2 + l != expectedWork) {
            expectedWork = (r - l) / 2 + l;
            if (!expectedWork) break;
            unsigned int dur = workDurationInHours(piles, expectedWork);
            if (dur > h)
                l = expectedWork;
            else {
                if (h - dur <= minDur && expectedWork < minWork) { minDur = h - dur; minWork = expectedWork; }
                r = expectedWork;
            }

        }


        return minWork;
    }
};