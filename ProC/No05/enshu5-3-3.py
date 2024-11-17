tall = int(input("身長(cm)を入力："))
weight = int(input("体重(kg)を入力："))

def calc_bmi(tall, weight):
    return weight/(tall/100)**2

def check_bmi(bmi):
    text = f'BMI:{bmi:.2f} - '
    if (bmi < 18.5):
        print(text + "低体重")
    elif (18.5 <= bmi < 25):
        print(text + "普通体重")
    else:
        print(text + "肥満")

check_bmi(calc_bmi(tall, weight))
