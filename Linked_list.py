class node:
    def __init__(self, value):
        self.value = value
        self.next = None

class linked:
    def __init__(self):
        self.head = None

    def insert(self, value):
        if self.head == None:
            self.head = node(value)
        else:
            curr = self.head
            while curr.next != None:
                curr = curr.next
            curr.next = node(value)

    def delete(self):
        curr = self.head
        while curr.next.next != None:
            curr = curr.next
        curr.next = None

    def display(self):
        curr = self.head
        while curr:
            print(curr.value)
            curr = curr.next

    def insert_in_front(self, value):
        new = node(value)
        new.next = self.head
        self.head = new

    def delete_from_front(self):
        old = self.head.next
        self.head = None
        self.head = old

    def reverse(self):
        curr = self.head
        while curr.next != None:
            curr = curr.next
        self.head = curr


l = linked()
l.insert(5)
l.insert(6)
l.insert(7)
l.display()
print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
l.delete()
l.display()
print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
l.insert_in_front(77)
l.display()
print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>")
l.delete_from_front()
l.display()