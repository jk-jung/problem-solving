def how_much_i_love_you(a):
    return ["I love you", "a little", "a lot", "passionately", "madly", "not at all"][
        (a - 1) % 6
    ]
