using Random

function tich_lon_nhat(a)
    n = length(a)
    ans = a[1]
    max_p = a[1]
    min_p = a[1]

    for i in 2:n
        if a[i] < 0
            max_p, min_p = min_p, max_p
        end
        max_p = max(a[i], max_p * a[i])
        min_p = min(a[i], min_p * a[i])
        ans = max(ans, max_p)
    end
    return ans
end

function tich_lon_nhat_n2(a)
    n = length(a)
    ans = a[1]
    for i in 1:n
        cur = 1
        for j in i:n
            cur *= a[j]
            ans = max(ans, cur)
        end
    end
    return ans
end

function kiem_thu_tu_dong(so_lan=1000)
    for _ in 1:so_lan
        n = rand(1:15)
        a = rand(-5:5, n)
        if tich_lon_nhat(a) != tich_lon_nhat_n2(a)
            println("FAILED voi mang: ", a)
            return
        end
    end
    println("OK (1000 tests matched)")
end

function main()
    if length(ARGS) > 0 && ARGS[1] == "--test"
        kiem_thu_tu_dong()
        return
    end

    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    idx = 1
    while idx <= length(tokens)
        n = parse(Int, tokens[idx])
        idx += 1
        a = [parse(Int, tokens[i]) for i in idx:(idx + n - 1)]
        idx += n
        println(tich_lon_nhat(a))
        flush(stdout)
    end
end

main()