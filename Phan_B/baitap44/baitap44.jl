using Random
using Printf

# 1. Thuật toán sắp xếp chọn Selection Sort O(n^2)
function selection_sort!(a)
    n = length(a)
    for i in 1:(n - 1)
        min_idx = i
        for j in (i + 1):n
            if a[j] < a[min_idx]
                min_idx = j
            end
        end
        a[i], a[min_idx] = a[min_idx], a[i]
    end
end

# 2. Đo thời gian: Chạy lặp 3 lần và lấy giá trị nhỏ nhất
function do_thoi_gian(n, lap=3)
    min_t = Inf
    Random.seed!(42)
    for _ in 1:lap
        a = rand(-10000:10000, n)
        t = @elapsed selection_sort!(a)
        min_t = min(min_t, t)
    end
    return min_t
end

# 3. Tự động sinh và lưu đồ thị đơn O(n^2)
function ve_do_thi_don(sizes, times)
    open("plot_julia_single.py", "w") do f
        write(f, """
import matplotlib.pyplot as plt
import numpy as np

sizes = np.array([$(join(sizes, ", "))])
times = np.array([$(join(times, ", "))])

plt.figure(figsize=(7.5, 5))
plt.plot(sizes, times, 's-', color='tab:purple', linewidth=2.5, markersize=8, label='Thực nghiệm Julia (Selection Sort)')

for x, y in zip(sizes, times):
    plt.annotate(f'{y:.6f}s', (x, y), textcoords='offset points', xytext=(0, 10), ha='center', fontsize=9, fontweight='bold')

plt.title(r'Đồ thị thời gian chạy của thuật toán \$O(n^2)\$ khi \$n\$ tăng gấp đôi (Julia)', fontsize=12, fontweight='bold')
plt.xlabel('Kích thước mảng (n)', fontsize=11)
plt.ylabel('Thời gian thực thi (giây)', fontsize=11)
plt.xticks(sizes)
plt.grid(True, linestyle='--', alpha=0.6)
plt.legend(fontsize=10)
plt.tight_layout()

plt.savefig('dothi_bai44_julia.png', dpi=300)
plt.show()
""")
    end
    run(`python plot_julia_single.py`)
    println("-> Da luu do thi don vao file 'dothi_bai44_julia.png' thanh cong.")
end

function main()
    # JIT warm-up
    dummy = [3, 1, 2]
    selection_sort!(dummy)

    sizes = [500, 1000, 2000, 4000]
    times = [do_thoi_gian(n, 3) for n in sizes]

    println("========== KET QUA KIEM CHUNG TI LE JULIA ==========")
    @printf("n = 500  -> 1000: ti le = %.2f\n", times[2] / times[1])
    @printf("n = 1000 -> 2000: ti le = %.2f\n", times[3] / times[2])
    @printf("n = 2000 -> 4000: ti le = %.2f\n", times[4] / times[3])

    println("\n========== BANG DO THOI GIAN JULIA (GIAY) ==========")
    for (n, t) in zip(sizes, times)
        @printf("n=%d: %.6fs | ", n, t)
    end
    @printf("Ti le cuoi: %.2f\n\n", times[4] / times[3])

    ve_do_thi_don(sizes, times)
end

main()