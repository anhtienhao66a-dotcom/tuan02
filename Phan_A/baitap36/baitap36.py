import sys

LLONG_MAX = 9223372036854775807

def giai_thua(n: int) -> int:
    kq = 1
    for i in range(1, n + 1):
        if kq > LLONG_MAX // i:
            return -1
        kq *= i
    return kq

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        n = int(line)
        res = giai_thua(n)
        if res != -1:
            print(res)
        else:
            print("TRAN SO (21! = 51 090 942 171 709 440 000 > 9 223 372 036 854 775 807)")

if __name__ == "__main__":
    main()