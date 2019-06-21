PKG		= matrixmultiplication
SRC		= $(PKG)/matrixmultiplication.mcl
TGT		= xeon_e5620
ENTRY_FUNCS	= matmul

OUTPUT_DIR	= ../cpp

OUTPUT_HDR	= $(OUTPUT_DIR)/$(PKG)/$(PKG).h
OUTPUT_CPP	= $(OUTPUT_DIR)/$(PKG)/$(PKG).cpp
OUTPUT_OCL	= $(OUTPUT_DIR)/$(PKG)/$(PKG)-kernels.cl

OUTPUT		= $(OUTPUT_HDR) $(OUTPUT_CPP) $(OUTPUT_OCL)

MCLC		= mcl
MCLFLAGS	= gen-cpp -t $(TGT) -e $(ENTRY_FUNCS) -o $(OUTPUT_DIR)

.PHONY:		all clean

all: $(OUTPUT)

$(OUTPUT): $(SRC)
	$(MCLC) $(MCLFLAGS) -- $<

clean: 
	rm -rf $(OUTPUT_DIR)/$(PKG)
