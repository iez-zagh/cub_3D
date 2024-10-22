import turtle

# Set up the turtle screen
screen = turtle.Screen()
screen.bgcolor("lightblue")

# Create a turtle object
my_turtle = turtle.Turtle()
my_turtle.shape("turtle")
my_turtle.color("green")

# Move the turtle forward 100 units
my_turtle.forward(100)

# Turn the turtle 90 degrees to the left
my_turtle.left(90)

# Move the turtle forward another 100 units
my_turtle.forward(100)

# Wait for the user to click to close the window
screen.exitonclick()
