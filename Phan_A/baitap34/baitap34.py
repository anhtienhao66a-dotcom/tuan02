import sys

def dao_nguoc(n: int) -> int:
    dau = -1 if n < 0 else 1
    temp = abs(n)
    rev = 0
    while temp > 0:
        rev = rev * 10 + (temp % 10)
        temp //= 10
    return rev * dau

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        n = int(line)
        print(dao_nguoc(n))

if __name__ == "__main__":
    main()