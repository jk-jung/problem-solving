def is_audio(fn):
    if any(not x.isalpha() for x in fn.split('.')[0]): return False
    return any(fn.endswith(x) for x in ('.mp3', '.flac', '.alac', '.aac'))

def is_img(fn):
    if any(not x.isalpha() for x in fn.split('.')[0]): return False
    return any(fn.endswith(x) for x in ('.jpg', '.jpeg', '.png', '.bmp', '.gif'))