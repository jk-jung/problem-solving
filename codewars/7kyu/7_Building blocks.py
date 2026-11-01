class Block:
    def __init__(self, x):
        self.w, self.l, self.h = x
    
    def get_width(self):
        return self.w
    
    def get_length(self):
        return self.l
    
    def get_height(self):
        return self.h
    
    def get_volume(self):
        return self.w * self.l * self.h
    
    def get_surface_area(self):
        return (self.w * self.l + self.l * self.h + self.h * self.w) * 2