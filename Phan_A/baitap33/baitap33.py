import sys

def phan_tich(n: int):
    so_chu_so = 0
    tong_chu_so = 0
    while n > 0:
        tong_chu_so += n % 10
        so_chu_so += 1
        n //= 10
    return (so_chu_so, tong_chu_so)

def main():
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue
        n = int(line)
        so_chu_so, tong_chu_so = phan_tich(n)
        print(f"{so_chu_so} {tong_chu_so}")

if __name__ == "__main__":
    main()