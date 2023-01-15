"""Write a Python program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort"""

n = int(input("Enter the number of students:"))
marks = []
for i in range(n):
     print("Enter the marks :")
     m = int(input())
     marks.append(m)
print("Marks :" , marks , end = " ")


def insertion(marks):
    for i in range(1,len(marks)):
        key = marks[i]
        j = i - 1
        while j>=0 and key<marks[j]:
            marks[j+1] = marks[j]
            j=j-1
            marks[j+1] = key
insertion(marks)
print("\nSorted array using insertion sort: " , marks)


def shell(marks,n):
    n = len(marks)
    gap = n//2
    while gap>0:
        j = gap
        while j<n:
            i = j - gap
            while i>=0:
                if marks[i+gap]>marks[i]:
                    break
                else:
                    marks[i+gap],marks[i]=marks[i],marks[i+gap]
                i = i - gap
            j = j + 1
        gap = gap//2
shell(marks,len(marks))
print("Sorted array using shell sort:" , marks)
