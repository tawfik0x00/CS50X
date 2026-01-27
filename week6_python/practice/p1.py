class Student():
    
    def __init__(self, name, id):
        self.name = name
        self.id = id


    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))


s1 = Student("Mohamed", "2002")
s1.print()
