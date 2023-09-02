
from Tools import *

class Player():

    def __init__(self):
        self.health = 100
        self.energy = 500
        self.weapons = []
        self.shields = []
        self.noOfWeapons = 0
        self.noOfShields = 0
        self.minWeaponEnergy = 1e9

    def weaponAdd(self, name, energy, damage, resource):
        weapon = Weapon(name, energy, damage, resource)
        self.weapons.append( weapon )
        self.noOfWeapons += 1
        self.minWeaponEnergy = min(weapon.energy, self.minWeaponEnergy)

    def shieldAdd(self, name, energy, save, resource):
        shield = Shield(name, energy, save, resource)
        self.shields.append( shield )
        self.noOfShields += 1

    def chooseWeapon(self, number):
        while( number >= self.noOfWeapons or number < 0 or self.weapons[number].resource == 0 or self.energy < self.weapons[number].energy ):
            print("Not a valid option ... Choose Another One")
            number = int( input() ) - 1
        
        self.energy -= self.weapons[number].energy

        if( self.weapons[number].resource != -1 ):
            self.weapons[number].resource -= 1

        return self.weapons[number].damage, number+1
    
    def chooseShield(self, number):
        while( number >= self.noOfShields or number < 0 or self.shields[number].resource == 0 or self.energy < self.shields[number].energy ):
            print("Not a valid option ... Choose Another One")
            number = int( input() ) - 1
        
        self.energy -= self.shields[number].energy

        if( self.shields[number].resource != -1 ):
            self.shields[number].resource -= 1

        return self.shields[number].save

