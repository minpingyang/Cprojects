pets = ["Fido", "Marlo"] # a mutable list

def add_pet(pet_list):
    pet_list.append("Fifi") # add a new pet
    pet_list = None # we try to overwrite the reference
    return pet_list

add_pet(pets)

for name in pets:
    print(name)