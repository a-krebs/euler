#!/usr/bin/python

def main():
    """
    Find the largest palindrom made from the product of two
    3-digit numbers.
    """
    i = 999
    j = 999
    products = []
    while i > 100:
        old_j = j
        while j > 100:
            products.append(i*j)
            j -= 1
        i -= 1
        j = i
    products.sort()
    for p in reversed(products):
        if is_palindrome(p):
            print p
            break

def is_palindrome(n):
    array_n = list(str(n))
    print array_n
    l = len(array_n)
    print l
    i = 0
    while i < l/2:
        print array_n[i]
        print array_n[(-i)-1]
        if array_n[i] != array_n[(-i)-1]:
            return False
        i += 1
    return True

if __name__ == "__main__":
    main()
