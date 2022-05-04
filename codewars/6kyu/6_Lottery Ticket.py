def bingo(x, w):
    return 'Winner!' if sum(chr(c) in s for s, c in x) >= w else 'Loser!'