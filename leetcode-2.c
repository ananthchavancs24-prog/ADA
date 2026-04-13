int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int sumOfGCD(int* nums, int numsSize){
    int sum = 0;

    for(int i = 0; i < numsSize; i++){
        for(int j = i + 1; j < numsSize; j++){
            sum += gcd(nums[i], nums[j]);
        }
    }

    return sum;
}
