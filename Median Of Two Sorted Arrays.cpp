class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int m=nums1.size();
        int n=nums2.size();
        int left=0;
        int right=m;
        while(left<=right){
            int partitionA=(left+right)/2;
            int partitionB=(m+n+1)/2-partitionA;
            int leftA=(partitionA==0)?INT_MIN:nums1[partitionA-1];
            int rightA=(partitionA==m)?INT_MAX:nums1[partitionA];
            int leftB=(partitionB==0)?INT_MIN:nums2[partitionB-1];
            int rightB=(partitionB==n)?INT_MAX:nums2[partitionB];
            if(leftA<=rightB && leftB<=rightA){
                if((m+n)%2==1){
                    return max(leftA,leftB);
                }
                return (max(leftA,leftB)+min(rightA,rightB))/2.0;
            }
            if(leftA>rightB){
                right=partitionA-1;
            }else{
                left=partitionA+1;
            }
        }
        return 0.0;
    }
};