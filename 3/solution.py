#!/usr/bin/python

import sys
N = 600851475143
memo = {1 : 1}

def get_memo(n):
    return memo[n]

def set_memo(k,v):
    print "Used set_memo for %s" % k
    memo[k] = v

def main(n):
    primes = primefactors(n)
    print primes

def primefactors(n):
    factors = set()
    primes = []
    try:
        ret = get_memo(n)
        print "Used get_memo for %s" % n
        return ret
    except KeyError:
        i = 0
        upper = n+1
        while i < upper:
            i += 1
            if i in factors:
                continue
            if n%i == 0:
                upper = n/i
                factors.add(i)
                factors.add(n/i)
        if len(factors) == 2:
            set_memo(n,n)
            return n
        factors = list(factors)
        factors.sort()
        print factors
        # remove n
        factors.pop()
        for f in factors:
            subprimes = primefactors(f)
            if isinstance(subprimes, int):
                primes.append(f)
        set_memo(n,primes)
        return primes

if __name__ == "__main__":
    if sys.argv[1] == 'N':
        main(N)
    else:
        main(int(sys.argv[1]))
