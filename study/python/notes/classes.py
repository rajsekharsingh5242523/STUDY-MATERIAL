from dataclasses import dataclass

#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#====================== dataclass =======================
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━

@dataclass  #here the dataclasses file contain a class dataclass .what is does it does the first boring self automaticaly
class Robot:
    name=str
    position=[0,0]

    def motion(self,x,y):
        self.position[0] += x
        self.position[1] += y
        print('New position is:', self.position)

    def eat(self):
        print("I am hungry !.FOOOOOooooood")


#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
#================= class inherentance ===================
#━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
class RobotDog(Robot):      #childclass(parent class name)
    """
    Child class that inherits from Robot and adds dog-like behavior.
    """

    def make_noise(self):
        """
        RobotDog makes a barking sound.
        """
        print('Woof Woof!')

    def eat(self):
        """
        Override the eat method to add custom dog-like behavior.
        """
        super().eat()            # Call the parent class's eat method first
        print('I like bacon!')   # Add extra behavior specific to RobotDog


dog1=Robot()
dog2=RobotDog()
dog1.motion(2,3)
dog2.motion(5,4)
dog2.make_noise()
dog2.eat()
