import sys

def parse(expr, variables):
    if len(expr) == 0:
        return []
    token = expr.pop()
    if token in set(list("KACE")):  # binary op
        expr1 = parse(expr, variables)
        expr2 = parse(expr, variables)
        return [token, expr1, expr2]
    elif token == "N":  # unary op
        return [token, parse(expr, variables)]
    else:
        variables.add(token)
        return [token]

def evaluate(expr, key_map):
    if len(expr) == 1:
        return key_map[expr[0]]
    token, expr = expr[0], expr[1:]
    if token == "K":
        r1, r2 = evaluate(expr[0], key_map), evaluate(expr[1], key_map)
        return r1 and r2
    elif token == "A":
        r1, r2 = evaluate(expr[0], key_map), evaluate(expr[1], key_map)
        return r1 or r2
    elif token == "C":
        r1, r2 = evaluate(expr[0], key_map), evaluate(expr[1], key_map)
        if not r1 and r2:
            return False
        return True
    elif token == "E":
        r1, r2 = evaluate(expr[0], key_map), evaluate(expr[1], key_map)
        return r1 == r2
    elif token == "N":
        return not evaluate(expr[0], key_map)
    else:
        return key_map[token]

def process(line):
    variables = set()
    expr = parse(list(reversed(line)), variables)
    l = len(variables)
    for i in range(2 ** l):
        assignments = map(lambda x: True if x == '1' else False, bin(i)[2:].rjust(l, "0"))
        key_map = dict(zip(variables, assignments))
        res = evaluate(expr, key_map)
        if not res:
            print("not")
            return
    print("tautology")

def main():
    for line in sys.stdin:
        line = line.strip()
        if line != "0":
            process(line)

if __name__ == '__main__':
    main()
