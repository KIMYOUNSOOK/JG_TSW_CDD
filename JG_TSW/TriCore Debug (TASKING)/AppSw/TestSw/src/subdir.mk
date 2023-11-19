################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppSw/TestSw/src/TestAdc.c \
../AppSw/TestSw/src/TestApp.c \
../AppSw/TestSw/src/TestCan.c \
../AppSw/TestSw/src/TestDio.c \
../AppSw/TestSw/src/TestFls.c \
../AppSw/TestSw/src/TestGpt.c \
../AppSw/TestSw/src/TestIcu.c \
../AppSw/TestSw/src/TestLin.c \
../AppSw/TestSw/src/TestStm.c \
../AppSw/TestSw/src/Utils.c 

COMPILED_SRCS += \
./AppSw/TestSw/src/TestAdc.src \
./AppSw/TestSw/src/TestApp.src \
./AppSw/TestSw/src/TestCan.src \
./AppSw/TestSw/src/TestDio.src \
./AppSw/TestSw/src/TestFls.src \
./AppSw/TestSw/src/TestGpt.src \
./AppSw/TestSw/src/TestIcu.src \
./AppSw/TestSw/src/TestLin.src \
./AppSw/TestSw/src/TestStm.src \
./AppSw/TestSw/src/Utils.src 

C_DEPS += \
./AppSw/TestSw/src/TestAdc.d \
./AppSw/TestSw/src/TestApp.d \
./AppSw/TestSw/src/TestCan.d \
./AppSw/TestSw/src/TestDio.d \
./AppSw/TestSw/src/TestFls.d \
./AppSw/TestSw/src/TestGpt.d \
./AppSw/TestSw/src/TestIcu.d \
./AppSw/TestSw/src/TestLin.d \
./AppSw/TestSw/src/TestStm.d \
./AppSw/TestSw/src/Utils.d 

OBJS += \
./AppSw/TestSw/src/TestAdc.o \
./AppSw/TestSw/src/TestApp.o \
./AppSw/TestSw/src/TestCan.o \
./AppSw/TestSw/src/TestDio.o \
./AppSw/TestSw/src/TestFls.o \
./AppSw/TestSw/src/TestGpt.o \
./AppSw/TestSw/src/TestIcu.o \
./AppSw/TestSw/src/TestLin.o \
./AppSw/TestSw/src/TestStm.o \
./AppSw/TestSw/src/Utils.o 


# Each subdirectory must supply rules for building sources it contributes
AppSw/TestSw/src/%.src: ../AppSw/TestSw/src/%.c AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/AppSw\/TestSw\/src\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestAdc.o: ./AppSw/TestSw/src/TestAdc.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestApp.o: ./AppSw/TestSw/src/TestApp.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestCan.o: ./AppSw/TestSw/src/TestCan.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestDio.o: ./AppSw/TestSw/src/TestDio.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestFls.o: ./AppSw/TestSw/src/TestFls.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestGpt.o: ./AppSw/TestSw/src/TestGpt.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestIcu.o: ./AppSw/TestSw/src/TestIcu.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestLin.o: ./AppSw/TestSw/src/TestLin.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/TestStm.o: ./AppSw/TestSw/src/TestStm.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

AppSw/TestSw/src/Utils.o: ./AppSw/TestSw/src/Utils.src AppSw/TestSw/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-AppSw-2f-TestSw-2f-src

clean-AppSw-2f-TestSw-2f-src:
	-$(RM) ./AppSw/TestSw/src/TestAdc.d ./AppSw/TestSw/src/TestAdc.o ./AppSw/TestSw/src/TestAdc.src ./AppSw/TestSw/src/TestApp.d ./AppSw/TestSw/src/TestApp.o ./AppSw/TestSw/src/TestApp.src ./AppSw/TestSw/src/TestCan.d ./AppSw/TestSw/src/TestCan.o ./AppSw/TestSw/src/TestCan.src ./AppSw/TestSw/src/TestDio.d ./AppSw/TestSw/src/TestDio.o ./AppSw/TestSw/src/TestDio.src ./AppSw/TestSw/src/TestFls.d ./AppSw/TestSw/src/TestFls.o ./AppSw/TestSw/src/TestFls.src ./AppSw/TestSw/src/TestGpt.d ./AppSw/TestSw/src/TestGpt.o ./AppSw/TestSw/src/TestGpt.src ./AppSw/TestSw/src/TestIcu.d ./AppSw/TestSw/src/TestIcu.o ./AppSw/TestSw/src/TestIcu.src ./AppSw/TestSw/src/TestLin.d ./AppSw/TestSw/src/TestLin.o ./AppSw/TestSw/src/TestLin.src ./AppSw/TestSw/src/TestStm.d ./AppSw/TestSw/src/TestStm.o ./AppSw/TestSw/src/TestStm.src ./AppSw/TestSw/src/Utils.d ./AppSw/TestSw/src/Utils.o ./AppSw/TestSw/src/Utils.src

.PHONY: clean-AppSw-2f-TestSw-2f-src

