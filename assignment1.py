"""Write a Python program to store marks scored in subject
“Fundamental of Data Structure” by N students in the class. Write
functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency"""

#taking marks as user input
print("Enter the number of students")
n = int(input())
marks = []
print("Enter the marks of student...(Enter -1 for absent students)")
for i in range(n):
    m = int(input())
    marks.append(m)

print("The list of students' score is: ", marks)

#to calculate average marks
def avg_score():
    total = 0
    for i in range(n):
        if (marks[i] != -1):
            total = total + marks[i]

    print("Total marks are: ", total)
    print("Average marks are: ", total / len(marks))

#to find maximum and minimum marks
def max_min():
    maxi = marks[0]
    for i in range(n):
        if (marks[i] > maxi):
            maxi = marks[i]
    print("Maximun marks obtained are: ", maxi)

    mini = maxi
    for i in range(n):
        if (marks[i] != -1):
            if (marks[i] < mini):
                mini = marks[i]
    print("Minimun marks obtained are: ", mini)

#to count number of absent students
def absent():
    cnt = 0
    for i in range(n):
        if (marks[i] == -1):
            cnt = cnt + 1
    print("The number of absent students are: ", cnt)
    
#to find marks with highest frequency
def high_freq():
    maxf = 0
    temp = marks[0]
    for i in range(len(marks)):
        freq = marks.count(i)
        if freq>maxf:
            maxf = freq
            temp = i
    print("Marks with highest frequency is: ", marks[temp])


ch = 0
while (ch != 5):

    print("Enter your choice: ")
    print(
        "1. Average marks \n2. Maximum and Minimun marks \n3. Number of absent students \n4. highest frequency marks \n5. Exit")
    ch = int(input())

    if (ch == 1):
        avg_score()

    elif (ch == 2):
        max_min()

    elif (ch == 3):
        absent()

    elif (ch == 4):
        high_freq()

    elif (ch == 5):
        break;
