# Matching Cards Game

## 📌 Project Overview

Matching Cards is a desktop memory game built using **C++** and the **Qt Framework**.  
The objective of the game is to match every two identical cards by flipping them and remembering their positions.

The game includes a login screen, a playable card-matching board, score tracking, an openings counter, and separate win/game-over screens.

## 🎮 Game Description

The player controls a cursor on a 6x6 card grid. Cards are initially hidden, and the player flips two cards at a time. If the two selected cards match, they are removed from the board and the score increases. If they do not match, they are flipped back.

The player wins when all matching pairs are found. The game ends if the player exceeds the allowed number of openings.

## ✨ Features

- Login screen before starting the game
- 6x6 card matching board
- Keyboard-controlled cursor movement
- Card flipping using the keyboard
- Score counter
- Openings counter
- Win screen when all cards are matched
- Game-over screen when the player exceeds the opening limit
- Qt resource system for loading card images
- Simple demo user accounts

## 🕹️ Controls

| Key | Action |
|---|---|
| Left Arrow | Move cursor left |
| Right Arrow | Move cursor right |
| Up Arrow | Move cursor up |
| Down Arrow | Move cursor down |
| Space | Flip/select a card |
| S | Show or hide all cards |

## 🔐 Demo Login

The project includes hardcoded demo users for testing:

| Username | Password |
|---|---|
| admin | admin |
| test | 1234 |

> Note: These accounts are for demo/testing purposes only. Hardcoded credentials should not be used in production applications.

## 🧱 Project Structure

```text
MatchingCards/
│
├── main.cpp                 # Application entry point
├── MatchingCards.pro        # Qt QMake project configuration
│
├── loginwindow.cpp/.h/.ui   # Login window
├── mainwindow.cpp/.h/.ui    # Main window files
├── playing.cpp/.h           # Core game logic
├── cursor.cpp/.h            # Keyboard cursor movement and card selection
├── gameover.cpp/.h/.ui      # Game-over screen
├── won.cpp/.h/.ui           # Winning screen
├── Users.cpp/.h             # Demo user data
│
├── imgs/                    # Image assets
├── resources.qrc            # Qt resource file
└── imgdata.txt              # Card data file
