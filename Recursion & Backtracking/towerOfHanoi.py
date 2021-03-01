def tower_of_hanoi(n, start, end):
    
    #base case
    if(n == 1):
        print(start, end)
    else:
        #find the other rod
        other = 6 - (start + end)

        #move n - 1 disks to the other node
        tower_of_hanoi(n - 1, start, other)

        #move the last node to end rod
        print(start, end)

        #move those n - 1 rods from other to end
        tower_of_hanoi(n - 1, other, end)

tower_of_hanoi(3, 1, 3)
