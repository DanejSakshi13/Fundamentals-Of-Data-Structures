a) Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using binary search (recursive and non- recursive). 
Insert friend if not present in phonebook
b) Write a Python program to store names and mobile numbers of your friends in sorted order on names. Search your friend from list using Fibonacci/Linear search. 
Insert friend if not present in phonebook.

def accept_info(arr):
    #n=int(input("How many friends information you want to save:"))
    print("Enter friends information")
    for i in range(n):
        print("Enter detals of friend:")
        name=input("\t\tNAME: ")
        mob=input("\tMOBILE NUMBER: ")
        X=[name,mob]
        arr.append(X)
        print("Information accepted and stored succefully")
def display_info(arr,n):
    if n==0:
        print("No Record found")
    else:
        print("Friends Information")
        for i in range(n):
            print("\t "," NAME: ",arr[i][0],"\n\tMobile Number:",arr[i][1])
            print("\n")


arr=[]
n=int(input("How many friends information you want to save:"))
accept_info(arr)
display_info(arr,n)

def binaryserch(arr,x):
    first=0
    last=len(arr)-1

    while(first<=last ):
        mid=(first+last)//2
        if arr[mid][0]== x:
            return mid
        else:
            if x<arr[mid][0]:
                last=mid-1
            else:
                first=mid+1
    return -1

def fiboserch(arr,x,n):
    f1=0
    f2=1
    f3=f1+f2
    while(f3<n):
        f1=f2
        f2=f3
        f3=f1+f2
        
    offset=-1
    while(f3>1):
        
        i=min(offset+f1,n-1)
        if(arr[i]==x):
            return i
            
        elif(arr[i][0]<x):
            f3=f2
            f2=f1
            f1=f3-f2
            offset=i
        elif(arr[i][0]>x):
            f3=f1
            f2=f1
            f1=f3-f2
        else :
            return i
    return -1

#arr = [10, 20, 35, 40, 45, 68, 70, 98]
n = len(arr)
print(arr)
print("--------------------------------------------------------------------------------")
def insert():
    name=input("enter name of friend that you want to insert:")
    mob_no=input("enter mob_no:")
    list=[name,mob_no]
    arr.append(list)
    print(arr)
loop=True
while loop:
    ch=int(input("\n Enter your choice \n1.Insert a friend \n 2.Binary search .\n3.Fibo search." ))
    if(ch==1):
        insert()
    elif ch==2:
        x =(input("\nEnter element to be searched "))
        print("Element found at index:",binaryserch(arr,x))
    elif ch==3:
        x =(input("\nEnter element to be searched "))
        print("Found at index :",fiboserch(arr, x, n))
    else:
        loop=False
