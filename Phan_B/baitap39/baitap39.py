import sys
import time

def cach1(a):
    n = len(a)
    max_sum = a[0]
    for i in range(n):
        for j in range(i, n):
            s = sum(a[i:j+1])
            if s > max_sum: max_sum = s
    return max_sum

def cach2(a):
    n = len(a)
    max_sum = a[0]
    for i in range(n):
        s = 0
        for j in range(i, n):
            s += a[j]
            if s > max_sum: max_sum = s
    return max_sum

def kadane(a):
    max_so_far = a[0]
    curr_max = a[0]
    for x in a[1:]:
        curr_max = max(x, curr_max + x)
        max_so_far = max(max_so_far, curr_max)
    return max_so_far

def main():
    content = sys.stdin.read().split()
    if not content: return
    idx = 0
    while idx < len(content):
        n = int(content[idx])
        idx += 1
        a = [int(x) for x in content[idx:idx + n]]
        idx += n

        st1 = time.perf_counter()
        r1 = cach1(a)
        d1 = time.perf_counter() - st1

        st2 = time.perf_counter()
        r2 = cach2(a)
        d2 = time.perf_counter() - st2

        reps = 5000
        st3 = time.perf_counter()
        for _ in range(reps):
            r3 = kadane(a)
        d3 = (time.perf_counter() - st3) / reps

        print(f"Ket qua: {r3}")
        print(f"1 - O(n^3):  {d1:.8f}s")
        print(f"2 - O(n^2):  {d2:.8f}s")
        print(f"3 - Kadane:  {d3:.8f}s", flush=True)

if __name__ == "__main__":
    main()