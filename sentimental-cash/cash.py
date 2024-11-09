from cs50 import get_float


def main():
    while (True):
        cents = get_float("change: ")
        if cents > 0:
            cents = cents * 100
            break

    quaters = calculate_quaters(cents)
    cents = cents - quaters * 25
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    sum = quaters + dimes + nickels + pennies
    print(sum)


def calculate_quaters(cents):
    quaters = 0
    while (cents >= 25):
        cents = cents - 25
        quaters += 1
    return quaters


def calculate_dimes(cents):
    dimes = 0
    while (cents >= 10):
        cents = cents - 10
        dimes += 1
    return dimes


def calculate_nickels(cents):
    nickels = 0
    while (cents >= 5):
        cents = cents - 5
        nickels += 1
    return nickels


def calculate_pennies(cents):
    pennies = 0
    while (cents >= 1):
        cents = cents - 1
        pennies += 1
    return pennies


main()
