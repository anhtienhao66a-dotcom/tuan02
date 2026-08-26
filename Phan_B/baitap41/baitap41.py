import sys
import random

def tich_lon_nhat(a: list) -> int:
    n = len(a)
    ans = a[0]
    max_p = a[0]
    min_p = a[0]

    for i in range(1, n):
        if a[i] < 0:
            max_p, min_p = min_p, max_p
        max_p = max(a[i], max_p * a[i])
        min_p = min(a[i], min_p * a[i])
        ans = max(ans, max_p)
    return ans

def tich_lon_nhat_n2(a: list) -> int:
    n = len(a)
    ans = a[0]
    for i in range(n):
        cur = 1
        for j in range(i, n):
            cur *= a[j]
            ans = max(ans, cur)
    return ans

def kiem_thu_tu_dong(so_lan: int = 1000):
    for _ in range(so_lan):
        n = random.randint(1, 15)
        a = [random.randint(-5, 5) for _ in range(n)]
        if tich_lon_nhat(a) != tich_lon_nhat_n2(a):
            print(f"FAILED voi mang: {a}")
            return
    print("OK (1000 tests matched)")

def main():
    if len(sys.argv) > 1 and sys.argv[1] == "--test":
        kiem_thu_tu_dong()
        return

    content = sys.stdin.read().split()
    if not content:
        return
    idx = 0
    while idx < len(content):
        n = int(content[idx])
        idx += 1
        a = [int(x) for x in content[idx:idx + n]]
        idx += n
        print(tich_lon_nhat(a), flush=True)

if __name__ == "__main__":
    main()