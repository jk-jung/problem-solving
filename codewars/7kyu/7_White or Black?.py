def square_color(file, rank):
    return "black" if (rank + 1 + ord(file) - ord('a')) % 2 == 0 else "white"
