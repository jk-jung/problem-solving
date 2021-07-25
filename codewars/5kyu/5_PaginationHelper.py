# TODO: complete this class

class PaginationHelper:

    # The constructor takes in an array of items and a integer indicating
    # how many items fit within a single page
    def __init__(self, collection, items_per_page):
        self.v = collection
        self.per = items_per_page

    # returns the number of items within the entire collection
    def item_count(self):
        return len(self.v)

    # returns the number of pages
    def page_count(self):
        return (len(self.v) + self.per - 1) // self.per

    # returns the number of items on the current page. page_index is zero based
    # this method should return -1 for page_index values that are out of range
    def page_item_count(self, page_index):
        if self.page_count() - 1 == page_index:
            return len(self.v) % self.per
        elif page_index < self.page_count():
            return self.per
        else:
            return -1

    # determines what page an item is on. Zero based indexes.
    # this method should return -1 for item_index values that are out of range
    def page_index(self, item_index):
        if len(self.v) <= item_index: return -1
        if item_index < 0: return -1
        return item_index // self.per
