import sys
import math

def doc_du_lieu(ten_tep: str):
    D = []
    with open(ten_tep, 'r', encoding='utf-8') as f:
        lines = f.read().split()
        if not lines:
            return [], 0
        n, d = int(lines[0]), int(lines[1])
        idx = 2
        for i in range(n):
            features = [float(x) for x in lines[idx:idx + d]]
            idx += d
            label = lines[idx]
            idx += 1
            D.append({"x": features, "y": label, "id": i + 1})
    return D, d

def kc_euclid(u, v):
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(u, v)))

def kc_manhattan(u, v):
    return sum(abs(a - b) for a, b in zip(u, v))

def lang_gieng_gan_nhat(q, D, kc=kc_euclid, bo_qua_id=-1):
    min_dist = float('inf')
    best_label = ""
    best_idx = -1

    for item in D:
        if item["id"] == bo_qua_id:
            continue
        dist = kc(q, item["x"])
        if dist < min_dist:
            min_dist = dist
            best_label = item["y"]
            best_idx = item["id"]

    return best_label, best_idx, min_dist

def main():
    D, d = doc_du_lieu("hoa30.txt")
    if not D:
        return

    # 1. Phan loai mau moi (6.5; 3.0; 5.5; 2.0)
    q = [6.5, 3.0, 5.5, 2.0]
    lbl_e, idx_e, dist_e = lang_gieng_gan_nhat(q, D, kc=kc_euclid)
    lbl_m, idx_m, dist_m = lang_gieng_gan_nhat(q, D, kc=kc_manhattan)

    print("=== KET QUA PHAN LOAI MAU MOI ===")
    print(f"Euclid: {lbl_e} - lang gieng la mau {idx_e}, khoang cach {dist_e:.4f}")
    print(f"Manhattan: {lbl_m} - lang gieng la mau {idx_m}, khoang cach {dist_m:.1f}\n")

    # 2. Kiem thu bo mot mau (LOOCV)
    dung_e, dung_m = 0, 0
    thong_tin_sai_m = ""

    for item in D:
        pe_lbl, _, _ = lang_gieng_gan_nhat(item["x"], D, kc=kc_euclid, bo_qua_id=item["id"])
        pm_lbl, pm_idx, pm_dist = lang_gieng_gan_nhat(item["x"], D, kc=kc_manhattan, bo_qua_id=item["id"])

        if pe_lbl == item["y"]:
            dung_e += 1
        if pm_lbl == item["y"]:
            dung_m += 1
        else:
            thong_tin_sai_m = f"Manhattan du doan sai thanh {pm_lbl} (lang gieng mau {pm_idx}, khoang cach {pm_dist:.1f})"

    print("=== KIEM THU BO MOT MAU (LOOCV) ===")
    print(f"Euclid {dung_e}/30 = {dung_e / len(D) * 100:.2f}% - Manhattan {dung_m}/30 = {dung_m / len(D) * 100:.2f}%")
    print(f"Mau 26 khi bi bo ra: {thong_tin_sai_m}")

if __name__ == "__main__":
    main()