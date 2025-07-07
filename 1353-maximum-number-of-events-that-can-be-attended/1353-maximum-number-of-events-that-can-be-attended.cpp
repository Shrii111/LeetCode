class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
          sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = events.size(), day = 0, i = 0, count = 0;
    int lastDay = 0;

    for (auto& e : events) lastDay = max(lastDay, e[1]);

    for (day = 1; day <= lastDay; ++day) {
        // Add events that start today
        while (i < n && events[i][0] == day)
            minHeap.push(events[i++][1]);

        // Remove events that have already expired
        while (!minHeap.empty() && minHeap.top() < day)
            minHeap.pop();

        // Attend one event that ends earliest
        if (!minHeap.empty()) {
            minHeap.pop();
            count++;
        }
    }

    return count;
    }
};