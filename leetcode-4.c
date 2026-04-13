int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int minimumSplits(int* nums, int numsSize){
    int g = 0, ans = 1;

    for(int i = 0; i < numsSize; i++){
        g = gcd(g, nums[i]);

        if(g == 1){
            ans++;
            g = nums[i];
        }
    }

    return ans;
}
