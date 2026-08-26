import matplotlib.pyplot as plt
import numpy as np
sizes = np.array([500, 1000, 2000, 4000])
times = np.array([6.95e-05, 0.0002505, 0.0009454, 0.0036535])
plt.figure(figsize=(7.5, 5))
plt.plot(sizes, times, '^-', color='tab:red', linewidth=2.5, markersize=8, label='Thực nghiệm C++ (Selection Sort)')
for x, y in zip(sizes, times):
    plt.annotate(f'{y:.6f}s', (x, y), textcoords='offset points', xytext=(0, 10), ha='center', fontsize=9, fontweight='bold')
plt.title(r'Đồ thị thời gian chạy của thuật toán $O(n^2)$ khi $n$ tăng gấp đôi (C++)', fontsize=12, fontweight='bold')
plt.xlabel('Kích thước mảng (n)', fontsize=11)
plt.ylabel('Thời gian thực thi (giây)', fontsize=11)
plt.xticks(sizes)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=10)
plt.tight_layout()
plt.savefig('dothi_bai44_cpp.png', dpi=300)
plt.show()
