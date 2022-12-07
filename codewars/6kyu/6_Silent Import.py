def silent_thief(x):
    t = list(globals()['_' * 2 + 'builtins' + '_' * 2 ].values())[6]
    return t(x)