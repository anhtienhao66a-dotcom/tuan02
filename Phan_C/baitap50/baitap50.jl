using Random
using Printf

function sinh_du_lieu(n::Int, d::Int)
    return [rand(Float64, d) for _ in 1:n]
end

function kc_euclid_sq(u::Vector{Float64}, v::Vector{Float64})
    return sum((u .- v) .^ 2)
end

function lang_gieng_gan_nhat(q::Vector{Float64}, D::Vector{Vector{Float64}})
    min_d2 = Inf
    best_idx = -1
    for i in 1:length(D)
        d2 = kc_euclid_sq(q, D[i])
        if d2 < min_d2
            min_d2 = d2
            best_idx = i
        end
    end
    return best_idx
end

function main()
    Random.seed!(12345)
    d = 20
    q_size = 1000
    Q = sinh_du_lieu(q_size, d)

    # Chay thu 1 mau de warm-up JIT compiler
    D_temp = sinh_du_lieu(10, d)
    lang_gieng_gan_nhat(Q[1], D_temp)

    N_list = [1000, 10000, 100000]
    T = Float64[]

    println("=== DO THOI GIAN JULIA ===")
    for n in N_list
        D = sinh_du_lieu(n, d)
        
        t = @elapsed for i in 1:q_size
            lang_gieng_gan_nhat(Q[i], D)
        end
        push!(T, t)
        @printf("n = %d: %.4f s\n", n, t)
    end

    @printf("Ti le T(10^4)/T(10^3) = %.2f\n", T[2] / T[1])
    @printf("Ti le T(10^5)/T(10^4) = %.2f\n", T[3] / T[2])
end

main()