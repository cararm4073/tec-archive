
/ Length of a known string in memory

         Clear              /AC=0
         Store Count        /Count = 0
         Load StrAddr       /Address where string starts in memory
         Store Ptr          /Save in Ptr

/Read memory
Loop,    LoadI Ptr          /Load character at Ptr
         Skipcond 400       /If AC == 0, skip next line of code
         Jump NextChar      /If false, restart the loop
         Jump EndLoop       /If true, exit loop

/LOop
NextChar, Load Count        /Load current counter value
         Add One            /Add 1
         Store Count        /Store new value

         Load Ptr           /Load current pointer address
         Add One            /Add 1 to pointer
         Store Ptr          /Store new pointer
         Jump Loop          /Repeat loop 

/Load into AC the counter and display
EndLoop, Load Count         /Load counter of string length
         Output             /Display in output register
         Halt               

/Variables
Ptr,     DEC 0              /Pointer to current memory
Count,   DEC 0              /String length counter
One,     DEC 1              /Increment value
StrAddr, ADR String         /Starting memory address of string

/String to be read: "HELLO"
String,  HEX 0048           / 'H'
         HEX 0045           / 'E'
         HEX 004C           / 'L'
         HEX 004C           / 'L'
         HEX 004F           / 'O' 
