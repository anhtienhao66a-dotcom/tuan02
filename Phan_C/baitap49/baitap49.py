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

def bo_mot_mau(D, kc=kc_euclid):
    so_dung = 0
    danh_sach_sai = []

    for i in range(len(D)):
        min_dist = float('inf')
        best_label = ""

        # Bo qua mau i
        for j in range(len(D)):
            if i == j:
                continue
            dist = kc(D[i]["x"], D[j]["x"])
            if dist < min_dist:
                min_dist = dist
                best_label = D[j]["y"]

        if best_label == D[i]["y"]:
            so_dung += 1
        else:
            danh_sach_sai.append(f"sai mau {D[i]['id']} (that: {D[i]['y']}, du doan: {best_label})")

    return so_dung, len(D), danh_sach_sai

def main():
    D30, _ = doc_du_lieu("hoa30.txt")
    
    D9 = [
        {"x": [1.4, 0.2], "y": "Setosa", "id": 1},
        {"x": [1.3, 0.2], "y": "Setosa", "id": 2},
        {"x": [1.5, 0.2], "y": "Setosa", "id": 3},
        {"x": [4.7, 1.4], "y": "Versicolor", "id": 4},
        {"x": [4.5, 1.5], "y": "Versicolor", "id": 5},
        {"x": [4.9, 1.5], "y": "Versicolor", "id": 6},
        {"x": [6.0, 2.5], "y": "Virginica", "id": 7},
        {"x": [5.8, 1.9], "y": "Virginica", "id": 8},
        {"x": [6.3, 2.5], "y": "Virginica", "id": 9}
    ]

    # 1. Euclid tren hoa30
    dung_e, tong_e, sai_e = bo_mot_mau(D30, kc_euclid)
    chuoi_sai_e = "khong mau nao sai" if not sai_e else "; ".join(sai_e)
    print(f"Euclid: {dung_e}/{tong_e} = {dung_e/tong_e*100:.2f}% - {chuoi_sai_e}")

    # 2. Manhattan tren hoa30
    dung_m, tong_m, sai_m = bo_mot_mau(D30, kc_manhattan)
    chuoi_sai_m = "khong mau nao sai" if not sai_m else "; ".join(sai_m)
    print(f"Manhattan: {dung_m}/{tong_m} = {dung_m/tong_m*100:.2f}% - {chuoi_sai_m}")

    # 3. Tap 9 mau Vi du 1.8
    dung_9, tong_9, _ = bo_mot_mau(D9, kc_euclid)
    print(f"Tap 9 mau: {dung_9}/{tong_9} = {dung_9/tong_9*100:.0f}% voi ca hai do do")

if __name__ == "__main__":
    main()