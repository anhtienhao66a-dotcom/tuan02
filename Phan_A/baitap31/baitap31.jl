using Printf

function main()
    input_data = split(read(stdin, String))
    if isempty(input_data)
        return
    end

    n = parse(Int, input_data[1])
    first_val = parse(Int64, input_data[2])
    
    tong = first_val
    nho_nhat = first_val
    lon_nhat = first_val

    for i in 2:n
        x = parse(Int64, input_data[i+1])
        tong += x
        if x < nho_nhat
            nho_nhat = x
        end
        if x > lon_nhat
            lon_nhat = x
        end
    end

    trung_binh = tong / n
    @printf("%d %.4f %d %d\n", tong, trung_binh, nho_nhat, lon_nhat)
end

main()