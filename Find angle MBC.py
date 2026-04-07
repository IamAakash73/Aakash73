import math

# Input the lengths of sides AB and BC
ab = int(input())
bc = int(input())

# In a right triangle ABC with right angle at B, 
# the median to the hypotenuse AC (which is BM) 
# is equal to half of the hypotenuse.
# Therefore, BM = MC, making triangle MBC isosceles.
# Thus, angle MBC = angle MCB (angle BCA).

# Calculate the angle using the arctangent of (AB/BC)
# math.atan2(ab, bc) provides the angle in radians
angle_radians = math.atan2(ab, bc)

# Convert radians to degrees
angle_degrees = math.degrees(angle_radians)

# Round to the nearest integer and append the degree symbol
# Using round() and then int() ensures correct rounding behavior
print(f"{round(angle_degrees)}{chr(176)}")
