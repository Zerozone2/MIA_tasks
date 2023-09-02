from Tools import *
from Players import Player
from os import system

print("Welcome Players")
print("Game Begin")

gru = Player()
vector = Player()

gru.shieldAdd("Energy-Projected BarrierGun", 20, 0.4, -1)
gru.shieldAdd("Selective Permeability", 50, 0.9, 2)

gru.weaponAdd("Freeze Gun", 50, 11, -1)
gru.weaponAdd("Electric Prod", 88, 18, 5)
gru.weaponAdd("Mega Magnet", 92, 10, 3)
gru.weaponAdd("Kalman Missile", 120, 20, 1)

vector.weaponAdd("Laser Blasters", 40, 8, -1)
vector.weaponAdd("Plasma Grenades", 56, 13, 8)
vector.weaponAdd("Laser Blasters", 100, 22, 3)

vector.shieldAdd("Energy Net Trap", 15, 0.32, -1)
vector.shieldAdd("Quantum Deflector", 40, 0.8, 3)

while( gru.health > 0 and vector.health > 0 ):
    
    system('cls')

    print("Gru Health: "+str(gru.health) + "\n" + "Vector Health: " + str(vector.health))

    print("Gru Energy: "+str(gru.energy) + "\n" + "Vector Energy: " + str(vector.energy))
    
    if( gru.minWeaponEnergy > gru.energy and vector.minWeaponEnergy <= vector.energy):
        gru.health = 0
        break
    elif( vector.minWeaponEnergy > vector.energy and gru.minWeaponEnergy > gru.energy ):
        break

    print("Gru Turn\nChoose Weapon Gru: ")
    numberGru = int(input())
    gurDamage, numberGru = gru.chooseWeapon(numberGru-1)
    print("Choose Shield Vector: ")
    
    vectorSave = 0

    if( gru.weapons[numberGru-1].name != "Kalman Missile" ):
        numberVector = int(input())
        vectorSave = vector.chooseShield(numberVector-1)

    vector.health -= gurDamage - vectorSave * gurDamage

    if( vector.health < 0 ):
        break
    
    if( gru.minWeaponEnergy <= gru.energy and vector.minWeaponEnergy > vector.energy):
        vector.health = 0
        break
    elif( vector.minWeaponEnergy > vector.energy and gru.minWeaponEnergy > gru.energy ):
        break
    
    system('cls')

    print("Gru Health: "+str(gru.health) + "\n" + "Vector Health: " + str(vector.health))

    print("Gru Energy: "+str(gru.energy) + "\n" + "Vector Energy: " + str(vector.energy))

    gruSave = 0

    if( gru.weapons[numberGru-1].name == "Mega Magnet" ):
        gruSave = 0.2

    print("Vector Turn\nChoose Weapon Vector: ")
    numberVector = int(input())
    vectorDamage, numberVector = vector.chooseWeapon(numberVector-1)
    print("Choose Shield Gru: ")
    numberGru = int(input())
    gruSave += gru.chooseShield(numberGru-1)

    gru.health -= vectorDamage - gruSave * vectorDamage


if( gru.health <= 0 ):
    print("____Vector Win____Gru Lose____")
elif( vector.health <= 0 ):
    print("____Gru Win____Vector Lose____")
else:
    print("____Draw____")