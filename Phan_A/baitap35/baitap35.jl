function la_nguyen_to(n::Int)
    if n < 2
        return false
    end
    i = 2
    while i * i <= n
        if n % i == 0
            return false
        end
        i += 1
    end
    return true
end

function sang(n::Int)
    check = trues(n)
    if n >= 1
        check[1] = false
    end
    p = 2
    while p * p <= n
        if check[p]
            for i in (p * p):p:n
                check[i] = false
            end
        end
        p += 1
    end
    primes = Int[]
    for i in 1:n
        if check[i]
            push!(primes, i)
        end
    end
    return primes
end

function main()
    for line in eachline(stdin)
        line = strip(line)
        if isempty(line)
            continue
        end
        n = parse(Int, line)
        primes = sang(n)
        if n <= 30
            println(join(primes, " ") * " ($(length(primes)) so)")
        else
            tong = sum(primes)
            if n == 1000000
                println("so luong = $(length(primes)), tong = $(tong)")
            else
                println("so luong = $(length(primes))")
            end
        end
    end
end

main()