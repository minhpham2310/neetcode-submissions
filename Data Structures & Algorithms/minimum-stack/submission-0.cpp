using namespace std;

class MinStack {
public:
    MinStack() = default;

    void push(int val) {
        if (list.size() == 0 || val <= minList.back()) {
            minList.push_back(val);
        }
        list.push_back(val);
    }

    void pop() {
        if (list.back() == minList.back()) {
            minList.pop_back();
        }
        list.pop_back();
    }

    int top() {
        return list.back();
    }

    int getMin() {
        return minList.back();
    }

private:
    vector<int32_t> minList;
    vector<int32_t> list;
};