#!/user/bin/python

def main():
    """
    Solution to Euler Project question 1.

    Find the sum of all the multiples of 3 or 5 below 1000.
    """
    print naive()

def naive():
    """
    Naive solution to this problem is to iterate over all
    values up to 1000 and check each for divisibility.
    """
    sum = 0
    for i in xrange(0, 1000):
        if i%3 == 0 or i%5 == 0:
            sum += i
    return sum

if __name__ == "__main__":
    main()

