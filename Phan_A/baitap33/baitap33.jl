function phan_tich(n::Int)
    so_chu_so = 0
    tong_chu_so = 0
    while n > 0
        tong_chu_so += n % 10
        so_chu_so += 1
        n = div(n, 10)
    end
    return (so_chu_so, tong_chu_so)
end

function main()
    for line in eachline(stdin)
        line = strip(line)
        if isempty(line)
            continue
        end
        n = parse(Int, line)
        so_chu_so, tong_chu_so = phan_tich(n)
        println("$(so_chu_so) $(tong_chu_so)")
    end
end

main()