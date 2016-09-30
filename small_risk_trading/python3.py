# -*- coding: utf-8 -*-

n, k = map(int, input().strip().split(' '))
assert (0 <= k <= n)
assert (n <= 10 ** 5)

profit_probabilities = [float(p) for p in input().strip().split(' ')]

potential_profits = [
    profit_probabilities[i] * p
    for i, p in
    enumerate([float(pp) for pp in input().strip().split(' ')])
]

# parsing potential losses
max_money = 0.0
expected_money = []
for i, loss in enumerate([float(l) for l in input().strip().split(' ')]):
    expected = potential_profits[i] - (1.0 - profit_probabilities[i]) * loss
    if expected > 0:
        expected_money.append(expected)

# sort and simply sum the last k elements
expected_money.sort()
if k > len(expected_money):
    k = len(expected_money)

print("{:.2f}".format(sum(expected_money[-k:])))
