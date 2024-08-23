""" entrada = input()
largo, num = entrada.split()
largo=int(largo)
num=int(num)


entrada = input()
entrada=entrada.strip().split()
entrada= [int(x) for x in entrada]
total = 1
mini_array=3

agrandar=0
while(mini_array<=largo):
    izq=0
    der=2+agrandar
    while(der<largo):
        temp=entrada[izq:der+1]
        if(num in temp):
            temp.sort()
            if(temp[mini_array//2]==num):
                total+=1
        der+=1
        izq+=1
    mini_array+=2
    agrandar+=2

print(total) """
def count_subsequences_with_median(N, B, A):
    # Find the position of B in the array A
    b_index = A.index(B)
    
    # Create a balance prefix array
    balance = 0
    prefix_count = {0: 1}  # To handle prefix sums before the median position
    result = 0
    
    # Traverse to the left of B
    for i in range(b_index - 1, -1, -1):
        if A[i] < B:
            balance -= 1
        else:
            balance += 1
        prefix_count[balance] = prefix_count.get(balance, 0) + 1
    
    # Reset balance and count subsequences including the position of B
    balance = 0
    
    # Traverse to the right of B including itself
    for i in range(b_index, N):
        if A[i] < B:
            balance -= 1
        elif A[i] > B:
            balance += 1
        
        # If the current balance is in the prefix_count, it means we found a valid subsequence
        result += prefix_count.get(balance, 0) + prefix_count.get(balance - 1, 0)
    
    return result

# Example usage
entrada = input()
largo, num = entrada.split()
largo=int(largo)
num=int(num)

A = [1, 2, 3, 4, 5]
print(count_subsequences_with_median(largo, num, A))  # Output should be 2
