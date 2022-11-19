from time import sleep
def found_rout(matrix_sol:list ,current_sol:list, r, c, matrix:list,m,n ):
    #print(f"pos = {r,c}")
    if  r == m-1 and c == n-1:   
        matrix_sol.append(current_sol)
        print(f"soluzione = {current_sol}") 
        r = 0
        m = 0
        
        
    


    if r == 0 and c == 0:
        current_sol.clear()
        current_sol.append(matrix[r][c])
        

   
    if r < m-1:#go to right
        r = r+1  
        current_sol.append(matrix[r][c]) 
        found_rout(matrix_sol, current_sol, r, c, matrix, m, n) 
        r = r-1
    
    if c < n - 1:#go down
        c = c+1   
        current_sol.append(matrix[r][c])
        found_rout(matrix_sol, current_sol, r, c, matrix,m,n)
        c = c-1
        
        
    current_sol.pop()

       
        
def main():
    m = int(input())
    n = int(input())
    matrix = []
    
    for i in range(m):
        matrix.append(n*[0])
        
    
    
    count = 1
    for i in range(m):
        for j in range(n):
            matrix[i][j] = count
            count += 1
    
    print(matrix)
    matrix_sol = []
    current_sol = []
    r = 0
    c = 0
    found_rout(matrix_sol, current_sol, r, c, matrix,m,n)
    
main()