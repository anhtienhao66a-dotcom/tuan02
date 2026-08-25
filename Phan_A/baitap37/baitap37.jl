function dem(a)
    chan = 0
    le = 0
    am = 0
    for x in a
        if x < 0
            am += 1
        end
        if x % 2 == 0
            chan += 1
        else
            le += 1
        end
    end
    return chan, le, am
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
        chan, le, am = dem(a)
        println("chan $(chan), le $(le), am $(am)")
        flush(stdout)
    end
end

main()