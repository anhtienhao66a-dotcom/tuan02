using Random
using Printf

function cua_so_truot(a, k)
    n = length(a)
    cur_sum = sum(a[1:k])
    max_sum = cur_sum
    best_start = 1

    for i in (k + 1):n
        cur_sum += a[i] - a[i - k]
        if cur_sum > max_sum
            max_sum = cur_sum
            best_start = i - k + 1
        end
    end
    return max_sum, best_start
end

function ngay_tho(a, k)
    n = length(a)
    max_sum = -typemax(Int64)
    best_start = 1
    for i in 1:(n - k + 1)
        s = sum(a[i:(i + k - 1)])
        if s > max_sum
            max_sum = s
            best_start = i
        end
    end
    return max_sum, best_start
end

function benchmark()
    # Warm-up JIT
    d = [1, 2, 3, 4]
    cua_so_truot(d, 2); ngay_tho(d, 2)

    n, k = 1000000, 1000
    Random.seed!(42)
    a = rand(-100:100, n)

    st = time_ns()
    ngay_tho(a, k)
    t_naive = (time_ns() - st) / 1e9

    st = time_ns()
    cua_so_truot(a, k)
    t_slide = (time_ns() - st) / 1e9

    println("=== BENCHMARK JULIA (n=10^6, k=1000) ===")
    @printf("Ngay tho O(n*k): %.6fs\n", t_naive)
    @printf("Cua so truot O(n): %.6fs\n", t_slide)
    @printf("So lan nhanh hon: %.1f lan\n", t_naive / t_slide)
end

function main()
    if length(ARGS) > 0 && ARGS[1] == "--benchmark"
        benchmark()
        return
    end

    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end
    idx = 1
    while idx <= length(tokens)
        n = parse(Int, tokens[idx])
        k = parse(Int, tokens[idx + 1])
        idx += 2
        a = [parse(Int, tokens[i]) for i in idx:(idx + n - 1)]
        idx += n
        if k > n || k <= 0 continue end
        max_s, start_pos = cua_so_truot(a, k)
        println("tong $(max_s), bat dau tai vi tri $(start_pos)")
        flush(stdout)
    end
end

main()