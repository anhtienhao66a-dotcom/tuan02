import sys
import time
import random

def cua_so_truot(a: list, k: int):
    n = len(a)
    cur_sum = sum(a[:k])
    max_sum = cur_sum
    best_start = 0

    for i in range(k, n):
        cur_sum += a[i] - a[i - k]
        if cur_sum > max_sum:
            max_sum = cur_sum
            best_start = i - k + 1

    return max_sum, best_start + 1

def ngay_tho(a: list, k: int):
    n = len(a)
    max_sum = -float('inf')
    best_start = 0
    for i in range(n - k + 1):
        s = sum(a[i:i + k])
        if s > max_sum:
            max_sum = s
            best_start = i
    return max_sum, best_start + 1

def benchmark():
    n, k = 1000000, 1000
    random.seed(42)
    a = [random.randint(-100, 100) for _ in range(n)]

    st = time.perf_counter()
    ngay_tho(a, k)
    t_naive = time.perf_counter() - st

    st = time.perf_counter()
    cua_so_truot(a, k)
    t_slide = time.perf_counter() - st

    print("=== BENCHMARK PYTHON (n=10^6, k=1000) ===")
    print(f"Ngay tho O(n*k): {t_naive:.6f}s")
    print(f"Cua so truot O(n): {t_slide:.6f}s")
    print(f"So lan nhanh hon: {(t_naive / t_slide):.1f} lan")

def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--benchmark":
        benchmark()
        return

    content = sys.stdin.read().split()
    if not content:
        return
    idx = 0
    while idx < len(content):
        n = int(content[idx])
        k = int(content[idx + 1])
        idx += 2
        a = [int(x) for x in content[idx:idx + n]]
        idx += n
        if k > n or k <= 0:
            continue
        max_s, start_pos = cua_so_truot(a, k)
        print(f"tong {max_s}, bat dau tai vi tri {start_pos}", flush=True)

if __name__ == "__main__":
    main()