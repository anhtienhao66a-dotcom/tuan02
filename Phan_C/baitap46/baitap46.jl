using Printf

# 9 mau hoa dien vi rut gon (Vi du 1.8)
const D = [
    ([1.4, 0.2], "Setosa"),      # Mau 1
    ([1.3, 0.2], "Setosa"),      # Mau 2
    ([1.5, 0.2], "Setosa"),      # Mau 3
    ([4.7, 1.4], "Versicolor"),  # Mau 4
    ([4.5, 1.5], "Versicolor"),  # Mau 5
    ([4.9, 1.5], "Versicolor"),  # Mau 6
    ([6.0, 2.5], "Virginica"),   # Mau 7
    ([5.8, 1.9], "Virginica"),   # Mau 8
    ([6.3, 2.5], "Virginica")    # Mau 9
]

khoang_cach(u, v) = sqrt(sum((u .- v) .^ 2))

function lang_gieng_gan_nhat(q, tap_mau)
    min_dist = Inf
    best_label = ""
    best_idx = -1

    for (i, (x, y)) in enumerate(tap_mau)
        d = khoang_cach(q, x)
        if d < min_dist
            min_dist = d
            best_label = y
            best_idx = i
        end
    end
    return best_label, min_dist, best_idx
end

function main()
    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    idx = 1
    while idx <= length(tokens)
        x1 = parse(Float64, tokens[idx])
        x2 = parse(Float64, tokens[idx + 1])
        idx += 2
        nhan, dist, chi_so = lang_gieng_gan_nhat([x1, x2], D)
        if round(dist, digits=4) == 0
            println("$(nhan) - trung dung mau $(chi_so), khoang cach 0")
        else
            @printf("%s - lang gieng la mau %d, khoang cach %.4f\n", nhan, chi_so, dist)
        end
        flush(stdout)
    end
end

main()