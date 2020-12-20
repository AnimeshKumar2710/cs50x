from cs50 import get_string


text = get_string("Enter the text:")
i = 0
words = 1
letters = 0
sentences = 0
for i in text:
    if i == " ":
        words += 1
    elif i == "." or i == "?" or i == "!":
        sentences += 1
    elif i.isalpha() == True:
        letters += 1
L = letters / words
S = sentences / words
index = 005.88 * L - 029.6 * S - 15.8
    
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {int(index + 0.5)}")
        
