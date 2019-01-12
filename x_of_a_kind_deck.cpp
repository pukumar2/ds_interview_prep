/* Run time 8ms, beats 88% CPP submission */
class Solution {
public:
    int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
    
    int findGCD(vector<int> arr) 
{ 
        
    int n = arr.size();    
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 
    
    bool hasGroupsSizeX(vector<int>& deck) {
       
        int n = deck.size();
        
        map<int, int> m;
        
        vector<int> vec;
        for(int i = 0; i <deck.size(); i++){
            auto it = m.find(deck[i]);
            if(it != m.end()){
                it->second++;
            } else {
                pair<int, int> p;
                p = make_pair(deck[i], 1);
                m.insert(p);
            }
        }
        
        for(auto it = m.begin(); it != m.end(); it++){
            vec.push_back(it->second);
        }
        
        int gcd = findGCD(vec);
        
        if(gcd > 1){
            return true;
        }
        
        return false;
        
    }
};
