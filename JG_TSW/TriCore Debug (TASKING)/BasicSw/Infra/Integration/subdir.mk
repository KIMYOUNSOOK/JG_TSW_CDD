################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Infra/Integration/FlsLdr_ExclArea.c \
../BasicSw/Infra/Integration/IFX_Os.c \
../BasicSw/Infra/Integration/SchM_Adc.c \
../BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.c \
../BasicSw/Infra/Integration/SchM_Can_17_McmCan.c \
../BasicSw/Infra/Integration/SchM_Crc.c \
../BasicSw/Infra/Integration/SchM_Dma.c \
../BasicSw/Infra/Integration/SchM_Gpt.c \
../BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.c \
../BasicSw/Infra/Integration/SchM_McalLib.c \
../BasicSw/Infra/Integration/SchM_Mcu.c \
../BasicSw/Infra/Integration/SchM_Ocu.c \
../BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.c \
../BasicSw/Infra/Integration/SchM_Spi.c \
../BasicSw/Infra/Integration/SchM_Wdg_17_Scu.c 

COMPILED_SRCS += \
./BasicSw/Infra/Integration/FlsLdr_ExclArea.src \
./BasicSw/Infra/Integration/IFX_Os.src \
./BasicSw/Infra/Integration/SchM_Adc.src \
./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.src \
./BasicSw/Infra/Integration/SchM_Can_17_McmCan.src \
./BasicSw/Infra/Integration/SchM_Crc.src \
./BasicSw/Infra/Integration/SchM_Dma.src \
./BasicSw/Infra/Integration/SchM_Gpt.src \
./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.src \
./BasicSw/Infra/Integration/SchM_McalLib.src \
./BasicSw/Infra/Integration/SchM_Mcu.src \
./BasicSw/Infra/Integration/SchM_Ocu.src \
./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.src \
./BasicSw/Infra/Integration/SchM_Spi.src \
./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.src 

C_DEPS += \
./BasicSw/Infra/Integration/FlsLdr_ExclArea.d \
./BasicSw/Infra/Integration/IFX_Os.d \
./BasicSw/Infra/Integration/SchM_Adc.d \
./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.d \
./BasicSw/Infra/Integration/SchM_Can_17_McmCan.d \
./BasicSw/Infra/Integration/SchM_Crc.d \
./BasicSw/Infra/Integration/SchM_Dma.d \
./BasicSw/Infra/Integration/SchM_Gpt.d \
./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.d \
./BasicSw/Infra/Integration/SchM_McalLib.d \
./BasicSw/Infra/Integration/SchM_Mcu.d \
./BasicSw/Infra/Integration/SchM_Ocu.d \
./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.d \
./BasicSw/Infra/Integration/SchM_Spi.d \
./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.d 

OBJS += \
./BasicSw/Infra/Integration/FlsLdr_ExclArea.o \
./BasicSw/Infra/Integration/IFX_Os.o \
./BasicSw/Infra/Integration/SchM_Adc.o \
./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.o \
./BasicSw/Infra/Integration/SchM_Can_17_McmCan.o \
./BasicSw/Infra/Integration/SchM_Crc.o \
./BasicSw/Infra/Integration/SchM_Dma.o \
./BasicSw/Infra/Integration/SchM_Gpt.o \
./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.o \
./BasicSw/Infra/Integration/SchM_McalLib.o \
./BasicSw/Infra/Integration/SchM_Mcu.o \
./BasicSw/Infra/Integration/SchM_Ocu.o \
./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.o \
./BasicSw/Infra/Integration/SchM_Spi.o \
./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Infra/Integration/%.src: ../BasicSw/Infra/Integration/%.c BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Infra\/Integration\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/FlsLdr_ExclArea.o: ./BasicSw/Infra/Integration/FlsLdr_ExclArea.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/IFX_Os.o: ./BasicSw/Infra/Integration/IFX_Os.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Adc.o: ./BasicSw/Infra/Integration/SchM_Adc.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.o: ./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Can_17_McmCan.o: ./BasicSw/Infra/Integration/SchM_Can_17_McmCan.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Crc.o: ./BasicSw/Infra/Integration/SchM_Crc.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Dma.o: ./BasicSw/Infra/Integration/SchM_Dma.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Gpt.o: ./BasicSw/Infra/Integration/SchM_Gpt.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.o: ./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_McalLib.o: ./BasicSw/Infra/Integration/SchM_McalLib.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Mcu.o: ./BasicSw/Infra/Integration/SchM_Mcu.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Ocu.o: ./BasicSw/Infra/Integration/SchM_Ocu.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.o: ./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Spi.o: ./BasicSw/Infra/Integration/SchM_Spi.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Infra/Integration/SchM_Wdg_17_Scu.o: ./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.src BasicSw/Infra/Integration/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Infra-2f-Integration

clean-BasicSw-2f-Infra-2f-Integration:
	-$(RM) ./BasicSw/Infra/Integration/FlsLdr_ExclArea.d ./BasicSw/Infra/Integration/FlsLdr_ExclArea.o ./BasicSw/Infra/Integration/FlsLdr_ExclArea.src ./BasicSw/Infra/Integration/IFX_Os.d ./BasicSw/Infra/Integration/IFX_Os.o ./BasicSw/Infra/Integration/IFX_Os.src ./BasicSw/Infra/Integration/SchM_Adc.d ./BasicSw/Infra/Integration/SchM_Adc.o ./BasicSw/Infra/Integration/SchM_Adc.src ./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.d ./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.o ./BasicSw/Infra/Integration/SchM_CanTrcv_17_W9255.src ./BasicSw/Infra/Integration/SchM_Can_17_McmCan.d ./BasicSw/Infra/Integration/SchM_Can_17_McmCan.o ./BasicSw/Infra/Integration/SchM_Can_17_McmCan.src ./BasicSw/Infra/Integration/SchM_Crc.d ./BasicSw/Infra/Integration/SchM_Crc.o ./BasicSw/Infra/Integration/SchM_Crc.src ./BasicSw/Infra/Integration/SchM_Dma.d ./BasicSw/Infra/Integration/SchM_Dma.o ./BasicSw/Infra/Integration/SchM_Dma.src ./BasicSw/Infra/Integration/SchM_Gpt.d ./BasicSw/Infra/Integration/SchM_Gpt.o ./BasicSw/Infra/Integration/SchM_Gpt.src ./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.d ./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.o ./BasicSw/Infra/Integration/SchM_Icu_17_TimerIp.src ./BasicSw/Infra/Integration/SchM_McalLib.d ./BasicSw/Infra/Integration/SchM_McalLib.o ./BasicSw/Infra/Integration/SchM_McalLib.src ./BasicSw/Infra/Integration/SchM_Mcu.d ./BasicSw/Infra/Integration/SchM_Mcu.o ./BasicSw/Infra/Integration/SchM_Mcu.src ./BasicSw/Infra/Integration/SchM_Ocu.d ./BasicSw/Infra/Integration/SchM_Ocu.o ./BasicSw/Infra/Integration/SchM_Ocu.src ./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.d ./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.o ./BasicSw/Infra/Integration/SchM_Pwm_17_GtmCcu6.src ./BasicSw/Infra/Integration/SchM_Spi.d ./BasicSw/Infra/Integration/SchM_Spi.o ./BasicSw/Infra/Integration/SchM_Spi.src ./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.d ./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.o ./BasicSw/Infra/Integration/SchM_Wdg_17_Scu.src

.PHONY: clean-BasicSw-2f-Infra-2f-Integration

