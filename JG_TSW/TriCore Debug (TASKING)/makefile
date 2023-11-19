################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include BasicSw/Mcal/generate/src/subdir.mk
-include BasicSw/Infra/Ssw/src/subdir.mk
-include BasicSw/Infra/Ssc/Spi/src/subdir.mk
-include BasicSw/Infra/Ssc/Port/src/subdir.mk
-include BasicSw/Infra/Ssc/Mcu/src/subdir.mk
-include BasicSw/Infra/Ssc/McalLib/src/subdir.mk
-include BasicSw/Infra/Ssc/Lin_17_AscLin/src/subdir.mk
-include BasicSw/Infra/Ssc/Irq/src/subdir.mk
-include BasicSw/Infra/Ssc/Icu_17_TimerIp/src/subdir.mk
-include BasicSw/Infra/Ssc/Gpt/src/subdir.mk
-include BasicSw/Infra/Ssc/Fls_17_Dmu/src/subdir.mk
-include BasicSw/Infra/Ssc/FlsLoader/src/subdir.mk
-include BasicSw/Infra/Ssc/Dma/src/subdir.mk
-include BasicSw/Infra/Ssc/Dio/src/subdir.mk
-include BasicSw/Infra/Ssc/Can_17_McmCan/src/subdir.mk
-include BasicSw/Infra/Ssc/Adc/src/subdir.mk
-include BasicSw/Infra/Integration/subdir.mk
-include BasicSw/Infra/Autosar_Srv/AS422/subdir.mk
-include BasicSw/Infra/Autosar_Srv/subdir.mk
-include BasicSw/Cdd/Pmic/src/subdir.mk
-include BasicSw/Cdd/Cmic/subdir.mk
-include BasicSw/Cdd/Adi/WBMS_Interface_Lib-Rel2.2.0/Source/subdir.mk
-include BasicSw/Cdd/Adi/Source/otap_files/subdir.mk
-include BasicSw/Cdd/Adi/Source/container_files/bms_scripts/subdir.mk
-include BasicSw/Cdd/Adi/Source/configuration_files/subdir.mk
-include BasicSw/Cdd/Adi/Source/application/subdir.mk
-include BasicSw/Cdd/Adi/Source/HAL/subdir.mk
-include BasicSw/Cdd/Adi/Source/subdir.mk
-include AppSw/TestSw/src/subdir.mk
-include AppSw/Infra/Main/subdir.mk
-include AppSw/Infra/Cfg_Ssw/src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := JG_TSW
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
JG_TSW.siz \


# All Target
all:
	+@$(MAKE) --no-print-directory main-build && $(MAKE) --no-print-directory post-build

# Main-build Target
main-build: JG_TSW.elf secondary-outputs

# Tool invocations
JG_TSW.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../JG_TSW.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="JG_TSW.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 -lcs_fpu -lfp_fpu -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc38x -o"JG_TSW.elf" -Wl-o"JG_TSW.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

JG_TSW.siz: JG_TSW.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "JG_TSW.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	find . ! -name "*.mk" ! -name "makefile" ! -name "." -type f -delete 
	-@echo ' '

post-build:
	-C:\WORK\JG_TSW\Tool\BuildProcedure\PostBuild.bat
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build post-build

-include ../makefile.targets
