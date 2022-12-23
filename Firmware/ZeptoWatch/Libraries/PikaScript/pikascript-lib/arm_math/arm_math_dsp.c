#include "pikaScript.h"
#include "PikaStdData_List.h"

#include "stm32f405xx.h"

#include "arm_math.h"

void arm_math_dsp_FFT___init__(PikaObj *self) {
	obj_setInt(self, "LENGTH_32", 32);
	obj_setInt(self, "LENGTH_64", 64);
	obj_setInt(self, "LENGTH_128", 128);
	obj_setInt(self, "LENGTH_256", 256);
	obj_setInt(self, "LENGTH_512", 512);
	obj_setInt(self, "LENGTH_1024", 1024);
}

float fft_tmp_list_1[1050] __attribute__((section(".ccmram")));
float fft_tmp_list_2[1050] __attribute__((section(".ccmram")));

PikaObj* arm_math_dsp_FFT_rfft(PikaObj *self, PikaObj* inputList, int length) {
	PikaList* in = obj_getPtr(inputList, "list");
	for (int i = 0; i < length; i ++) fft_tmp_list_1[i] = pikaList_getFloat(in, i);

	arm_rfft_fast_instance_f32 S;
	arm_rfft_fast_init_f32(&S, length);
	arm_rfft_fast_f32(&S, fft_tmp_list_1, fft_tmp_list_2, 0);

	PikaObj *res = newNormalObj(New_PikaStdData_List);
	PikaStdData_List___init__(res);
	for (int i = 0; i < length; i ++) PikaStdData_List_append(res, arg_newFloat(fft_tmp_list_2[i]));

	return res;
}

PikaObj* arm_math_dsp_Complex_mag(PikaObj *self, PikaObj* inputList, int num) {
	PikaList* in = obj_getPtr(inputList, "list");
	for (int i = 0; i < num * 2; i ++) fft_tmp_list_1[i] = pikaList_getFloat(in, i);

	arm_cmplx_mag_f32(fft_tmp_list_1, fft_tmp_list_2, num);

	PikaObj *res = newNormalObj(New_PikaStdData_List);
	PikaStdData_List___init__(res);
	for (int i = 0; i < num; i ++) PikaStdData_List_append(res, arg_newFloat(fft_tmp_list_2[i]));

	return res;
}

PikaObj* arm_math_dsp_Hamming_getFactors(PikaObj *self, int N) {
	PikaObj *res = newNormalObj(New_PikaStdData_List);
	PikaStdData_List___init__(res);
	for (int i = 0; i < N; i ++) PikaStdData_List_append(res, arg_newFloat(0.54 - 0.46 * arm_cos_f32(2.0 * PI * i / (N - 1))));
	return res;
}
