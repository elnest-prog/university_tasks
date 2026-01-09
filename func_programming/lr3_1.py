def count_lucky_tickets(num_digits):

    if num_digits % 2 != 0:
        return "Количество цифр должно быть четным."
    
    half_digits = num_digits // 2
    max_sum = 9 * half_digits
    
    def count_sum_combinations(n, s):
        if n == 0:
            return 1 if s == 0 else 0
        if s < 0:
            return 0
        
        def sum_digits(digit, acc):
            if digit > 9:
                return acc
            count = count_sum_combinations(n - 1, s - digit)
            return sum_digits(digit + 1, acc + count)
        
        return sum_digits(0, 0)
    
    def count_lucky_recursive(current_sum, total):
        if current_sum > max_sum:
            return total
        
        count_for_sum = count_sum_combinations(half_digits, current_sum)
        total += count_for_sum * count_for_sum
        return count_lucky_recursive(current_sum + 1, total)
    
    result = count_lucky_recursive(0, 0)
    return result



# Для 2 цифр должно быть 10
print("Тест для 2 цифр:", count_lucky_tickets(2))

# Для 4 цифр должно быть 670
print("\nТест для 4 цифр:", count_lucky_tickets(4))

# Для 6 цифр должно быть 55252
print("\nТест для 6 цифр:", count_lucky_tickets(6))