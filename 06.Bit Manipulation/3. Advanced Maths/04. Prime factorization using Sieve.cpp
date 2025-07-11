/*
QUESTION:
Given a positive integer N, find all **prime factors** of N and return them in a list. Prime factors are the prime numbers that divide N exactly, possibly multiple times.

Example:
Input: N = 60
Output: [2, 2, 3, 5]
Explanation: 60 = 2 × 2 × 3 × 5

Input: N = 17
Output: [17]
Explanation: 17 is a prime number, so its only prime factor is itself.

APPROACH:
To find all prime factors of a given number N:
1. Create a boolean array (sieve-like) to track prime numbers up to N.
2. Iterate from i = 2 to sqrt(N):
   a. If i is prime and divides N, divide N by i repeatedly while it remains divisible.
   b. Add i to the result list each time it divides N.
   c. Mark all multiples of i as non-prime in the sieve.
3. After the loop, if N is still greater than 1, it means N itself is a prime and must be included in the result.
4. Return the list of collected prime factors.

CODE:
*/
vector<int> findPrimeFactors(int n) {
    vector<bool> prime(n + 1, true);  // Boolean array to track primes
    vector<int> ans;                  // Resultant list of prime factors

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            // Divide N by i while it is divisible
            while (n % i == 0) {
                ans.push_back(i);
                n /= i;
            }
            // Mark all multiples of i as non-prime
            for (long long j = 1LL * i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    // If remaining n is a prime number
    if (n > 1)
        ans.push_back(n);

    return ans;
}

// Time Complexity: O(sqrt(N) + log N)
// Space Complexity: O(N)
