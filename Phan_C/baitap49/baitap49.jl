using Printf

struct Mau
    x::Vector{Float64}
    y::String
    id::Int
end

function doc_du_lieu(ten_tep::String)
    content = read(ten_tep, String)
    tokens = split(content)
    if isempty(tokens) return Mau[], 0 end
    n = parse(Int, tokens[1])
    d = parse(Int, tokens[2])
    D = Mau[]
    idx = 3
    for i in 1:n
        coords = [parse(Float64, tokens[j]) for j in idx:(idx + d - 1)]
        idx += d
        label = String(tokens[idx])
        idx += 1
        push!(D, Mau(coords, label, i))
    end
    return D, d
end

kc_euclid(u, v) = sqrt(sum((u .- v) .^ 2))
kc_manhattan(u, v) = sum(abs.(u .- v))

function bo_mot_mau(D; kc = kc_euclid)
    so_dung = 0
    danh_sach_sai = String[]
    n = length(D)

    for i in 1:n
        min_dist = Inf
        best_label = ""

        # Bo qua mau i
        for j in 1:n
            if i == j continue end
            dist = kc(D[i].x, D[j].x)
            if dist < min_dist
                min_dist = dist
                best_label = D[j].y
            end
        end

        if best_label == D[i].y
            so_dung += 1
        else
            push!(danh_sach_sai, "sai mau $(D[i].id) (that: $(D[i].y), du doan: $(best_label))")
        end
    end

    return so_dung, n, danh_sach_sai
end

function main()
    D30, _ = doc_du_lieu("hoa30.txt")

    D9 = [
        Mau([1.4, 0.2], "Setosa", 1),
        Mau([1.3, 0.2], "Setosa", 2),
        Mau([1.5, 0.2], "Setosa", 3),
        Mau([4.7, 1.4], "Versicolor", 4),
        Mau([4.5, 1.5], "Versicolor", 5),
        Mau([4.9, 1.5], "Versicolor", 6),
        Mau([6.0, 2.5], "Virginica", 7),
        Mau([5.8, 1.9], "Virginica", 8),
        Mau([6.3, 2.5], "Virginica", 9)
    ]

    # 1. Euclid
    dung_e, tong_e, sai_e = bo_mot_mau(D30; kc = kc_euclid)
    chuoi_sai_e = isempty(sai_e) ? "khong mau nao sai" : join(sai_e, "; ")
    @printf("Euclid: %d/%d = %.2f%% - %s\n", dung_e, tong_e, dung_e / tong_e * 100, chuoi_sai_e)

    # 2. Manhattan
    dung_m, tong_m, sai_m = bo_mot_mau(D30; kc = kc_manhattan)
    chuoi_sai_m = isempty(sai_m) ? "khong mau nao sai" : join(sai_m, "; ")
    @printf("Manhattan: %d/%d = %.2f%% - %s\n", dung_m, tong_m, dung_m / tong_m * 100, chuoi_sai_m)

    # 3. Tap 9 mau
    dung_9, tong_9, _ = bo_mot_mau(D9; kc = kc_euclid)
    @printf("Tap 9 mau: %d/%d = %.0f%% voi ca hai do do\n", dung_9, tong_9, dung_9 / tong_9 * 100)
end

main()