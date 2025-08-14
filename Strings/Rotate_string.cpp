class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length() ; 
        int m = goal.length() ; 
        if(n != m){
            return false ; 
        }
        for(int i = 0  ; i < n ; i++){
            string temp = s.substr(1) + s[0] ; 
            if(temp == goal){
                return true ; 
            }
            s = temp ; 
        }
        return false ; 
    }
        
};