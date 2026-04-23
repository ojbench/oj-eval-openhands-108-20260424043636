#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    // dp[j] represents the maximum value achievable with capacity j
    std::vector<int> dp(m + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int p, w, v;
        std::cin >> p >> w >> v;
        
        // Binary optimization: decompose p items into powers of 2
        // This reduces O(p) to O(log p) for each item type
        int remaining = p;
        int power = 1;
        
        while (remaining > 0) {
            int count = std::min(power, remaining);
            int total_weight = count * w;
            int total_value = count * v;
            
            // 0-1 knapsack update in reverse order
            for (int j = m; j >= total_weight; j--) {
                dp[j] = std::max(dp[j], dp[j - total_weight] + total_value);
            }
            
            remaining -= count;
            power *= 2;
        }
    }
    
    std::cout << dp[m] << std::endl;
    
    return 0;
}