/*
QUESTION:
Given a non-negative number N, set the rightmost unset bit in its binary representation. If there are no unset bits, leave the number as it is.

Example:
Input: N = 6
Output: 7
Explanation:
The binary representation of 6 is 110.
After setting the rightmost unset bit, it becomes 111 which is 7.

Input: N = 15
Output: 15
Explanation:
The binary representation of 15 is 1111.
Since there are no unset bits, it remains the same.

APPROACH:
To set the rightmost unset bit in the binary representation of N, we can follow these steps:
1. Iterate through all 32 bits of the integer starting from the least significant bit (LSB).
2. For each bit position i, check whether the bit is unset (i.e., 0) using bitwise AND:
   if ((N & (1 << i)) == 0)
3. Once the first unset bit is found, set it using bitwise OR:
   N | (1 << i)
4. Return the modified value immediately.
5. If all bits are already set (no unset bit found), return N as it is.

CODE:
*/
int setRightmostUnsetBit(int N) {
    for (int i = 0; i < 32; i++) {
        if ((N & (1 << i)) == 0) {
            return N | (1 << i); // Set the first 0-bit found
        }
    }
    return N; // All bits are already set
}

// Time Complexity: O(log N)
// Space Complexity: O(1)
