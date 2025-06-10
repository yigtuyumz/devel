# Generic
PROJECT_ROOT     := $(realpath .)

COLOR_RED        := $(shell tput setaf 1)
COLOR_GREEN      := $(shell tput setaf 2)
COLOR_YELLOW     := $(shell tput setaf 3)
COLOR_BLUE       := $(shell tput setaf 4)
COLOR_PINK       := $(shell tput setaf 5)
COLOR_RESET      := $(shell tput sgr0)

# Project
CC               := gcc
CFLAGS            = -Wall -Wextra -MMD
LDFLAGS           = -L$(LIB_DIR) -Wl,-rpath=$(LIB_DIR)

OUT_DIR          := $(PROJECT_ROOT)/obj
LIB_DIR          := $(PROJECT_ROOT)/lib
SRC_DIR          := $(PROJECT_ROOT)/src
INCLUDE_DIR      := $(PROJECT_ROOT)/include
PROG_NAME        := $(PROJECT_ROOT)/lists

DYN_LIBS         := $(wildcard $(LIB_DIR)/*.so)
STATIC_LIBS      := $(wildcard $(LIB_DIR)/*.a)
DYN_LIB_FLAG     := $(patsubst lib%.so,-l%, $(notdir $(DYN_LIBS)))
STATIC_LIB_FLAG  := $(patsubst lib%.a,-l%, $(notdir $(STATIC_LIBS)))

LDFLAGS         += $(DYN_LIB_FLAG) $(STATIC_LIB_FLAG)
CFLAGS          += -I$(INCLUDE_DIR)

SRCS             = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJS             = $(patsubst $(SRC_DIR)/%.c, $(OUT_DIR)/%.o, $(SRCS))
OBJ_DIRS         = $(sort $(dir $(OBJS)))
DEPS            := $(OBJS:.o=.d)

# Clear default search patterns of make
.SUFFIXES:
# Don't treat rules as dependencies
.PHONY: all clean re fclean

all: $(PROG_NAME)

$(PROG_NAME): $(OBJS)
	@echo "Linking: $@"
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIRS)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OUT_DIR)

fclean: clean
	rm -rf $(PROG_NAME)


re: clean all


-include $(DEPS)
