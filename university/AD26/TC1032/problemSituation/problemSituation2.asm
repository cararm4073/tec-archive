/ MAIN PROGRAM
Main,		JnS subRead		/subroutine for reading data
			JnS subAvg		/subroutine for the division
			Load avg		/loads the calculated avg from AC
			Output			/display result
			Halt

/ READING SUBROUTINE
/reads from InREG, making sure that SEL, pin 15 = 0, choosing sensor 1
/store 10 readings/values into consecutive memory addresses

subRead, 	HEX 0			/return address
			Load startAdr	/loads base address, 0x060
			Store ptr		/store that address into ptr
			Load n			/load the number of readings. n is set to 10 for this code
			Store count		/store that number into counter

readLoop, 	Input			/reads value from inreg into AC
			Skipcond 000	/check if AC < 0. if bit 15 is 1, we are working with sensor 2, jump next line
			Jump isValid	/if AC >= 0, bit 15 is 0, we are working with sensor 1, process data
			Jump readLoop	/if sensor 2 was selected, discard

isValid, 	StoreI ptr		/stores the 12 bits value into ptr's address
			Load ptr		/get address of pointer
			Add one			/move to the next address
			Store ptr		/update with new address
			Load count		/get counter for remaining readings
			Subt one		/substract one
			Store count		/update with remaining readings
			Skipcond 400 	/if count == 0, all readings done, jump next line
			Jump readLoop	/if it is not 0, jump back to get remaining readings
			JumpI subRead	/return to main program

/ SUBROUTINE FOR AVERAGE
/takes all 10 readings, and divides them by 10: sum/10

subAvg, 	HEX 0 /return address
			Load startAdr	/restarts the pointer into the starting address, 0x060
			Store ptr		/store into pointer
			Load n			/set counter to 10
			Store count		/store it into counter var
			Load zero		/clear previous value from sum
			Store sum		/update value
			Load zero		/set quotient to 0
			Store quotient	/update value 

sumLoop,    Load sum		/load sum value into ac, should be 0
            AddI ptr        /sum value from pointer
            Store sum		/store value
            Load ptr        /move to next address
            Add one
            Store ptr		
            Load count      /counter decreases, starting at 10, by 1 unit
            Subt one		
            Store count	
            Skipcond 400	/if count==0, stop summing
            Jump sumLoop    /keep on summing values

divLoop, 	Load sum		/loads current value stored, should be 10
			Subt ten		/substracts 10. the divider
			SkipCond 000	/if sum-10 < 0, avoid illegal "division", jumps next line
			Jump contDiv	/if sum-10 >=0, continue with "division"
			Jump endDiv		/if sum-10 < 0, end "division"

contDiv, 	STORE sum		/store the remainder from substraction
			Load quotient	/add 1 to quotient value
			Add one
			Store quotient 	/save new value
			Jump divLoop	/return to div loop. substract 10 from next reading

endDiv, 	Load quotient  	/loads final quotient, mean or average
			Store avg		/store into correct variable
			JumpI subAvg 	/return to main program		

/ VARIABLES
one, 		DEC 1			/constant 1
zero,		DEC 0			/constant 0
ten,		DEC 10			/constant 10
n, 			DEC 10			/number of readings
startAdr,	HEX 060			/first memory address where data will be stored
ptr,		HEX 0			/pointer starts in the previous memory address
count,		DEC 0			/counter for iterations, on readings
sum,		DEC 0			/counter for the summation of the readings
quotient,	DEC 0			/stores the quotient from the division
avg,		DEC 0			/stores the final result of the division, average of n readings
