################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppSw/Infra/Main/Core0_Main.c \
../AppSw/Infra/Main/Core1_Main.c \
../AppSw/Infra/Main/Core2_Main.c \
../AppSw/Infra/Main/Core3_Main.c 

COMPILED_SRCS += \
./AppSw/Infra/Main/Core0_Main.src \
./AppSw/Infra/Main/Core1_Main.src \
./AppSw/Infra/Main/Core2_Main.src \
./AppSw/Infra/Main/Core3_Main.src 

C_DEPS += \
./AppSw/Infra/Main/Core0_Main.d \
./AppSw/Infra/Main/Core1_Main.d \
./AppSw/Infra/Main/Core2_Main.d \
./AppSw/Infra/Main/Core3_Main.d 

OBJS += \
./AppSw/Infra/Main/Core0_Main.o \
./AppSw/Infra/Main/Core1_Main.o \
./AppSw/Infra/Main/Core2_Main.o \
./AppSw/Infra/Main/Core3_Main.o 


# Each subdirectory must supply rules for building sources it contributes
AppSw/Infra/Main/%.src: ../AppSw/Infra/Main/%.c AppSw/Infra/Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/AppSw\/Infra\/Main\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

AppSw/Infra/Main/Core0_Main.o: ./AppSw/Infra/Main/Core0_Main.src AppSw/Infra/Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/Infra/Main/Core1_Main.o: ./AppSw/Infra/Main/Core1_Main.src AppSw/Infra/Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/Infra/Main/Core2_Main.o: ./AppSw/Infra/Main/Core2_Main.src AppSw/Infra/Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/Infra/Main/Core3_Main.o: ./AppSw/Infra/Main/Core3_Main.src AppSw/Infra/Main/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-AppSw-2f-Infra-2f-Main

clean-AppSw-2f-Infra-2f-Main:
	-$(RM) ./AppSw/Infra/Main/Core0_Main.d ./AppSw/Infra/Main/Core0_Main.o ./AppSw/Infra/Main/Core0_Main.src ./AppSw/Infra/Main/Core1_Main.d ./AppSw/Infra/Main/Core1_Main.o ./AppSw/Infra/Main/Core1_Main.src ./AppSw/Infra/Main/Core2_Main.d ./AppSw/Infra/Main/Core2_Main.o ./AppSw/Infra/Main/Core2_Main.src ./AppSw/Infra/Main/Core3_Main.d ./AppSw/Infra/Main/Core3_Main.o ./AppSw/Infra/Main/Core3_Main.src

.PHONY: clean-AppSw-2f-Infra-2f-Main

