# 🐍 Snake Game in C++ (BFS + Data Structures)

A turn-based, console Snake game written in C++ using **only `<iostream>`**. It was built as a Data Structures project and evolved from a BFS-based maze game. Every structure the game needs (queue, deque, graph traversal, random generator) is implemented by hand with plain arrays.

## Features

- 5 levels with growing board size (10×10 → 14×14), more obstacles and a higher food target
- Randomly generated walls, with a guarantee that every free cell is reachable
- 3 lives, so a crash costs a life and resets the snake
- Scoring: +10 per food and a +20 bonus per level cleared
- **BFS autopilot**: press `P` and the game takes one step along the shortest safe path to the food
- No external libraries, just `#include <iostream>`

## Getting Started

### Requirements
- A C++ compiler (g++, clang++, MSVC)
- A terminal that supports ANSI escape codes (Linux, macOS, Windows Terminal / modern Windows 10+ console)

### Build and run

```bash
g++ snake_iostream.cpp -o snake
./snake
```

On startup, enter your name and a "lucky number". The number seeds the random generator, so the same number gives the same mazes.

## Controls

The game is turn-based: type a key and press **Enter**.

| Key | Action |
|-----|--------|
| `W` | Move up |
| `A` | Move left |
| `S` | Move down |
| `D` | Move right |
| `P` | Autopilot: one step along the BFS shortest path to the food |
| `Q` | Quit |

Keys are case-insensitive. You can type several moves at once, e.g. `dddss` + Enter moves 5 steps.

### Legend

| Symbol | Meaning |
|--------|---------|
| `@` | Snake head |
| `o` | Snake body |
| `$` | Food |
| `X` | Wall |
| `.` | Empty cell |

## Rules

- Eat enough food to clear the level (`5 + 2 × level`).
- Hitting a wall or your own body costs a life. With 0 lives, the game is over.
- Moving straight back into your own neck is ignored and costs nothing.
- Clear all 5 levels to win.

## Data Structures Used

| Data structure | Where | Purpose |
|---|---|---|
| **2D array** | `char grid[MAXN][MAXN]` | Game board (walls, food, snake) |
| **Circular array deque** (used as a queue) | `class Body` | Snake body: the head is added at the front and the tail removed from the back, both in O(1), with wrap-around via `% MAXC` |
| **Array-based queue** | `int Q[MAXC]` with front/back indexes | BFS queue |
| **Graph (implicit)** | The grid itself | Each cell is a vertex (`row*n + col`) and its edges are the 4 non-wall neighbours |
| **Visited array** | `bool vis[]` | Marks cells already reached by BFS |
| **Parent array** | `int parent[]` | Rebuilds the shortest path from food back to the head |

## Algorithms

- **BFS shortest path** (`bfsDirection`): powers the autopilot, O(n²). Walls and the snake's body are treated as blocked, except the tail, which moves away on the next step.
- **BFS flood fill** (`allReachable`): checks connectivity so no generated level has sealed-off areas. A level is regenerated until it passes.
- **LCG pseudo-random generator** (`myRand`): a hand-written replacement for `rand()` and `time()`.

## Project Structure

```
.
├── snake_iostream.cpp   # the whole game (single file)
└── README.md
```

Main components inside the file:

- `Levels`: board size, wall percentage and food target per level
- `Body`: circular-array deque holding the snake
- `SnakeGame`: level generation, food placement, movement, BFS and drawing
- `main()`: game loop, lives and scoring

## Origin

This project reuses the ideas from an earlier BFS maze game (grid, graph + BFS shortest path, random obstacles, levels, lives and score) and applies them to Snake.

## Possible Improvements

- Undo feature using a stack of previous moves
- High-score table
- Bonus food that disappears after a few turns
- Real-time movement (needs platform-specific headers)
