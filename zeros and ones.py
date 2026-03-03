import numpy

shape_str = input().split()

shape_tuple = tuple(map(int, shape_str))

zeros_array = numpy.zeros(shape_tuple, dtype=int)

ones_array = numpy.ones(shape_tuple, dtype=int)

print(zeros_array)

print(ones_array)
