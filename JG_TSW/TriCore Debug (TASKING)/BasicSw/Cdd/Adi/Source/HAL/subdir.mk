################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.c \
../BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.c 

COMPILED_SRCS += \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.src \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.src 

C_DEPS += \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.d \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.d 

OBJS += \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.o \
./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Cdd/Adi/Source/HAL/%.src: ../BasicSw/Cdd/Adi/Source/HAL/%.c BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Cdd\/Adi\/Source\/HAL\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.o: ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.src BasicSw/Cdd/Adi/Source/HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-HAL

clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-HAL:
	-$(RM) ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_spi.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_task_cb.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_ticker_bt.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_hal_tmr.src ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.d ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.o ./BasicSw/Cdd/Adi/Source/HAL/adi_wil_osal.src

.PHONY: clean-BasicSw-2f-Cdd-2f-Adi-2f-Source-2f-HAL

