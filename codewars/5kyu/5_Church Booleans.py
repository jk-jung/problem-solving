and_map = {
    (true, true): true,
    (true, false): false,
    (false, true): false,
    (false, false): false
}

or_map = {
    (true, true): true,
    (true, false): true,
    (false, true): true,
    (false, false): false
}

xor_map = {
    (true, true): false,
    (true, false): true,
    (false, true): true,
    (false, false): false
}


Not = lambda X: false if unchurch(X) else true
And = lambda X: lambda Y: and_map[(X, Y)]
Or = lambda X: lambda Y: or_map[(X, Y)]
Xor = lambda X: lambda Y: xor_map[(X, Y)]