N = int(input())

aranhas = []
for i in range(1, N * 2 + 1):
    aranhas.append(i)
aranhas_matar = []
for x in range(N + 1, N * 2 + 1):
    aranhas_matar.append(x)

for j in range(N):
    try:
        aranhas.pop(N+1)
    except IndexError:
        aranhas.pop(N)

print(aranhas_matar)
print(aranhas)