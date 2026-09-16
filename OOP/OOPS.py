class Car:
    # class variable
    total_car = 0

    def __init__(self, brand, model):
        # encapsulation(2underscore in front)
        self.__brand=brand
        self.model=model
        Car.total_car += 1
        
    def get_brand(self):
        return self.__brand + " !"
        
    def fullname(self):
        return f"{self.__brand} {self.model}"
    
    # polymorphism
    def fuel_type(self):
        return "Petrol or diesel"

# inheritance
class ElectricCar(Car):
    def __init__(self, brand, model, battery_size):
        super().__init__(brand, model)
        self.battery_size=battery_size
        
    def fuel_type(self):
        return "Electric Charge"
    
my_car = Car("range", "rover")
print(my_car.get_brand())
print(my_car.fullname())

e_car = ElectricCar("tata","punch","55kWh")

print(e_car.fullname())
print(e_car.battery_size)

print(Car.total_car)
