int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int gcdOfOddEvenSums(int n) {
    int odd = n * n;
    int even = n * (n + 1);
    return gcd(odd, even);
}
