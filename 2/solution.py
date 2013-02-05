#!/user/bin/python

def main():
    """
    Solution to Euler Project question 2.

    Find the sum of the even-valued Fibonacci numbers below four million.
    """
    print naive(1,2)

def naive(first, second):
    """
    Naive solution to this problem is to generate the Fibonnaci sequence numbers
    in turn and add the even ones to a sum.
    """
    s = 0
    while second < 4e6:
        if second%2 == 0:
            s += second
        first, second = second, first+second
    return s

if __name__ == "__main__":
    main()

