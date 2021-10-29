// Algorithm: We need to find the worst case. Initially take 1 socks of each color and reduce each element by 1.
// After that just try to keep every element as odd by picking pair of each color (if possible) and res++ accordingly.
// If socksPair is still less than k, then in another loop, take all remaining socks till we get K pairs. 
// At last if we get K pairs then return res, otherwise return -1.

int find_min(int a[], int n, int k) {
    int res = n, socksPair = 0;
    for(int i=0; socksPair<k && i<n; i++) {
        a[i]--;
        while(a[i]>=2) {
            socksPair += 1;
            if(socksPair == k) {
                res += 1;
                break;
            }
            res += 2;
            a[i] -= 2;
        }
    }
    for(int i=0; socksPair<k && i<n; i++) {
        if(a[i] > 0) socksPair++, res++;
    }
    return (socksPair == k)? res : -1;
}
