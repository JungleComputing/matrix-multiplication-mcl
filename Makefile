CPP_LIB_DIR	= cpp/lib

DIRS	= 	mcl/. \
		$(CPP_LIB_DIR)/lib-io-data/src/. \
		$(CPP_LIB_DIR)/lib-timer/src/. \
		$(CPP_LIB_DIR)/lib-opencl-wrapper/src/. \
		cpp/.

TARGETS := all clean

# foo/.all bar/.all foo/.clean bar/.clean
DIRS_TARGETS := \
	$(foreach t,$(TARGETS),$(addsuffix $t,$(DIRS)))

.PHONY : $(TARGETS) $(DIRS_TARGETS)

$(TARGETS) : % : $(addsuffix %,$(DIRS))
	@echo 'Done "$*" target'

# here, for foo/.all:
#   $(@D) is foo
#   $(@F) is .all, with leading period
#   $(@F:.%=%) is just all
$(DIRS_TARGETS) :
	$(MAKE) -C $(@D) $(@F:.%=%)
