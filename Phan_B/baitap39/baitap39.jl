using Printf

function cach1(a)
    n = length(a)
    max_sum = a[1]
    for i in 1:n
        for j in i:n
            s = sum(a[i:j])
            if s > max_sum max_sum = s end
        end
    end
    return max_sum
end

function cach2(a)
    n = length(a)
    max_sum = a[1]
    for i in 1:n
        s = 0
        for j in i:n
            s += a[j]
            if s > max_sum max_sum = s end
        end
    end
    return max_sum
end

function kadane(a)
    max_so_far = a[1]
    curr_max = a[1]
    for i in 2:length(a)
        curr_max = max(a[i], curr_max + a[i])
        max_so_far = max(max_so_far, curr_max)
    end
    return max_so_far
end

function main()
    # Warm-up JIT compiler
    dummy = [1, 2, 3]
    cach1(dummy); cach2(dummy); kadane(dummy)

    content = read(stdin, String)
    tokens = split(content)
    if isempty(tokens) return end

    idx = 1
    while idx <= length(tokens)
        n = parse(Int, tokens[idx])
        idx += 1
        a = [parse(Int, tokens[i]) for i in idx:(idx + n - 1)]
        idx += n

        st1 = time_ns()
        r1 = cach1(a)
        d1 = (time_ns() - st1) / 1e9

        st2 = time_ns()
        r2 = cach2(a)
        d2 = (time_ns() - st2) / 1e9

        reps = 10000
        st3 = time_ns()
        r3 = 0
        for _ in 1:reps
            r3 = kadane(a)
        end
        d3 = ((time_ns() - st3) / 1e9) / reps

        println("Ket qua: ", r3)
        @printf("1 - O(n^3):  %.8fs\n", d1)
        @printf("2 - O(n^2):  %.8fs\n", d2)
        @printf("3 - Kadane:  %.8fs\n", d3)
        flush(stdout)
    end
end

main()