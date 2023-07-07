def lazy(n):
    def wrapper(f):
        cnt = 0
        def tmp(*args, **kwargs):
            nonlocal cnt
            run = False
            if n > 0:
                if cnt % n == 0:
                    run = True
            else:
                run = cnt % (-n) != -n - 1
            cnt += 1
            return f(*args, **kwargs) if run else None
        return tmp
    return wrapper
