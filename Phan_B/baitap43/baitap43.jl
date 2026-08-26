const DEM = Ref(0)

function fib_de_quy(n)
    DEM[] += 1
    if n <= 2
        return Int64(1)
    end
    return fib_de_quy(n - 1) + fib_de_quy(n - 2)
end

function fib_ghi_nho(n, memo=Dict{Int, Int64}())
    if n <= 2
        return Int64(1)
    end
    if haskey(memo, n)
        return memo[n]
    end
    memo[n] = fib_ghi_nho(n - 1, memo) + fib_ghi_nho(n - 2, memo)
    return memo[n]
end

function fib_lap(n)
    if n <= 2
        return Int64(1)
    end
    a = Int64(1)
    b = Int64(1)
    for i in 3:n
        c = a + b
        a = b
        b = c
    end
    return b
end

function main()
    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    for token in tokens
        n = parse(Int, token)
        if n >= 93
            println("tran long long - phai phat hien va bao")
            continue
        end

        if n <= 35
            DEM[] = 0
            ans = fib_de_quy(n)
            println("F = $(ans), so loi goi = $(DEM[])")
        else
            ans = fib_lap(n)
            println("F = $(ans)")
        end
        flush(stdout)
    end
end

main()