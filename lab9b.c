int findTargetSumWays(int* nums, int numsSize, int target) {

    int total = 0;

    for(int i = 0; i < numsSize; i++) {
        total += nums[i];
    }

    if((total + target) % 2 != 0 || abs(target) > total)
        return 0;

    int subsetSum = (total + target) / 2;

    int dp[subsetSum + 1];

    for(int i = 0; i <= subsetSum; i++)
        dp[i] = 0;

    dp[0] = 1;

    for(int i = 0; i < numsSize; i++) {

        for(int j = subsetSum; j >= nums[i]; j--) {

            dp[j] += dp[j - nums[i]];
        }
    }

    return dp[subsetSum];
}
