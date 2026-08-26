using Printf

struct Mau
    x::Vector{Float64}
    y::String
    id::Int
end

function doc_du_lieu(ten_tep::String)
    content = read(ten_tep, String)
    tokens = split(content)
    if isempty(tokens)
        return Mau[], 0
    end
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

function lang_gieng_gan_nhat(q, D; kc = kc_euclid, bo_qua_id = -1)
    min_dist = Inf
    best_label = ""
    best_idx = -1

    for mau in D
        if mau.id == bo_qua_id
            continue
        end
        dist = kc(q, mau.x)
        if dist < min_dist
            min_dist = dist
            best_label = mau.y
            best_idx = mau.id
        end
    end
    return best_label, best_idx, min_dist
end

function main()
    D, d = doc_du_lieu("hoa30.txt")
    if isempty(D)
        return
    end

    # 1. Phan loai mau moi (6.5; 3.0; 5.5; 2.0)
    q = [6.5, 3.0, 5.5, 2.0]
    lbl_e, idx_e, dist_e = lang_gieng_gan_nhat(q, D; kc = kc_euclid)
    lbl_m, idx_m, dist_m = lang_gieng_gan_nhat(q, D; kc = kc_manhattan)

    println("=== KET QUA PHAN LOAI MAU MOI ===")
    @printf("Euclid: %s - lang gieng la mau %d, khoang cach %.4f\n", lbl_e, idx_e, dist_e)
    @printf("Manhattan: %s - lang gieng la mau %d, khoang cach %.1f\n\n", lbl_m, idx_m, dist_m)

    # 2. Kiem thu bo mot mau (LOOCV)
    dung_e = 0
    dung_m = 0
    thong_tin_sai_m = ""

    for mau in D
        pe_lbl, _, _ = lang_gieng_gan_nhat(mau.x, D; kc = kc_euclid, bo_qua_id = mau.id)
        pm_lbl, pm_idx, pm_dist = lang_gieng_gan_nhat(mau.x, D; kc = kc_manhattan, bo_qua_id = mau.id)

        if pe_lbl == mau.y
            dung_e += 1
        end
        if pm_lbl == mau.y
            dung_m += 1
        else
            thong_tin_sai_m = @sprintf("Manhattan du doan sai thanh %s (lang gieng mau %d, khoang cach %.1f)", pm_lbl, pm_idx, pm_dist)
        end
    end

    println("=== KIEM THU BO MOT MAU (LOOCV) ===")
    @printf("Euclid %d/30 = %.2f%% - Manhattan %d/30 = %.2f%%\n", dung_e, dung_e * 100.0 / length(D), dung_m, dung_m * 100.0 / length(D))
    println("Mau 26 khi bi bo ra: ", thong_tin_sai_m)
end

main()