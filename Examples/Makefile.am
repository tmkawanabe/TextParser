###################################################################################
#
# TextParser - Text Parsing Library
#
# Copyright (C) 2012-2014 Institute of Industrial Science, The University of Tokyo.
# All rights reserved.
#
###################################################################################
#

noinst_PROGRAMS = test test2 test_mpi test_mpi2 test_mpi3

 
SUBDIRS = tpp_examples
EXTRA_DIST=Makefile_hand



if MPI
MPIPROGRAMS=Example3_cpp_mpi Example3-1_cpp_mpi
Example3_cpp_mpi_SOURCES=Example3_cpp_mpi.cpp
Example3_1_cpp_mpi_SOURCES=Example3-1_cpp_mpi.cpp
Example3_cpp_mpi_LDADD= -L../lib -lTP_mpi -lstdc++
Example3_1_cpp_mpi_LDADD= -L../lib -lTP_mpi -lstdc++ 
else
MPIPROGRAMS=
endif

if FORTRAN
FORTRANPROGRAMS= Example1_f90 Example2_f90 Example3_f90 Example4_f90 Example5_f90 Example7_f90
Example1_f90_SOURCES=Example1_f90.f90
Example2_f90_SOURCES=Example2_f90.f90
Example3_f90_SOURCES=Example3_f90.f90
Example4_f90_SOURCES=Example4_f90.f90
Example5_f90_SOURCES=Example5_f90.f90
Example7_f90_SOURCES=Example7_f90.f90
Example1_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example2_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example3_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example4_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example5_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example7_f90_LDADD=  -L../lib -lTP -lTP_f90api -lstdc++
Example1_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
Example2_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
Example3_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
Example4_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
Example5_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
Example7_f90.o:../include/TextParser.inc ../lib/libTP.la ../lib/libTP_f90api.la
else
FORTRANPROGRAMS=
endif


noinst_PROGRAMS=Example1_cpp Example2_cpp Example3_cpp Example4_cpp \
Example5_cpp Example6_cpp Example7_cpp Example8_cpp \
Example1_c Example2_c Example3_c Example4_c Example5_c Example7_c \
${FORTRANPROGRAMS} ${MPIPROGRAMS}

# Example3_cpp_mpi_newAPI

#Example_f90_tmp Example_tmp Example_tmp2 
# Example_c_tmp

DISTCLEANFILES=*~
#CLEANFILES=Output*.txt nodq/Output*.txt

LDADD=-L../lib -lTP -lstdc++
CXXFLAGS=-I../include
CFLAGS=-I../include
FCFLAGS=-I../include

Example1_cpp_SOURCES=Example1_cpp.cpp
Example1_c_SOURCES=Example1_c.c
Example2_cpp_SOURCES=Example2_cpp.cpp
Example2_c_SOURCES=Example2_c.c
Example3_cpp_SOURCES=Example3_cpp.cpp
Example3_c_SOURCES=Example3_c.c
Example4_cpp_SOURCES=Example4_cpp.cpp
Example4_c_SOURCES=Example4_c.c

Example5_cpp_SOURCES=Example5_cpp.cpp
Example5_c_SOURCES=Example5_c.c
Example6_cpp_SOURCES=Example6_cpp.cpp

Example7_cpp_SOURCES=Example7_cpp.cpp
Example8_cpp_SOURCES=Example8_cpp.cpp
Example7_c_SOURCES=Example7_c.c

#Example3_cpp_mpi_newAPI_SOURCES=Example3_cpp_mpi_newAPI.cpp
#Example_f90_tmp_SOURCES=Example_f90_tmp.f90
#Example_f90_tmp_LDADD=-L../lib -lTP -lTP_f90api -lstdc++
#Example3_cpp_mpi_newAPI_LDADD= -L../lib -lTP -lTP_mpi -lstdc++


Example1_cpp.o:../include/TextParser.h ../lib/libTP.la
Example2_cpp.o:../include/TextParser.h ../lib/libTP.la
Example3_cpp.o:../include/TextParser.h ../lib/libTP.la
Example4_cpp.o:../include/TextParser.h ../lib/libTP.la
Example5_cpp.o:../include/TextParser.h ../lib/libTP.la

Example7_cpp.o:../include/TextParser.h ../lib/libTP.la
Example8_cpp.o:../include/TextParser.h ../lib/libTP.la


Example1_c.o:../include/TextParser.h ../lib/libTP.la
Example2_c.o:../include/TextParser.h ../lib/libTP.la
Example3_c.o:../include/TextParser.h ../lib/libTP.la
Example4_c.o:../include/TextParser.h ../lib/libTP.la
Example5_c.o:../include/TextParser.h ../lib/libTP.la

Example7_c.o:../include/TextParser.h ../lib/libTP.la

.PHONY: