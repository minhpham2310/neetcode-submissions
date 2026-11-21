class TimeMap {
public:
    TimeMap() = default;

    void set(string key, string value, int timestamp) {
        state[key].push_back({ value, timestamp });
    }

    string get(string key, int timestamp) {
        if (state.find(key) == state.end()) return "";
        auto& currentObject{ state[key] };
        if (timestamp < currentObject[0].second) return "";
        else if (timestamp >= currentObject.back().second) currentObject.back().first;

        int l = 0;
        int r = currentObject.size()-1;
        while (l < r) {
            int cur = (r - l) / 2 + l + 1;
            int temp{ currentObject[cur].second };
            if (timestamp < currentObject[cur].second) {
                r = cur-1;
            }
            else {
                l = cur;
            }
        }
        return currentObject[r].first;
    }

private:
    unordered_map<string, vector<pair<string, int>>> state{}; // value , timestamp

};
