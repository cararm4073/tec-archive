/Fill 6 memory addresses with previous + 1, starting from first

/Start
         Load BaseAddr      /Load first mem address
         Store Ptr          /Ptr = BaseAddr

         LoadI Ptr          /Read the first number indirectly from memory
         Store CurrVal      /Save it as the current value
         Output             /Output the 1st number

         Load Five          /5 remaining slots
         Store Count        /Start loop 

/Loop
Loop,    Load Ptr           /Load current pointer address
         Add One            /Ptr+1, move to next address
         Store Ptr          /Save ptr+1

         Load CurrVal       /Load previous number's value
         Add One            /previous + 1
         Store CurrVal      /Update CurrVal
         StoreI Ptr         /Write no next memory address 
         Output             /Output new stored number

         Load Count         /Load remaining count to ac
         Subt One           /count-1
         Store Count        /update Count
         Skipcond 800       /Count > 0? If yes, skip next line
         Jump EndLoop       /If Count == 0, exit loop
         Jump Loop          /Continue in loop

/Halt program
EndLoop, Halt

/Vars
Ptr,      DEC 0             / Address 016: Pointer to current memory location
CurrVal,  DEC 0             / Address 017: Holds current value being written
Count,    DEC 0             / Address 018: Counter for the 5 remaining slots
One,      DEC 1             / Address 019: Constant 1
Five,     DEC 5             / Address 01A: Constant 5 (number of slots to fill)
BaseAddr, ADR Seq           / Address 01B: Address of the 1st location of Seq (01C)

/Numbers used
Seq,      DEC 10            /Initial value = 10)
          DEC 0             /Will become 11
          DEC 0             /Will become 12
          DEC 0             /Will become 13
          DEC 0             /Will become 14
          DEC 0             /Will become 15
