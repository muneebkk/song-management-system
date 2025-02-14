// author: Muhammad Muneeb Kamran
// date: 20th september 2024


/*
 * Default Constructor
 * O Notation: O(1)
 * Explanation: Initializes the head to nullptr and songCount to 0, a constant-time operation.
 *
 * Copy Constructor
 * O Notation: O(n)
 * Explanation: Iterates through the source playlist to create new nodes, leading to O(n) complexity.
 *
 * Destructor
 * O Notation: O(n)
 * Explanation: Deletes each node in the linked list, resulting in O(n) complexity.
 *
 * Overloaded Assignment Operator
 * O Notation: O(n)
 * Explanation: Deallocates existing nodes and deep copies from the source, both O(n) operations.
 *
 * Insert Method
 * O Notation: O(n)
 * Explanation: Traverses the list to find the position for insertion, resulting in O(n) complexity.
 *
 * Remove Method
 * O Notation: O(n)
 * Explanation: Traverses the list to find the node before the one to be removed, leading to O(n) complexity.
 *
 * Swap Method
 * O Notation: O(n)
 * Explanation: Requires traversal to find nodes at pos1 and pos2, resulting in O(n) complexity.
 *
 * Get Method
 * O Notation: O(n)
 * Explanation: Traverses from the head to the specified position, leading to O(n) complexity.
 *
 * Size Method
 * O Notation: O(1)
 * Explanation: Returns songCount directly, making it a constant-time operation.
 *
 * Enter a Song (Insert)
 * O Notation: O(m)
 * Explanation: Must traverse the list to find the insertion point, where m is the number of songs.
 *
 * Remove a Song
 * O Notation: O(n)
 * Explanation: Traverses to find the node before the one to be removed, resulting in O(n) complexity.
 *
 * Swap Two Songs
 * O Notation: O(n)
 * Explanation: Finds both nodes to swap, requiring traversal, leading to O(n) complexity.
 *
 * Print All the Songs
 * O Notation: O(n^2)
 * Explanation: The loop with n iterations calls get, which has O(n) complexity, resulting in O(n^2).
 */

#include <iostream>
#include "PlayList.h"

int main() {
    PlayList myPlaylist;

    // Print the menu
    std::cout << "Menu:\n";
    std::cout << "1 - Enter a song in the play list at a given position\n";
    std::cout << "2 - Remove a song from the play list at a given position\n";
    std::cout << "3 - Swap two songs in the play list\n";
    std::cout << "4 - Print all the songs in the play list\n";
    std::cout << "5 - Quit\n";

    int choice;
    do {
        std::cout << "\nEnter 1 (insert), 2 (remove), 3 (swap), 4 (print) or 5 (quit): ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name, artist;
                int length;

                std::cout << "Song name: ";
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, name);

                std::cout << "Artist: ";
                std::getline(std::cin, artist);

                while (true) {
                    std::cout << "Length: ";
                    std::cin >> length;

                    // Check for input failure
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "\nPlease enter a valid length (in seconds).\n";
                        continue;
                    }

                    break;
                }

                unsigned int pos;
                while (true) {
                    if (myPlaylist.size() == 0) {
                        std::cout << "Position (1): ";
                    } else {
                        std::cout << "Position (1 to " << (myPlaylist.size() + 1) << "): ";
                    }
                    std::cin >> pos;

                    // Check for input failure
                    if (std::cin.fail()) {
                        std::cin.clear(); // Clear the error state
                        std::cin.ignore(10000, '\n');
                        std::cout << "\nPlease enter a valid position.\n";
                        continue;
                    }

                    if (pos < 1 || pos > myPlaylist.size() + 1) {
                        std::cout << "\nInvalid position. Please choose a position between 1 and " << (myPlaylist.size() + 1) << ".\n"; // Added newline
                        continue;
                    }

                    // If valid, insert the song
                    Song newSong(name, artist, length);
                    myPlaylist.insert(newSong, pos - 1);

                    std::cout << "\nYou entered " << name << " at position " << pos << " in the play list\n";
                    break;
                }
                break;
            }
            case 2: {
                if (myPlaylist.size() == 0) {
                    std::cout << "The playlist is empty. Please choose an option from the menu.\n";
                    break;
                }

                unsigned int pos;
                while (true) {
                    std::cout << "Position (1 to " << myPlaylist.size() << "): ";
                    std::cin >> pos;

                    // Check for input failure
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Please enter a valid position.\n";
                        continue;
                    }

                    if (pos < 1 || pos > myPlaylist.size()) {
                        std::cout << "Invalid position. Please choose a position between 1 and " << myPlaylist.size() << ".\n";
                        continue;
                    }

                    // If valid, remove the song
                    try {
                        Song removedSong = myPlaylist.remove(pos - 1);
                        std::cout << "You removed " << removedSong.getName() << " from the play list\n";
                    } catch (const std::out_of_range& e) {
                        std::cout << e.what() << std::endl;
                    }
                    break;
                }
                break;
            }
            case 3: {
                if (myPlaylist.size() == 0) {
                    std::cout << "The playlist is empty. You cannot swap songs.\n";
                    break;
                }

                unsigned int pos1, pos2;
                std::cout << "Swap song at position (1 to " << myPlaylist.size() << "): ";
                std::cin >> pos1;

                // Check for input failure
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Please enter a valid position.\n";
                    break;
                }

                if (pos1 < 1 || pos1 > myPlaylist.size()) {
                    std::cout << "Invalid position. Please choose a position between 1 and " << myPlaylist.size() << ".\n";
                    break;
                }

                std::cout << "with the song at position (1 to " << myPlaylist.size() << "): ";
                std::cin >> pos2;

                // Check for input failure
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cout << "Please enter a valid position.\n";
                    break;
                }

                if (pos2 < 1 || pos2 > myPlaylist.size()) {
                    std::cout << "Invalid position. Please choose a position between 1 and " << myPlaylist.size() << ".\n";
                    break;
                }

                // If valid, swap the songs
                try {
                    myPlaylist.swap(pos1 - 1, pos2 - 1);
                    std::cout << "You swapped the songs at positions " << pos1 << " and " << pos2 << "\n";
                } catch (const std::out_of_range& e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
            case 4: {
                if (myPlaylist.size() == 0) {
                    std::cout << "The playlist is empty.\n";
                } else {
                    for (unsigned int i = 0; i < myPlaylist.size(); i++) {
                        Song song = myPlaylist.get(i);
                        std::cout << (i + 1) << ". " << song.getName() << " ("
                                  << song.getArtist() << ") "
                                  << song.getLength() << "s\n";
                    }
                    std::cout << "There are " << myPlaylist.size() << " songs in the playlist.\n";
                }
                break;
            }
            case 5: {
                std::cout << "You have chosen to quit the program.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
