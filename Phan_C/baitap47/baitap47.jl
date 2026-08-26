using Printf

function doc_du_lieu(ten_tep::String)
    content = read(ten_tep, String)
    tokens = split(content)
    if isempty(tokens)
        return [], 0
    end
    n = parse(Int, tokens[1])
    d = parse(Int, tokens[2])
    D = []
    idx = 3
    for _ in 1:n
        features = [parse(Float64, tokens[i]) for i in idx:(idx + d - 1)]
        idx += d
        label = String(tokens[idx])
        idx += 1
        push!(D, (features, label))
    end
    return D, d
end

khoang_cach(u, v) = sqrt(sum((u .- v) .^ 2))

function lang_gieng_gan_nhat(q, D)
    min_dist = Inf
    best_label = ""
    best_idx = -1

    for (i, (features, label)) in enumerate(D)
        dist = khoang_cach(q, features)
        if dist < min_dist
            min_dist = dist
            best_label = label
            best_idx = i
        end
    end
    return best_label, best_idx, min_dist
end

function main()
    D, d = doc_du_lieu("hoa30.txt")
    if isempty(D) return end

    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    idx = 1
    while idx <= length(tokens)
        q = [parse(Float64, tokens[i]) for i in idx:(idx + d - 1)]
        idx += d
        nhan, chi_so, dist = lang_gieng_gan_nhat(q, D)
        @printf("%s - mau %d, khoang cach %.4f\n", nhan, chi_so, dist)
        flush(stdout)
    end
end

main()