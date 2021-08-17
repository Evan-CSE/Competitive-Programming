/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divisor Game.
 * Memory Usage: 5.7 MB, less than 99.23% of C++ online submissions for Divisor Game.

 * */

class Solution
{
public:
    bool divisorGame(int n)
    {
        return !(n & 1);
    }
};