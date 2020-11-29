//
// Created by galan on 11/24/2020.
//

/*
Going to create a version of the Game of Yahtzee
need a number of users and scorecards for each (most likely going to need a class)

Starting by rolling 6 different dice each round and storing them in a list
        going to print what the dice are to the user so they get to choose what category they want to store the points in
        going to use binary digits 0 & 1 to signify if something can be entered into that area
if can be entered, going to store the point values for each person
going to total up points at the end of the game to show the winner

structures:
    scorecards
    players
functions:
    game
    main
classes:
    dice ?
_____ (what else)
number of games?

*/
//  header that holds the key to randomness for the die using rand() and srand()
#include <cstdlib>
//  included to call time() in die roll for randomness
#include <ctime>
//  basic header for main function
#include <iostream>
using namespace std;

struct PLAYER {
    //  each player has a name to specify who is playing, their own scorecard, final score, and final placement
    //  string name; if I want to allow players to give themselves names, ask for names as part of main and insert them here
    SCORECARD scorecard;
    int score = 0;
    int placement = 0;
};

struct Node {
    string data;
    Node* next;
    explicit Node(string elt) { data = elt; next = nullptr; }
};

struct SCORECARD {
    //  the booleans show if the part of the scorecard has been scored or not yet
    bool ONE = 0;
    bool TWO = 0;
    bool THREE = 0;
    bool FOUR = 0;
    bool FIVE = 0;
    bool SIX = 0;
    bool THREE_OF_KIND = 0;
    bool FOUR_OF_KIND = 0;
    bool FULL_HOUSE = 0;
    bool SMALL_STRAIGHT = 0;
    bool LARGE_STRAIGHT = 0;
    bool YAHTZEE = 0;
    bool YAHTZEE_BONUS = 0;
    bool CHANCE = 0;
    bool FINISHED = 0;
    //  individual scores for each section from different rolls
    int score_one = 0;
    int score_two = 0;
    int score_three = 0;
    int score_four = 0;
    int score_five = 0;
    int score_six = 0;
    int score_3ofK = 0;
    int score_4ofK = 0;
    int score_full_house = 0;
    int score_sStraight = 0;
    int score_lStraight = 0;
    int score_yahtzee = 0;
    int score_yahtzee_bonus = 0;
    int score_chance = 0;
    //  final score to distinguish the totals
    int upper_section = 0;
    int lower_section = 0;
    int total_score = upper_section + lower_section;

    string plays[14] {"one", "two", "three", "four", "five", "six", "three of a kind", "four of a kind", "full house", "small straight", "large straight", "yahtzee", "yahtzee bonus", "chance"};
    Node* head = new Node(plays[0]);
    Node* temp = head;
    for (int i = 1; i < 15; i++) {
        Node* newNode = new Node(plays[i]);
        temp->next = newNode;
        temp = temp->next;
    }
};

class Scoring() {
public:
    //  upper section scoring systems
    //  first I check if it has been scored or not
    //      if it has, I throw and exception error to be caught in game function
    //      if not, I score the points and change the boolean operator to show it has been scored
    void one(PLAYER player, int* dice) {
        if (player.scorecard.ONE == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 1) {
                    player.scorecard.score_one += 1;
                }
            }
            player.scorecard.ONE = 1;
            player.scorecard.upper_section += player.scorecard.score_one;
            player.scorecard.plays[0]
        } else {
            throw "Position already played.";
        }
    }
    void two(PLAYER player, int* dice) {
        if (player.scorecard.TWO == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 2) {
                    player.scorecard.score_two += 2;
                }
            }
            player.scorecard.TWO = 1;
            player.scorecard.upper_section += player.scorecard.score_two;
        } else {
            throw "Position already played.";
        }
    }
    void three(PLAYER player, int* dice) {
        if (player.scorecard.THREE == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 3) {
                    player.scorecard.score_three += 3;
                }
            }
            player.scorecard.THREE = 1;
            player.scorecard.upper_section += player.scorecard.score_three;
        } else {
            throw "Position already played.";
        }
    }
    void four(PLAYER player, int* dice) {
        if (player.scorecard.FOUR == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 4) {
                    player.scorecard.score_four += 4;
                }
            }
            player.scorecard.FOUR = 1;
            player.scorecard.upper_section += player.scorecard.score_four;
        } else {
            throw "Position already played.";
        }
    }
    void five(PLAYER player, int* dice) {
        if (player.scorecard.FIVE == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 5) {
                    player.scorecard.score_five += 5;
                }
            }
            player.scorecard.FIVE = 1;
            player.scorecard.upper_section += player.scorecard.score_five;
        } else {
            throw "Position already played.";
        }
    }
    void six(PLAYER player, int* dice) {
        if (player.scorecard.SIX == 0) {
            for (int i = 0; i < 5; i++) {
                if (dice[i] == 6) {
                    player.scorecard.score_six += 6;
                }
            }
            player.scorecard.SIX = 1;
            player.scorecard.upper_section += player.scorecard.score_six;
        } else {
            throw "Position already played.";
        }
    }



    //  scoring for the lower section



    //  counting function that will be used in a lot of lower section scoring charts
    int* counter(int* dice) {
        int count[6]{0};
        for (int i = 0; i < 5; i++) {
            if (dice[i] == 1) {
                count[0] += 1;
            } else if (dice[i] == 2) {
                count[1] += 1;
            } else if (dice[i] == 3) {
                count[2] += 1;
            } else if (dice[i] == 4) {
                count[3] += 1;
            } else if (dice[i] == 5) {
                count[4] += 1;
            } else if (dice[i] == 6) {
                count[5] += 1;
            }
        }
        return count;
    }

    void three_of_a_kind(PLAYER player, int* dice) {
        if (player.scorecard.THREE_OF_KIND == 0) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            //  seeing if there is a three of a kind and adding it to a total integer which will be the scoring
            for (int i = 0; i < 6; i++) {
                if (count[i] >= 3) {
                    int total = 0;
                    for (int x = 0; x < 5; x++) {
                        total += dice[x];
                    }
                    player.scorecard.score_3ofK = total;
                }
            }
            player.scorecard.THREE_OF_KIND = 1;
            player.scorecard.lower_section += player.scorecard.score_3ofK;
        } else {
            throw "Position already played.";
        }
    }
    void four_of_a_kind(PLAYER player, int* dice) {
        if (player.scorecard.FOUR_OF_KIND == 0) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            //  seeing if there is a four of a kind and adding it to a total integer which will be the scoring
            for (int i = 0; i < 6; i++) {
                if (count[i] >= 4) {
                    int total = 0;
                    for (int x = 0; x < 5; x++) {
                        total += dice[x];
                    }
                    player.scorecard.score_4ofK = total;
                }
            }
            player.scorecard.FOUR_OF_KIND = 1;
            player.scorecard.lower_section += player.scorecard.score_4ofK;
        } else {
            throw "Position already played.";
        }
    }
    void full_house(PLAYER player, int* dice) {
        if (player.scorecard.FULL_HOUSE == 0) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            //  seeing if there is a three of a kind and a four of a kind
            bool x = 0;
            bool y = 0;
            for (int i = 0; i < 6; i++) {
                if (count[i] == 3) {
                    x = 1;
                } else if (count[i] == 2) {
                    y = 1;
                }
            }
            if (x == 1 && y == 1) {
                player.scorecard.score_full_house = 25;
            }
            player.scorecard.FULL_HOUSE = 1;
            player.scorecard.lower_section += player.scorecard.score_full_house;
        } else {
            throw "Position already played.";
        }
    }
    void small_straight(PLAYER player, int* dice) {
        if (player.scorecard.SMALL_STRAIGHT == 0) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            //  seeing if there is four in a row
            if (count[0] == 1 && count[1] == 1 && count[2] == 1 && count[3] == 1) {
                player.scorecard.score_sStraight = 30;
            } else if (count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1) {
                player.scorecard.score_sStraight = 30;
            } else if (count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1) {
                player.scorecard.score_sStraight = 30;
            }
            player.scorecard.SMALL_STRAIGHT = 1;
            player.scorecard.lower_section += player.scorecard.score_sStraight;
        } else {
            throw "Position already played.";
        }
    }
    void large_straight(PLAYER player, int* dice) {
        if (player.scorecard.LARGE_STRAIGHT == 0) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            //  seeing if there is five in a row
            if (count[0] == 1 && count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1) {
                player.scorecard.score_sStraight = 40;
            } else if (count[1] == 1 && count[2] == 1 && count[3] == 1 && count[4] == 1 && count[5] == 1) {
                player.scorecard.score_sStraight = 40;
            }
            player.scorecard.LARGE_STRAIGHT = 1;
            player.scorecard.lower_section += player.scorecard.score_lStraight;
        } else {
            throw "Position already played.";
        }
    }
    void yahtzee(PLAYER player, int* dice) {
        if (player.scorecard.YAHTZEE == 0 || player.scorecard.YAHTZEE_BONUS != -1) {
            //  calling counter function to set up a count array for the dice
            int *count = counter(dice);

            // seeing if there is a yahtzee
            for (int i = 0; i < 6; i++) {
                if (count[i] == 5) {
                    if (player.scorecard.YAHTZEE == 0) {
                        player.scorecard.YAHTZEE = 1;
                        player.scorecard.score_yahtzee = 50;
                        player.scorecard.lower_section += player.scorecard.score_yahtzee;
                    } else if (player.scorecard.score_yahtzee == 50 && player.scorecard.YAHTZEE_BONUS == 0) {
                        player.scorecard.score_yahtzee_bonus += 100;
                        player.scorecard.YAHTZEE_BONUS += 1;
                        player.scorecard.lower_section += 100;
                    } else {
                        throw "Unusable Yahtzee.";
                    }
                }
            }
        } else {
            throw "Position already played.";
        }
    }
    void chance(PLAYER player, int* dice) {
        if (player.scorecard.CHANCE == 0) {
            player.scorecard.CHANCE = 1;
            int total = 0;
            for (int i = 0; i < 5; i++) {
                player.scorecard.score_chance += dice[i];
            }
            player.scorecard.lower_section += player.scorecard.score_chance;
        } else {
            throw "Position already played.";
        }
    }
};

class Dice() {
public:
    int* full_roll() {
        dice[5]{0};
        for (int i = 0; i < 5; i++) {
            srand(static_cast<unsigned int>(time(nullptr)));
            static constexpr double fraction {1.0 / (RAND_MAX + 1.0)};
            dice[i] = 1 + static_cast<int>((6) * (rand() * fraction));
        }
        return dice;
    }
    int* reRoll(int* dice, int* dice_to_change) {
        for (int i = 0; i < dice_to_change.size(); i++) {
            for (int y = 0; y < dice.size(); y++) {
                if (dice[y] == dice_to_change[i]) {
                    srand(static_cast<unsigned int>(time(nullptr)));
                    static constexpr double fraction {1.0 / (RAND_MAX + 1.0)};
                    dice[y] = 1 + static_cast<int>((6) * (rand() * fraction));
                }
            }
        }
        return dice;
    }

};

//  using main function as my entire game.
int main() {
    //  need to find number of players
    int number_of_players = 1;
    cout >> "Enter the number of players going to play: ";
    cin << number_of_players << endl;
    PLAYER player_array[number_of_players]{};


    for(int turns = 0; turns < 16; turns ++) {
       for (int player = 0; player < number_of_players; player++) {
            if (player_array[player].scorecard.FINISHED == 1) {
                continue;
            }
            int* dice = Dice::full_roll();
            cout >> "Your dice roll is: " >> dice >> "/nHow many die would you like to change? ";
            int dice_to_change_number = 0;
            cin << dice_to_change_number << endl;
            int* dice_to_change[dice_to_change]{0};
            for (int i = 0; i < dice_to_change_number; i++) {
                cout >> "What is the number of a die you want to change? ";
                int n = 0;
                cin << n << endl;
                dice_to_change[i] = n;
            }
            dice = Dice::reRoll(dice, dice_to_change);
        tryAgain:
            cout << "Here are your dice to play with: " << dice << endl;
            cout << "Here are the plays you have left: ";
            Node* temp = player_array[player].scorecard.head;
            while (temp != nullptr) {
                cout << temp << "/t";
                temp = temp->next;
            }
            cout << "/nWhat play would you like to play? ";
            string play;
            cin >> play;
            if (play == "one") {
                try {
                    one(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "two") {
                try {
                    two(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "three") {
                try {
                    three(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "four") {
                try {
                    four(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "five") {
                try {
                    five(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "six") {
                try {
                    six(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "three of a kind") {
                try {
                    three_of_a_kind(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "four of a kind") {
                try {
                    four_of_a_kind(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "full house") {
                try {
                    full_house(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "small straight") {
                try {
                    small_straight(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "large straight") {
                try {
                    large_straight(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "yahtzee") {
                try {
                    yahtzee(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "yahtzee bonus") {
                try {
                    yahtzee(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else if (play == "chance") {
                try {
                    chance(player_array[player], dice);
                } catch (const char* exception) {
                    cout << "/nScoring slot already used; use another slot/n";
                    goto tryAgain;
                }
            } else {
                goto tryAgain;
            }
            temp = player_array[player].scorecard.head;
            Node* trail = nullptr;
            while (temp != nullptr ++ temp->data != play) {
                trail = temp;
                temp = temp->next;
            }
            if (trail == nullptr) {
                head = head->next;
            } else {
                trail->next = temp->next;
            }
            delete temp;
            if (player_array[player].scorecard.head== nullptr) {
                player_array[player].scorecard.FINISHED = 1;
            }
       }
    }
    int highest = -1;
    for (int i = 0; i < number_of_players; i++) {
        if (player_array[i].scorecard.upper_section >= 63) {
            total += 35;
        }
        if (player_array[i].scorecard.total_score > highest) {
            highest = i;
        }
        //  need to find out how to manage a tie
        cout << "Player " << i + 1 << "'s score is: " << player_array[i].scorecard.total_score << endl;
    }
    cout << "Player " << highest + 1 << "came in first place with a score of: " << player_array[highest].scorecard.total_score << endl;
    return 0;
}