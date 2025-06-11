# Minesweeper

![mInesweeper](https://github.com/10anees/MInesweeper/assets/128053118/8c51800a-3e7d-4e58-bb5e-5d9477c6f15f)


Minesweeper is a puzzle game in which the player is presented with a board filled with mines, without knowing what fields they occupy. When the player clicks on a field, a number appears on it, indicating how many mines are located in the fields nearest to it. The player then clicks on other fields, trying to avoid mines. The objective is to clear the board without detonating any mines, with help from clues about the number of neighboring mines in each field. Minesweeper is a game of deduction that dates back to at least 1990, though the concept originated even before that.


## Installation

To install and run Minesweeper, you need to have C++ and SFML installed on your system. Then, follow these steps:

```bash
  1. Clone this repository to your local machine: git clone (https://github.com/10anees/Minesweeper)/Download zip file and extract
  2. Navigate to the project directory: Minesweeper
  3. Compile the source code: g++ Minesweeper.ccp
  4. Link the file with SFML Libraries:
     sfml-graphics-d.lib
     sfml-window-d.lib
     sfml-audio-d.lib
     sfml-network-d.lib
     sfml-system-d.lib
  5. Run the executable file
     Minesweeper.cpp

OR

  2. Navigate to the project directory: Release
  3. Run Minesweeper.exe

```
    
## Features

- Flagging/Unflagging
- Retry Button
- Timer
- Custom sprite for winning/losing

##  Screenshots

Extract zip file

![Screenshot 2023-12-13 234236](https://github.com/10anees/MInesweeper/assets/128053118/d60ac1d4-2b34-43cf-b380-6b4902ba2ddd)

Open "Release" Directory

![Screenshot 2023-12-13 234250](https://github.com/10anees/MInesweeper/assets/128053118/3204c131-9d52-4d75-af38-f074b76a46ed)



### Make sure you have the following files in the same directory to run the application. All files are in the same directory with the name release on github. These also include the required SFML libraries to run the application along with other required .dll files to run on x64 architecture.



Run the executable file
 
![Readme_instructions](https://github.com/10anees/MInesweeper/assets/128053118/e4d86ef7-cc04-4aa4-98d6-c4703e8e57f2)


Basic Functions

![Minesweeper Instruction](https://github.com/10anees/MInesweeper/assets/128053118/27a2dcc0-b445-41ab-b7d0-7f1ec1173498)

Flagging/Unflagging (Right-Click)

![Screenshot 2023-12-12 184611](https://github.com/10anees/MInesweeper/assets/128053118/a38dda1e-966b-4ced-aa88-02b7147eba0d)

![Screenshot 2023-12-12 184621](https://github.com/10anees/MInesweeper/assets/128053118/abc3298f-2bcc-42dd-8312-01b84df5e703)

Revealing tile (Left-Click)

![Screenshot 2023-12-12 183846](https://github.com/10anees/MInesweeper/assets/128053118/abb6efc7-15c4-4950-949e-cfd0efc491f1)

Winning/Losing

![Screenshot 2023-12-12 184037](https://github.com/10anees/MInesweeper/assets/128053118/bccaece4-690c-46f0-a89a-34a7587aff2f)

![Screenshot 2023-12-12 183916](https://github.com/10anees/MInesweeper/assets/128053118/0e72e056-6a9a-4f47-91b5-905191e77d85)

## FAQ

#### How to win the game?

Reveal all hidden tiles without detonating a mine to win. You also need to have a positive flag count.

#### What purpose does flagging have?

Flagging is a way for the player to keep in check the predicted position of the mines. To make sure this feature is fair, one can only win if they have a positive flag count.

## Contributors

- Qatada Aadil (@l230998@lhr.nu.edu.pk)
- Anees Hamid (@l230671@lhr.nu.edu.pk)








  
