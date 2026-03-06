from itertools import product

def solve():
    # Read K and M
    k, m = map(int, input().split())
    
    # Read the lists, skipping the first element (size of the list)
    lists = []
    for _ in range(k):
        # We only need the elements starting from index 1
        elements = list(map(int, input().split()))[1:]
        # Pre-squaring the elements and taking modulo M helps simplify the sum later
        lists.append([x**2 for x in elements])
    
    # Generate all possible combinations (Cartesian product)
    combinations = product(*lists)
    
    # Calculate (sum of squares) % M for each combination and find the maximum
    max_value = 0
    for combo in combinations:
        current_sum_mod = sum(combo) % m
        if current_sum_mod > max_value:
            max_value = current_sum_mod
            
    print(max_value)

if __name__ == "__main__":
    solve()
