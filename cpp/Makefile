SRC		= main.cpp kernels.cpp matrixmultiplication/matrixmultiplication.cpp
HDR		= kernels.h matrixmultiplication/matrixmultiplication.h
PROGNAME	= matmul

#OCL_OPTIONS	= "-cl-fast-relaxed-math -cl-mad-enable -cl-single-precision-constant"

IO_DATA_INC		= -Ilib/lib-io-data/include
TIMER_INC		= -Ilib/lib-timer/include
OPENCLWRAPPER_INC	= -Ilib/lib-opencl-wrapper/include

IO_DATA_LIB_DIR		= lib/lib-io-data/src
TIMER_LIB_DIR		= lib/lib-timer/src
OPENCLWRAPPER_LIB_DIR	= lib/lib-opencl-wrapper/src

INCLUDE_DIRS		+= -I. \
			   $(IO_DATA_INC) \
			   $(TIMER_INC) \
			   $(OPENCLWRAPPER_INC)

LIB_DIRS		+= -L$(IO_DATA_LIB_DIR) \
			   -L$(TIMER_LIB_DIR) \
			   -L$(OPENCLWRAPPER_LIB_DIR)

LIBS			+= -lio_data -ltimer -lopencl-wrapper -lOpenCL

LIB_FILES		+= $(IO_DATA_LIB_DIR/libio_data.a \
			   $(TIMER_LIB_DIR)/libtimer.a \
			   $(OPENCLUTIL_LIB_DIR)/libopencl-wrapper.a

CC		= g++
CFLAGS		= -g -Wall $(INCLUDE_DIRS)

LD		= g++
LD_FLAGS	= $(LIB_DIRS) $(LIBS)

DEPFILE		= .depends

OBJ		= $(SRC:%.cpp=%.o)

.PHONY:	clean run depend


$(PROGNAME): $(DEPFILE) $(OBJ) $(LIB_FILES)
	$(LD) $(OBJ) -o $@ $(LD_FLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.s: %.cpp
	$(CC) -S $(CFLAGS) -c $< -o $@

%.o: %.cu
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

$(DEPFILE):
	$(CC) -M $(DEPFLAGS) $(CFLAGS) $(SRC) > $@

clean:
	rm -f *.s *.o $(PROGNAME) out_* $(DEPFILE) 

run: $(PROG)
	rm -f out_*
	@echo #preserve -np 1 -native '-l gpu=GTX480' -t 8:00:00
	@echo #prun -v -np 1 -native '-l gpu=GTX480' $(PROG) $(arg)
	@echo #prun -v -np 1 -native '-l gpu=C2050' $(PROG) $(arg)
	@echo #prun -v -np 1 -reserve 73038 $(PROG)
	OCL_OPTIONS=$(OCL_OPTIONS) ./$(PROG) $(arg)

sinclude $(DEPFILE)
