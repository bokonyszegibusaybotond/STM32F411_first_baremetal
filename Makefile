# ============================================================================
# Makefile for STM32F411 Bare Metal Project
# 
# Targets:
#   make build       - Compile, link, and generate binary (default)
#   make flash       - Upload binary to STM32F411 via dfu-util
#   make clean       - Remove all generated files
#   make rebuild     - Clean then build
# ============================================================================

# ============================================================================
# TOOLCHAIN CONFIGURATION
# ============================================================================

# ARM GNU Embedded Toolchain prefix
TOOLCHAIN_PREFIX = arm-none-eabi-

# Compiler, linker, objcopy, and size tools
CC       = $(TOOLCHAIN_PREFIX)gcc
LD       = $(TOOLCHAIN_PREFIX)ld
OBJCOPY  = $(TOOLCHAIN_PREFIX)objcopy
SIZE     = $(TOOLCHAIN_PREFIX)size

# ============================================================================
# SOURCE AND OUTPUT FILES
# ============================================================================

# Source files
SOURCES  = main.c startup.c gpio.c timer9.c usart1.c extint.c

# Build output directory
BUILD_DIR = build-destination

# Object files (generated from .c files)
OBJECTS  = $(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))

# Output files
TARGET_ELF   = $(BUILD_DIR)/firmware.elf
TARGET_BIN   = $(BUILD_DIR)/firmware.bin

# Linker script
LINKER_SCRIPT = linker.ld

# ============================================================================
# COMPILER FLAGS
# ============================================================================

# CPU and Architecture
CPU_FLAGS = -mcpu=cortex-m4 -mthumb

# FPU (Floating Point Unit) configuration
FPU_FLAGS = -mfpu=fpv4-sp-d16 -mfloat-abi=hard

# Optimization and debugging
OPT_FLAGS = -O0 -g

# Standard library and startup handling
SUPPORT_FLAGS = -nostdlib -nostartfiles

# Warning flags
WARN_FLAGS = -Wall -Wextra

# Combine all C compiler flags
CFLAGS = $(CPU_FLAGS) $(FPU_FLAGS) $(OPT_FLAGS) $(SUPPORT_FLAGS) $(WARN_FLAGS)

# ============================================================================
# LINKER FLAGS
# ============================================================================

# Use linker script to define memory layout
LDFLAGS = -T$(LINKER_SCRIPT)

# ============================================================================
# DFU FLASH SETTINGS
# ============================================================================

# dfu-util parameters for uploading to STM32F411
DFU_INTERFACE = 0
DFU_START_ADDR = 0x08000000

# ============================================================================
# BUILD RULES
# ============================================================================

# Default target
.PHONY: build
build: $(TARGET_BIN)
	@echo "✓ Build complete: $(TARGET_BIN)"
	@$(SIZE) $(TARGET_ELF)

# Generate binary from ELF
# arm-none-eabi-objcopy converts ELF executable to raw binary for flashing
$(TARGET_BIN): $(TARGET_ELF)
	@echo "Generating binary: $@"
	$(OBJCOPY) -O binary $< $@

# Link object files into ELF executable
# Combines all .o files and applies linker script (LDFLAGS)
$(TARGET_ELF): $(OBJECTS)
	@echo "Linking: $@"
	$(LD) $(LDFLAGS) $^ -o $@

# Compile C source files to object files
# Pattern rule: any .c file becomes .o file in build directory
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@echo "Compiling: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build output directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# ============================================================================
# FLASH TARGET
# ============================================================================

.PHONY: flash
flash: $(TARGET_BIN)
	@echo "Flashing $(TARGET_BIN) to STM32F411..."
	dfu-util -a $(DFU_INTERFACE) -D $(TARGET_BIN) -s $(DFU_START_ADDR)
	@echo "✓ Flash complete!"

# ============================================================================
# CLEANING
# ============================================================================

.PHONY: clean
clean:
	@echo "Cleaning build artifacts..."
#	-del /Q /F $(subst /,\,$(OBJECTS)) $(subst /,\,$(TARGET_ELF)) $(subst /,\,$(TARGET_BIN)) 2>nul
	-rm -f $(OBJECTS) $(TARGET_ELF) $(TARGET_BIN)
	@echo "✓ Clean complete!"

# ============================================================================
# REBUILD (clean then build)
# ============================================================================

.PHONY: rebuild
rebuild: clean build

# ============================================================================
# HELP TARGET
# ============================================================================

.PHONY: help
help:
	@echo "STM32F411 Bare Metal Build System"
	@echo ""
	@echo "Targets:"
	@echo "  make flash       - Upload binary via dfu-util"
	@echo "  make clean       - Remove generated files"
	@echo "  make rebuild     - Clean then build"
	@echo "  make help        - Show this help message"
	@echo ""
	@echo "Prerequisites:"
	@echo "  - arm-none-eabi-gcc (compiler)"
	@echo "  - arm-none-eabi-ld (linker)"
	@echo "  - dfu-util (for flashing)"
