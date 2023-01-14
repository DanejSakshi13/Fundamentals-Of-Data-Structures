Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort 

marks = [6.7,4.21,9.1,2.45,0,5.5]     #marks can be taken from user aswell
def selectionSort(marks):
    for i  in range(len(marks)):
        minIndex = i
        for j  in range(i+1 , len(marks)):
            if marks[minIndex] > marks[i]:
                minIndex = j
        marks[i],marks[minIndex] = marks[minIndex] , marks[i]
    
    for i in range(len(marks)):
        print(marks[i])

def bubbleSort(marks):
    n = len(marks)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if(marks[j]>marks[j+1]):
                marks[j],marks[j+1]=marks[j+1],marks[j]
    for i in range(len(marks)):
        print(marks[i])

ch=0
while(ch!=3):
    ch = int(input("Enter choice : "))
    if(ch==1):
        bubbleSort(marks)
    elif (ch==2):
        selectionSort(marks)
    elif (ch==3):
        print("See you")
    else:
        break


