def solve_happiness():
    n, m = map(int, input().split())

    arr = list(map(int, input().split()))
    set_a = set(map(int, input().split()))
    set_b = set(map(int, input().split()))
    
    happiness = 0
    
    for num in arr:
        if num in set_a:
            happiness += 1
        elif num in set_b:
            happiness -= 1
            
    print(happiness)

if __name__ == '__main__':
    solve_happiness()
