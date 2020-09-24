std::vector<int> input {1, -1, -2, -3, 1, -2, 3};
    
    std::vector<int> dp (input.size(),0);
    dp[0] = input[0];
    
    int dieSize = 3;

    for (size_t i = 1; i < dp.size(); i++) {
        int maxSum = input[i] + dp[std::max(int(i-dieSize),0)];
        for (size_t j = 1; j <= dieSize; j++) {
            if (i > j) {
                maxSum = std::max(maxSum, input[i] + dp[i-j]);
            }
            else
                break;
        }
        dp[i] = maxSum;
    }
    
    for (auto ele : dp) {
        std::cout << ele << '\n';
    }
    
    return 0;
