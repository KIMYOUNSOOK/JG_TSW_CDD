################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BasicSw/Mcal/generate/src/Adc_PBcfg.c \
../BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.c \
../BasicSw/Mcal/generate/src/Dio_Lcfg.c \
../BasicSw/Mcal/generate/src/Dma_PBcfg.c \
../BasicSw/Mcal/generate/src/FlsLoader_Cfg.c \
../BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.c \
../BasicSw/Mcal/generate/src/Gpt_PBcfg.c \
../BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.c \
../BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.c \
../BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.c \
../BasicSw/Mcal/generate/src/Mcu_PBcfg.c \
../BasicSw/Mcal/generate/src/Port_PBcfg.c \
../BasicSw/Mcal/generate/src/Spi_PBcfg.c 

COMPILED_SRCS += \
./BasicSw/Mcal/generate/src/Adc_PBcfg.src \
./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.src \
./BasicSw/Mcal/generate/src/Dio_Lcfg.src \
./BasicSw/Mcal/generate/src/Dma_PBcfg.src \
./BasicSw/Mcal/generate/src/FlsLoader_Cfg.src \
./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.src \
./BasicSw/Mcal/generate/src/Gpt_PBcfg.src \
./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.src \
./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.src \
./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.src \
./BasicSw/Mcal/generate/src/Mcu_PBcfg.src \
./BasicSw/Mcal/generate/src/Port_PBcfg.src \
./BasicSw/Mcal/generate/src/Spi_PBcfg.src 

C_DEPS += \
./BasicSw/Mcal/generate/src/Adc_PBcfg.d \
./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.d \
./BasicSw/Mcal/generate/src/Dio_Lcfg.d \
./BasicSw/Mcal/generate/src/Dma_PBcfg.d \
./BasicSw/Mcal/generate/src/FlsLoader_Cfg.d \
./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.d \
./BasicSw/Mcal/generate/src/Gpt_PBcfg.d \
./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.d \
./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.d \
./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.d \
./BasicSw/Mcal/generate/src/Mcu_PBcfg.d \
./BasicSw/Mcal/generate/src/Port_PBcfg.d \
./BasicSw/Mcal/generate/src/Spi_PBcfg.d 

OBJS += \
./BasicSw/Mcal/generate/src/Adc_PBcfg.o \
./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.o \
./BasicSw/Mcal/generate/src/Dio_Lcfg.o \
./BasicSw/Mcal/generate/src/Dma_PBcfg.o \
./BasicSw/Mcal/generate/src/FlsLoader_Cfg.o \
./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.o \
./BasicSw/Mcal/generate/src/Gpt_PBcfg.o \
./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.o \
./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.o \
./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.o \
./BasicSw/Mcal/generate/src/Mcu_PBcfg.o \
./BasicSw/Mcal/generate/src/Port_PBcfg.o \
./BasicSw/Mcal/generate/src/Spi_PBcfg.o 


# Each subdirectory must supply rules for building sources it contributes
BasicSw/Mcal/generate/src/%.src: ../BasicSw/Mcal/generate/src/%.c BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -cs --dep-file="$(basename $@).d" --misrac-version=2004 -D__CPU__=tc38x "-fC:/WORK/Aurix-Workspace_JG_TSW/JG_TSW/JG_TSW/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<" && \
	if [ -f "$(basename $@).d" ]; then sed.exe -r  -e 's/\b(.+\.o)\b/BasicSw\/Mcal\/generate\/src\/\1/g' -e 's/\\/\//g' -e 's/\/\//\//g' -e 's/"//g' -e 's/([a-zA-Z]:\/)/\L\1/g' -e 's/\d32:/@TARGET_DELIMITER@/g; s/\\\d32/@ESCAPED_SPACE@/g; s/\d32/\\\d32/g; s/@ESCAPED_SPACE@/\\\d32/g; s/@TARGET_DELIMITER@/\d32:/g' "$(basename $@).d" > "$(basename $@).d_sed" && cp "$(basename $@).d_sed" "$(basename $@).d" && rm -f "$(basename $@).d_sed" 2>/dev/null; else echo 'No dependency file to process';fi
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Adc_PBcfg.o: ./BasicSw/Mcal/generate/src/Adc_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.o: ./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Dio_Lcfg.o: ./BasicSw/Mcal/generate/src/Dio_Lcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Dma_PBcfg.o: ./BasicSw/Mcal/generate/src/Dma_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/FlsLoader_Cfg.o: ./BasicSw/Mcal/generate/src/FlsLoader_Cfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.o: ./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Gpt_PBcfg.o: ./BasicSw/Mcal/generate/src/Gpt_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.o: ./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.o: ./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.o: ./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Mcu_PBcfg.o: ./BasicSw/Mcal/generate/src/Mcu_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Port_PBcfg.o: ./BasicSw/Mcal/generate/src/Port_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

BasicSw/Mcal/generate/src/Spi_PBcfg.o: ./BasicSw/Mcal/generate/src/Spi_PBcfg.src BasicSw/Mcal/generate/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-BasicSw-2f-Mcal-2f-generate-2f-src

clean-BasicSw-2f-Mcal-2f-generate-2f-src:
	-$(RM) ./BasicSw/Mcal/generate/src/Adc_PBcfg.d ./BasicSw/Mcal/generate/src/Adc_PBcfg.o ./BasicSw/Mcal/generate/src/Adc_PBcfg.src ./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.d ./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.o ./BasicSw/Mcal/generate/src/Can_17_McmCan_PBcfg.src ./BasicSw/Mcal/generate/src/Dio_Lcfg.d ./BasicSw/Mcal/generate/src/Dio_Lcfg.o ./BasicSw/Mcal/generate/src/Dio_Lcfg.src ./BasicSw/Mcal/generate/src/Dma_PBcfg.d ./BasicSw/Mcal/generate/src/Dma_PBcfg.o ./BasicSw/Mcal/generate/src/Dma_PBcfg.src ./BasicSw/Mcal/generate/src/FlsLoader_Cfg.d ./BasicSw/Mcal/generate/src/FlsLoader_Cfg.o ./BasicSw/Mcal/generate/src/FlsLoader_Cfg.src ./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.d ./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.o ./BasicSw/Mcal/generate/src/Fls_17_Dmu_PBcfg.src ./BasicSw/Mcal/generate/src/Gpt_PBcfg.d ./BasicSw/Mcal/generate/src/Gpt_PBcfg.o ./BasicSw/Mcal/generate/src/Gpt_PBcfg.src ./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.d ./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.o ./BasicSw/Mcal/generate/src/Icu_17_TimerIp_PBcfg.src ./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.d ./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.o ./BasicSw/Mcal/generate/src/Lin_17_AscLin_PBcfg.src ./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.d ./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.o ./BasicSw/Mcal/generate/src/Mcu_17_TimerIp_Cfg.src ./BasicSw/Mcal/generate/src/Mcu_PBcfg.d ./BasicSw/Mcal/generate/src/Mcu_PBcfg.o ./BasicSw/Mcal/generate/src/Mcu_PBcfg.src ./BasicSw/Mcal/generate/src/Port_PBcfg.d ./BasicSw/Mcal/generate/src/Port_PBcfg.o ./BasicSw/Mcal/generate/src/Port_PBcfg.src ./BasicSw/Mcal/generate/src/Spi_PBcfg.d ./BasicSw/Mcal/generate/src/Spi_PBcfg.o ./BasicSw/Mcal/generate/src/Spi_PBcfg.src

.PHONY: clean-BasicSw-2f-Mcal-2f-generate-2f-src

