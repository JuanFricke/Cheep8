# Cheep8

This Chip8 emulator has nothing innovative.

I'm creating this just to learn about emulation and C.
And, being the maniac I am, this is indeed the first time I've ever touched C.

## Build Instructions

To build and run Cheep8 on your system, follow these steps:

1. **Clone the repository**: Begin by cloning this repository to your local machine: `git clone https://github.com/JuanFricke/Cheep8`
2. **Compilation with Make (Recommended)**:
    - Ensure you have `make` installed. On Windows, you can install it using Chocolatey: `choco install make`. On Linux, it's usually available by default(sometimes it will not compile on linux, i will solve that after a stable windows release).
    - Open a terminal and navigate to the emulator folder.
    - Run the command `make` to compile the source code.
3. **Alternate Compilation Method - Mingw32 (Windows Only)**:
    - Mingw32 must be in your path. You can follow this [tutorial](https://www.youtube.com/watch?v=FJmwrqbYZFQ) to easily understand how to install it on your Windows 8.1 machine.
    - In the emulator folder, use `mingw32-make` in the terminal to compile the source code.
4. **Running the Emulator**:
    - This can be done by using the terminal and executing `./bin/main.exe`. Or if you aren't that cool you can just double click in the .exe file.

