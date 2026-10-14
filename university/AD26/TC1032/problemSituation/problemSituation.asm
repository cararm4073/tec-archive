/ MARIE program: store 50 sensor readings (of 12 bits each) in memory.

/ NOTE: The structure of this program (indirect addressing, subroutines,
/ and the Skipcond loop) is based on two tutorials by TickQ (2023)
/ - TickQ (2023). Video on indirect addressing and subroutines in MARIE.
/   https://www.youtube.com/watch?v=kqZkMRH_U48
/ - TickQ (2023). Video on loops in MARIE.
/   https://www.youtube.com/watch?v=zvxdEHPG5oc
/ Most of the ideas and concepts were taken from both videos. 
/ Changes on this code: replaced the condition in which if a value is 0, the program terminates both reading and printing 
/ Added counters: count, pcount. These help keep reading values from the sensore, even if a reading is 0

/ Main program
JnS subRead		/subroutine to read 50 data
JnS subPrint	/subroutine to print the read data
Halt			/complete program

/------------------------------------------
/Subroutine that read an Input and stores it

/ This is the pointer, memory address where the next reading will be stored
readFrom,   HEX 0
/ New: Reading counter that starts at 0. Inside the subRead it is set to 50 and decreases
count,      DEC 0

subRead,    HEX 0				/ Saves the address for main program
            Load startAdr		/ Loads buffer (address 0x070) into AC
            Store readFrom		/ readFrom poins to the beginning of the buffer
            Load n				/ New: set the counter to 50 and load them into AC
            Store count			/ Initialize counter to 50

startInput, Input
            StoreI readFrom     / Keep whatever is in AC at addres of readFrom   
            Load readFrom       /Move the pointer to the next address
            Add One				/Move the pointer address
            Store readFrom      /Update pointer
            Load count          /Load the counter into the AC
            Subt One			/Drecrement counter by one
            Store count			/Update the value of the counter in memory
            Skipcond 400        / Checks if input, AC, == 0, skip next line
            Jump startInput     / If AC != 0, increment pointer
            JumpI subRead       / If AC == 0, increment pointer

/------------------------------------------
/Subroutine for printing values

printFrom,  HEX 0       		/ Pointer with memory address of current value
pcount,     DEC 0               /new: Printing counter

subPrint,   HEX 0				/Store return address to main
            Load startAdr		/ Loads buffer (address 0x070) into AC
            Store printFrom		/ printFrom points to the start of the buffer
            Load n              /Load the 50 readings into AC
            Store pcount		/Start counter at 50

startPrint, LoadI printFrom		/ load value from address in printFrom to AC
            Output				/ send value from AC to output register
            Load printFrom		/ Load current pointer address to AC
            Add One				/ Increment pointer/address
            Store printFrom		/ Update pointer to the next address
            Load pcount         /new: pcount--
            Subt One			/ Decrement counter by one
            Store pcount		/ Update counter in memory
            Skipcond 400        / If AC==0, skip next program's line
            Jump startPrint     / If AC!=0, print the value
            JumpI subPrint      / If AC==0, everything got printed, return to main program

/Variables
One,        DEC 1				/Constant DECIMAL value of 1 for pointers and counters
n,          DEC 50      		/number of readings to store and print
startAdr,   HEX 070				/Memory addresses for data buffer (from 0x070 to 0x0A1)
