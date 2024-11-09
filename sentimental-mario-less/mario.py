from cs50 import get_int

while True:
    height = get_int("Height: ")

    if height <= 8 and height >= 1:
        break
n = 1
for i in range(height):
    for k in range(height - n):
        print(" ", end="")
    for j in range(n):
        print("#", end="")
    print("")
    n += 1
