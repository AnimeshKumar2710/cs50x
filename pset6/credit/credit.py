from cs50 import get_int


def main():

    card = get_int("Enter the Credit Card number: ")
    if card > 0:
        temp = card
        count = 0
        
        while temp > 0:
            temp = temp // 10
            count += 1
            
        if count in range(12, 18):
            Card(card, count)

        else:
            print("INVALID")

    else:
        print("INVALID")


def Card(card, count):
    i = 0
    finalsum = 0
    cardcompany = ""
    for i in range(count):
        digit = card % 10
        
        card //= 10
        
        if i % 2 == 0:
            finalsum += digit
        elif digit * 2 > 9:
            finalsum += ((digit * 2) // 10) + ((digit * 2) % 10) 
        else:
            finalsum += digit * 2
        
        if card == 34 or card == 37:
            cardcompany = "A"
        elif card < 56 and card > 50:
            cardcompany = "M"
        elif card == 4:
            cardcompany = "V"

    if finalsum % 10 == 0:
        if cardcompany == "A" and count == 15:
            print("AMEX")
        elif cardcompany == "M" and count == 16:
            print("MASTERCARD")
        elif cardcompany == "V" and count == 13:
            print("VISA")
        elif cardcompany == "V" and count == 16:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()

