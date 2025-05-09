def color_2_grey(image):
    def f(R, G, B): return [round(x) for x in [(R + G + B) / 3, (R + G + B) / 3, (R + G + B) / 3]]

    return [[f(*x) for x in y] for y in image]
