"""
Going to create a version of the Game of Yahtzee
need a number of users and scorecards for each (most likely going to need a class)

Starting by rolling 6 different dice each round and storing them in a list
going to print what the dice are to the user so they get to choose what category they want to store the points in
    going to use binary digits 0 & 1 to signify if something can be entered into that area
        if can be entered, going to store the point values for each person
            going to total up points at the end of the game to show the winner

going to need classes for:
    scorecards
    players
    dice?
    _____ (what else)
    number of games?

"""

import random

class DICE:
    def __init__(self):
        """Constructor roles six dice and places them into a list."""
        self.dice = []
        for number in range(6):
            self.dice.append(random.randint(1,6))

    def get_dice(self):
        """Returns the list of dice values after first role"""
        return self.dice

    def get_specific_dice(self, number):
        """Returns the number of a specific dice wanted"""
        return self.dice[number-1]

    def roll_die(self):
        """Rolls all die again"""
        self.dice = []
        for number in range(6):
            self.dice.append(random.randint(1,6))

    def roll_specific_die(self, *lyst):
        """Keeps specific die in place and rolls the other die that are listed in an input lyst"""
        for number in lyst:
            self.dice[number-1] = random.randint(1,6)


class PLAYER:
    def __init__(self, name):
        """Initializes a player by giving them a name, scorecard, and set of dice"""
        self.name = name

'''
class SCORECARD:
    # scoring goes in score-type_total
    # if not scored already uppercase score-type == 0
    # if scored already uppercase score-type == 1
    ONE = 0
    one_total = 0
    TWO = 0
    two_total = 0
    THREE = 0
    three_total = 0
    FOUR = 0
    four_total = 0
    FIVE = 0
    five_total = 0
    SIX = 0
    six_total = 0
    T_OF_K = 0
    F_OF_K = 0
    FULL_HOUSE = 0
    S_STRAIGHT = 0
    LG_STRAIGHT = 0
    YAHTZEE_1 = 0
    YAHTZEE_2 = 0
    YAHTZEE_3 = 0
    CHANCE = 0


    def one(dice):
        """When this is called, the scoring of the ones column is tallied unless the one column has already been recorded."""
        if ONE == 1:

        for number in dice:
            if number == 1:
                one_total += 1

    def two(dice):
        two_total = 0
        for number in dice:
            if number == 2:
                two_total += 2
        return two_total

    def three(dice):
        three_total = 0
        for number in dice:
            if number == 3:
                three_total += 3
        return three_total

    def four(dice):
        four_total = 0
        for number in dice:
            if number == 4:
                four_total += 4
        return four_total

    def five(dice):
        five_total = 0
        for number in dice:
            if number == 5:
                five_total += 5
        return five_total

    def six(dice):
        six_total = 0
        for number in dice:
            if number == 6:
                six_total += 6
        return six_total

    def three_of_a_kind(dice):
'''

