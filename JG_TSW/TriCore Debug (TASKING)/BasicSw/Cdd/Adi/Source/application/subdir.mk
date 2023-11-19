################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.c \
../BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.c 

COMPILED_SRCS += \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.src \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.src 

C_DEPS += \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.d \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.d 

OBJS += \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.o \
./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Cdd/Adi/Source/application/%.src: ../BasicSw/Cdd/Adi/Source/application/%.c BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Cdd\/Adi\/Source\/application\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.o: ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.src BasicSw/Cdd/Adi/Source/application/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-application

clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-application:
	-$(RM) ./BasicSw/Cdd/Adi/Source/application/adi_wil_example.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_PSFromLatency.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_acl.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_cell_balance.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_debug_functions.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_functions.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_owd.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_printf.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_scheduler.src ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.d ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.o ./BasicSw/Cdd/Adi/Source/application/adi_wil_example_utilities.src

.PHONY: clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-application

