from cs50 import get_int


while (True):
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break
n = 1
for i in range(height):
    for j in range(height - n):
        print(" ", end="")
    for k in range(n):
        print("#", end="")
    print("  ", end="")
    for l in range(n):
        print("#", end="")
    print("")
    n += 1
