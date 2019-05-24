PKG		= matrixmultiplication
SRC		= $(PKG)/matrixmultiplication.mcl
TGT		= fermi
ENTRY_FUNCS	= matmul

OUTPUT_DIR	= ../cpp

OUTPUT_HDR	= $(OUTPUT_DIR)/$(PKG)/$(PKG).h
OUTPUT_CPP	= $(OUTPUT_DIR)/$(PKG)/$(PKG).cpp
OUTPUT_OCL	= $(OUTPUT_DIR)/$(PKG)/$(PKG)-kernels.cl

MCLC		= mcl
MCLFLAGS	= gen-cpp -t $(TGT) -e $(ENTRY_FUNCS) -o $(OUTPUT_DIR)

.PHONY:		clean

$(OUTPUT_HDR) $(OUTPUT_CPP) $(OUTPUT_OCL): $(SRC)
	$(MCLC) $(MCLFLAGS) -- $<

clean: 
	rm -rf $(OUTPUT_DIR)/$(PKG)
