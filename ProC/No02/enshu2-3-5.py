lower = int(input("下限値を入力："))
upper = int(input("上限値を入力："))
primes = []
flag = False

def isPrime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

for num in range(lower, upper + 1):
        if isPrime(num):
            primes.append(num)
    
print(primes)
