function giai_thua(n::Int)
    kq = Int64(1)
    for i in 1:n
        if kq > div(typemax(Int64), Int64(i))
            return -1
        end
        kq *= Int64(i)
    end
    return kq
end

function main()
    for line in eachline(stdin)
        line = strip(line)
        if isempty(line)
            continue
        end
        n = parse(Int, line)
        res = giai_thua(n)
        if res != -1
            println(res)
        else
            println("TRAN SO (21! = 51 090 942 171 709 440 000 > 9 223 372 036 854 775 807)")
        end
    end
end

main()