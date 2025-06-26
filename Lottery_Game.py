import random as r

print("\n\t... WELCOME TO LOTTERY GAME ... ")
print("\n--- DESCRIPTION ---")
print("You are provided with a list containing 15 numbers. You must provide a certain")
print("seed value so that the numbers are generated randomly and are assigned to three")
print("different lists. After than you must guess which list has the maximum sum of numbers")
print("If guessed correctly then you are the winner other-wise you lost ... !")
print("\n... BEST OF LUCK FOR YOUR VICTORY ...")

while True :

    print("\n--- STARTING THE GAME ---\n")

    list_original = []
    list_1 = []
    list_2 = []
    list_3 = []

    seed_value = int(input("Enter the seed value of randomness : "))
    r.seed(seed_value)

    a,b = map(int,input("Enter the range upto which random numbers are generated : ").split())
    for i in range(15):
        rand_num = r.randint(a,b+1)
        list_original.append(rand_num)

    print("\nRANDOM LIST GENERATED : ",list_original)
    print("\n--- SELECTING 1st LIST --- ")
    for i in range(5):
        while True :
            num = r.randint(a,b+1)
            if num in list_original :
                list_1.append(num)
                if num in list_original:
                    list_original.remove(num)
                break
            else:
                continue
    print("--- FIRST LIST MADE ---")
        
    print("\n--- SELECTING 2nd LIST --- ")
    for i in range(5):
        while True :
            num = r.randint(a,b+1)
            if num in list_original :
                list_2.append(num)
                if num in list_original:
                    list_original.remove(num)
                break
            else:
                continue
    print("--- SECOND LIST MADE ---")

    print("\n--- SELECTING 3rd LIST --- ")
    for i in range(5):
        while True :
            num = r.randint(a,b+1)
            if num in list_original :
                list_3.append(num)
                if num in list_original:
                    list_original.remove(num)
                break
            else:
                continue
    print("--- THIRD LIST MADE ")
    print()    

    sum_1 = 0 
    for i in list_1:
        sum_1 += i

    sum_2 = 0 
    for i in list_2:
        sum_2 += i

    sum_3 = 0 
    for i in list_3:
        sum_3 += i

    if sum_1 > sum_2 and sum_1 > sum_3:
        winning_list = list_1
        winning_number = 1

    elif sum_2 > sum_1 and sum_2 > sum_3:
        winning_list = list_2
        winning_number = 2

    elif sum_3 > sum_2 and sum_3 > sum_1:
        winning_list = list_3
        winning_number = 3

    else:
        winning_list = "--- ITS A TIE AMONG ALL LIST ---"

    print("\nFor the guess, please enter your option from below :")
    print(f"+--------------+-------------+")
    print(f"| {"  LIST" :12} |{"  OPTIONS" :12} |")
    print(f"+--------------+-------------+")
    print(f"| {"  LIST-1" :12} |{"  1." :12} |")
    print(f"+--------------+-------------+")
    print(f"| {"  LIST-2" :12} |{"  2." :12} |")
    print(f"+--------------+-------------+")
    print(f"| {"  LIST-3" :12} |{"  3." :12} |")
    print(f"+--------------+-------------+")

    while True :
        choice = int(input("\nEnter choice  : "))
        if choice <1 or choice > 3:
            print("--- INVALID CHOICE ----")
            print("--- PLEASE RE-ENTER ---")
            continue
        else :
            break

    if choice == winning_number :
        print("--- CONGRATULATIONS ... ! ---")
        print("--- SUCCESSFULLY GUESSED ---")
        print("The list : ",winning_list)
        
    else :
        print("--- BETTER LUCK NEXT TIME :) ---")
        print("--- FAILED GUESS ---")
        print("The list :",winning_list)
    
    print("\n")
    print("Please enter your choice DEAR USER :")
    print(f"+--------------+-------------+")
    print(f"| {"  CHOICE":12} |{"  OPTIONS" :12} |")
    print(f"+--------------+-------------+")
    print(f"| {"  EXIT" :12} |{"  1." :12} |")
    print(f"+--------------+-------------+")
    print(f"| {"  RE-PLAY" :12} |{"  2." :12} |")
    print(f"+--------------+-------------+")

    while True :
        choice = int(input("\nEnter choice : "))
        if choice!=1 and choice!=2:
            print("--- INVALID CHOICE ----")
            print("--- PLEASE RE-ENTER ---")
            continue
        else :
            break

    if choice == 1:
        print("\n--- EXITING THE SYSTEM ---")
        print("GOOD BYE :)")
        print()
        exit()
    else:
        continue










