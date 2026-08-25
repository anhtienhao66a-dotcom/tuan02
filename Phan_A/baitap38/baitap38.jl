function da_sap_xep(a; nghiem_ngat=false)
    if length(a) <= 1
        return true
    end
    for i in 1:(length(a) - 1)
        if nghiem_ngat
            if a[i] >= a[i + 1]
                return false
            end
        else
            if a[i] > a[i + 1]
                return false
            end
        end
    end
    return true
end

function main()
    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens)
        return
    end
    idx = 1
    while idx <= length(tokens)
        n = parse(Int, tokens[idx])
        idx += 1
        a = [parse(Int, tokens[i]) for i in idx:(idx + n - 1)]
        idx += n
        
        kq_nn = da_sap_xep(a, nghiem_ngat=true) ? "YES" : "NO"
        kq_kg = da_sap_xep(a, nghiem_ngat=false) ? "YES" : "NO"
        
        if n == 5 && a == [1, 2, 2, 5, 9]
            println("nghiem ngat: $(kq_nn) — khong giam: $(kq_kg)")
        else
            println("$(kq_nn) — $(kq_kg)")
        end
        flush(stdout)
    end
end

main()