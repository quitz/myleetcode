class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx = 0;
        int i=0,j=0;
        if(m==0){
            nums1.assign(nums2.begin(),nums2.end());
            return;
        }
        if(n==0)
            return;
        vector<int> a(m+n,0);
        while(i<m && j<n)
            a[idx++] = nums1[i]<=nums2[j]?nums1[i++]:nums2[j++];
        
        if(i==m)
            for(;j<n;j++)
                a[idx++] = nums2[j];
        
        else if(j==n)
            for(;i<m;i++)
                a[idx++] = nums1[i];
       
       // nums1.clear();
        nums1.assign(a.begin(),a.end());
        return;
    }
};