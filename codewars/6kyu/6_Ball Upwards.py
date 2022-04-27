def max_ball(v):
    v /= 3.6
    return max((v * t / 10 - .5 * 9.81 * t * t / 100, t) for t in range(1000))[1]