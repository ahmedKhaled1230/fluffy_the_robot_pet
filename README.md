# Fluffy the Robot Pet

A plain C99 practice project based on **Project 4 - Fluffy the Robot Pet** from `Five_C_Practice_Projects.md`.

Fluffy is a virtual robot pet with food, fun, energy, mood flags, and an age measured in hours. The user can care for Fluffy through a menu and view its face and status report.

## Author

**Ahmed khaled mohamed youssri khaled elbohy**  
Email: [ahmed2006688@gmail.com](mailto:ahmed2006688@gmail.com)

## Features

- Hatch Fluffy with a custom name.
- Feed Fluffy to increase food.
- Play with Fluffy to increase fun while using energy.
- Put Fluffy to sleep or wake it up.
- Advance time by one hour.
- Display Fluffy's face and stat bars.
- View Fluffy's age, mood byte, and care status.
- Prevent food, fun, and energy values from leaving the `0` to `10` range.

## Mood System

Fluffy stores mood states as individual bits in one byte:

- Bit 0: asleep
- Bit 1: hungry
- Bit 2: sad
- Bit 3: sick

Mood bits are changed through the `SET_BIT` and `CLR_BIT` macros and read through `READ_BIT`. This keeps several independent states compact while allowing each mood to be checked or updated separately.

## Build and Run

Requirements:

- A C99-compatible compiler
- GCC recommended

Compile with warnings enabled:

```bash
gcc -std=c99 -Wall -Wextra fluffy_the_robot_pet.c -o fluffy_the_robot_pet
```

Run the program:

```bash
./fluffy_the_robot_pet
```

On Windows PowerShell, run:

```powershell
.\fluffy_the_robot_pet.exe
```

## Menu

1. Feed Fluffy
2. Play with Fluffy
3. Sleep or wake Fluffy
4. Let one hour pass
5. Show Fluffy's face
6. Show the pet report
0. Exit

## Project Files

- `fluffy_the_robot_pet.c` - Complete C implementation.
- `Five_C_Practice_Projects.md` - Original practice-project brief.
- `README.md` - Project description, usage, and build instructions.
