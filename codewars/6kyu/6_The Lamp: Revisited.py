# implement the Lamp class
class Lamp:
    def __init__(self, color):
        self.color = color
        self.on = False

    def toggle_switch(self):
        self.on = not self.on

    def state(self):
        return f"The lamp is {'on' if self.on else 'off'}."