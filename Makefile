TARGET_EXEC ?= phatt.exe
# TARGET_EXEC = phattl
# TARGET_EXEC = phattm

WBUILD_DIR ?= ./wobj
LBUILD_DIR ?= ./lobj
MBUILD_DIR ?= ./mobj
SRC_DIRS ?= ./src

CC := clang
CXX := clang++

SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
WOBJS := $(SRCS:%=$(WBUILD_DIR)/%.o)
LOBJS := $(SRCS:%=$(LBUILD_DIR)/%.o)
MOBJS := $(SRCS:%=$(MBUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS)) -I./include

WCPPFLAGS ?= $(INC_FLAGS) -std=c11 -Wall -m64 -O2
LCPPFLAGS ?= $(INC_FLAGS) -std=c11 -Wall -m64 -O2

WLDFLAGS = ./lib/libwren.ucrt.a -lopengl32 -lgdi32
LLDFLAGS = ./lib/libwren.l.a -lGLU -lGL -lX11

$(WBUILD_DIR)/phatt.exe: $(WOBJS)
	$(eval LDFLAGS=$(WLDFLAGS))
	$(CC) $(WOBJS) -o $@ $(LDFLAGS)

$(LBUILD_DIR)/phattl: $(LOBJS)
	$(eval LDFLAGS=$(LLDFLAGS))
	$(CC) $(LOBJS) -o $@ $(LDFLAGS)

# assembly
./wobj/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

./lobj/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source, windows
./wobj/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(WCPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source, windows
./wobj/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(WCPPFLAGS) $(CXXFLAGS) -c $< -o $@

# c source, linux
./lobj/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(LCPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source, linux
./lobj/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(LCPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(WBUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p