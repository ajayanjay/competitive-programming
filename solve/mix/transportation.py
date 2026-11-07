def printCurrent(costs, supply, demand):
    for i in range(len(costs)):
        print(f"{costs[i]} | {supply[i]}")

    print(demand)


# north west corner
def nwc(costs, supply, demand):
    costs = [row[:] for row in costs]
    supply = supply.copy()
    demand = demand.copy()

    rows = len(costs)
    cols = len(costs[0])

    if sum(supply) < sum(demand):
        print("Total supply less than total demand")
        return None

    print("North West Corner Method Steps:")
    print("Initial State: ")
    printCurrent(costs, supply, demand)
    print()

    total_cost = 0
    i = 0
    j = 0
    while i < rows and j < cols:
        total_cost += costs[i][j]

        print(f"Supply[{i}] - Demand[{j}]")
        costs[i][j] = float("inf")

        if demand[j] > supply[i]:
            demand[j] -= supply[i]
            supply[i] = 0
            i += 1
        elif demand[j] < supply[i]:
            supply[i] -= demand[j]
            demand[j] = 0
            j += 1
        else:
            supply[i] = 0
            demand[j] = 0
            i += 1
            j += 1

        printCurrent(costs, supply, demand)
        print()

    print("Total Cost:", total_cost)
    return total_cost


# least cost first.
def lcf(costs, supply, demand):
    costs = [row[:] for row in costs]
    supply = supply.copy()
    demand = demand.copy()

    rows = len(costs)
    cols = len(costs[0])

    res = sum(demand)
    if sum(supply) < res:
        print("Total supply less than total demand")
        return None

    print("Lowest Cost Method Steps:")
    print("Initial State: ")
    printCurrent(costs, supply, demand)
    print()

    total_cost = 0

    while res > 0:
        mn = float("inf")

        row = -1
        col = -1

        for i in range(rows):
            for j in range(cols):
                if mn > costs[i][j]:
                    mn = costs[i][j]
                    row = i
                    col = j

        if row == -1:
            break

        total_cost += costs[row][col]
        costs[row][col] = float("inf")

        if supply[row] == 0:
            continue

        difference = demand[col] - supply[row]
        if difference < 0:  # supply > demand
            res -= demand[col]
            supply[row] -= demand[col]
            demand[col] = 0
        elif difference > 0:
            res -= supply[row]
            demand[col] -= supply[row]
            supply[row] = 0
        else:
            res -= supply[row]
            demand[col] = 0
            supply[row] = 0

        print(f"Supply[{row}] - Demand[{col}]")
        printCurrent(costs, supply, demand)
        print()

    print("Total Cost:", total_cost)
    return total_cost


if __name__ == "__main__":
    costs = [[19, 30, 50, 10], [70, 30, 40, 60], [40, 8, 70, 20]]
    supply = [7, 9, 18]
    demand = [5, 8, 7, 14]
    lcf(costs, supply, demand)
    nwc(costs, supply, demand)
