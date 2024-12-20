function sortList (sortBy, list) {
    return list.sort((x, y) => y[sortBy] - x[sortBy]);
}