class Solution {
public:
/*
each cinema has n rows of seats -> numbered from 1 to n. each row has 10 seats -> numbered from 1 to 10.
reservedSeats[i] = [rowi, seati] -> seati in rowi is already reserved
four person group must be assigned four seats in the same row like -> seats [2,3,4,5]-> the seats have to be consecutive
*/
/* 
*****The seats can be given are -> [2,3,4,5], [4,5,6,7],[6,7,8,9]
Dry run of testcase :-
I>  n = 3, reservedSeats = [[1,2], [1,3], [1,8],[2,6],[3,1], [3,10]]
    seats that can be given :- [<[1, 4],[1,5],[1,6],[1,7]>,[2,1],<[2,2],[2,3],[2,4],[2,5]>,
    <[3,2],[3,3],[3,4],[3,5]>,<[3,6],[3,7],[3,8],[3,9]>]
    the continous parts ->1+1+1+1 = 4 which is the answer
II> n = 2, reservedSeats = [[2,1], [1,8], [2,6]]
    seats that can be given :- [[1,1], <[1,2], [1,3],[1,4],[1,5]>,[1,6],[1,7],[1,9],[1,10], 
    ,< [2, 2],[2,3],[2,4],[2,5]>,[2,7],[2,8],[2,9],[2,10]]
    the continous parts -> 2 which is the answer
*/
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> grp;
        long long count_group = 0;
        for(auto &seat: reservedSeats){
            int row = seat[0];
            int col = seat[1];
            grp[row].insert(col);
        }
        for(auto &[row, seats]: grp){
            bool left = !seats.count(2) && !seats.count(3) && !seats.count(4) && !seats.count(5);
            bool mid = !seats.count(4) && !seats.count(5) && !seats.count(6) && !seats.count(7);
            bool right = !seats.count(6) && !seats.count(7) && !seats.count(8) && !seats.count(9);
            if(left && right){
                count_group += 2;
            }
            else if(left || mid || right) count_group += 1;
        }
        count_group += (long long) (n - grp.size()) * 2;
        return (int)count_group;
    }
};