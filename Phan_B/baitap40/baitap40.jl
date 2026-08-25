function kadane_chi_so(a)
    max_so_far = a[1]
    curr_max = a[1]
    start_idx = 1
    end_idx = 1
    temp_start = 1

    for i in 2:length(a)
        if a[i] > curr_max + a[i]
            curr_max = a[i]
            temp_start = i
        else
            curr_max += a[i]
        end

        if curr_max > max_so_far
            max_so_far = curr_max
            start_idx = temp_start
            end_idx = i
        end
    end

    return max_so_far, start_idx, end_idx
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
        tong, dau, cuoi = kadane_chi_so(a)
        println("tong $(tong), doan [$(dau)..$(cuoi)]")
        flush(stdout)
    end
end

main()