import sys
N = int(input())

def factorial(N):
    result = 1
    for i in range(2, N + 1):
        result *= i
    return result

print(factorial(N))