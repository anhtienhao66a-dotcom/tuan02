import time
import random
import matplotlib.pyplot as plt
import numpy as np

# 1. Thuật toán sắp xếp chọn Selection Sort O(n^2)
def selection_sort(a: list):
    n = len(a)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if a[j] < a[min_idx]:
                min_idx = j
        a[i], a[min_idx] = a[min_idx], a[i]

# 2. Đo thời gian: Chạy lặp 3 lần và lấy giá trị nhỏ nhất
def do_thoi_gian(n: int, lap: int = 3) -> float:
    min_t = float('inf')
    random.seed(42)
    for _ in range(lap):
        a = [random.randint(-10000, 10000) for _ in range(n)]
        t0 = time.perf_counter()
        selection_sort(a)
        t1 = time.perf_counter()
        min_t = min(min_t, t1 - t0)
    return min_t

def main():
    sizes = [500, 1000, 2000, 4000]
    
    # Đo thời gian tại từng mốc
    times = [do_thoi_gian(n, 3) for n in sizes]

    # In kết quả kiểm chứng tỉ lệ ra console (Bảng 1)
    print("========== KET QUA KIEM CHUNG TI LE ==========")
    print(f"n = 500  -> 1000: ti le = {times[1] / times[0]:.2f}")
    print(f"n = 1000 -> 2000: ti le = {times[2] / times[1]:.2f}")
    print(f"n = 2000 -> 4000: ti le = {times[3] / times[2]:.2f}")

    # In bảng thời gian chi tiết (Bảng 2)
    print("\n========== BANG DO THOI GIAN (GIAY) ==========")
    for n, t in zip(sizes, times):
        print(f"n={n}: {t:.6f}s | ", end="")
    print(f"Ti le cuoi: {times[3] / times[2]:.2f}\n")

    # 3. Vẽ duy nhất 1 đồ thị đơn O(n^2)
    n_arr = np.array(sizes)
    t_arr = np.array(times)

    plt.figure(figsize=(7.5, 5))
    plt.plot(n_arr, t_arr, 'o-', color='#1f77b4', linewidth=2.5, markersize=8, label='Thực nghiệm (Selection Sort)')

    # Hiển thị số giây chi tiết trên từng điểm mốc
    for x, y in zip(n_arr, t_arr):
        plt.annotate(f'{y:.4f}s', (x, y), textcoords="offset points", xytext=(0, 10), ha='center', fontsize=10, fontweight='bold')

    plt.title(r'Đồ thị thời gian chạy của thuật toán $O(n^2)$ khi $n$ tăng gấp đôi', fontsize=12, fontweight='bold')
    plt.xlabel('Kích thước mảng (n)', fontsize=11)
    plt.ylabel('Thời gian thực thi (giây)', fontsize=11)
    plt.xticks(n_arr)
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend(fontsize=10)
    plt.tight_layout()

    # Lưu đồ thị vào file ảnh để chèn vào báo cáo
    plt.savefig('dothi_bai44.png', dpi=300)
    print("-> Da luu do thi don vao file 'dothi_bai44.png' thanh cong.")
    plt.show()

if __name__ == "__main__":
    main()