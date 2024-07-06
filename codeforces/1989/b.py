def min_length_containing_substring_and_subsequence(t, test_cases):
    results = []
    
    for case in test_cases:
        a = case[0]
        b = case[1]
        
        # Convert string a to a list to allow modifications
        result = list(a)
        
        # Pointer in the result string
        j = 0
        
        # Insert each character from b into result to maintain subsequence
        for char in b:
            # If char is not found in result starting from position j
            if char not in result[j:]:
                result.append(char)
            # Move j to the next character in result where we found char
            else:
                while j < len(result) and result[j] != char:
                    j += 1
                j += 1
        
        results.append(len(result))
    
    return results

# Input processing
input_data = [
    (5, [('aba', 'cb'), ('er', 'cf'), ('mmm', 'mmm'), ('contest', 'test'), ('cde', 'abcefg')])
]

# Extract number of test cases and test cases list
t = input_data[0][0]
test_cases = input_data[0][1]

# Solve the problem
results = min_length_containing_substring_and_subsequence(t, test_cases)

# Output results
for result in results:
    print(result)
