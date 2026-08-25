import sys

def dem(a):
    chan = 0
    le = 0
    am = 0
    for x in a:
        if x < 0:
            am += 1
        if x % 2 == 0:
            chan += 1
        else:
            le += 1
    return chan, le, am

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    while idx < len(input_data):
        n = int(input_data[idx])
        idx += 1
        a = [int(x) for x in input_data[idx:idx+n]]
        idx += n
        chan, le, am = dem(a)
        print(f"chan {chan}, le {le}, am {am}", flush=True)

if __name__ == "__main__":
    main()