import math

def calculate_area(radius):
    return radius**2*math.pi

radius = input("半径を入力してください")
print(calculate_area(radius))
