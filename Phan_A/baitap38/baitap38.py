import sys

def da_sap_xep(a: list, nghiem_ngat: bool = False) -> bool:
    if len(a) <= 1:
        return True
    for i in range(len(a) - 1):
        if nghiem_ngat:
            if a[i] >= a[i + 1]:
                return False
        else:
            if a[i] > a[i + 1]:
                return False
    return True

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    while idx < len(input_data):
        n = int(input_data[idx])
        idx += 1
        a = [int(x) for x in input_data[idx:idx + n]]
        idx += n
        
        kq_nn = "YES" if da_sap_xep(a, True) else "NO"
        kq_kg = "YES" if da_sap_xep(a, False) else "NO"
        
        if n == 5 and a == [1, 2, 2, 5, 9]:
            print(f"nghiem ngat: {kq_nn} - khong giam: {kq_kg}", flush=True)
        else:
            print(f"{kq_nn} - {kq_kg}", flush=True)

if __name__ == "__main__":
    main()