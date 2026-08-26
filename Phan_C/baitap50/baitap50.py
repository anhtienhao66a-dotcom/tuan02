import random
import time

def sinh_du_lieu(n, d):
    return [[random.random() for _ in range(d)] for _ in range(n)]

def kc_euclid_sq(u, v):
    return sum((a - b) ** 2 for a, b in zip(u, v))

def lang_gieng_gan_nhat(q, D):
    min_d2 = float('inf')
    best_idx = -1
    for i, x in enumerate(D):
        d2 = kc_euclid_sq(q, x)
        if d2 < min_d2:
            min_d2 = d2
            best_idx = i
    return best_idx

def main():
    random.seed(12345)
    d = 20
    q_size = 1000
    Q = sinh_du_lieu(q_size, d)

    N_list = [1000, 10000, 100000]
    T = []

    print("=== DO THOI GIAN PYTHON ===")
    for n in N_list:
        D = sinh_du_lieu(n, d)
        
        # Voi n = 10^5 do 100 mau roi nhan 10 de tiet kiem thoi gian
        so_mau = q_size if n <= 10000 else 100
        t0 = time.perf_counter()
        for i in range(so_mau):
            lang_gieng_gan_nhat(Q[i], D)
        t1 = time.perf_counter()
        
        t_chuan = (t1 - t0) * (q_size / so_mau)
        T.append(t_chuan)
        print(f"n = {n}: {t_chuan:.4f} s")

    print(f"Ti le T(10^4)/T(10^3) = {T[1] / T[0]:.2f}")
    print(f"Ti le T(10^5)/T(10^4) = {T[2] / T[1]:.2f}")

if __name__ == "__main__":
    main()