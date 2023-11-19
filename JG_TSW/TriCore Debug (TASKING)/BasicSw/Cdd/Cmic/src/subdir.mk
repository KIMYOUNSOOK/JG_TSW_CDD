################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Cdd/Cmic/src/Adrf8850.c \
../BasicSw/Cdd/Cmic/src/Cmic_Comm.c \
../BasicSw/Cdd/Cmic/src/Cmic_Fsm.c \
../BasicSw/Cdd/Cmic/src/Cmic_Manager.c 

COMPILED_SRCS += \
./BasicSw/Cdd/Cmic/src/Adrf8850.src \
./BasicSw/Cdd/Cmic/src/Cmic_Comm.src \
./BasicSw/Cdd/Cmic/src/Cmic_Fsm.src \
./BasicSw/Cdd/Cmic/src/Cmic_Manager.src 

C_DEPS += \
./BasicSw/Cdd/Cmic/src/Adrf8850.d \
./BasicSw/Cdd/Cmic/src/Cmic_Comm.d \
./BasicSw/Cdd/Cmic/src/Cmic_Fsm.d \
./BasicSw/Cdd/Cmic/src/Cmic_Manager.d 

OBJS += \
./BasicSw/Cdd/Cmic/src/Adrf8850.o \
./BasicSw/Cdd/Cmic/src/Cmic_Comm.o \
./BasicSw/Cdd/Cmic/src/Cmic_Fsm.o \
./BasicSw/Cdd/Cmic/src/Cmic_Manager.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Cdd/Cmic/src/%.src: ../BasicSw/Cdd/Cmic/src/%.c BasicSw/Cdd/Cmic/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Cdd\/Cmic\/src\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Cmic/src/Adrf8850.o: ./BasicSw/Cdd/Cmic/src/Adrf8850.src BasicSw/Cdd/Cmic/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Cmic/src/Cmic_Comm.o: ./BasicSw/Cdd/Cmic/src/Cmic_Comm.src BasicSw/Cdd/Cmic/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Cmic/src/Cmic_Fsm.o: ./BasicSw/Cdd/Cmic/src/Cmic_Fsm.src BasicSw/Cdd/Cmic/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Cmic/src/Cmic_Manager.o: ./BasicSw/Cdd/Cmic/src/Cmic_Manager.src BasicSw/Cdd/Cmic/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Cdd-2f-Cmic-2f-src

clean-BasicSw-2f-Cdd-2f-Cmic-2f-src:
	-$(RM) ./BasicSw/Cdd/Cmic/src/Adrf8850.d ./BasicSw/Cdd/Cmic/src/Adrf8850.o ./BasicSw/Cdd/Cmic/src/Adrf8850.src ./BasicSw/Cdd/Cmic/src/Cmic_Comm.d ./BasicSw/Cdd/Cmic/src/Cmic_Comm.o ./BasicSw/Cdd/Cmic/src/Cmic_Comm.src ./BasicSw/Cdd/Cmic/src/Cmic_Fsm.d ./BasicSw/Cdd/Cmic/src/Cmic_Fsm.o ./BasicSw/Cdd/Cmic/src/Cmic_Fsm.src ./BasicSw/Cdd/Cmic/src/Cmic_Manager.d ./BasicSw/Cdd/Cmic/src/Cmic_Manager.o ./BasicSw/Cdd/Cmic/src/Cmic_Manager.src

.PHONY: clean-BasicSw-2f-Cdd-2f-Cmic-2f-src

