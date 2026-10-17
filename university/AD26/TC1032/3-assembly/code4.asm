/Invert (Reverse) the content of 4 memory locations

/Swap outter part
         Load V1            /AC = V1
         Store Temp         /Temp = V1
         Load V4            /AC = V4
         Store V1           /V1 = V4
         Load Temp          /AC = Temp
         Store V4           /V4 = V1

/Swap inner part
         Load V2            /AC = V2
         Store Temp         /Temp = V2
         Load V3            /AC = V3
         Store V2           /V2 = V3
         Load Temp          /AC = Temp
         Store V3           /V3 = V2

/Output, in order, the new-arrangement of the data
         Load V1
         Output 
         Load V2
         Output 
         Load V3
         Output
         Load V4
         Output

         Halt               / Address 014: Stop execution

/ Values to be exchanged
V1,      DEC 10             /Outter: Becomes 40
V2,      DEC 20             /Inner: Becomes 30
V3,      DEC 30             /Inner: Becomes 20
V4,      DEC 40             /Outter: Becomes 10

/Temp var
Temp,    DEC 0
