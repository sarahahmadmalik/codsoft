#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    int i_randomNumber = rand() % 100 + 1;
    int i_guessNumber;
    bool b_hasGuessed = false;

    std::cout << std::setfill(' ') << std::setw(30) << "";
    std::cout << std::setfill('-') << std::setw(57) << "" << std::endl;

    std::cout << std::setfill(' ') << std::setw(78) << "Welcome to the Number Guessing Game" << std::endl;

    std::cout << std::setfill(' ') << std::setw(30) << "";
    std::cout << std::setfill('-') << std::setw(57) << "" << std::endl;

    std::cout << std::setfill(' ') << std::setw(60) << "Guess a number from 1 - 100: ";

    while (!b_hasGuessed) {
        
        std::cin >> i_guessNumber;

        if (i_guessNumber == i_randomNumber) {
            b_hasGuessed = true;
            std::cout << std::endl << std::setfill(' ') << std::setw(70) << "Congratulations! You guessed the number " << i_randomNumber << "!" << std::endl;
        }
        else if (i_guessNumber < i_randomNumber) {
            std::cout << std::endl << std::setfill(' ') << std::setw(60) << "Too Low. Try a higher number: ";
        }
        else {
            std::cout << std::endl << std::setfill(' ') << std::setw(60) << "Too High. Try a lower number: ";
        }
    }

    return 0;
}
