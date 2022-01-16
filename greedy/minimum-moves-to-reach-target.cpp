class Solution {
public:
    int minMoves(int target, int maxDoubles, int moves = 0) {
        while(target > 0){
            if(target == 1) return moves;
            if(maxDoubles == 0) return moves + target - 1;
            if(target % 2 == 0 && maxDoubles > 0){
                target = target / 2;
                maxDoubles--; moves++;
            }
            else{
                target--;
                moves++;
            }
        }
        return -1;
    }
};