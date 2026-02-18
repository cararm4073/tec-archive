#Fernanda Valentina Padrón Hernández - A01663795
#Carlos Colmenares Acosta - A01663510
#Rebecca Campos Díaz - A01662979


#file = "/Users/fervalph/Desktop/miTec/Semestre 1/Computational Thinking for Engineering/Capstone Project/seating.txt" #variable if using Mac
file = "seating.txt" #variable if using Windows
import time 

#Will print the matrix with the seats
def print_matrix(matrix):
    print("\nCurrent chosen classroom:\n")
    for row in matrix: #Following the logic from past codes to create nxn matrixes
        show_row = []
        for seat in row:
            if seat == '.':
                show_row.append('EMPTY')
            else:
                show_row.append(seat)
        print(' | '.join(show_row)) #PREGUNTAR SI SE PUEDE USAR JOIN
    print("\n") #To continue correctly with the print

#Will sfind the position of any student's name
def position(matrix,student):
    for i in range(len(matrix)): #rows
        for j in range(len(matrix[i])): #columns
            if student in matrix[i][j]: #Will search the student's name in the matrix
                return (i, j) #Will return the coordinates 
    return None #If not found, None, will be returned

#Mark someone as present
def mark(matrix, present_list):
    print("\nMark present selected!") 
    time.sleep(0.5)
    print_matrix(matrix)
    while True:
        #matrix is the original one from the .txt file, present_list is a new matrix where we will store wether someone is present or not
        student = input("\n\n    Write the student's name: ").capitalize()
        position_student = position(matrix, student) #Get the position of the student from the original matrix, calling position function
        
        if position_student == None: #If the student is not found
            time.sleep(0.5)
            print(f"\n    Error. {student} was not found on the list. Try again.\n")
            continue
        else: #If the student is found
            row, column = position_student
            
            if student not in present_list:
                present_list.append(student)
                time.sleep(0.5)    
                print(f"\n    {student} marked present at row {row}, column {column}.\n")
            else:
                time.sleep(0.5)
                print(f"\n    {student} is already marked as present (at row {row}, column {column}).\n")
        
            
            time.sleep(0.5)
            print("\n    Returning to the menu...")
            time.sleep(0.7)
            return #To quit correctly the function

#Swap seats between students
def swap(matrix):
    print("\nSwap seats selected!\n")
    while True: 
        time.sleep(0.5)
        print_matrix(matrix)
        student_1 = input("\n    Write the first student name: ").capitalize()
        position_student_1 = position(matrix, student_1)
        student_2 = input("\n    Write the second student name: ").capitalize()
        position_student_2 = position(matrix, student_2)
        if position_student_1 == None:
            print(f"\n    Error. {student_1} was not found on the list. Try again.\n")
            continue
        elif position_student_2 == None:
            print(f"\n    Error. {student_2} was not found on the list. Try again.\n")
            continue
        elif student_1 == student_2:
            print("Make sure to select two different studets with different seats.")
            continue
        else:
            row_1, column_1 = position_student_1
            row_2, column_2 = position_student_2
            matrix[row_1][column_1] = student_2
            matrix[row_2][column_2] = student_1
            print_matrix(matrix)
            time.sleep(3)
            break 
        
    print("\n    Returning to the menu...")
    time.sleep(0.5)
    return  #To quit correctly the function

#Mark as empty a student's place from a .
def empty(matrix):
    print("\nMove student to empty seats selected!\n")
    
    while True:
        time.sleep(0.5)
        print_matrix(matrix)
        
        try:
            student = input("\n    Write the student's name you want to change into this empty seat: ").capitalize()
            position_student = position(matrix, student)
            rows = int(input("\n    Write the row of the empty position [0-based]: "))
            columns = int(input("\n    Write the column of the empty position [0-based]: "))
            
            #Error management
            if rows < 0 or columns < 0:
                print("\nMake sure to write a value greater than 0 for the index of the seats.\n")
                continue
            elif rows > 2 or columns > 2:
                print("\nError. Make sure to write an index between 0 and 2 for the index of the matrix.\n")
                continue
            elif position_student == None:
                print(f"\nError. {student} is not in the current classroom. Try again.\n")
                continue
            else:
                pass  
        
        except ValueError:
            print("\nMake sure to write only numbers to select the empty seat.\n")
            continue
        
        #From the matrix, get the coordinates and change the value to "." = empty
        row_student, column_student = position_student
        if matrix[rows][columns] == '.':
            matrix[rows][columns] = student
            matrix[row_student][column_student] = '.'
            break
        else:
            print("\nError. This seat is not empty, try again.\n")
            continue
        
    print_matrix(matrix)
    time.sleep(3)
    print("\n    Returning to the menu...\n")
    time.sleep(0.5)
    return  #To quit correctly the function

#Stats from the whole exercise, shown if the program is exited or saved        
def stats(matrix,present_list):
    print("\nShow stats selected!\n")
    time.sleep(0.5)
    print_matrix(matrix)
    
    #Count empty seats
    empty_count = 0
    for row in matrix:
        for seat in row:
            if seat == '.': #From original file, if a . is found, add 1 to the empty counting
                empty_count += 1
    
    print(f"Empty seats: {empty_count}")
    print(f"Present today: {len(present_list)}")
    
    time.sleep(2)
    print("\n\n    Returning to the menu...")
    time.sleep(0.5)
    return


def save(matrix, present_list):
    #Update original file
    with open(file, 'w', encoding='utf-8') as update:
        for row in matrix: #Every row from the matrix
            line = ','.join(row) #Joins row elements with ,
            update.write(line + '\n') #Write each row of elements in the file,  
    
    #Save summary file, stats shown if function stats is run
    with open('summary.txt', 'w', encoding='utf-8') as save: #It's going to create and save the file in the same folder
        #Calculate stats
        total_seats = sum(len(row) for row in matrix)
        empty_count = sum(1 for row in matrix for seat in row if seat == '.')
        occupied = total_seats - empty_count
        
        #Content of the file
        save.write("=== CLASSROOM SUMMARY ===\n\n")
        save.write(f"Total seats: {total_seats}\n")
        save.write(f"Seats occupied: {occupied}\n")
        save.write(f"Empty seats: {empty_count}\n")
        save.write(f"Present today: {len(present_list)}\n\n")
        save.write("Students present:\n")
        for student in sorted(present_list):
            save.write(f"  - {student}\n")
    
    print("\n    Seating chart and summary saved successfully!")
    print("\n    Goodbye!")
    return


def menu():
    with open(file, 'r', encoding='utf-8') as seating: #MAC
    
        matrix = []
        present_list: list[str] = []
        #File settings, matrix
        for line in seating: #For every "line" in the file "seating", do:
            line = line.strip()  #Delete special format
            row = line.split(',')  #Add comas per row
            matrix.append(row)  #Add the new rows to the matrix
    
    while True:
        print("\n -- Start -- ")
        print_matrix(matrix)
        time.sleep(0.5)
        print("\n-- MENU --")
        time.sleep(0.5)
        print("1) Mark present")
        print("2) Swap seats")
        print("3) Move student to empty seat")
        print("4) Show stats")   
        print("5) Save & Exit")
        print("\nWrite either the name of the option, the number or press enter to save & exit.")
        time.sleep(0.5)
        selection = input("\nSelect one of the options above: ").lower()

        if selection == "1" or selection == "mark present":
            mark(matrix,present_list)
            
        elif selection == "2" or selection == "swap seats":
            swap(matrix)
            
        elif selection == "3" or selection == "move student to empty seat":
            empty(matrix)

        elif selection == "4" or selection == "show stats":
            stats(matrix, present_list)

        elif selection == "5" or selection == "save & exit" or selection == "":
            save(matrix, present_list)
            break
        
        else:
            print("Remember to chose one option from the menu.\n")
            time.sleep(1)
            continue

menu() #Call the main function, the menu 
