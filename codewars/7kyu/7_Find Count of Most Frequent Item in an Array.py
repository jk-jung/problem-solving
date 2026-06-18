def most_frequent_item_count(a):
    return max([a.count(x) for x in a]) if a else 0
