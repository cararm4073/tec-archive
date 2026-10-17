/Y = 5 * (A - B + C)

/Temp = (A - B + C)
         Load A             /AC = A
         Subt B             /AC = A - B
         Add C              /AC = A - B + C
         Store Temp         /Save final result

/Y = 5 * Temp
         Add Temp           /AC = 2 * Temp
         Add Temp           /AC = 3 * Temp
         Add Temp           /AC = 4 * Temp
         Add Temp           /AC = 5 * Temp
         Store Y            /Save final result

/Display result
         Output             /Display final reuslt
         Halt

/Test vars for A B and C
A,       DEC 10             /A = 10
B,       DEC 7              /B = 7
C,       DEC 13             /C = 13

/Temp var and final result
Temp,    DEC 0              /A - B + C
Y,       DEC 0              /Final result
