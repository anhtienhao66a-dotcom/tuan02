import sys

dem = 0

def fib_de_quy(n: int) -> int:
    global dem
    dem += 1
    if n <= 2:
        return 1
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)

def fib_ghi_nho(n: int, bo_nho=None) -> int:
    if bo_nho is None:
        bo_nho = {}
    if n <= 2:
        return 1
    if n in bo_nho:
        return bo_nho[n]
    bo_nho[n] = fib_ghi_nho(n - 1, bo_nho) + fib_ghi_nho(n - 2, bo_nho)
    return bo_nho[n]

def fib_lap(n: int) -> int:
    if n <= 2:
        return 1
    a, b = 1, 1
    for _ in range(3, n + 1):
        a, b = b, a + b
    return b

def main():
    global dem
    content = sys.stdin.read().split()
    if not content:
        return
    for token in content:
        n = int(token)
        if n >= 93:
            print("tran long long - phai phat hien va bao", flush=True)
            continue

        if n <= 35:
            dem = 0
            ans = fib_de_quy(n)
            print(f"F = {ans}, so loi goi = {dem}", flush=True)
        else:
            ans = fib_lap(n)
            print(f"F = {ans}", flush=True)

if __name__ == "__main__":
    main()