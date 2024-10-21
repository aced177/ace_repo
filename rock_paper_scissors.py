import random

# check_winner decides which option wins against the other.
def check_winner(x):
	if ("rock" in x) and ("scissors" in x):
		return "rock"
	elif ("rock" in x) and ("paper" in x):
		return "paper"
	elif ("paper" in x) and ("scissors" in x):
		return "scissors"

# Options for computer and player the chose
options = ["rock", "paper", "scissors"]

# Game loop
while True:
	
	# Computer choice by random selection.
	computer_choice = random.choice(options)
	
	print("Enter choice \n\t[0] for rock. \n\t[1] for paper. \n\t[2] for scissors.")
	
	# Avoid input that are out of range in options and no numeric inputs
	while True:
		choice = input("::= ")
		try:
			int(choice)
		except ValueError:
			choice = 3
		if (int(choice) >= 0) and (int(choice) <= 2):
			break
		else:
			print("Not an option.")
	# Player choice
	player_choice = options[int(choice)]
	
	# Get winner from player and computer choice
	win_ch = check_winner([computer_choice, player_choice])
	
	print("\n")
	
	# if player and computer choices are equal print("Tie")
	if player_choice == computer_choice:
		print("Tie.")
	# if player_choice equals winning choice player wins
	elif player_choice == win_ch:
		print("Player wins")
		break
	# if computer_choice equals winning choice computer wins
	elif computer_choice == win_ch:
		print("Computer wins")
		break
	
	print(f"[Computer]: {computer_choice} VS [Player]: {player_choice}\n")
print(f"[Computer]: {computer_choice} VS [Player]: {player_choice}")