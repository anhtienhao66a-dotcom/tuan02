import sys

def luy_thua_mod(a: int, b: int, m: int) -> int:
    r = 1 % m
    a %= m
    while b > 0:
        if b & 1:
            r = (r * a) % m
        a = (a * a) % m
        b >>= 1
    return r

def main():
    content = sys.stdin.read().split()
    if not content:
        return
    idx = 0
    while idx < len(content):
        a = int(content[idx])
        b = int(content[idx + 1])
        m = int(content[idx + 2])
        idx += 3
        print(luy_thua_mod(a, b, m), flush=True)

if __name__ == "__main__":
    main()