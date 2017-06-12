def cheeseshop(*args, **kwargs):

    print("Arguments:")
    for arg in args:
        print(str(arg))
    print('-'*40)
    print("Default keyword arguments:")
    for key_word in kwargs:
        print(key_word + " = " + kwargs[key_word])
    print('='*40)
    return;

# Now you can call printinfo function
cheeseshop(hello='hi',test='moo')