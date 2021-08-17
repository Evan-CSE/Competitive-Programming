/**
 * Key Observation:
 * 1) If we multiply any numbe with its base then all the digits remain same
 * with some left shift operation and with extra 0
 * Example: For 10 based number system
 * 5
 * 5*10 = 50 (same digit but with a 0 and some right shift operation)
 * 125
 * 125*10 = 1250 (same digits  with an extra 0 with some right shift operation)
 * 
 * This is true for all number system. So for binary represtation we can apply same concept
 * 5(101)
 * 5*2 (101<<1) => 1010
 * 
 * 2) For odd numbers we have one set bit in 0th position for binary number system 
 * */

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> v(n + 1);
        v[0] = 0;
        v[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i & 1)
                v[i] = v[i - 1] + 1;
            else
                v[i] = v[i >> 1];
        }
        return v;
    }
};