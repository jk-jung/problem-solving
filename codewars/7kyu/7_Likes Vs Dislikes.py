from preloaded import Like, Dislike, Nothing

def like_or_dislike(lst):
    r = Nothing
    for x in lst:
        if r == x:
            r = Nothing
        else: r = x
    return r
