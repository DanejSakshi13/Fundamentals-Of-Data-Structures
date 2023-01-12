row=int(input("Enter the no. of rows :"))
col = int(input("Enter the no. of columns :"))
mat1=[]
mat2=[]
sum_mat=[]
sub_mat=[]
multi_mat=[]
trans_mat=[]

print("Matrix is of the form : e.g.- a11 a12 a21 a22")

#Input of Elements of 1st Matrix
print("\nENTER ELEMENTS OF 1st MATRIX\n")
for i in range(row):
	colms = []
	for j in range(col):
		ele = int(input("Enter element :"))
		colms.append(ele)
	mat1.append(colms)
	
#Input of Elements of 2nd Matrix	
print("\nENTER ELEMENTS OF 2nd MATRIX\n")
for i in range(row):
	colms = []
	for j in range(col):
		ele = int(input("Enter element :"))
		colms.append(ele)
	mat2.append(colms)
	
#Addition of Matrices
def addition():
	for i in range(row):
		for j in range(col):
			summ=mat1[i][j]+mat2[i][j]
			sum_mat.append(summ)
	print(sum_mat)

#Subtraction of Matrices
def subtraction():
	for i in range(row):
		for j in range(col):
			minus=mat1[i][j]-mat2[i][j]
			sub_mat.append(minus)
	print(sub_mat)

#Multiplication of Matrices
def multiplication():
	for i in range(row):
		multi=0
		for j in range(col):
			for k in range(row):
				multi+=(mat1[i][k]*mat2[k][j])
			multi_mat.append(multi)
			multi=0
	print(multi_mat)

#Transpose of Matrices
def transpose():
	for i in range(row):
		for j in range(col):
			trans_mat.append(mat1[j][i])
	print(trans_mat)
			
ch = 0
while (ch != 5):

    print("Enter your choice: ")
    print("1. Addition \n2. Subtraction \n3. Multiplication \n4. Transpose \n5. Exit")
    ch = int(input())

    if (ch == 1):
        addition()

    elif (ch == 2):
        subtraction()

    elif (ch == 3):
        multiplication()

    elif (ch == 4):
        transpose()

    elif (ch == 5):
        break;
