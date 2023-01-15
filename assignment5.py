"""Write a Python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort"""

n = int(input("Enter the number of students:"))
marks = []
for i in range(n):
     print("Enter the marks :")
     m = int(input())
     marks.append(m)
print("Marks :" , marks , end = " ")

def selectionSort(marks):
    for i  in range(len(marks)):
        minIndex = i
        for j  in range(i+1 , len(marks)):
            if marks[minIndex] > marks[i]:
                minIndex = j
        marks[i],marks[minIndex] = marks[minIndex] , marks[i]
    
    
def bubbleSort(marks):
    n = len(marks)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if(marks[j]>marks[j+1]):
                marks[j],marks[j+1]=marks[j+1],marks[j]
    

ch=0
while(ch!=3):
    ch = int(input("\nEnter choice : "))
    if(ch==1):
        bubbleSort(marks)
        print("\nSorted array using bubble sort:" , marks)
    elif (ch==2):
        selectionSort(marks)
        print("\nSorted array using selection sort:" , marks)
    elif (ch==3):
        print("\nExit.")
    else:
        break
