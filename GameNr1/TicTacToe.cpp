/*Base code comes from www.cppforschool.com
http://www.cppforschool.com/project/tic-tac-toe-project.html*/

#include <iostream>
#include <limits>

char area[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void playingBoard()
// Structure of the playing board, that is printed to the terminal.
{
    std::cout << std::endl;
    std::cout << "--- Tic Tac Toe ---" << std::endl;
    std::cout << std::endl;
    std::cout << "Player 1 (X) - Player 2 (O)" << std::endl;
    std::cout << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << area[1] << "  |  " << area[2] << "  |  " << area[3] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << area[4] << "  |  " << area[5] << "  |  " << area[6] << std::endl;

    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;

    std::cout << "  " << area[7] << "  |  " << area[8] << "  |  " << area[9] << std::endl;

    std::cout << "     |     |     " << std::endl;
    std::cout << std::endl;
}

int checkForWin()
/*
1 = game is over with result.
-1 = game in progress.
0 = game is over and no result.*/
{
    int result = -1;

    if (area[1] == area[2] && area[2] == area[3])
    {
        result = 1;
    }
    else if (area[4] == area[5] && area[5] == area[6])
    {
        result = 1;
    }
    else if (area[7] == area[8] && area[8] == area[9])
    {
        result = 1;
    }
    else if (area[1] == area[4] && area[4] == area[7])
    {
        result = 1;
    }
    else if (area[2] == area[5] && area[5] == area[8])
    {
        result = 1;
    }
    else if (area[3] == area[6] && area[6] == area[9])
    {
        result = 1;
    }
    else if (area[1] == area[5] && area[5] == area[9])
    {
        return 1;
    }
    else if (area[3] == area[5] && area[5] == area[7])
    {
        result = 1;
    }
    else if (area[1] != '1' && area[2] != '2' && area[3] != '3' && area[4] != '4' && area[5] != '5' && area[6] != '6' && area[7] != '7' && area[8] != '8' && area[9] != '9')
    {
        result = 0;
    }

    return result;
}

int main()
{
    int player = 1, i, choice;
    char mark;

    do
    {
        playingBoard();
        player = (player % 2) ? 1 : 2; // Divides the player to two.

        std::cout << "Player " << player << ", enter a number: " << std::endl;

        while (!(std::cin >> choice)) // Makes sure the players enters a number only.
        {
            std::cout << "Invalid input. Enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        mark = (player == 1) ? 'X' : 'O'; // Switch marker between players.

        // Makes sure to place the mark in the correct choice.
        if (choice == 1 && area[1] == '1')
        {
            area[1] = mark;
        }
        else if (choice == 2 && area[2] == '2')
        {
            area[2] = mark;
        }
        else if (choice == 3 && area[3] == '3')
        {
            area[3] = mark;
        }
        else if (choice == 4 && area[4] == '4')
        {
            area[4] = mark;
        }
        else if (choice == 5 && area[5] == '5')
        {
            area[5] = mark;
        }
        else if (choice == 6 && area[6] == '6')
        {
            area[6] = mark;
        }
        else if (choice == 7 && area[7] == '7')
        {
            area[7] = mark;
        }
        else if (choice == 8 && area[8] == '8')
        {
            area[8] = mark;
        }
        else if (choice == 9 && area[9] == '9')
        {
            area[9] = mark;
        }
        else // Comes in if the player enters a number that is already marked.
        {
            std::cout << "Invalid move" << std::endl;
            player--;

            // Ignores the input to be able to get the new input.
            std::cin.ignore();
            std::cin.get();
        }

        i = checkForWin(); // Calling function that are checking for a winner.

        player++;
    } while (i == -1); // Continues the game in a loop.

    playingBoard();

    // If a winner is found, print out the winning player.
    if (i == 1)
    {
        std::cout << "\aPlayer " << --player << " win " << std::endl;
    }
    else // Prints out if none of the players win.
    {
        std::cout << "\aGame draw" << std::endl;
    }

    // Makes sure to empty inputs and close game when enter is pressed.
    std::cin.ignore();
    std::cin.get();

    return 0;
}