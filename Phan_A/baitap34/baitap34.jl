function dao_nguoc(n::Int)
    dau = n < 0 ? -1 : 1
    temp = abs(n)
    rev = 0
    while temp > 0
        rev = rev * 10 + (temp % 10)
        temp = div(temp, 10)
    end
    return rev * dau
end

function main()
    for line in eachline(stdin)
        line = strip(line)
        if isempty(line)
            continue
        end
        n = parse(Int, line)
        println(dao_nguoc(n))
    end
end

main()