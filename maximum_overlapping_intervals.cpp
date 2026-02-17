// Problem: Maximum Number of Overlapping Intervals
// Link: https://www.geeksforgeeks.org/problems/intersecting-intervals/1
class Solution {
public:
    int overlapInt(vector<vector<int>> &arr) {
        map<int, int> events;

        // Step 1: Mark events
        for (auto &interval : arr) {
            int start = interval[0];
            int end = interval[1];

            events[start]++;        // interval starts
            events[end + 1]--;      // interval ends (inclusive fix)
        }

        // Step 2: Sweep through events
        int currentOverlap = 0;
        int maxOverlap = 0;

        for (auto &e : events) {
            currentOverlap += e.second;
            maxOverlap = max(maxOverlap, currentOverlap);
        }

        return maxOverlap;
    }
};
