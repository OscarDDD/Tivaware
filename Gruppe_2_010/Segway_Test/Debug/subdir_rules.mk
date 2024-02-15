################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
ADC.obj: G:/Gruppe_2_010/Common_Classes/ADC.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Controller.obj: G:/Gruppe_2_010/Common_Classes/Controller.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

GPIO.obj: G:/Gruppe_2_010/Common_Classes/GPIO.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

MPU6050.obj: G:/Gruppe_2_010/Common_Classes/MPU6050.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

PWM.obj: G:/Gruppe_2_010/Common_Classes/PWM.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Segway.obj: G:/Gruppe_2_010/Common_Classes/Segway.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Steering.obj: G:/Gruppe_2_010/Common_Classes/Steering.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

System.obj: G:/Gruppe_2_010/Common_Classes/System.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Timer.obj: G:/Gruppe_2_010/Common_Classes/Timer.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.cpp $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

uartstdio.obj: G:/TivaWare_C_Series-2.1.4.178/utils/uartstdio.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="G:/Gruppe_2_010/Segway_Test" --include_path="G:/TivaWare_C_Series-2.1.4.178" --include_path="G:/Gruppe_2_010/Common_Classes" --include_path="G:/TivaWare_C_Series-2.1.4.178/utils" --include_path="D:/ti/ccs1031/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --define=ccs="ccs" --define=__STDC_LIMIT_MACROS --define=PART_TM4C123GH6PM -g --c99 --float_operations_allowed=32 --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


