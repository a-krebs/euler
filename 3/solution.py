#!/usr/bin/python

import sys
N = 600851475143
memo = {}

def main(n):
    """
    Find the largest prime factor of n.

    N is given as the value of n in the problem.
    """
    primes = primefactors(n)
    print primes[-1]

def primefactors(n):
    """
    Recursively find all the prime factors of n.

    Uses memoization to eliminate duplicate calculations.
    """
    factors = []
    primes = []
    try:
        # memoization case
        return memo[n]
    except KeyError:
        i = 0
        upper = n+1
        while i < upper:
            i += 1
            if i in factors:
                continue
            if n%i == 0:
                upper = n/i
                factors.append(i)
                factors.append(n/i)
        # base case: n is prime if it has only 2 factors
        if len(factors) == 2:
            memo[n] = n
            return n
        factors.sort()
        # remove n to avoid infinite recursion
        factors.pop()
        # find out which factors of n are prime
        for f in factors:
            subprimes = primefactors(f)
            if isinstance(subprimes, int):
                primes.append(f)
        memo[n] = primes
        return primes

if __name__ == "__main__":
    if sys.argv[1] == 'N':
        main(N)
    else:
        main(int(sys.argv[1]))
