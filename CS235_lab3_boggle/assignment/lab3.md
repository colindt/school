*Note: This was originally posted on the course website, which is no longer online. I have reformatted this version for GitHub. You can view the original HTML version that I downloaded [here](lab3-boggle.php.html).*

# Boggle

Note: Projects are to be completed by each student individually (not by groups of students).

The objective of this project is to design and implement the data structures and algorithms necessary for a computer player to play the popular board game Boggle.

## What is Boggle?

The game of Boggle is played with a set of sixteen letter cubes, which are standard six-sided dice except that they are marked with letters of the alphabet instead of numbers. The cubes are rolled and arranged into a 4x4 square that might look like this:

![](lab3-boggle.php_files/image002.gif)

The object of the game is to start at one cube and then work through a chain of letters to form a word that meets the following conditions:

* The word must be at least four letters long.
* The path traced out by the letters in the word must be connected horizontally, vertically, or diagonally. You can't skip over intervening cubes to get the next letter.
* Each cube may be used only once in a given word.

For example, the sample board contains the word **PEACE** as follows:

![](lab3-boggle.php_files/image004.gif)

The board, however, does not contain the word **PLACE** which would require jumping from the **P** to the **L** and then back to the **A** . Similarly, it is not possible to make the word **POPE** , because doing so would require reusing the **P** .

The Boggle player you create will find and output all the valid words on a given board. Valid words are those listed in a given dictionary.

## Example

When the Boggle player is run with the following dictionary and board it gives the output shown below.

### Dictionary

    blue
    boot
    booth
    cat
    dog
    orbit
    riot
    robot
    root
    run

### Board

    R B O
    O I T
    R O H

### Output

    boot
    booth
    orbit
    riot
    robot
    root

## Dictionary File Format

The dictionary is a text file that contains a list of words, one word per line. When comparing words on the board with words in the dictionary, use a comparison that is not case-sensitve.

## Boggle Board Files

The Boggle board is a text file that contains a list of strings separated by white space. Each string gives the letter(s) for one of the tiles on the Boggle board.

The number of strings in the file will always be a perfect square such as 9, 16, or 25. (The board will always be square.) In standard Boggle the number of tiles is 16 (a 4x4 board). Your Boggle player needs to work correctly with a square board of any size.

The strings in the file are organized by row. The strings for the first board-row are given first followed by the strings for the second row. The strings for the last row on the board come last. Within each row the strings are listed from left to right. The first string in the file gives the letter(s) on the die at the upper left corner of the board. The last string in the file gives the letter(s) on the die at the bottom right corner of the board. The strings for a row on the board may be listed on more than one line in the file.

Each string may be upper or lower case and may contain one or more letters. In official Boggle, each tile contains only one letter, (except for one tile that contains 'Qu'). Your Boggle player needs to work correctly with strings of any length.

## Output Format

The output is a list of the words found on the Boggle board, one word per line. Each word given in the output must be:

1. found in the dictionary
2. at least the minimum length of 4 letters
3. found on the board following the standard Boggle rules. (Each tile can participate at most once in a given word.)

The words are output in sorted order.

The words are output in lower case.

Each word is only output once even though the board may contain the same word in multiple locations.

The output is written to a file, not to the standard output.


## Testing

You may use these files to do some minimal testing:

[in30a.txt](../tests/in00a.txt)
[in30b.txt](../tests/in00b.txt)
[out30.txt](../tests/out00.txt)

The files are also available in a zip archive:

[test30.zip](#)

You are required to write additional tests to fully exercise all of your code. Here are some ideas for additional tests.

1. An empty dictionary file.
2. Boards of various sizes such as 9, 16, and 25.
3. Check that words cannot be made that are too short.
4. Check that words can be made with multi-letter tiles.
5. Check that words cannot be made by reusing tiles.
6. Check that words can be found in all directions.
7. Check that words cannot be made by skipping tiles.
8. Check that words cannot be made by wrapping around at the edge of the board.

## Design

What classes will you use to solve this problem?

What data values will be stored in each class?

What operations will be supported on each class?

What algorithms will you use?


## Dictionary Operations

If Boggle is to run in a reasonable amount of time, the operations for searching the dictionary must be fast, even for large dictionaries.

One way to make the search fast is to store the dictionary in a Set and use the Set find operation to search for a word. The find operation for a Set in a data structure library will typically be a very fast operation.

Another way to make the search fast is to store the dictionary in a sorted List and use a binary search algorithm to search for a word. You would need to use a type of List that supports efficient indexing (such as a vector).

When searching the Boggle board for words you will need to stop following a path whenever you can determine that the first part of the path does not match a prefix of any word in the dictionary. Thus you need to be able to search the dictionary for prefixes and the prefix search must be fast.

If the dictionary is stored in a Set, many data structure libraries provide a way to find the string in the Set that is closest to the one you are searching for. Such an operation could be used to quickly find a word with a given prefix.

If the dictionary is stored in a sorted List, the binary search algorithm can be modified to find the string in the List that is closest to the one you are searching for.

## Word Search Operations

You are required to find the words on the board using a recursive search over the paths on the board. Of course, there are many paths to be followed. If Boggle is to run in a reasonable amount of time, your algorithm will need to be intelligent about avoiding wasted effort. One way to speed up the search is to only follow paths that have the possibility of leading to valid words. Before moving along a path, the search algorithm should ask the dictionary if any words begin with the prefix represented by the current path. If the answer is no, there is no need to follow the path further. Checking prefixes in this manner will allow your algorithm to avoid many dead-end paths, and therefore run more quickly. In fact, if you don't do this, your program will run too slowly to pass off.

## Implementation Requirements

1. Store the dictionary in a Set or a sorted List.
2. Use either a set operation or binary search to locate a word in the dictionary that is closest to a given prefix.
3. Use a recursive search over the contents of the board to find the words.
4. Use a compare that is not case-sensitive when comparing words on the board with words in the dictionary.
5. Output the words in sorted order.
6. Output the words in lower case.
7. Avoid following dead-end paths, thus allowing Boggle to run quickly on large boards.

## Command Line

The program is run with the names of the dictionary, board, and output files given on the command-line. For example the program might be run like this:

    lab3 dictionary.txt board.txt words.txt

## Submission

Submit all .h and .cpp files needed to build the project. The project should build successfully with a simple command.

    g++ *.cpp

All files must have either a .h or .cpp extension. Any files with a .h extension must be 'included' in a file with a .cpp extension. Do not use any subfolder structure. All files must be in a single folder.
