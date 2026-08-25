import sys

def is_square(n):
    if n == 0 or n == 1:
        return True
    
    left = 1
    right = min(n, 10**9)
    
    while left <= right:
        mid = (left + right) // 2
        sq = mid * mid
        
        if sq == n:
            return True
        elif sq < n:
            left = mid + 1
        else:
            right = mid - 1
            
    return False

def main():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    if is_square(n):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()