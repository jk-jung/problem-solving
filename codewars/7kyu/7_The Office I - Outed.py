def outed(meet, boss):
    t = sum(meet.values())
    return 'Get Out Now!' if (t + meet[boss]) / len(meet) <= 5 else 'Nice Work Champ!'
