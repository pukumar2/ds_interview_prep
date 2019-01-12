class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     
        
        /* The main idea is to create a map with number and the indices,
         * if the number is occuring two times and in the range of k then return true
         * else update the last occurence index
         * Run time 44ms and beats 40% CPP Submissions
        int n = nums.size();
        
        
        map<int, int> m;
        for(int i = 0; i < n; i++){
            auto it = m.find(nums[i]);
            if(it != m.end()){
                if(abs(it->second - i) <= k){
                    return true;
                } else {
                    it->second = i;
                }
            }
            else {
                pair<int, int> p;
                p = make_pair(nums[i], i);
                m.insert(p);
            }
            
        }
        
        return false;*/
       
       /* The basic idea is to maintain a set s which contain unique values from 
        * nums[i - k] to nums[i - 1], if nums[i] is in set s then return true 
        * else update the set. 
        * Run time 28ms and beats 63% CPP submission
        */
        
       unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
    }
};
