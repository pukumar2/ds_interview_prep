/* Run time 0ms, beats 100% CPP Submission
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {

     unordered_map<char, string> m;
        unordered_set<string> wordset;
        vector<string> s;

        int i=0;
        string temp = "";
        while(i < str.size()){
            if(str[i] == ' '){
                s.push_back(temp);
                temp = "";
            }else temp += str[i];
            i++;
        }


        if(temp.size() > 0) s.push_back(temp);
        if(s.size() != pattern.size())
            return false;

        for(int i=0; i<pattern.size(); ++i){
            if(m.find(pattern[i]) != m.end()){
                if(m[pattern[i]] != s[i])
                    return false;
            }
            m[pattern[i]] = s[i];
            wordset.insert(s[i]);
            if(wordset.size() != m.size()) return false;
        }
        return true;

    }
};
