class Node {
public:
    int start;
    int end;
    int profit;
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Node> ranges;
        for (int i = 0; i < n; ++i) {
            ranges.push_back({startTime[i], endTime[i], profit[i]});
        }
        
        sort(begin(ranges), end(ranges), [&](const Node &a, const Node &b) {
            if (a.start == b.start) return a.end < b.end;
            return a.start < b.start;
        });
        vector<int> dp(n + 1, 0);
        dp[n - 1] = ranges[n - 1].profit;
        auto binary_search = [&](auto &&binary_search, int s, int e, int x) {
            int res = -1;
            while (s <= e) {
                int m = s + ((e - s) / 2);
                if (ranges[m].start >= x) {
                    e = m - 1;
                    res = m;
                } else {
                    s = m + 1;
                }
            }
            return res;
        };
        for (int i = n - 2; i >= 0; --i) {
            /* if we take the current interval, then next interval we can take is a[i].end (atleast) do the binary search to find this interval this would be your dp transition, and we will maximise the answer  by taking max(dp[i + 1], dp[found_interval_index] + cur_interval_profit); */
            int retValue = binary_search(binary_search, i + 1, n - 1, ranges[i].end);
            dp[i] = max(dp[i + 1], (retValue != -1? dp[retValue]: 0) + ranges[i].profit);
        }
        
        return dp[0];
    }
};