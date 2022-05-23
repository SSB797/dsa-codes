class hasht:
    arry = []
    for i in range(10):
        a = [-1, -1]
        arry.append(a)

    def insert(self, no):
        index = no % 10
        if self.arry[index][0] == -1:
            self.arry[index][0] = no
        else:
            t = index + 10
            while(self.arry[index % 10][1] != -1 and t > index):
                index = self.arry[index % 10][1]
            tmpi = index
            if index == t:
                print("Hash table is full")
                return
            else:
                t = index + 10
                while(self.arry[index % 10][0] != -1 and t > index):
                    index = index + 1
                if index == t:
                    print("Hash table is full")
                    return
                self.arry[index % 10][0] = no
                self.arry[tmpi % 10][1] = index%10

    def printht(self):
        for i in range(10):
            print(i, "  ", self.arry[i][0], "  ", self.arry[i][1])

    def find(self,no):
        index = no%10
        if self.arry[index][0] == no:
            print("No found ")
        else:
            t = 0
            while(self.arry[index%10][0] != no and t <10):
                index = self.arry[index%10][1]
                t = t+1
            if self.arry[index][0] == no:
                print("No found ")
            else:
                print("No is not present in hash table ")


    def delteno(self,no):
        index = no%10
        if self.arry[index][0] == no:
            print("No found ")
            self.arry[index][0] = -1
            print("no deleted")
        else:
            t = 0
            lindex = index
            while(self.arry[index%10][0] != no and t<10):
                lindex = index
                index = self.arry[index%10][1]
                t = t+1
            if self.arry[index][0] == no:
                print("No found ")
                self.arry[lindex%10][1] = self.arry[index%10][1]
                self.arry[index%10][0]  = -1
                print("no deleted")
            else:
                print("No is not present in hash table ")

           
            
                


p1 = hasht()
c = -1
while c != 5:
    print("Enter 1 to add the no \nEnter 2 to display hashing table \nEnter 3 to find  \nEnter 4 to delet\nEnter 5 to exit")
    c = int(input())
    if c == 1:
        print("Enter the no you want to insert : ")
        num = int(input())
        p1.insert(num)
    if c == 2:
        p1.printht()
    if c == 3:
        print("Enter the no you want to Find : ")
        num = int(input())
        p1.find(num)
    if c == 4:
        print("Enter the no you want to Delete : ")
        num = int(input())
        p1.delteno(num)