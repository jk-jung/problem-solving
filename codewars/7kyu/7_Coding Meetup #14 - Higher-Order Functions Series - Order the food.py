from collections import Counter

def order_food(a): 
    return Counter([x['meal'] for x in a])
