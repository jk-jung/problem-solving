def answer(puzzlebox):
    print(puzzlebox)
    print(dir())
    print(dir(puzzlebox))
    print(puzzlebox.answer)
    print(puzzlebox.hint)
    print(puzzlebox.hint_two)
    print(puzzlebox.key)
    print(puzzlebox.lock)
    print(puzzlebox.lock(puzzlebox.key))
    # Print statements are your friend.
    return 42