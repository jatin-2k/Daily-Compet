
class Solution {
public:
    bool isRobotBounded(string s) {
        vector<int> dir = {0,1};
        vector<int> pos = {0,0};
        for(int i = 0; i<s.size(); i++){
            switch(s[i]){
                case 'G':
                    pos[0] += dir[0]; pos[1] += dir[1];
                    break;
                case 'L':
                    dir = {-dir[1], dir[0]};
                    break;
                case 'R':
                    dir = {dir[1], -dir[0]};
                    break;
            }
        }
        return (pos[0]==0 && pos[1]==0) or (dir[0] != 0 || dir[1] != 1);
    }
    
};