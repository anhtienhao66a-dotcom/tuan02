import sys

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    a = [int(x) for x in input_data[1:n+1]]
    
    tong = 0
    nho_nhat = a[0]
    lon_nhat = a[0]
    
    for x in a:
        tong += x
        if x < nho_nhat:
            nho_nhat = x
        if x > lon_nhat:
            lon_nhat = x
            
    trung_binh = tong / n
    print(f"{tong} {trung_binh:.4f} {nho_nhat} {lon_nhat}")

if __name__ == "__main__":
    main()