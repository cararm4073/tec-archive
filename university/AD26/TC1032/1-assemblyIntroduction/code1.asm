//$X = \frac{(A + B)^2}{C - D} \times (B + C)$

//using 3-adress
ADD T1, A, B
MPY T2, T1, T1
SUB T3, C, D
ADD T4, B, C
DIV T5, T2, T3 //this can fail if the div is 0
MPY RESULT, T5, T4


