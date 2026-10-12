//$X = \frac{(A + B)^2}{C - D} \times (B + C)$

//using 2-adress
MOVE T1, A
ADD T1, B
MPY T1, T1

MOVE T2, C
SUB T2, D

MOVE T3, B
ADD T3, C

MOVE T4, T1
DIV T4, T2

MOVE T5, T4
MPY T5, T3