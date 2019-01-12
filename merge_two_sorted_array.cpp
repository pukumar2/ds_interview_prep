/* Run time 4ms, beats 100% CPP Submissions */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int one = m-1;
        int two = n-1;
       
        int mergepos = one + two + 1;
        
        while(one >= 0 && two >= 0){
            if(nums1[one] > nums2[two]){
                nums1[mergepos--] = nums1[one--];
            } 
            else {
                nums1[mergepos--] = nums2[two--];
            }
        }
        
        
       /* while (one >= 0 && two >= 0) {
            if (nums1[one] > nums2[two])
                nums1[mergepos--] = nums1[one--] ;
            else 
                nums1[mergepos--] = nums2[two--];
        }*/
        
        while(two >= 0){
            nums1[mergepos--] = nums2[two--];
        }
      
      
      /*
        int one = m - 1, two = n - 1;
        int mergePos = two + one + 1;
        
        while (one >= 0 && two >= 0) {
            if (nums1[one] > nums2[two])
                nums1[mergePos--] = nums1[one--] ;
            else 
                nums1[mergePos--] = nums2[two--];
        }
        
        while (two >= 0)
            nums1[mergePos--] = nums2[two--];
        */
    }
};
