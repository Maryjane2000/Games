/*Base code comes from www.cppforschool.com
http://www.cppforschool.com/project/hangman-game-code.html*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

const int maxTries = 5;

bool validateInput(char input)
{
    // Check that the player only enters an alphabet letter
    return std::isalpha(input) != 0;
}

int fillLettersInWord(char guess, std::string secretWord, std::string &guessWord)
{
    /*This function will fill in the characters in the secret word and returns
    the number of characters matched.*/

    int i;
    int matches = 0;
    int len = secretWord.length();

    for (i = 0; i < len; i++)
    {
        // The letter has already been matched in the word.
        if (std::toupper(guess) == guessWord[i])
        {
            return 0;
        }
        // Check if the guess is in the secret word.
        else if (std::toupper(guess) == secretWord[i] || std::tolower(guess) == secretWord[i])
        {
            // Convert the first letter of the secret word to uppercase
            if (i == 0)
            {
                guessWord[i] = std::toupper(secretWord[i]);
            }
            else
            {
                guessWord[i] = secretWord[i];
            }
            matches++;
        }
    }

    return matches;
}

int main()
{
    std::string name;
    char letter;
    int numberOfWrongGuesses;
    std::string word;
    std::string words[] =
        {
            "Wolverine",
            "Cheetah",
            "Lynx",
            "Alligator"};
    // Random word from array.
    srand(time(NULL));
    int x = rand() % 4;
    word = words[x];

    // Make the secret word appear with the * character.
    std::string unknown(word.length(), '*');

    // Welcome the player to the game.
    std::cout << std::endl;
    std::cout << "Welcome to the hangman game... Try to guess the predator animal!" << std::endl;
    std::cout << "Each letter is hidden behind the * character" << std::endl;
    std::cout << "You can only enter one letter in one try" << std::endl;
    std::cout << "You have " << maxTries << "tries to try and guess the word! Good luck!" << std::endl;
    std::cout << "--------------------------------------------------------------------------------" << std::endl;

    // Loop the game until the guesses are used up.
    while (numberOfWrongGuesses < maxTries)
    {
        std::cout << unknown << std::endl;
        std::cout << "Guess a letter: " << std::endl;
        std::cin >> letter;

        // Call the validate input function if input is invalidate
        if (!validateInput(letter))
        {
            std::cout << "Invalid input. Enter a letter." << std::endl;
            // Clear input buffer
            std::cin.clear();
            std::cin.ignore();
            continue;
        }

        // Fill in the word if guess is correct, otherwise increment the number of wrong guesses.
        if (fillLettersInWord(letter, word, unknown) == 0)
        {
            std::cout << "No, That letter is not in the secret word..." << std::endl;
            numberOfWrongGuesses++;
        }
        else
        {
            std::cout << "Yes, you found a letter!" << std::endl;
        }

        // Tell the player how many guesses you have left(wrong guesses).
        std::cout << "You have " << maxTries - numberOfWrongGuesses << " guesses left." << std::endl;

        // Check if the player guessed the secret word.
        if (word == unknown)
        {
            std::cout << word << std::endl;
            std::cout << "Yes! Congratulations you found the secret word!" << std::endl;
            break;
        }
    }
    if (numberOfWrongGuesses == maxTries)
    {
        std::cout << "Sorry, you loose..." << std::endl;
        std::cout << "The word was : " << word << std::endl;
    }

    std::cin.ignore();
    std::cin.get();
    return 0;
}