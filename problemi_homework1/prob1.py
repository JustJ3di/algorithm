class Node:
    def __init__(self,head,element):
        self.next = head
        self.name = element
        


def push(head, element):
    return  Node(head, element)

def print_list(head):
    current = head
    while current!=None:
        print(current.name)
        current = current.next

def size(head):
    current = head
    count = 0
    while current :
        current = current.next
        count += 1   
    return count


def reverse(head, m, n):
 
    # caso base
    if m > n:
        return head
 
    prev = None
    curr = head
 
    # 1. Salta i primi `m` nodi
    i = 1
    while curr is not None and i < m:
        prev = curr
        curr = curr.next
        i = i + 1
 
    # `prev` ora punta a (m-1)'esimo nodo
    # `curr` ora punta all'ennesimo nodo
 
    start = curr
    end = None
 
    # 2. Attraversare e invertire la sottolista dalla posizione `m` a `n`
    while curr is not None and i <= n:
 
        # Prendere nota del nodo successivo
        next = curr.next
 
        # sposta il nodo corrente alla `end`
        curr.next = end
        end = curr
 
        # passa al nodo successivo
        curr = next
        i = i + 1
 
    '''
        `start` points to the m'th node
        `end` now points to the n'th node
        `curr` now points to the (n+1)'th node
    '''
 
    # 3. Fissare i puntatori e restituire il nodo principale
 
    if start:
        start.next = curr
        if prev is None:        # quando m = 1, `prev` è Nessuno
            head = end
        else:
            prev.next = end
 
    return head


head = None
head = push( head, "hermo")
head = push( head, "ciro")
head = push( head, "lorenzo")
head = push(head, "marco")
head = push(head, "Alice")
head = push(head, "raffo")

print(size(head))
print_list(head)

print("\n")
reverse(head,4,6)
print_list(head)