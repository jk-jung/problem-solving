def simple_assembler(program):
    pos = 0
    memory = {}

    def to_i(x):
        try: return int(x)
        except: return 0

    while pos < len(program):
        cmd, *args = program[pos].split()

        if cmd == 'mov':
            memory[args[0]] = memory.get(args[1], to_i(args[1]))
        if cmd == 'inc':
            memory[args[0]] += 1
        if cmd == 'dec':
            memory[args[0]] -= 1
        if cmd == 'jnz' and memory.get(args[0], to_i(args[0])) != 0:
            pos += memory.get(args[1], int(args[1]))
            continue
        pos += 1

    return memory