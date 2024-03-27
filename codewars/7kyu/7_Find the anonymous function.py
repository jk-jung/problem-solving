def find_function(func,arr):
    for x in func:
        try :return [y for y in arr if x(y)]
        except:pass
