import sys
import math

# 9 mau hoa dien vi rut gon (Vi du 1.8)
D = [
    ([1.4, 0.2], "Setosa"),      # Mau 1
    ([1.3, 0.2], "Setosa"),      # Mau 2
    ([1.5, 0.2], "Setosa"),      # Mau 3
    ([4.7, 1.4], "Versicolor"),  # Mau 4
    ([4.5, 1.5], "Versicolor"),  # Mau 5
    ([4.9, 1.5], "Versicolor"),  # Mau 6
    ([6.0, 2.5], "Virginica"),   # Mau 7
    ([5.8, 1.9], "Virginica"),   # Mau 8
    ([6.3, 2.5], "Virginica")    # Mau 9
]

def khoang_cach(u, v):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(u, v)))

def lang_gieng_gan_nhat(q, tap_mau):
    min_dist = float('inf')
    best_label = ""
    best_idx = -1

    for i, (x, y) in enumerate(tap_mau, start=1):
        d = khoang_cach(q, x)
        if d < min_dist:
            min_dist = d
            best_label = y
            best_idx = i

    return best_label, min_dist, best_idx

def main():
    content = sys.stdin.read().split()
    if not content:
        return
    idx = 0
    while idx < len(content):
        x1 = float(content[idx])
        x2 = float(content[idx + 1])
        idx += 2
        nhan, dist, chi_so = lang_gieng_gan_nhat([x1, x2], D)
        if round(dist, 4) == 0:
            print(f"{nhan} - trung dung mau {chi_so}, khoang cach 0", flush=True)
        else:
            print(f"{nhan} - lang gieng la mau {chi_so}, khoang cach {dist:.4f}", flush=True)

if __name__ == "__main__":
    main()