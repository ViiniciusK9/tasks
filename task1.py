n = int(input())

def vogal (v):
    if v in "aeiouAEIOU":
        return True
    else:
        return False

for i in range(n):
    c = 0
    strg = input()
    for l in strg:
        if vogal(l):
            c = 0
        else:
            c+=1
        if c == 3:
            print(f"{strg} nao eh facil")
            break
        
    if c < 3:
        print(f"{strg} eh facil")