# Topic: "Programación avanzada"

This repo constains the final project and some exercises developed during my last year of high school for this topic course.

It mainly contains some basic instructions for SQL and a python game with logic that can run on real hardware.


## 1. Some SQL Fundamentals 

> [!IMPORTANT]  
> All names, ages, e-mails and any other "personal information" or records contained in the SQL files of this repo were created with an academical purpose. Any coincidence with real data is purely coincidential.

Essential concepts for database administration and data manipulation were covered. Some of the queries put into practice were:

* **Data Definition:**
    *   `CREATE DATABASE` and `DROP DATABASE`
* **Data Manipulation:**
    *   `INSERT INTO`
    * `SELECT`: Filtering data with the use of `WHERE` and `ORDER BY`

## 2. Python snake (sense hat)

> [!IMPORTANT]  
> This challenge was developed as a collaborative team project. 

This is a basic version of the classic Snake game on Python.

The code was made and tested to work on a **Raspberry Pi** with the $8\times 8$ LED matrix of the Sense HAT. Tho the code can be run too on any online emulator for the *Sense HAT* (if any error is show, just comment such line).

### Game mechanics and features
* **Infinite screen:** The snake does not disappear nor die when hitting any of the edges of the LED matrix. It rather appears on the opposite side by using the modulo operator `% 8`
* **Control the snake with real hardware:** You can use the Sense HAT joystick to control the snake on the matrix.
* **Eating mechanic:** You can eat 3 vegetables that are show as green LEDs, which will make your snake grow up one LED. Such vegetables are randomly placed on the matrix.
* **Increasing difficulty:** As your snake progressively grows, it becomes larger. The delay value (which makes the whole game slow down) also reduces, making the whole game speed-up.
* **Collisions:** If the snake's head gets in touch with its body, the `game_over()` function is triggered, which shows your final score and restarts the game.

### Some features that could be added
* Different head color.
* Sometimes the food appears on top of the snake. Make it so the function `snake_veg()` checks where the vegetables can and will spawn.
* Basically re-do the code with a OOP perspective instead of relying on global variables.