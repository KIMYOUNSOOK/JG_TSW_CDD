################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Infra/Autosar_Srv/CanIf.c \
../BasicSw/Infra/Autosar_Srv/CanIf_Cbk.c \
../BasicSw/Infra/Autosar_Srv/Dem.c \
../BasicSw/Infra/Autosar_Srv/Det.c \
../BasicSw/Infra/Autosar_Srv/EcuM.c \
../BasicSw/Infra/Autosar_Srv/LinIf.c \
../BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.c \
../BasicSw/Infra/Autosar_Srv/Os.c 

COMPILED_SRCS += \
./BasicSw/Infra/Autosar_Srv/CanIf.src \
./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.src \
./BasicSw/Infra/Autosar_Srv/Dem.src \
./BasicSw/Infra/Autosar_Srv/Det.src \
./BasicSw/Infra/Autosar_Srv/EcuM.src \
./BasicSw/Infra/Autosar_Srv/LinIf.src \
./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.src \
./BasicSw/Infra/Autosar_Srv/Os.src 

C_DEPS += \
./BasicSw/Infra/Autosar_Srv/CanIf.d \
./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.d \
./BasicSw/Infra/Autosar_Srv/Dem.d \
./BasicSw/Infra/Autosar_Srv/Det.d \
./BasicSw/Infra/Autosar_Srv/EcuM.d \
./BasicSw/Infra/Autosar_Srv/LinIf.d \
./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.d \
./BasicSw/Infra/Autosar_Srv/Os.d 

OBJS += \
./BasicSw/Infra/Autosar_Srv/CanIf.o \
./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.o \
./BasicSw/Infra/Autosar_Srv/Dem.o \
./BasicSw/Infra/Autosar_Srv/Det.o \
./BasicSw/Infra/Autosar_Srv/EcuM.o \
./BasicSw/Infra/Autosar_Srv/LinIf.o \
./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.o \
./BasicSw/Infra/Autosar_Srv/Os.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Infra/Autosar_Srv/%.src: ../BasicSw/Infra/Autosar_Srv/%.c BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Infra\/Autosar_Srv\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/CanIf.o: ./BasicSw/Infra/Autosar_Srv/CanIf.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/CanIf_Cbk.o: ./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/Dem.o: ./BasicSw/Infra/Autosar_Srv/Dem.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/Det.o: ./BasicSw/Infra/Autosar_Srv/Det.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/EcuM.o: ./BasicSw/Infra/Autosar_Srv/EcuM.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/LinIf.o: ./BasicSw/Infra/Autosar_Srv/LinIf.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.o: ./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Autosar_Srv/Os.o: ./BasicSw/Infra/Autosar_Srv/Os.src BasicSw/Infra/Autosar_Srv/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Infra-2f-Autosar_Srv

clean-BasicSw-2f-Infra-2f-Autosar_Srv:
	-$(RM) ./BasicSw/Infra/Autosar_Srv/CanIf.d ./BasicSw/Infra/Autosar_Srv/CanIf.o ./BasicSw/Infra/Autosar_Srv/CanIf.src ./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.d ./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.o ./BasicSw/Infra/Autosar_Srv/CanIf_Cbk.src ./BasicSw/Infra/Autosar_Srv/Dem.d ./BasicSw/Infra/Autosar_Srv/Dem.o ./BasicSw/Infra/Autosar_Srv/Dem.src ./BasicSw/Infra/Autosar_Srv/Det.d ./BasicSw/Infra/Autosar_Srv/Det.o ./BasicSw/Infra/Autosar_Srv/Det.src ./BasicSw/Infra/Autosar_Srv/EcuM.d ./BasicSw/Infra/Autosar_Srv/EcuM.o ./BasicSw/Infra/Autosar_Srv/EcuM.src ./BasicSw/Infra/Autosar_Srv/LinIf.d ./BasicSw/Infra/Autosar_Srv/LinIf.o ./BasicSw/Infra/Autosar_Srv/LinIf.src ./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.d ./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.o ./BasicSw/Infra/Autosar_Srv/Mcal_SafetyError.src ./BasicSw/Infra/Autosar_Srv/Os.d ./BasicSw/Infra/Autosar_Srv/Os.o ./BasicSw/Infra/Autosar_Srv/Os.src

.PHONY: clean-BasicSw-2f-Infra-2f-Autosar_Srv

