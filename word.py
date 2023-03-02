import os, random
os.system('clear')
''' This is a program to create a worg guessing game
all variables will be declared at the beginning of the program
Menu Function will create Menu'''
##Lists
HardestWords=["craziest", "Phenomenon", "Worcestershire","Sixth", "Mischievous","Draconian","Homogeneous","Laconic","Corroborate","Pragmatic"]
InterWords=["aggressive","futuristic","imagine","religion","produce","fraudulent","Japanese","diverse","entrepreneur","acknowledgement"]
EasyWords=["bananas", "grapes", "pharmacy", 'post office', 'apples', "cafeteria",
    "papaya", 'oranges', 'towers', 'mangos', 'kiwis','house' ]
#Variables
word=""
guess=""
#Function to select the word to guess
def selectWord(choice):
    global word        #it is global so the change will be accepted everywhere we use word
                        # global var do not need to be returned
    if '2' in choice:
        word=random.choice(EasyWords)
    elif '3' in choice:
        word=random.choice(InterWords)
    elif '4' in choice:
        word=random.choice(HardestWords)
    word=word.lower()
    # size= len(fruits)
    # randy= random.randint(0,size)
    # print(randy)
    # word=fruits[randy]
    # print(word)+


def Menu():
    os.system('clear')
    print("####################################")
    print("#     Word Game for you            #")
    print("#       1 Instructions             #")
    print("#       2 Easy Words               #")
    print("#       3 Medium                   #")
    print("#       4 Difficult                #")
    print("#       5 Exit                     #")
    print("########################################")
    choice = input("Enter your choice ")
    os.system('clear')
    if '1' in choice:
        print("my instruction are not here but they will be soon :) !!!")
        input(" Press return to go back to main menu" )
        Menu()
    elif '5' in choice:
        print ("good Bye")
        exit()
    elif '3' in choice or '2' in choice or '4' in choice:
        selectWord(choice)
    else:
        print("PLease enter a valid option")
        Menu()

#Function to control your user input
def getLetter():
    global guess
    check=True
    while check:
        try:
            guess=input("\nenter a letter to guess the word ")
            if guess.isalpha() and len(guess)==1:
                guess=guess.lower()
                check=False
            else:
                print("only one letter please")
        except ValueError:
            print("only one letter please")
#Function to control the game( in the AP will be your main function to tal about it
def playing():
    turns=len(word)+2
    check = True
    guesses=''
    count=0
    while (turns>0 and check):
        for letter in word:
            if letter in guesses:
                print(letter, end=" " )
                if len(guesses)>=len(set(word))-1:
                    check = False
            else:
                print ("_", end=" ")
        getLetter()
        # newGuess=input ("\n please enter a letter ")
        if guess in word:
            if guess not in guesses:
                guesses += guess
                print(" Good guess ")
            else:
                print("You have used that letter before")
        else:
            turns -=1
            print("sorry guess again")
        print(guesses)
    if(not check):
        print("you guessed correctly, your score was...")

    else:
        print("Sorry you did not guess correctly...")
    input("Press enter to countinue")
    Menu()
Menu()
print(word)
playing()