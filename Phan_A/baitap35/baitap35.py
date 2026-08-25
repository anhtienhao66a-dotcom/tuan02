import sys

def sang(n: int) -> list:
    if n < 2:
        return []
    check = [True] * (n + 1)
    check[0] = check[1] = False
    p = 2
    while p * p <= n:
        if check[p]:
            for i in range(p * p, n + 1, p):
                check[i] = False
        p += 1
    return [p for p in range(2, n + 1) if check[p]]

def main():
    content = sys.stdin.read().strip()
    if not content:
        return
    
    tokens = content.split()
    for token in tokens:
        n = int(token)
        primes = sang(n)
        if n <= 30:
            print(" ".join(map(str, primes)) + f" ({len(primes)} so)", flush=True)
        elif n == 1000000:
            tong = sum(primes)
            print(f"so luong = {len(primes)}, tong = {tong}", flush=True)
        else:
            print(f"so luong = {len(primes)}", flush=True)

if __name__ == "__main__":
    main()