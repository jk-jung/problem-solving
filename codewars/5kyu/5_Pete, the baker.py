def cakes(recipe, available):
    return min(available.get(k, 0) // v for k, v in recipe.items())