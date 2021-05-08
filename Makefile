CC = gcc
TARGET = main
OBJECTS = main.c computerCourse.o
$(TARGET) : $(OBJECTS)
        $(CC) -o $@ $^
clean :
        rm *.o main