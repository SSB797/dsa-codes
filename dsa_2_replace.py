from ast import If


MAX = 100
 
class Node:
   def __init__(this, data, next):
       this.data = data
       this.next = None
 
def insert(head, x):
   if (head == None):
       head = Node(x, None)
       return head
 
   temp = head
   while (temp.next != None):
       temp = temp.next
   temp.next = Node(x , None)
   return head
 
def display(head):
   temp = head
   while (temp.next != None):
       print(temp.data, end="-->")
       temp = temp.next
   print(temp.data)
 
class HashTable:
   ht = []
   def __init__(this):
       for i in range(MAX):
           dummy = Node([-1,-1], None)
           this.ht.append(dummy)
 
   def hash(this, name):
       sum = 0
       for i in name:
           sum += ord(i)
       return sum % MAX
 
   def insert(this, name, phone_number):
       record = [name, phone_number]
       index = this.hash(name)
       node = this.ht[index]
       insert(node, record)
 
   def display(this):
       for i in range(MAX):
           if (this.ht[i].next == None):
               continue
           node = this.ht[i].next
           while (node != None):
               print("[" , node.data[0] , "," , node.data[1] , "]", end="-->")
               node = node.next
           print()
 
   def find(this, name):
       index = this.hash(name)
       node = this.ht[index]
       if (node.next == None):
           print("Record is not present in the dictionary!")
       else:
           flag = False
           while (node != None):
               if (node.data[0] == name):
                   flag = True
                   print("Record found!")
                   print("Phone number is", node.data[1])
               node = node.next  
           if (flag == False):
               print("Record not found!")
 
   def delete(this, name):
      index = this.hash(name)
      if (this.ht[index].next == None):
          print("Record to be deleted is not present in the dictionary")
      else:
          node = this.ht[index]
          while (node.next.data[0] != name):
              node = node.next
          node.next = node.next.next
 
 
 
ht = HashTable()


a=1
while(a != 0):
    print("\n\n1)Insert\n2)Display\n3)Find\n4)Dlete\n5)Exit")
    c = int(input())
    if c == 1:
        print("Enter the name :")
        nm = input()
        print("Enter the no. :")
        numb = int(input())
        ht.insert(nm,numb)
    if c ==2:
        ht.display()
    if c == 3:
        print("Enter the name  you want to find :")
        nm = input()
        ht.find(nm)
    if c == 4:
        print("Enter the name you wan to delete :")
        nm = input()
        ht.delete(nm)
    if c == 5:
        a =0