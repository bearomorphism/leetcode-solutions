from random import randint

cards = list(range(52))

def my_shuffle(l):
    n = len(l)
    for i in range(n):
        b = randint(i, n - 1)
        l[i], l[b] = l[b], l[i]


my_shuffle(cards)

num_of_players = int(input())

# print(cards)

card_number = 52 // num_of_players
card_end = num_of_players * card_number

removed_cards = cards[card_end:]
print(removed_cards)
cards = cards[:card_end]

# round 1

players = []
for _ in range(num_of_players):
    players.append([])
k = 0
for _ in range(card_number):
    for player in players:
        player.append(cards[k])
        k += 1


for i, player in enumerate(players):
    print(i, player)

my_shuffle(cards)

players = []

for _ in range(num_of_players):
    players.append([])
k = 0
for _ in range(card_number):
    for player in players:
        player.append(cards[k])
        k += 1
for i, player in enumerate(players):
    print(i, player)

