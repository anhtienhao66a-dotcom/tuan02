function luy_thua_mod(a::Int64, b::Int64, m::Int64)
    r = Int64(1 % m)
    a = a % m
    while b > 0
        if (b & 1) == 1
            r = (r * a) % m
        end
        a = (a * a) % m
        b >>= 1
    end
    return r
end

function main()
    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    idx = 1
    while idx <= length(tokens)
        a = parse(Int64, tokens[idx])
        b = parse(Int64, tokens[idx + 1])
        m = parse(Int64, tokens[idx + 2])
        idx += 3
        println(luy_thua_mod(a, b, m))
        flush(stdout)
    end
end

main()