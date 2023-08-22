def bisection_method(f, a, b, tol):
    while (b - a) / 2 > tol:
        c = (a + b) / 2
        if f(c) == 0:
            return c
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2

def main():
    f = lambda x: eval(input("Enter the function f(x): "))
    a = float(input("Enter the initial guess for a: "))
    b = float(input("Enter the initial guess for b: "))
    tol = float(input("Enter the desired level of accuracy: "))
    root = bisection_method(f, a, b, tol)
    print("The root of the equation is approximately:", root)

if __name__ == '__main__':
    main()
    