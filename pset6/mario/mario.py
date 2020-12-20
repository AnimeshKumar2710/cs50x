from cs50 import get_int


def main():
    while True:
        height = get_int("enter the height: ")
        if height in range(1, 9):
            break
        
    mario(height)


def mario(n):
    i = 0
    for i in range(n):
        print(" " * ((n - i) - 1), end="")
        print("#" * (i + 1), end="")
        print("  ", end="")
        print("#" * (i + 1), end="")
        print()
        

main()
