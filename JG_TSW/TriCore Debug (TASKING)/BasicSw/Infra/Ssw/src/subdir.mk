################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.c \
../BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.c \
../BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.c \
../BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.c \
../BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.c 

COMPILED_SRCS += \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.src \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.src \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.src \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.src \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.src 

C_DEPS += \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.d \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.d \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.d \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.d \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.d 

OBJS += \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.o \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.o \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.o \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.o \
./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Infra/Ssw/src/%.src: ../BasicSw/Infra/Ssw/src/%.c BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Infra\/Ssw\/src\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.o: ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.src BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.o: ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.src BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.o: ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.src BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.o: ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.src BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.o: ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.src BasicSw/Infra/Ssw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Infra-2f-Ssw-2f-src

clean-BasicSw-2f-Infra-2f-Ssw-2f-src:
	-$(RM) ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.d ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.o ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Infra.src ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.d ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.o ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc0.src ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.d ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.o ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc1.src ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.d ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.o ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc2.src ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.d ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.o ./BasicSw/Infra/Ssw/src/Ifx_Ssw_Tc3.src

.PHONY: clean-BasicSw-2f-Infra-2f-Ssw-2f-src

