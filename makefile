cc=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB1=baiscClassification.o
OBJECTS_LIB2=advancedClassificat.o
OBJECTS_LIB3=advancedClassificationRecursion.o
FLAGS= -Wall -g

# -lm links with math libreary !

# target: dependencies.....
# 	commands......

# maind: $(OBJECTS_MAIN) loops
# 	$(cc) $(FLAGS) -o maind $(OBJECTS_MAIN) libclassloops.a -lm


# builds executable
all: mains maindloop maindrc loops  
mains: $(OBJECTS_MAIN) libclassrec.a 
	$(cc) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(cc) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm

maindrc: $(OBJECTS_MAIN) libclassrec.so
	$(cc) $(FLAGS) -o maindrc $(OBJECTS_MAIN) ./libclassrec.so -lm

loops: libclassloops.a # סטטי
libclassloops.a: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIB1) $(OBJECTS_LIB2)

loopd: libclassloops.so #דינמי
libclassloops.so: $(OBJECTS_LIB1) $(OBJECTS_LIB2)
	$(cc) -shared -o libclassloops.so $(OBJECTS_LIB1) $(OBJECTS_LIB2)

recursives: libclassrec.a #סטטי
libclassrec.a: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB1) $(OBJECTS_LIB3)

recursived: libclassrec.so #דינמי
libclassrec.so: $(OBJECTS_LIB1) $(OBJECTS_LIB3)
	$(cc) -shared -o libclassrec.so $(OBJECTS_LIB1) $(OBJECTS_LIB3)

# builds main.c to main.o // builds -o not executable 
$(OBJECTS_MAIN): main.c NumClass.h
	$(cc) $(FLAGS) -c main.c
$(OBJECTS_LIB1): baiscClassification.c NumClass.h
	$(cc) $(FLAGS) -c baiscClassification.c
$(OBJECTS_LIB2): advancedClassificat.c NumClass.h
	$(cc) $(FLAGS) -c advancedClassificat.c
$(OBJECTS_LIB3): advancedClassificationRecursion.c NumClass.h
	$(cc) $(FLAGS) -c advancedClassificationRecursion.c


.PHONY: clean all
clean:
	rm -f *.o  *.a *.so mains maindloop maindrc