class TimeMap {
public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        state[key].push_back({ value, timestamp });
    }

    string get(string key, int timestamp) {
        if (state[key].empty() || timestamp < state[key][0].second) return "";
        else if (timestamp > state[key].back().second) return state[key].back().first;

        int l = 0;
        int r = state[key].size()-1;
        while (l < r) {
            int cur = (r - l) / 2 + l + 1;
            int temp{ state[key][cur].second };
            if (timestamp < state[key][cur].second) {
                r = cur-1;
            }
            else {
                l = cur;
            }
        }
        return state[key][r].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> state{}; // value , timestamp

};