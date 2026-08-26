import sys
import math

def doc_du_lieu(ten_tep: str):
    D = []
    with open(ten_tep, 'r', encoding='utf-8') as f:
        lines = f.read().split()
        if not lines:
            return [], 0
        n = int(lines[0])
        d = int(lines[1])
        idx = 2
        for _ in range(n):
            features = [float(x) for x in lines[idx:idx + d]]
            idx += d
            label = lines[idx]
            idx += 1
            D.append((features, label))
    return D, d

def khoang_cach(u, v):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(u, v)))

def lang_gieng_gan_nhat(q, D):
    min_dist = float('inf')
    best_label = ""
    best_idx = -1

    for i, (features, label) in enumerate(D, start=1):
        dist = khoang_cach(q, features)
        if dist < min_dist:
            min_dist = dist
            best_label = label
            best_idx = i

    return best_label, best_idx, min_dist

def main():
    D, d = doc_du_lieu("hoa30.txt")
    if not D:
        return

    content = sys.stdin.read().split()
    if not content:
        return

    idx = 0
    while idx < len(content):
        q = [float(x) for x in content[idx:idx + d]]
        idx += d
        nhan, chi_so, dist = lang_gieng_gan_nhat(q, D)
        print(f"{nhan} - mau {chi_so}, khoang cách {dist:.4f}", flush=True)

if __name__ == "__main__":
    main()