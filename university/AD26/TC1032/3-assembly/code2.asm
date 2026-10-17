/Calculate Y = X - 2*A - 3*B - 4*C 

/Calculate 2*A
         Load A             /AC = A
         Add A              /AC = 2 * A
         Store TwoA         /Save 2*A 

/Calculate 3*B
         Load B             /AC = B
         Add B              /AC = 2 * B
         Add B              /AC = 3 * B
         Store ThreeB       /Save 3*B 

/Calculate 4 * C
         Load C             /AC = C
         Add C              /AC = 2 * C
         Add C              /AC = 3 * C
         Add C              /AC = 4 * C
         Store FourC        /Save 4*C 

/Calculate Y, final result
         Load X             /AC = X
         Subt TwoA          /AC = X - 2*A
         Subt ThreeB        /AC = X - 2*A - 3*B
         Subt FourC         /AC = X - 2*A - 3*B - 4*C
         Store Y            /Store final result from previos operations

/Display in output log
         Output             /Display Y
         Halt               

/Input vars with given vals
X,       DEC 30             /Sample X = 30
A,       DEC 20             /A = 20
B,       DEC 15             /B = 15
C,       DEC 22             /C = 22

/Vars for multiplications
TwoA,    DEC 0              /Holds 2*A
ThreeB,  DEC 0              /Holds 3*B
FourC,   DEC 0              /Holds 4*C
Y,       DEC 0              /Holds final result
