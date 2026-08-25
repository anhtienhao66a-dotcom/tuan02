import sys

def kadane_chi_so(a: list):
    max_so_far = a[0]
    curr_max = a[0]
    start = 0
    end = 0
    temp_start = 0

    for i in range(1, len(a)):
        if a[i] > curr_max + a[i]:
            curr_max = a[i]
            temp_start = i
        else:
            curr_max += a[i]

        if curr_max > max_so_far:
            max_so_far = curr_max
            start = temp_start
            end = i

    # Đánh số từ 1
    return max_so_far, start + 1, end + 1

def main():
    content = sys.stdin.read().split()
    if not content:
        return
    idx = 0
    while idx < len(content):
        n = int(content[idx])
        idx += 1
        a = [int(x) for x in content[idx:idx + n]]
        idx += n
        tong, dau, cuoi = kadane_chi_so(a)
        print(f"tong {tong}, doan [{dau}..{cuoi}]", flush=True)

if __name__ == "__main__":
    main()