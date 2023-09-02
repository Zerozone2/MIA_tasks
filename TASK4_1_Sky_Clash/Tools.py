
class Tool():

    def __init__(self, name, energy, resource):
        self.name = name
        self.energy = energy
        self.resource = resource    

class Weapon(Tool):

    def __init__(self, name, energy, damage, resource):
        super().__init__(name, energy, resource)
        self.damage = damage


class Shield(Tool):

    def __init__(self, name, energy, save, resource):
        super().__init__(name, energy, resource)
        self.save = save
    
