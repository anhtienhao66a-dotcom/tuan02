function is_square(n::UInt128)
    if n == 0 || n == 1
        return true
    end

    left = UInt128(1)
    right = min(n, UInt128(10^9))

    while left <= right
        mid = left + div(right - left, 2)
        sq = mid * mid

        if sq == n
            return true
        elseif sq < n
            left = mid + 1
        else
            right = mid - 1
        end
    end
    return false
end

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end

    n = parse(UInt128, input_data[1])
    if is_square(n)
        println("YES")
    else
        println("NO")
    end
end

main()