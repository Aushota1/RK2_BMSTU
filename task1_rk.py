
A = '101101'
B = '110011'

a_int = int(A, 2)
b_int = int(B, 2)

and_result = a_int & b_int


sum_result = a_int + b_int

and_result_bin = bin(and_result)[2:]  
sum_result_bin = bin(sum_result)[2:]  

print("Результат побитовой операции AND:", and_result_bin)
print("Сумма чисел:", sum_result_bin)

